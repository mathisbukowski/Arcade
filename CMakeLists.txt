
cmake_minimum_required(VERSION 3.20)

project(arcade
    VERSION 1.0
    DESCRIPTION "Arcade Game Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY $(CMAKE_SOURCE_DIR)/lib)

file(GLOB_RECURSE CORE_SRC "src/Arcade/*.cpp")
file(GLOB_RECURSE CORE_INC "src/Arcade/*.hpp")

add_executable(${PROJECT_NAME} ${CORE_SRC} ${CORE_INC})

# Compile Ncurses Dynamic library
file (GLOB_RECURSE NCURSES_SRC "src/Graphics/Ncurses/*.cpp")
file (GLOB_RECURSE NCURSES_INC "src/Graphics/Ncurses/*.hpp")
add_library(arcade_ncurses SHARED ${NCURSES_SRC} ${NCURSES_INC})
target_include_directories(arcade_ncurses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Ncurses ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Arcade ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)