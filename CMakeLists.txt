cmake_minimum_required(VERSION 3.29)
project(DataStructures C)

set(CMAKE_C_STANDARD 11)

add_executable(DataStructures src/main.c
        include/singlelinkedlist.h
        src/singlelinkedlist.c
        include/utils.h
        src/utils.c)
