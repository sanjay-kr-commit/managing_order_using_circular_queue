cmake_minimum_required(VERSION 3.29)
project(serving_dsa C)

set(CMAKE_C_STANDARD 17)

add_executable(
        serving_dsa
        main.c
        circular_queue.c
        circular_queue.h
)
