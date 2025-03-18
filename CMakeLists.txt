cmake_minimum_required(VERSION 3.20)
project(arcade LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(CMAKE_COMPILER_IS_GNUCXX OR "${CMAKE_CXX_COMPILER_ID}" STREQUAL "Clang")
    if(NOT APPLE)
        set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -fno-gnu-unique")
    endif()
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

include_directories(
    ${CMAKE_SOURCE_DIR}/src/interfaces
)

if(UNIX AND NOT APPLE)
    find_library(DL_LIBRARY dl REQUIRED)
    set(PLATFORM_LIBS ${DL_LIBRARY})
else()
    set(PLATFORM_LIBS "")
endif()

message(STATUS "Building on: ${CMAKE_SYSTEM_NAME}")
message(STATUS "Compiler: ${CMAKE_CXX_COMPILER_ID}")
message(STATUS "Platform-specific libraries: ${PLATFORM_LIBS}")

set(CORE_SOURCES
    src/main.cpp
    src/Arcade/DLLoader.cpp
    src/Arcade/Core.cpp
)

add_executable(arcade ${CORE_SOURCES})
target_link_libraries(arcade ${PLATFORM_LIBS})

add_custom_target(core DEPENDS arcade)

set(GRAPHICAL_TARGETS "")
set(GAME_TARGETS "")

if(EXISTS "${CMAKE_SOURCE_DIR}/src/graphics/ncurses/NcursesGraphics.cpp")
    find_package(Curses REQUIRED)
    set(NCURSES_SOURCES
        src/graphics/ncurses/NcursesGraphics.cpp
    )

    add_library(arcade_ncurses SHARED ${NCURSES_SOURCES})
    set_target_properties(arcade_ncurses PROPERTIES PREFIX "")
    target_include_directories(arcade_ncurses PRIVATE ${CURSES_INCLUDE_DIR})
    target_link_libraries(arcade_ncurses ${CURSES_LIBRARIES})

    list(APPEND GRAPHICAL_TARGETS arcade_ncurses)
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/src/graphics/sdl2/SDLGraphics.cpp")
    find_package(SDL2 REQUIRED)
    set(SDL2_SOURCES
        src/graphics/sdl2/SDLGraphics.cpp
    )

    add_library(arcade_sdl2 SHARED ${SDL2_SOURCES})
    set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")
    target_include_directories(arcade_sdl2 PRIVATE ${SDL2_INCLUDE_DIRS})
    target_link_libraries(arcade_sdl2 ${SDL2_LIBRARIES})

    list(APPEND GRAPHICAL_TARGETS arcade_sdl2)
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/src/games/snake/SnakeGame.cpp")
    set(SNAKE_SOURCES
        src/games/snake/SnakeGame.cpp
    )

    add_library(arcade_snake SHARED ${SNAKE_SOURCES})
    set_target_properties(arcade_snake PROPERTIES PREFIX "")

    list(APPEND GAME_TARGETS arcade_snake)
endif()

if(EXISTS "${CMAKE_SOURCE_DIR}/src/games/pacman/PacmanGame.cpp")
    set(PACMAN_SOURCES
        src/games/pacman/PacmanGame.cpp
    )

    add_library(arcade_pacman SHARED ${PACMAN_SOURCES})
    set_target_properties(arcade_pacman PROPERTIES PREFIX "")

    list(APPEND GAME_TARGETS arcade_pacman)
endif()

if(GRAPHICAL_TARGETS)
    add_custom_target(graphicals DEPENDS ${GRAPHICAL_TARGETS})
endif()

if(GAME_TARGETS)
    add_custom_target(games DEPENDS ${GAME_TARGETS})
endif()
