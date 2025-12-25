cmake_minimum_required(VERSION 4.2)
project(arbitrary_multiplication_c C)

set(CMAKE_C_STANDARD 17)

add_executable(arbitrary_multiplication_c main.c
        linked_list.c
        arbitrary_util.c
        text_util.c
        panic.c)
