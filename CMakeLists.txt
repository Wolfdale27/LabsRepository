cmake_minimum_required(VERSION 3.12)
project(LabsRepository)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Python3_NumPy_INCLUDE_DIRS})

add_executable(LabsRepository main.cpp labs_executor.hpp lab2.cpp lab7.cpp lab12.cpp lab17.cpp)

target_link_libraries(LabsRepository ${Python3_LIBRARIES})
