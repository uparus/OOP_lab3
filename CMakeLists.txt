cmake_minimum_required(VERSION 3.31)
project(untitled8)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled8 Command.cpp
        Command.h
        pch.h
        Field.cpp
        Field.h
        Fifteen.cpp
        Fifteen.h
        ConsoleApplication5.cpp
        Exceptions.cpp
        Exceptions.h
)
