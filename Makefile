#############################################################################
# Makefile for building: 705_DMS
# Generated by qmake (3.1) (Qt 5.9.9)
# Project:  trdp_tabwidget.pro
# Template: app
# Command: D:\tools\qt5.9.9\5.9.9\mingw53_32\bin\qmake.exe -o Makefile trdp_tabwidget.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
#############################################################################

MAKEFILE      = Makefile

first: debug
install: debug-install
uninstall: debug-uninstall
QMAKE         = D:\tools\qt5.9.9\5.9.9\mingw53_32\bin\qmake.exe
DEL_FILE      = del
CHK_DIR_EXISTS= if not exist
MKDIR         = mkdir
COPY          = copy /y
COPY_FILE     = copy /y
COPY_DIR      = xcopy /s /q /y /i
INSTALL_FILE  = copy /y
INSTALL_PROGRAM = copy /y
INSTALL_DIR   = xcopy /s /q /y /i
QINSTALL      = D:\tools\qt5.9.9\5.9.9\mingw53_32\bin\qmake.exe -install qinstall
QINSTALL_PROGRAM = D:\tools\qt5.9.9\5.9.9\mingw53_32\bin\qmake.exe -install qinstall -exe
DEL_FILE      = del
SYMLINK       = $(QMAKE) -install ln -f -s
DEL_DIR       = rmdir
MOVE          = move
SUBTARGETS    =  \
		debug \
		release


debug: FORCE
	$(MAKE) -f $(MAKEFILE).Debug
debug-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Debug 
debug-all: FORCE
	$(MAKE) -f $(MAKEFILE).Debug all
debug-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug clean
debug-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Debug distclean
debug-install: FORCE
	$(MAKE) -f $(MAKEFILE).Debug install
debug-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Debug uninstall
release: FORCE
	$(MAKE) -f $(MAKEFILE).Release
release-make_first: FORCE
	$(MAKE) -f $(MAKEFILE).Release 
release-all: FORCE
	$(MAKE) -f $(MAKEFILE).Release all
release-clean: FORCE
	$(MAKE) -f $(MAKEFILE).Release clean
release-distclean: FORCE
	$(MAKE) -f $(MAKEFILE).Release distclean
release-install: FORCE
	$(MAKE) -f $(MAKEFILE).Release install
release-uninstall: FORCE
	$(MAKE) -f $(MAKEFILE).Release uninstall

Makefile: trdp_tabwidget.pro ../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf ../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_pre.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/qdevice.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/device_config.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/sanitize.conf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/gcc-base.conf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/g++-base.conf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/angle.conf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/qconfig.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_functions.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_config.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_post.prf \
		.qmake.stash \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/toolchain.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/default_pre.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/default_pre.prf \
		QXlsx/QXlsx.pri \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/resolve_config.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds_post.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/default_post.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/console.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qml_debug.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/precompile_header.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/warn_on.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/resources.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/moc.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/opengl.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/uic.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qmake_use.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/file_copies.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/testcase_targets.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exceptions.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/yacc.prf \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/lex.prf \
		trdp_tabwidget.pro \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Widgets.prl \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Gui.prl \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Network.prl \
		../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Core.prl
	$(QMAKE) -o Makefile trdp_tabwidget.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_pre.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/qdevice.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/device_config.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/sanitize.conf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/gcc-base.conf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/g++-base.conf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/common/angle.conf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/qconfig.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3danimation_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dcore_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dextras_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dinput_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dlogic_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquick_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickanimation_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickextras_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickinput_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickrender_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3dquickscene2d_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_3drender_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_accessibility_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axbase_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axcontainer_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_axserver_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bluetooth_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_bootstrap_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_concurrent_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_core_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_dbus_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designer_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_designercomponents_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_devicediscovery_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_egl_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_eventdispatcher_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fb_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_fontdatabase_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gamepad_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_gui_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_help_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_location_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimedia_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_multimediawidgets_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_network_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_nfc_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_opengl_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_openglextensions_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_packetprotocol_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_platformcompositor_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_positioning_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_printsupport_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qml_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldebug_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmldevtools_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qmltest_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_qtmultimediaquicktools_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quick_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickcontrols2_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickparticles_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quicktemplates2_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_quickwidgets_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_scxml_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sensors_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialbus_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_serialport_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_sql_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_svg_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_testlib_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_theme_support_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uiplugin.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_uitools_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_webchannel_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_websockets_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_widgets_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_winextras_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xml_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/modules/qt_lib_xmlpatterns_private.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_functions.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt_config.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/win32-g++/qmake.conf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/spec_post.prf:
.qmake.stash:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/toolchain.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/default_pre.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/default_pre.prf:
QXlsx/QXlsx.pri:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/resolve_config.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exclusive_builds_post.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/default_post.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/console.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qml_debug.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/precompile_header.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/warn_on.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qt.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/resources.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/moc.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/win32/opengl.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/uic.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/qmake_use.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/file_copies.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/testcase_targets.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/exceptions.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/yacc.prf:
../../../tools/qt5.9.9/5.9.9/mingw53_32/mkspecs/features/lex.prf:
trdp_tabwidget.pro:
../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Widgets.prl:
../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Gui.prl:
../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Network.prl:
../../../tools/qt5.9.9/5.9.9/mingw53_32/lib/Qt5Core.prl:
qmake: FORCE
	@$(QMAKE) -o Makefile trdp_tabwidget.pro -spec win32-g++ "CONFIG+=debug" "CONFIG+=qml_debug"

qmake_all: FORCE

make_first: debug-make_first release-make_first  FORCE
all: debug-all release-all  FORCE
clean: debug-clean release-clean  FORCE
distclean: debug-distclean release-distclean  FORCE
	-$(DEL_FILE) Makefile
	-$(DEL_FILE) .qmake.stash

debug-mocclean:
	$(MAKE) -f $(MAKEFILE).Debug mocclean
release-mocclean:
	$(MAKE) -f $(MAKEFILE).Release mocclean
mocclean: debug-mocclean release-mocclean

debug-mocables:
	$(MAKE) -f $(MAKEFILE).Debug mocables
release-mocables:
	$(MAKE) -f $(MAKEFILE).Release mocables
mocables: debug-mocables release-mocables

check: first

benchmark: first
FORCE:

$(MAKEFILE).Debug: Makefile
$(MAKEFILE).Release: Makefile
