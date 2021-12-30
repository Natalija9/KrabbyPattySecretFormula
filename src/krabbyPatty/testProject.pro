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
    Source/jellyfish.cpp \
    Source/deadlybarrier.cpp \
    testing/jellyfishTest.cpp \
    testing/rangListTest.cpp \
    testing/settingsTest.cpp

HEADERS += \
    Headers/settings.h \
    Headers/ranglist.h \
    Headers/jellyfish.h \
    Headers/deadlybarrier.h \
    testing/catch.hpp \

