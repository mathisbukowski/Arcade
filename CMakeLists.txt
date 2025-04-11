
cmake_minimum_required(VERSION 3.20)

project(arcade
    VERSION 1.0
    DESCRIPTION "Arcade Game Engine"
    LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)

file(GLOB_RECURSE CORE_SRC "src/Arcade/*.cpp")
file(GLOB_RECURSE CORE_INC "src/Arcade/*.hpp")

add_executable(${PROJECT_NAME} ${CORE_SRC} ${CORE_INC})

# Compile SDL Dynamic Lib
find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)
find_package(SDL2_mixer REQUIRED)
find_package(SDL2_ttf REQUIRED)
file (GLOB_RECURSE SDL_SRC "src/Graphics/Sdl/*.cpp")
file (GLOB_RECURSE SDL_INC "src/Graphics/Sdl/*.hpp")
add_library(arcade_sdl2 SHARED ${SDL_SRC} ${SDL_INC})
target_include_directories(arcade_sdl2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Sdl ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")
target_link_libraries(arcade_sdl2
        PRIVATE
        SDL2::SDL2
        SDL2_image::SDL2_image
        SDL2_mixer::SDL2_mixer
        SDL2_ttf::SDL2_ttf
)

# Compile SFML Dynamic Lib
find_package(SFML 2.5.1 COMPONENTS graphics window audio system REQUIRED)
file (GLOB_RECURSE SFML_SRC "src/Graphics/Sfml/*.cpp")
file (GLOB_RECURSE SFML_INC "src/Graphics/Sfml/*.hpp")
add_library(arcade_sfml SHARED ${SFML_SRC} ${SFML_INC})
target_include_directories(arcade_sfml PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Sfml ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sfml PROPERTIES PREFIX "")
target_link_libraries(arcade_sfml PRIVATE sfml-graphics sfml-window sfml-system sfml-audio)

# Compile Ncurses Dynamic library
file (GLOB_RECURSE NCURSES_SRC "src/Graphics/Ncurses/*.cpp")
file (GLOB_RECURSE NCURSES_INC "src/Graphics/Ncurses/*.hpp")
add_library(arcade_ncurses SHARED ${NCURSES_SRC} ${NCURSES_INC})
target_link_libraries(arcade_ncurses PRIVATE ncurses)
target_include_directories(arcade_ncurses PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Ncurses ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_ncurses PROPERTIES PREFIX "")

# Compile Common Files
file (GLOB_RECURSE COMMON_SRC "src/Games/Common/*.cpp")
file (GLOB_RECURSE COMMON_INC "src/Games/Common/*.hpp")

# Compile Nibbler Dynamic Lib
file (GLOB_RECURSE NIBBLER_SRC "src/Games/Nibbler/*.cpp")
file (GLOB_RECURSE NIBBLER_INC "src/Games/Nibbler/*.hpp")
add_library(arcade_nibbler SHARED ${NIBBLER_SRC} ${NIBBLER_INC} ${COMMON_SRC} ${COMMON_INC})
target_include_directories(arcade_nibbler PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Games/Nibbler ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Games/Common/BaseSnakeGame)
set_target_properties(arcade_nibbler PROPERTIES PREFIX "")

# Compile Snake Dynamic Lib
file (GLOB_RECURSE SNAKE_SRC "src/Games/Snake/*.cpp")
file (GLOB_RECURSE SNAKE_INC "src/Games/Snake/*.hpp")
add_library(arcade_snake SHARED ${SNAKE_SRC} ${SNAKE_INC} ${COMMON_SRC} ${COMMON_INC})
target_include_directories(arcade_snake PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Games/Snake ${CMAKE_CURRENT_SOURCE_DIR}/include ${CMAKE_CURRENT_SOURCE_DIR}/src/Games/Common/BaseSnakeGame)
set_target_properties(arcade_snake PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Arcade ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
target_compile_options(arcade_sdl2 PRIVATE -fno-gnu-unique)
target_compile_options(arcade_sfml PRIVATE -fno-gnu-unique)
target_compile_options(arcade_ncurses PRIVATE -fno-gnu-unique)
target_compile_options(arcade_nibbler PRIVATE -fno-gnu-unique)
target_compile_options(arcade_snake PRIVATE -fno-gnu-unique)