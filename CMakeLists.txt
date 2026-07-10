cmake_minimum_required(VERSION 3.10)
project(MIT_6087 C)

set(CMAKE_C_STANDARD 11)

add_executable(main
        src/main.c
        src/assignment_1.c
        src/assignment_2.c
        src/assignment_2.h
        src/assignment_3.c
        src/assignment_3.h
        src/assignment_4.c
        src/assignment_4.h
        src/assignment_5.c
        src/assignment_5.h
)

target_include_directories(main PRIVATE src)