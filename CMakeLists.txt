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
        src/assignment_5_1.c
        src/assignment_5_1.h
        src/assignment_5_2.c
        src/assignment_5_2.h
        src/prob1.c
        src/prob2.c
        src/assignment_6a.c
        src/assignment_6a.h
)

target_include_directories(main PRIVATE src)