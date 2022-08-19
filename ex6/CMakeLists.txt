cmake_minimum_required(VERSION 3.20)
project(ex6_eli_levinkopf)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex6_eli_levinkopf
        Apartment.h
        AVL.h
        Find.h
        MesureTimeHelper.h
        Stack.h
        Apartment.cpp
        Stack.cpp
        AVL.cpp
#        test.cpp
        test_runner.h
        test_runner.cpp
        tests.cpp
#        presubmit_ex6.cpp
#        Bonus.cpp
        )
