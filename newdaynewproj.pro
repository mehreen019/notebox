QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    adduserwindow.cpp \
    button.cpp \
    cell.cpp \
    controller.cpp \
    dashboard.cpp \
    form.cpp \
    image.cpp \
    info.cpp \
    loginwindow.cpp \
    main.cpp \
    mainwindow.cpp \
    notes.cpp \
    publicWorkspace.cpp \
    pwscell.cpp \
    remEdit.cpp \
    remWindow.cpp \
    sclButton.cpp \
    textviewwindow.cpp \
    updatebutton.cpp \
    updatepasswordwindow.cpp \
    user.cpp \
    wsCell.cpp

HEADERS += \
    Header.h \
    adduserwindow.h \
    button.h \
    cell.h \
    controller.h \
    dashboard.h \
    form.h \
    image.h \
    info.h \
    loginwindow.h \
    mainwindow.h \
    notes.h \
    publicWorkspace.h \
    pwscell.h \
    remEdit.h \
    remWindow.h \
    sclButton.h \
    textviewwindow.h \
    updatebutton.h \
    updatepasswordwindow.h \
    user.h \
    wsCell.h

FORMS += \
    adduserwindow.ui \
    button.ui \
    cell.ui \
    dashboard.ui \
    form.ui \
    image.ui \
    info.ui \
    loginwindow.ui \
    mainwindow.ui \
    publicWorkspace.ui \
    pwscell.ui \
    remEdit.ui \
    remWindow.ui \
    sclButton.ui \
    textviewwindow.ui \
    updatebutton.ui \
    updatepasswordwindow.ui \
    wsCell.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    button.qrc

