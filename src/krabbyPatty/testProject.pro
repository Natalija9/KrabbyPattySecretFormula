TEMPLATE = app
QT += gui core widgets

CONFIG += c++11

isEmpty(CATCH_INCLUDE_DIR): CATCH_INCLUDE_DIR=$$(CATCH_INCLUDE_DIR)
!isEmpty(CATCH_INCLUDE_DIR): INCLUDEPATH *= $${CATCH_INCLUDE_DIR}

isEmpty(CATCH_INCLUDE_DIR): {
    message("CATCH_INCLUDE_DIR is not set, assuming Catch2 can be found automatically in your system")
}

SOURCES +=    testing/main.cpp     \
    Source/settings.cpp \
    Source/ranglist.cpp \
    testing/jellyfishTest.cpp \
    Source/leveldata.cpp \
    Source/deadlybarrier.cpp \
    Source/leveldata.cpp \
    Source/jellyfish.cpp \
    Source/dirtybubble.cpp \
    Source/karen.cpp \
    Source/evilspongebob.cpp \
    testing/evilSpongeBobTest.cpp \
    testing/levelDataTest.cpp \
    testing/rangListTest.cpp \
    testing/settingsTest.cpp

HEADERS += \
    Headers/settings.h \
    Headers/ranglist.h \
    testing/catch.hpp \
    Headers/leveldata.h \
    Headers/deadlybarrier.h \
    Headers/leveldata.h \
    Headers/jellyfish.h \
    Headers/dirtybubble.h \
    Headers/karen.h \
    Headers/evilspongebob.h \
    testing/catch.hpp

