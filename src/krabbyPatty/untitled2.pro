QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Source/deadlybarrier.cpp \
    Source/dirtybubble.cpp \
    Source/evilspongebob.cpp \
    Source/flag.cpp \
    Source/informationbar.cpp \
    Source/ingredient.cpp \
    Source/item.cpp \
    Source/jellyfish.cpp \
    Source/karen.cpp \
    Source/level.cpp \
    Source/leveldata.cpp \
    Source/life.cpp \
    Source/main.cpp \
    Source/message.cpp \
    Source/player.cpp \
    Source/playerparameters.cpp \
    Source/ranglist.cpp \
    Source/regulartile.cpp \
    Source/score.cpp \
    Source/settings.cpp \
    Source/slowingtile.cpp \
    Source/sound.cpp \
    Source/tile.cpp \
    Source/widget.cpp

HEADERS += \
    Headers/deadlybarrier.h \
    Headers/dirtybubble.h \
    Headers/evilspongebob.h \
    Headers/flag.h \
    Headers/informationbar.h \
    Headers/ingredient.h \
    Headers/item.h \
    Headers/jellyfish.h \
    Headers/karen.h \
    Headers/level.h \
    Headers/leveldata.h \
    Headers/life.h \
    Headers/message.h \
    Headers/player.h \
    Headers/playerparameters.h \
    Headers/ranglist.h \
    Headers/regulartile.h \
    Headers/score.h \
    Headers/settings.h \
    Headers/slowingtile.h \
    Headers/sound.h \
    Headers/tile.h \
    Headers/widget.h

FORMS += \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resources.qrc

DISTFILES += \
    CMakeLists.txt \
    files/players.txt \
    images/messageBox1.jpg \
    images/player.png \
    images/playerLeft.png
