cmake_minimum_required(VERSION 3.25)
project(GameOfLife)

set(CMAKE_CXX_STANDARD 17)

find_package(SDL2 REQUIRED)

add_executable(${PROJECT_NAME}
        main.cpp

        src/color_functions.cpp
        src/complex_functions.cpp
        src/graphic_functions.cpp
        src/mainLib.cpp
)

target_link_libraries(${PROJECT_NAME} PUBLIC
        ${SDL2_LIBRARIES}
)

# Sets executable folder to bin
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)