cmake_minimum_required(VERSION 3.29)
project(transistor_logic C)

set(CMAKE_C_STANDARD 11)

add_executable(transistor_logic main.c
        gates.h
        gates.c)
