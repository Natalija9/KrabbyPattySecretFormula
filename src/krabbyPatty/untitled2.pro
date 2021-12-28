QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    deadlybarrier.cpp \
    dirtybubble.cpp \
    evilspongebob.cpp \
    flag.cpp \
    informationbar.cpp \
    ingredient.cpp \
    item.cpp \
    jellyfish.cpp \
    karen.cpp \
    level.cpp \
    leveldata.cpp \
    life.cpp \
    main.cpp \
    message.cpp \
    player.cpp \
    playerparameters.cpp \
    ranglist.cpp \
    regulartile.cpp \
    score.cpp \
    settings.cpp \
    slowingtile.cpp \
    sound.cpp \
    tile.cpp \
    widget.cpp

HEADERS += \
    deadlybarrier.h \
    dirtybubble.h \
    evilspongebob.h \
    flag.h \
    informationbar.h \
    ingredient.h \
    item.h \
    jellyfish.h \
    karen.h \
    level.h \
    leveldata.h \
    life.h \
    message.h \
    player.h \
    playerparameters.h \
    ranglist.h \
    regulartile.h \
    score.h \
    settings.h \
    slowingtile.h \
    sound.h \
    tile.h \
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
    files/players.txt \
    images/messageBox1.jpg \
    images/player.png \
    images/playerLeft.png
