cmake_minimum_required(VERSION 3.31)
project(untitled)

set(CMAKE_CXX_STANDARD 98)

add_executable(untitled main.cpp
        Contact.cpp
        Contact.h
        PhoneBook.cpp
        PhoneBook.h)
