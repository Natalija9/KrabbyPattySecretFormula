TEMPLATE = app
QT += gui core widgets multimedia

CONFIG += c++11

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=    testing/main.cpp     \
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
        Source/widget.cpp \
        testing/dirtybubbleTest.cpp \
        testing/jellyfishTest.cpp \
        testing/evilSpongeBobTest.cpp \
        testing/karenTest.cpp \
        testing/levelDataTest.cpp \
        testing/levelTest.cpp \
        testing/messageTest.cpp \
        testing/playerTest.cpp \
        testing/rangListTest.cpp \
        testing/settingsTest.cpp \
        testing/scoreTest.cpp
        testing/playerParametersTest.cpp

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
        Headers/widget.h \
        testing/catch.hpp


FORMS += \
    widget.ui
