#############################################################################
# Makefile for building: cuACS
# Generated by qmake (3.1) (Qt 5.9.5)
# Project:  cuACS.pro
# Template: app
# Command: /usr/lib/qt5/bin/qmake -o Makefile cuACS.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
#############################################################################

MAKEFILE      = Makefile

####### Compiler, tools and options

CC            = gcc
CXX           = g++
DEFINES       = -DQT_DEPRECATED_WARNINGS -DQT_QML_DEBUG -DQT_WIDGETS_LIB -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -g -Wall -W -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -isystem /usr/include/x86_64-linux-gnu/qt5 -isystem /usr/include/x86_64-linux-gnu/qt5/QtWidgets -isystem /usr/include/x86_64-linux-gnu/qt5/QtGui -isystem /usr/include/x86_64-linux-gnu/qt5/QtCore -I. -isystem /usr/include/libdrm -I. -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++
QMAKE         = /usr/lib/qt5/bin/qmake
DEL_FILE      = rm -f
CHK_DIR_EXISTS= test -d
MKDIR         = mkdir -p
COPY          = cp -f
COPY_FILE     = cp -f
COPY_DIR      = cp -f -R
INSTALL_FILE  = install -m 644 -p
INSTALL_PROGRAM = install -m 755 -p
INSTALL_DIR   = cp -f -R
QINSTALL      = /usr/lib/qt5/bin/qmake -install qinstall
QINSTALL_PROGRAM = /usr/lib/qt5/bin/qmake -install qinstall -exe
DEL_FILE      = rm -f
SYMLINK       = ln -f -s
DEL_DIR       = rmdir
MOVE          = mv -f
TAR           = tar -cf
COMPRESS      = gzip -9f
DISTNAME      = cuACS1.0.0
DISTDIR = /home/student/cuACS/.tmp/cuACS1.0.0
LINK          = g++
LFLAGS        = 
LIBS          = $(SUBLIBS) -lsqlite3 -lQt5Widgets -lQt5Gui -lQt5Core -lGL -lpthread 
AR            = ar cqs
RANLIB        = 
SED           = sed
STRIP         = strip

####### Output directory

OBJECTS_DIR   = ./

####### Files

SOURCES       = data/DatabaseInterface.cpp \
		interface/main.cpp \
		interface/Animal.cpp \
		interface/AnimalManager.cpp \
		interface/MainWindow.cpp \
		interface/AnimalInputDiag.cpp \
		interface/AnimalListView.cpp \
		interface/AnimalDetailDiag.cpp \
		interface/species.cpp \
		interface/Address.cpp \
		interface/Client.cpp \
		interface/ClientProfile.cpp \
		interface/ClientInputDiag.cpp \
		interface/ClientManager.cpp \
		interface/ClientListView.cpp \
		interface/ClientDetailDiag.cpp moc_MainWindow.cpp \
		moc_AnimalInputDiag.cpp \
		moc_AnimalListView.cpp \
		moc_AnimalDetailDiag.cpp \
		moc_ClientInputDiag.cpp \
		moc_ClientListView.cpp \
		moc_ClientDetailDiag.cpp
OBJECTS       = DatabaseInterface.o \
		main.o \
		Animal.o \
		AnimalManager.o \
		MainWindow.o \
		AnimalInputDiag.o \
		AnimalListView.o \
		AnimalDetailDiag.o \
		species.o \
		Address.o \
		Client.o \
		ClientProfile.o \
		ClientInputDiag.o \
		ClientManager.o \
		ClientListView.o \
		ClientDetailDiag.o \
		moc_MainWindow.o \
		moc_AnimalInputDiag.o \
		moc_AnimalListView.o \
		moc_AnimalDetailDiag.o \
		moc_ClientInputDiag.o \
		moc_ClientListView.o \
		moc_ClientDetailDiag.o
DIST          = /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3danimation.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dcore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dextras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dinput.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dlogic.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickextras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickinput.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickrender.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3drender.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		cuACS.pro data/DatabaseInterface.h \
		interface/Animal.h \
		interface/AnimalManager.h \
		interface/MainWindow.h \
		interface/AnimalInputDiag.h \
		interface/AnimalListView.h \
		interface/AnimalDetailDiag.h \
		interface/species.h \
		interface/Address.h \
		interface/Client.h \
		interface/ClientProfile.h \
		interface/Levels.h \
		interface/ClientInputDiag.h \
		interface/ClientManager.h \
		interface/ClientListView.h \
		interface/ClientDetailDiag.h data/DatabaseInterface.cpp \
		interface/main.cpp \
		interface/Animal.cpp \
		interface/AnimalManager.cpp \
		interface/MainWindow.cpp \
		interface/AnimalInputDiag.cpp \
		interface/AnimalListView.cpp \
		interface/AnimalDetailDiag.cpp \
		interface/species.cpp \
		interface/Address.cpp \
		interface/Client.cpp \
		interface/ClientProfile.cpp \
		interface/ClientInputDiag.cpp \
		interface/ClientManager.cpp \
		interface/ClientListView.cpp \
		interface/ClientDetailDiag.cpp
QMAKE_TARGET  = cuACS
DESTDIR       = 
TARGET        = cuACS


first: all
####### Build rules

$(TARGET): ui_listview.h ui_mainwindow.h ui_animaldetaildialog.h ui_animalinputdialog.h ui_clientinputdialog.h ui_clientdetaildialog.h $(OBJECTS)  
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

Makefile: cuACS.pro /usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3danimation.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dcore.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dextras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dinput.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dlogic.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickextras.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickinput.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickrender.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3drender.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf \
		.qmake.stash \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf \
		/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf \
		cuACS.pro \
		/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Gui.prl \
		/usr/lib/x86_64-linux-gnu/libQt5Core.prl
	$(QMAKE) -o Makefile cuACS.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/linux.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/sanitize.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/gcc-base-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-base.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/common/g++-unix.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/qconfig.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3danimation.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dcore.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dextras.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dinput.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dlogic.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquick.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickanimation.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickextras.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickinput.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickrender.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3dquickscene2d.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_3drender.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_accessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_bootstrap_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_concurrent_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_core_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_dbus_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_egl_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfs_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eglfsdeviceintegration_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fb_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_glx_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_gui_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_input_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_kms_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_linuxaccessibility_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_network_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_opengl_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_openglextensions_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_printsupport_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_qmltest.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quick.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_quickwidgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_service_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_sql_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_testlib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_theme_support_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_widgets_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xcb_qpa_lib_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/modules/qt_lib_xml_private.pri:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_functions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++/qmake.conf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/spec_post.prf:
.qmake.stash:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exclusive_builds.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/toolchain.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_pre.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resolve_config.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/default_post.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qml_debug.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/warn_on.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qt.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/resources.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/moc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/opengl.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/uic.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/unix/thread.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/qmake_use.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/file_copies.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/testcase_targets.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/exceptions.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/yacc.prf:
/usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/lex.prf:
cuACS.pro:
/usr/lib/x86_64-linux-gnu/libQt5Widgets.prl:
/usr/lib/x86_64-linux-gnu/libQt5Gui.prl:
/usr/lib/x86_64-linux-gnu/libQt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile cuACS.pro -spec linux-g++ CONFIG+=debug CONFIG+=qml_debug

qmake_all: FORCE


all: Makefile $(TARGET)

dist: distdir FORCE
	(cd `dirname $(DISTDIR)` && $(TAR) $(DISTNAME).tar $(DISTNAME) && $(COMPRESS) $(DISTNAME).tar) && $(MOVE) `dirname $(DISTDIR)`/$(DISTNAME).tar.gz . && $(DEL_FILE) -r $(DISTDIR)

distdir: FORCE
	@test -d $(DISTDIR) || mkdir -p $(DISTDIR)
	$(COPY_FILE) --parents $(DIST) $(DISTDIR)/
	$(COPY_FILE) --parents /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp $(DISTDIR)/
	$(COPY_FILE) --parents data/DatabaseInterface.h interface/Animal.h interface/AnimalManager.h interface/MainWindow.h interface/AnimalInputDiag.h interface/AnimalListView.h interface/AnimalDetailDiag.h interface/species.h interface/Address.h interface/Client.h interface/ClientProfile.h interface/Levels.h interface/ClientInputDiag.h interface/ClientManager.h interface/ClientListView.h interface/ClientDetailDiag.h $(DISTDIR)/
	$(COPY_FILE) --parents data/DatabaseInterface.cpp interface/main.cpp interface/Animal.cpp interface/AnimalManager.cpp interface/MainWindow.cpp interface/AnimalInputDiag.cpp interface/AnimalListView.cpp interface/AnimalDetailDiag.cpp interface/species.cpp interface/Address.cpp interface/Client.cpp interface/ClientProfile.cpp interface/ClientInputDiag.cpp interface/ClientManager.cpp interface/ClientListView.cpp interface/ClientDetailDiag.cpp $(DISTDIR)/
	$(COPY_FILE) --parents interface/listview.ui interface/mainwindow.ui interface/animaldetaildialog.ui interface/animalinputdialog.ui interface/clientinputdialog.ui interface/clientdetaildialog.ui $(DISTDIR)/


clean: compiler_clean 
	-$(DEL_FILE) $(OBJECTS)
	-$(DEL_FILE) *~ core *.core


distclean: clean 
	-$(DEL_FILE) $(TARGET) 
	-$(DEL_FILE) .qmake.stash
	-$(DEL_FILE) Makefile


####### Sub-libraries

mocclean: compiler_moc_header_clean compiler_moc_source_clean

mocables: compiler_moc_header_make_all compiler_moc_source_make_all

check: first

benchmark: first

compiler_rcc_make_all:
compiler_rcc_clean:
compiler_moc_predefs_make_all: moc_predefs.h
compiler_moc_predefs_clean:
	-$(DEL_FILE) moc_predefs.h
moc_predefs.h: /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp
	g++ -pipe -g -Wall -W -dM -E -o moc_predefs.h /usr/lib/x86_64-linux-gnu/qt5/mkspecs/features/data/dummy.cpp

compiler_moc_header_make_all: moc_MainWindow.cpp moc_AnimalInputDiag.cpp moc_AnimalListView.cpp moc_AnimalDetailDiag.cpp moc_ClientInputDiag.cpp moc_ClientListView.cpp moc_ClientDetailDiag.cpp
compiler_moc_header_clean:
	-$(DEL_FILE) moc_MainWindow.cpp moc_AnimalInputDiag.cpp moc_AnimalListView.cpp moc_AnimalDetailDiag.cpp moc_ClientInputDiag.cpp moc_ClientListView.cpp moc_ClientDetailDiag.cpp
moc_MainWindow.cpp: interface/AnimalInputDiag.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/ClientInputDiag.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/AnimalListView.h \
		interface/AnimalDetailDiag.h \
		interface/ClientListView.h \
		interface/ClientDetailDiag.h \
		interface/MainWindow.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/MainWindow.h -o moc_MainWindow.cpp

moc_AnimalInputDiag.cpp: interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/AnimalInputDiag.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/AnimalInputDiag.h -o moc_AnimalInputDiag.cpp

moc_AnimalListView.cpp: interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/AnimalDetailDiag.h \
		interface/AnimalListView.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/AnimalListView.h -o moc_AnimalListView.cpp

moc_AnimalDetailDiag.cpp: interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/AnimalDetailDiag.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/AnimalDetailDiag.h -o moc_AnimalDetailDiag.cpp

moc_ClientInputDiag.cpp: interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/ClientInputDiag.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/ClientInputDiag.h -o moc_ClientInputDiag.cpp

moc_ClientListView.cpp: interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/ClientDetailDiag.h \
		interface/ClientListView.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/ClientListView.h -o moc_ClientListView.cpp

moc_ClientDetailDiag.cpp: interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/ClientDetailDiag.h \
		moc_predefs.h \
		/usr/lib/qt5/bin/moc
	/usr/lib/qt5/bin/moc $(DEFINES) --include ./moc_predefs.h -I/usr/lib/x86_64-linux-gnu/qt5/mkspecs/linux-g++ -I/home/student/cuACS -I/usr/include/x86_64-linux-gnu/qt5 -I/usr/include/x86_64-linux-gnu/qt5/QtWidgets -I/usr/include/x86_64-linux-gnu/qt5/QtGui -I/usr/include/x86_64-linux-gnu/qt5/QtCore -I/usr/include/c++/7 -I/usr/include/x86_64-linux-gnu/c++/7 -I/usr/include/c++/7/backward -I/usr/lib/gcc/x86_64-linux-gnu/7/include -I/usr/local/include -I/usr/lib/gcc/x86_64-linux-gnu/7/include-fixed -I/usr/include/x86_64-linux-gnu -I/usr/include interface/ClientDetailDiag.h -o moc_ClientDetailDiag.cpp

compiler_moc_source_make_all:
compiler_moc_source_clean:
compiler_uic_make_all: ui_listview.h ui_mainwindow.h ui_animaldetaildialog.h ui_animalinputdialog.h ui_clientinputdialog.h ui_clientdetaildialog.h
compiler_uic_clean:
	-$(DEL_FILE) ui_listview.h ui_mainwindow.h ui_animaldetaildialog.h ui_animalinputdialog.h ui_clientinputdialog.h ui_clientdetaildialog.h
ui_listview.h: interface/listview.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/listview.ui -o ui_listview.h

ui_mainwindow.h: interface/mainwindow.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/mainwindow.ui -o ui_mainwindow.h

ui_animaldetaildialog.h: interface/animaldetaildialog.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/animaldetaildialog.ui -o ui_animaldetaildialog.h

ui_animalinputdialog.h: interface/animalinputdialog.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/animalinputdialog.ui -o ui_animalinputdialog.h

ui_clientinputdialog.h: interface/clientinputdialog.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/clientinputdialog.ui -o ui_clientinputdialog.h

ui_clientdetaildialog.h: interface/clientdetaildialog.ui \
		/usr/lib/qt5/bin/uic
	/usr/lib/qt5/bin/uic interface/clientdetaildialog.ui -o ui_clientdetaildialog.h

compiler_yacc_decl_make_all:
compiler_yacc_decl_clean:
compiler_yacc_impl_make_all:
compiler_yacc_impl_clean:
compiler_lex_make_all:
compiler_lex_clean:
compiler_clean: compiler_moc_predefs_clean compiler_moc_header_clean compiler_uic_clean 

####### Compile

DatabaseInterface.o: data/DatabaseInterface.cpp data/DatabaseInterface.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/Client.h \
		interface/Address.h \
		interface/ClientProfile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o DatabaseInterface.o data/DatabaseInterface.cpp

main.o: interface/main.cpp interface/MainWindow.h \
		interface/AnimalInputDiag.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/ClientInputDiag.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/AnimalListView.h \
		interface/AnimalDetailDiag.h \
		interface/ClientListView.h \
		interface/ClientDetailDiag.h \
		data/DatabaseInterface.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o interface/main.cpp

Animal.o: interface/Animal.cpp interface/Animal.h \
		interface/species.h \
		interface/Levels.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Animal.o interface/Animal.cpp

AnimalManager.o: interface/AnimalManager.cpp interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		data/DatabaseInterface.h \
		interface/Client.h \
		interface/Address.h \
		interface/ClientProfile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AnimalManager.o interface/AnimalManager.cpp

MainWindow.o: interface/MainWindow.cpp interface/MainWindow.h \
		interface/AnimalInputDiag.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/ClientInputDiag.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/AnimalListView.h \
		interface/AnimalDetailDiag.h \
		interface/ClientListView.h \
		interface/ClientDetailDiag.h \
		ui_mainwindow.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o MainWindow.o interface/MainWindow.cpp

AnimalInputDiag.o: interface/AnimalInputDiag.cpp interface/AnimalInputDiag.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		ui_animalinputdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AnimalInputDiag.o interface/AnimalInputDiag.cpp

AnimalListView.o: interface/AnimalListView.cpp interface/AnimalListView.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		interface/AnimalDetailDiag.h \
		ui_listview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AnimalListView.o interface/AnimalListView.cpp

AnimalDetailDiag.o: interface/AnimalDetailDiag.cpp interface/AnimalDetailDiag.h \
		interface/AnimalManager.h \
		interface/Animal.h \
		interface/species.h \
		interface/Levels.h \
		ui_animaldetaildialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o AnimalDetailDiag.o interface/AnimalDetailDiag.cpp

species.o: interface/species.cpp interface/species.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o species.o interface/species.cpp

Address.o: interface/Address.cpp interface/Address.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Address.o interface/Address.cpp

Client.o: interface/Client.cpp interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o Client.o interface/Client.cpp

ClientProfile.o: interface/ClientProfile.cpp interface/ClientProfile.h \
		interface/Levels.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ClientProfile.o interface/ClientProfile.cpp

ClientInputDiag.o: interface/ClientInputDiag.cpp interface/ClientInputDiag.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		ui_clientinputdialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ClientInputDiag.o interface/ClientInputDiag.cpp

ClientManager.o: interface/ClientManager.cpp interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		data/DatabaseInterface.h \
		interface/Animal.h \
		interface/species.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ClientManager.o interface/ClientManager.cpp

ClientListView.o: interface/ClientListView.cpp interface/ClientListView.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		interface/ClientDetailDiag.h \
		ui_listview.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ClientListView.o interface/ClientListView.cpp

ClientDetailDiag.o: interface/ClientDetailDiag.cpp interface/ClientDetailDiag.h \
		interface/ClientManager.h \
		interface/Client.h \
		interface/Levels.h \
		interface/Address.h \
		interface/ClientProfile.h \
		ui_clientdetaildialog.h
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o ClientDetailDiag.o interface/ClientDetailDiag.cpp

moc_MainWindow.o: moc_MainWindow.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_MainWindow.o moc_MainWindow.cpp

moc_AnimalInputDiag.o: moc_AnimalInputDiag.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AnimalInputDiag.o moc_AnimalInputDiag.cpp

moc_AnimalListView.o: moc_AnimalListView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AnimalListView.o moc_AnimalListView.cpp

moc_AnimalDetailDiag.o: moc_AnimalDetailDiag.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_AnimalDetailDiag.o moc_AnimalDetailDiag.cpp

moc_ClientInputDiag.o: moc_ClientInputDiag.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ClientInputDiag.o moc_ClientInputDiag.cpp

moc_ClientListView.o: moc_ClientListView.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ClientListView.o moc_ClientListView.cpp

moc_ClientDetailDiag.o: moc_ClientDetailDiag.cpp 
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o moc_ClientDetailDiag.o moc_ClientDetailDiag.cpp

####### Install

install:  FORCE

uninstall:  FORCE

FORCE:

