/*
htop - Process.h
(C) 2004-2015 Hisham H. Muhammad
Released under the GNU GPLv2+, see the COPYING file
in the source distribution for its full text.
*/

#ifndef HEADER_Process
#define HEADER_Process

#include <stdbool.h>
#include <stdint.h>
#include <sys/types.h>

#include "Object.h"

#define PROCESS_FLAG_IO        0x0001
#define PROCESS_FLAG_CWD       0x0002

typedef enum ProcessField_ {
   PID = 1,
   COMM,
   STATE,
   PPID,
   PGRP,
   SESSION,
   TTY,
   TPGID,
   MINFLT,
   MAJFLT,
   PRIORITY,
   NICE,
   STARTTIME,
   PROCESSOR,
   M_VIRT,
   M_RESIDENT,
   ST_UID,
   PERCENT_CPU,
   PERCENT_MEM,
   USER,
   TIME,
   NLWP,
   TGID,
   LAST_PROCESSFIELD
} ProcessField;

typedef struct Process_ {
   /* Super object must be first */
   Object super;

   /* Pointer to ProcessList that owns this process */
   struct ProcessList_* processList;

   /* Process ID */
   pid_t pid;

   /* Parent process ID */
   pid_t ppid;

   /* Thread group ID */
   pid_t tgid;

   /* Process group ID */
   int pgrp;

   /* Session ID */
   int session;

   /* Controlling terminal */
   unsigned int tty_nr;

   /* Foreground process group of controlling terminal */
   int tpgid;

   /* Process name/command */
   char* comm;

   /* Full command line */
   char* cmdline;

   /* Process state (R, S, D, Z, T, etc.) */
   char state;

   /* Number of threads */
   int nlwp;

   /* CPU usage percentage */
   float percent_cpu;

   /* Memory usage percentage */
   float percent_mem;

   /* User ID */
   uid_t st_uid;

   /* Username string */
   const char* user;

   /* Priority and nice value */
   long int priority;
   long int nice;

   /* Virtual and resident memory (in kB) */
   long m_virt;
   long m_resident;

   /* CPU times */
   unsigned long long int utime;
   unsigned long long int stime;

   /* Start time (in clock ticks since boot) */
   unsigned long long int starttime;

   /* Which CPU is this process running on */
   int processor;

   /* Whether this process is selected/tagged */
   bool tag;

   /* Whether this is a userland thread */
   bool isUserlandThread;

   /* Whether this entry is shown (not filtered) */
   bool show;

   /* Flags for optional fields */
   uint32_t flags;
} Process;

typedef Process*(*Process_New)(struct ProcessList_*);
typedef void (*Process_WriteField)(const Process*, RichString*, ProcessField);

typedef struct ProcessClass_ {
   const ObjectClass super;
   const Process_WriteField writeField;
} ProcessClass;

#define As_Process(this_)              ((const ProcessClass*)((this_)->super.klass))
#define Process_writeField(this_, buf_, field_) As_Process(this_)->writeField(this_, buf_, field_)

void Process_delete(Object* cast);

bool Process_isThread(const Process* this);

void Process_writeField(const Process* this, RichString* str, ProcessField field);

int Process_compare(const void* v1, const void* v2);

#endif
