cmake_minimum_required(VERSION 3.26)
project(Student)

set(CMAKE_CXX_STANDARD 14)

include_directories(Student)

add_executable(Student
        Student/StudentManagement.cpp
        Student/StudentManagement.h
        Student/StudentManagementMain.cpp)
