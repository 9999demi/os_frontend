QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    account.cpp \
    appstore.cpp \
    calendar.cpp \
    changepassword.cpp \
    chess.cpp \
    database.cpp \
    disk_operation.cpp \
    file_run.cpp \
    file_system.cpp \
    filemanager.cpp \
    filesystem.cpp \
    fishjoy.cpp \
    logout.cpp \
    main.cpp \
    mainwindow.cpp \
    management.cpp \
    map.cpp \
    map_app.cpp \
    ram.cpp \
    register.cpp \
    rom.cpp \
    shutdown.cpp \
    snake.cpp \
    start.cpp \
    user.cpp \
    wallpaper.cpp \
    widget.cpp

HEADERS += \
    account.h \
    appstore.h \
    calendar.h \
    changepassword.h \
    chess.h \
    database.h \
    disk_operation.h \
    file_run.h \
    file_system.h \
    filemanager.h \
    filesystem.h \
    fishjoy.h \
    logout.h \
    mainwindow.h \
    management.h \
    map.h \
    map_app.h \
    ram.h \
    register.h \
    rom.h \
    shutdown.h \
    snake.h \
    start.h \
    user.h \
    wallpaper.h \
    widget.h

FORMS += \
    account.ui \
    changepassword.ui \
    filemanager.ui \
    filesystem.ui \
    logout.ui \
    mainwindow.ui \
    register.ui \
    shutdown.ui \
    start.ui \
    wallpaper.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    pictures.qrc

LIBS += \
    -lpsapi

QT += concurrent

QT += concurrent widgets
CONFIG += console
CONFIG -= app_bundle

DISTFILES += \
    Chinese_Chess.exe \
    Snake.exe \
    calendarwidget.exe \
    fishjoy.exe
