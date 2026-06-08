cmake_minimum_required(VERSION 3.8)
project(ITaP_CP)

set(CMAKE_CXX_STANDARD 20)

include_directories(.)

add_executable(ITaP_CP
        main.cpp
        console_interface.cpp
        utils.h
        sorting_algorithms.cpp
        sorting_algorithms.h
        utils.cpp
        unit_tests.cpp
        unit_tests.h
        file_interface.cpp
        file_interface.h)
