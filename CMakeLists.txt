cmake_minimum_required(VERSION 3.12)
project(LabsRepository)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Python3_NumPy_INCLUDE_DIRS})

#Шаг 5: ниже в конце add_executable(перед последней скобкой добавить вашу лабу .cpp)
add_executable(LabsRepository labs/main.cpp labs/labs_executor.hpp labs/lab2.cpp labs/lab7.cpp labs/lab12.cpp labs/lab17.cpp)

target_link_libraries(LabsRepository ${Python3_LIBRARIES})
