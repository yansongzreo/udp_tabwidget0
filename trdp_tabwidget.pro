QT       += core gui
QT       += network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app
TARGET = 705_DMS

#LIBS += D:/software/tcnopen-trdp-r2319-trunk/tcnopen-trdp-r2319-trunk/trdp/VSExpress2015/Release/TRDP.lib
#INCLUDEPATH += D:/software/tcnopen-trdp-r2319-trunk/tcnopen-trdp-r2319-trunk/trdp/src/api \
#D:/software/tcnopen-trdp-r2319-trunk/tcnopen-trdp-r2319-trunk/trdp/src/vos/api \
#D:/software/tcnopen-trdp-r2319-trunk/tcnopen-trdp-r2319-trunk/trdp/resources/windows/getopt \
#D:/software/tcnopen-trdp-r2319-trunk/tcnopen-trdp-r2319-trunk/trdp/src/vos/windows


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS
# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0
include(./QXlsx/QXlsx.pri)
SOURCES += \
    main.cpp \
    mainwindow.cpp \
trdp_recv.cpp \
    trdp_send.cpp\
cfg.cpp

HEADERS += \
    mainwindow.h \
trdp_recv.h \
    trdp_send.h\
cfg.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
