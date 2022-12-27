cmake_minimum_required(VERSION 3.16)
project(untitled2 VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

set(SOURCE_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Source")
set(HEADER_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Headers")
set(FORMS_PATH "${CMAKE_CURRENT_SOURCE_DIR}/")
set(RESOURCES_PATH "${CMAKE_CURRENT_SOURCE_DIR}/Resources")



set(CMAKE_PREFIX_PATH "/home/marija/Qt/6.2.2/gcc_64/lib/cmake")
find_package(Qt6 COMPONENTS Core Widgets Multimedia REQUIRED)
#find_package(Qt{$QT_VERSION_MAJOR} COMPONENTS Core Widgets Multimedia REQUIRED)

set(SOURCES
    "${SOURCE_PATH}/deadlybarrier.cpp"
    "${SOURCE_PATH}/dirtybubble.cpp"
    "${SOURCE_PATH}/evilspongebob.cpp"
    "${SOURCE_PATH}/flag.cpp"
    "${SOURCE_PATH}/informationbar.cpp"
    "${SOURCE_PATH}/ingredient.cpp"
    "${SOURCE_PATH}/item.cpp"
    "${SOURCE_PATH}/jellyfish.cpp"
    "${SOURCE_PATH}/karen.cpp"
    "${SOURCE_PATH}/level.cpp"
    "${SOURCE_PATH}/leveldata.cpp"
    "${SOURCE_PATH}/life.cpp"
    "${SOURCE_PATH}/main.cpp"
    "${SOURCE_PATH}/message.cpp"
    "${SOURCE_PATH}/player.cpp"
    "${SOURCE_PATH}/playerparameters.cpp"
    "${SOURCE_PATH}/ranglist.cpp"
    "${SOURCE_PATH}/regulartile.cpp"
    "${SOURCE_PATH}/score.cpp"
    "${SOURCE_PATH}/settings.cpp"
    "${SOURCE_PATH}/slowingtile.cpp"
    "${SOURCE_PATH}/sound.cpp"
    "${SOURCE_PATH}/tile.cpp"
    "${SOURCE_PATH}/widget.cpp"
)

set(HEADERS
    "${HEADER_PATH}/deadlybarrier.h"
    "${HEADER_PATH}/dirtybubble.h"
    "${HEADER_PATH}/evilspongebob.h"
    "${HEADER_PATH}/flag.h"
    "${HEADER_PATH}/informationbar.h"
    "${HEADER_PATH}/ingredient.h"
    "${HEADER_PATH}/item.h"
    "${HEADER_PATH}/jellyfish.h"
    "${HEADER_PATH}/karen.h"
    "${HEADER_PATH}/level.h"
    "${HEADER_PATH}/leveldata.h"
    "${HEADER_PATH}/life.h"
    "${HEADER_PATH}/message.h"
    "${HEADER_PATH}/player.h"
    "${HEADER_PATH}/playerparameters.h"
    "${HEADER_PATH}/ranglist.h"
    "${HEADER_PATH}/regulartile.h"
    "${HEADER_PATH}/score.h"
    "${HEADER_PATH}/settings.h"
    "${HEADER_PATH}/slowingtile.h"
    "${HEADER_PATH}/sound.h"
    "${HEADER_PATH}/tile.h"
    "${HEADER_PATH}/widget.h"
)

set(FORMS,
    "${FORMS_PATH}/widget.ui")

set(CMAKE_AUTOUIC_SEARCH_PATHS ${FORMS_PATH})

set(RSC resources.qrc)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})

#target_link_libraries(${PROJECT_NAME} Qt{$QT_VERSION_MAJOR}::Core Qt{$QT_VERSION_MAJOR}::Widgets Qt{$QT_VERSION_MAJOR}::Multimedia)
target_link_libraries(${PROJECT_NAME} Qt6::Core Qt6::Widgets Qt6::Multimedia)
