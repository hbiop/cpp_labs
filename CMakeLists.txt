cmake_minimum_required(VERSION 4.2)
project(cpp_labs)

set(CMAKE_CXX_STANDARD 20)

add_executable(cpp_labs main.cpp
        lab4/arrays/src/OneDimensionArrays.cpp
        lab4/arrays/include/OneDimensionArrays.h
        lab4/arrays/src/TwoDimensionArrays.cpp
        lab4/arrays/include/TwoDimensionArrays.h
        lab4/arrays/src/ThreeDimensionArrays.cpp
        lab4/arrays/include/ThreeDimensionArrays.h
        lab4/generators/src/RandomNumberGenerators.cpp
        lab4/generators/include/RandomNumberGenerators.h
        lab4/solutions/src/Solutions.cpp
        lab4/solutions/include/Solutions.h)
