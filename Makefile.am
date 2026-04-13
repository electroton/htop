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
WARN_CFLAGS = -Wall -Wextra -Wno-unused-parameter

htop_CFLAGS = @CFLAGS@ $(WARN_CFLAGS)
htop_LDADD = @LDFLAGS@ @LIBS@

if HTOP_LINUX
htop_SOURCES += \
	linux/CGroupUtils.c \
	linux/CGroupUtils.h \
	linux/CPUMeter.c \
	linux/CPUMeter.h \
	linux/GenericCPUMeter.c \
	linux/GenericCPUMeter.h \
	linux/IOPriorityPanel.c \
	linux/IOPriorityPanel.h \
	linux/LibSensors.c \
	linux/LibSensors.h \
	linux/LinuxMachine.c \
	linux/LinuxMachine.h \
	linux/LinuxProcess.c \
	linux/LinuxProcess.h \
	linux/LinuxProcessTable.c \
	linux/LinuxProcessTable.h \
	linux/Platform.c \
	linux/Platform.h \
	linux/PressureStallMeter.c \
	linux/PressureStallMeter.h \
	linux/SELinuxMeter.c \
	linux/SELinuxMeter.h \
	linux/SystemdMeter.c \
	linux/SystemdMeter.h \
	linux/ZramMeter.c \
	linux/ZramMeter.h \
	linux/ZswapMeter.c \
	linux/ZswapMeter.h
endif

if HTOP_FREEBSD
htop_SOURCES += \
	freebsd/FreeBSDMachine.c \
	freebsd/FreeBSDMachine.h \
	freebsd/FreeBSDProcess.c \
	freebsd/FreeBSDProcess.h \
	freebsd/FreeBSDProcessTable.c \
	freebsd/FreeBSDProcessTable.h \
	freebsd/Platform.c \
	freebsd/Platform.h \
	bsd/BSDProcess.c \
	bsd/BSDProcess.h \
	bsd/BSDProcessT
