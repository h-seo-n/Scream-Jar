QT       += core gui sql network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    analysispopup.cpp \
    clickablelabel.cpp \
    custompopup.cpp \
    customtextedit.cpp \
    database.cpp \
    feedmodel.cpp \
    feedpopup.cpp \
    friendaddpopup.cpp \
    friendmodel.cpp \
    friendspopup.cpp \
    jarpopup.cpp \
    loginwidget.cpp \
    main.cpp \
    mainpage.cpp \
    mainwindow.cpp \
    scream.cpp \
    screammodel.cpp \
    serverapi.cpp \
    signupwidget.cpp \
    startpage.cpp \
    user.cpp

HEADERS += \
    analysispopup.h \
    clickablelabel.h \
    custompopup.h \
    customtextedit.h \
    database.h \
    feedmodel.h \
    feedpopup.h \
    friendaddpopup.h \
    friendmodel.h \
    friendspopup.h \
    jarpopup.h \
    loginwidget.h \
    mainpage.h \
    mainwindow.h \
    scream.h \
    screammodel.h \
    serverapi.h \
    signupwidget.h \
    startpage.h \
    user.h

FORMS += \
    analysispopup.ui \
    custompopup.ui \
    feedpopup.ui \
    friendaddpopup.ui \
    friendspopup.ui \
    jarpopup.ui \
    loginwidget.ui \
    mainpage.ui \
    mainwindow.ui \
    signupwidget.ui \
    startpage.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    ../../pyflask/server.py
