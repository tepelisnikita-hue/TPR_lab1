cmake_minimum_required(VERSION 4.3)
project(Lab1)

set(CMAKE_CXX_STANDARD 20)

add_executable(Lab1 main.cpp
        BaseException.h
        BaseEdition.h BaseEdition.cpp
        Poet.h Poet.cpp
        Novelist.h Novelist.cpp
        Fantast.h Fantast.cpp
        Keeper.h Keeper.cpp)
