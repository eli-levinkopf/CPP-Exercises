cmake_minimum_required(VERSION 3.20)
project(ex5_eli_levinkopf)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(ex5_eli_levinkopf
        Activation.h
        Dense.h
        Matrix.h
        MlpNetwork.h
        Matrix.cpp
        Activation.cpp
        Dense.cpp
        MlpNetwork.cpp
        main.cpp
#        test_ex4.cpp
#        presubmit_ex5.cpp
        )
