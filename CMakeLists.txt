cmake_minimum_required(VERSION 3.20)
project(Lista5_ed2 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(Exer01 src/Exer01_TwoPointersMerge.cpp)
add_executable(Exer02 src/Exer02_MergeSortTrace.cpp)
add_executable(Exer03 src/Exer03_QuickSortStructComparison.cpp)
add_executable(Exer04 src/Exer04_QuickSortSwapsLomutoVsHoare.cpp)
add_executable(Exer05 src/Exer05_QuickSortMedianOfThree.cpp)