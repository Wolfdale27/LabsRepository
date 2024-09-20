cmake_minimum_required(VERSION 3.12)
project(LabsRepository)

set(CMAKE_CXX_STANDARD 17)

find_package(Python3 COMPONENTS Interpreter Development NumPy REQUIRED)

include_directories(${Python3_INCLUDE_DIRS})
include_directories(${Python3_NumPy_INCLUDE_DIRS})

message(STATUS "Python3 Include: ${Python3_INCLUDE_DIRS}")
message(STATUS "Python3 NumPy Include: ${Python3_NumPy_INCLUDE_DIRS}")
message(STATUS "Python3 Libraries: ${Python3_LIBRARIES}")

if(NOT ${Python3_FOUND})
    message(FATAL_ERROR "Python3 не найден")
endif()

if(NOT ${Python3_NumPy_FOUND})
    message(FATAL_ERROR "NumPy не найден")
endif()

add_executable(LabsRepository
    labs/main.cpp
    labs/labs_executor.hpp
    labs/lab2.cpp
    labs/lab7.cpp
    labs/lab12.cpp
    labs/lab17.cpp
    labs/lab22.cpp
    labs/lab27.cpp
)

target_link_libraries(LabsRepository ${Python3_LIBRARIES})
set_target_properties(LabsRepository PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
