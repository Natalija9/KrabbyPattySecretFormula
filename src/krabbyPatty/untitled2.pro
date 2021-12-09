QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deadlybarrier.cpp \
    ingredient.cpp \
    item.cpp \
    level.cpp \
    life.cpp \
    main.cpp \
    player.cpp \
    settings.cpp \
    slowingbarrier.cpp \
    widget.cpp

HEADERS += \
    deadlybarrier.h \
    ingredient.h \
    item.h \
    level.h \
    life.h \
    player.h \
    settings.h \
    slowingbarrier.h \
    widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    images/player.png \
    images/playerLeft.png
