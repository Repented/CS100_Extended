QT       += core gui

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
    SortByD.cpp \
    SortByP.cpp \
    addeventwindow.cpp \
    calendarviewwindow.cpp \
    listviewwindow.cpp \
    main.cpp \
    maincalendarwindow.cpp \
    removeeventwindow.cpp \
    updateeventwindow.cpp

HEADERS += \
    Calendar.h \
    DailyPlan.h \
    Schedule.h \
    Sort.h \
    SortByD.h \
    SortByP.h \
    addeventwindow.h \
    calendarviewwindow.h \
    listviewwindow.h \
    maincalendarwindow.h \
    removeeventwindow.h \
    updateeventwindow.h

FORMS += \
    addeventwindow.ui \
    calendarviewwindow.ui \
    listviewwindow.ui \
    maincalendarwindow.ui \
    removeeventwindow.ui \
    updateeventwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    calendardata.txt
