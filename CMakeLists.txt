cmake_minimum_required(VERSION 3.20)
project(PR2 C)

set(CMAKE_C_STANDARD 11)

add_executable(PR2 MathTasks.c)

add_executable(Strings Strings.c)

add_executable(Books Books.c)
