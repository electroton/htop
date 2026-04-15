/*
htop - ProcessList.h
(C) 2004,2005 Bram Moolenaar
(C) 2004-2011 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#ifndef HEADER_ProcessList
#define HEADER_ProcessList

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

#include "Hashtable.h"
#include "Panel.h"
#include "Process.h"
#include "Settings.h"
#include "Vector.h"

#ifndef MAX_NAME
#define MAX_NAME 128
#endif

#ifndef MAX_READ
#define MAX_READ 2048
#endif

typedef struct ProcessList_ {
   Vector* processes;
   Vector* processes2;
   Hashtable* processTable;

   const Settings* settings;

   unsigned int totalTasks;
   unsigned int runningTasks;
   unsigned int userlandThreads;
   unsigned int kernelThreads;

   long long int totalMem;
   long long int usedMem;
   long long int buffersMem;
   long long int cachedMem;
   long long int sharedMem;
   long long int availableMem;

   long long int totalSwap;
   long long int usedSwap;
   long long int cachedSwap;

   int cpuCount;
} ProcessList;

/* Constructor / destructor */
ProcessList* ProcessList_new(const Settings* settings, uid_t userId);
void ProcessList_delete(ProcessList* this);

/* Scan and update the process list from /proc */
void ProcessList_scan(ProcessList* this, bool pauseProcessUpdate);

/* Rebuild the display list (apply filters, sort, etc.) */
void ProcessList_rebuildPanel(ProcessList* this, Panel* panel, bool hideKernelThreads,
                              bool hideUserlandThreads, bool hideRunningInContainer);

/* Lookup a process by PID */
Process* ProcessList_getProcess(ProcessList* this, pid_t pid,
                                bool* preExisting, Process_New constructor);

/* Print basic stats (for debugging) */
void ProcessList_printHeader(ProcessList* this, RichString* header);

/* Remove processes that were not updated in the last scan */
void ProcessList_removeStaledProcesses(ProcessList* this);

/* Helpers */
static inline int ProcessList_size(const ProcessList* this) {
   return Vector_size(this->processes);
}

static inline Process* ProcessList_get(const ProcessList* this, int index) {
   return (Process*) Vector_get(this->processes, index);
}

#endif /* HEADER_ProcessList */
