QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    chatwithworker.cpp \
    chosenworker.cpp \
    main.cpp \
    mainwindow.cpp \
    settasks.cpp

HEADERS += \
    chatwithworker.h \
    chosenworker.h \
    mainwindow.h \
    settasks.h

FORMS += \
    chatwithworker.ui \
    chosenworker.ui \
    mainwindow.ui \
    settasks.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc

TARGET = Coffee_boss
win32:RC_ICONS += img/coffee_app.ico
