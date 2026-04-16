/*
htop - htop.c
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#include "config.h"

#include <assert.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#include "Action.h"
#include "CRT.h"
#include "Hashtable.h"
#include "Header.h"
#include "IncSet.h"
#include "MainPanel.h"
#include "Panel.h"
#include "Platform.h"
#include "ProcessProcessList.h"
#include "ProvideCurses.h"
#include "ScreenManager.h"
#include "Settings.h"
#include "UsersTable.h"
#include "XUtils.h"


int main(int argc, char** argv) {
   /* Set locale based on environment variables */
   setlocale(LC_ALL, "");

   /* Parse command-line arguments */
   Settings* settings = Settings_new(argc, argv);
   if (!settings) {
      fprintf(stderr, "htop: failed to load settings.\n");
      return EXIT_FAILURE;
   }

   /* Personal preference: default to tree view on startup */
   if (!settings->treeView) {
      settings->treeView = true;
   }

   /* Initialize the curses display */
   CRT_init(settings, /* allowUnicode */ true);

   /* Build the user table */
   UsersTable* usersTable = UsersTable_new();

   /* Create the process list */
   ProcessList* pl = Platform_newProcessList(usersTable, settings->flags);
   if (!pl) {
      CRT_done();
      UsersTable_delete(usersTable);
      Settings_delete(settings);
      fprintf(stderr, "htop: failed to create process list.\n");
      return EXIT_FAILURE;
   }

   /* Initial process list scan */
   ProcessList_scan(pl, /* pauseProcessUpdate */ false);

   /* Set up the header (CPU/memory meters) */
   Header* header = Header_new(pl, settings, /* nrColumns */ 2);
   Header_populateFromSettings(header);

   /* Create the main panel */
   int headerHeight = Header_calculateHeight(header);
   MainPanel* panel = MainPanel_new();
   ProcessList_setPanel(pl, (Panel*)panel);

   MainPanel_updateTreeFunctions(panel, settings->treeView);

   /* Set up the screen manager */
   ScreenManager* scr = ScreenManager_new(header, settings, (State[]){{ .pl = pl, .mainPanel = panel, .header = header }}, /* owner */ true);
   ScreenManager_add(scr, (Panel*)panel, /* fuseKey */ -1);

   /* Main event/display loop */
   bool quit = false;
   int iterations = 0;
   double period = 1.0 / settings->delay;

   while (!quit) {
      struct timespec startTime;
      clock_gettime(CLOCK_MONOTONIC, &startTime);

      /* Refresh process list */
      ProcessList_scan(pl, settings->pauseProcessUpdate);

      /* Sort if needed */
      if (iterations % 2 == 0) {
         ProcessList_sort(pl);
      }

      /* Rebuild the display panel */
      ProcessList_rebuildPanel(pl);

      /* Redraw header */
      Header_draw(header);

      /* Run the screen manager for one tick */
      ScreenManager_run(scr, NULL, NULL);

      iterations++;

      /* Check for quit signal */
      if (Panel_getEventHandlerResult((Panel*)panel) == HTOP_QUIT) {
         quit = true;
      }

      /* Sleep for the remainder of the refresh interval */
