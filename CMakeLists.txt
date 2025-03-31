
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
file (GLOB_RECURSE SDL_SRC "src/Graphics/Sdl/*.cpp")
file (GLOB_RECURSE SDL_INC "src/Graphics/Sdl/*.hpp")
add_library(arcade_sdl2 SHARED ${SDL_SRC} ${SDL_INC})
target_include_directories(arcade_sdl2 PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Sdl ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sdl2 PROPERTIES PREFIX "")

# Compile SFML Dynamic Lib
file (GLOB_RECURSE SFML_SRC "src/Graphics/Sfml/*.cpp")
file (GLOB_RECURSE SFML_INC "src/Graphics/Sfml/*.hpp")
add_library(arcade_sfml SHARED ${SFML_SRC} ${SFML_INC})
target_include_directories(arcade_sfml PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Graphics/Sfml ${CMAKE_CURRENT_SOURCE_DIR}/include)
set_target_properties(arcade_sfml PROPERTIES PREFIX "")

target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src/Arcade ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror)
target_compile_options(arcade_sdl2 PRIVATE -fno-gnu-unique)