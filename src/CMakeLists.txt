cmake_minimum_required(VERSION 3.5)

project(MazeAndCaves VERSION 0.1 LANGUAGES CXX)

set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_AUTOUIC ON)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(QT NAMES Qt6 Qt5 REQUIRED COMPONENTS Widgets)
find_package(Qt${QT_VERSION_MAJOR} REQUIRED COMPONENTS Widgets)

set(PROJECT_SOURCES
        main.cc
        view/view.cc
        view/view.h
        view/view.ui
        controller/controller.cc
        controller/controller.h
        model/cave_automaton.h
        model/cave_automaton.cc
        model/maze_generator.cc
        model/maze_generator.h
        model/maze_solve.cc
        model/maze_solve.h
        view/paint_window.cc
        view/paint_window.h
        model/parsing_file.h
        model/parsing_file.cc
        model/maze.cc
        model/maze.h
        model/cave.h
        model/cave.cc)

if(${QT_VERSION_MAJOR} GREATER_EQUAL 6)
    qt_add_executable(MazeAndCaves
        MANUAL_FINALIZATION
        ${PROJECT_SOURCES}
    )
# Define target properties for Android with Qt 6 as:
#    set_property(TARGET MazeAndCaves APPEND PROPERTY QT_ANDROID_PACKAGE_SOURCE_DIR
#                 ${CMAKE_CURRENT_SOURCE_DIR}/android)
# For more information, see https://doc.qt.io/qt-6/qt-add-executable.html#target-creation
else()
    if(ANDROID)
        add_library(MazeAndCaves SHARED
            ${PROJECT_SOURCES}
        )
# Define properties for Android with Qt 5 after find_package() calls as:
#    set(ANDROID_PACKAGE_SOURCE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/android")
    else()
        add_executable(MazeAndCaves
            ${PROJECT_SOURCES}
        )
    endif()
endif()

target_link_libraries(MazeAndCaves PRIVATE Qt${QT_VERSION_MAJOR}::Widgets)
target_include_directories(MazeAndCaves
        PRIVATE
        view/
        model/
        controller/)
set_target_properties(MazeAndCaves PROPERTIES
    MACOSX_BUNDLE_GUI_IDENTIFIER my.example.com
    MACOSX_BUNDLE_BUNDLE_VERSION ${PROJECT_VERSION}
    MACOSX_BUNDLE_SHORT_VERSION_STRING ${PROJECT_VERSION_MAJOR}.${PROJECT_VERSION_MINOR}
    MACOSX_BUNDLE TRUE
    WIN32_EXECUTABLE TRUE
)

if(QT_VERSION_MAJOR EQUAL 6)
    qt_finalize_executable(MazeAndCaves)
endif()
