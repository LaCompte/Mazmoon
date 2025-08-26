QT += core widgets gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

TARGET = mazmoon
TEMPLATE = app

DEFINES += QT_DEPRECATED_WARNINGS
DEFINES += UNICODE _UNICODE

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    ribbonwidget.cpp \
    urdutextedit.cpp

HEADERS += \
    mainwindow.h \
    ribbonwidget.h \
    urdutextedit.h

FORMS += \
    mainwindow.ui

# RESOURCES +=

# Default rules for deployment
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
