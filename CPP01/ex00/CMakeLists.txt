cmake_minimum_required(VERSION 3.31)
project(CPP01)

set(CMAKE_CXX_STANDARD 98)

add_executable(CPP01 main.cpp
        Zombie.cpp
        Zombie.h
        newZombie.cpp
        randomChump.cpp
        zombieHorde.cpp)
