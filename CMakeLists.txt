cmake_minimum_required(VERSION 3.0)

set(CMAKE_BUILD_TYPE Debug)
set(CMAKE_C_FLAGS " -std=c99 -Wall -g")

project(worder)

add_executable(
	WorderApp
	src/data.c
	src/prompt.c
	src/score.c
	src/main_func.c
	src/main.c
)
