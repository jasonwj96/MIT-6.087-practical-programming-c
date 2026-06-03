cmake_minimum_required(VERSION 3.10)
project(MIT_6087 C)

set(CMAKE_C_STANDARD 11)

add_executable(main
        src/main.c
        src/assignment_1.c
)

target_include_directories(main PRIVATE src)