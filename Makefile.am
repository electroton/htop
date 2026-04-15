# Makefile.am - automake input for htop
# Personal fork: added WARN_CFLAGS for stricter compilation warnings

AUTOMAKE_OPTIONS = foreign

bin_PROGRAMS = htop

htop_SOURCES = \
	Action.c \
	Action.h \
	AffinityPanel.c \
	AffinityPanel.h \
	CRT.c \
	CRT.h \
	CmdlinePanel.c \
	CmdlinePanel.h \
	ClockMeter.c \
	ClockMeter.h \
	ColorsPanel.c \
	ColorsPanel.h \
	ColumnSettings.c \
	ColumnSettings.h \
	CommandLine.c \
	CommandLine.h \
	CommandScreen.c \
	CommandScreen.h \
	DiskIOMeter.c \
	DiskIOMeter.h \
	DisplayOptionsPanel.c \
	DisplayOptionsPanel.h \
	DynamicColumn.c \
	DynamicColumn.h \
	DynamicMeter.c \
	DynamicMeter.h \
	DynamicScreen.c \
	DynamicScreen.h \
	EnvScreen.c \
	EnvScreen.h \
	FunctionBar.c \
	FunctionBar.h \
	GenericCommandLineHandler.c \
	GenericCommandLineHandler.h \
	Hashtable.c \
	Hashtable.h \
	Header.c \
	Header.h \
	HeaderLayout.c \
	HeaderLayout.h \
	HostnameMeter.c \
	HostnameMeter.h \
	Htop.c \
	Htop.h \
	IncSet.c \
	IncSet.h \
	InfoScreen.c \
	InfoScreen.h \
	Iterator.h \
	ListItem.c \
	ListItem.h \
	LoadAverageMeter.c \
	LoadAverageMeter.h \
	Machine.c \
	Machine.h \
	MainPanel.c \
	MainPanel.h \
	MemoryMeter.c \
	MemoryMeter.h \
	MemorySwapMeter.c \
	MemorySwapMeter.h \
	Meter.c \
	Meter.h \
	MeterMode.h \
	MetersPanel.c \
	MetersPanel.h \
	NetIOMeter.c \
	NetIOMeter.h \
	Object.c \
	Object.h \
	OpenFilesScreen.c \
	OpenFilesScreen.h \
	OptionItem.c \
	OptionItem.h \
	Panel.c \
	Panel.h \
	Process.c \
	Process.h \
	ProcessList.c \
	ProcessList.h \
	ProcessLocksScreen.c \
	ProcessLocksScreen.h \
	RichString.c \
	RichString.h \
	Row.c \
	Row.h \
	RowField.h \
	ScreenManager.c \
	ScreenManager.h \
	ScreensPanel.c \
	ScreensPanel.h \
	ScreenTabsPanel.c \
	ScreenTabsPanel.h \
	Settings.c \
	Settings.h \
	Signal.c \
	Signal.h \
	SignalsPanel.c \
	SignalsPanel.h \
	Table.c \
	Table.h \
	TraceScreen.c \
	TraceScreen.h \
	UptimeMeter.c \
	UptimeMeter.h \
	UsersTable.c \
	UsersTable.h \
	Vector.c \
	Vector.h \
	XUtils.c \
	XUtils.h \
	main.c

# Enable extra warnings during personal builds to catch potential issues
# Added -Wshadow to catch variable shadowing bugs, and -Wformat=2 for
# stricter printf/scanf format string checking.
# Also added -Wconversion to catch implicit type conversion issues that
# could lead to subtle bugs (e.g. int -> char truncation).
# Removed -Wconversion for now -- it produces too many noisy warnings in
# third-party headers included via ncurses. Re-evaluate after upstream
# cleans up their includes.
# Added -Wdouble-promotion to catch unintentional float->double promotions
# which can silently impact performance on platforms without an FPU.
# Added -Wnull-dereference to catch potential null pointer dereferences at
# compile time where the compiler can statically determine the issue.
# Added -Wundef to catch uses of undefined macros in #if conditions, which
# can silently evaluate to 0 and cause hard-to-debug conditional logic bugs.
# Fixed truncated flag: completed -Wdouble-promotion (was cut off as -Wd)

# Note: keeping WARN_CFLAGS separate from AM_CFLAGS so it's easy to
# disable all extra warnings in one place when doing a quick test build.
WARN_CFLAGS = -Wall -Wextra -Wshadow -Wformat=2 -Wdouble-promotion -Wnull-dereference -Wundef
AM_CFLAGS = $(WARN_CFLAGS)
