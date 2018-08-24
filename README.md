# Worder

## What is Worder?
Worder is a learning application written in C geared towards improving
proficiency in French. It tests the user's knowledge on many foreign
words. The user responds and gains points on right answers and no points
on wrong answers.

Worder stores a large database of words on disk. More can be added if desired.
The program linearly selects a word from disk and poses it to the user. It then
continues to the next word, awarding 300 points for every correct answer.

## Build Instructions

To build this project, you must have CMake and a C compiler
installed. If you don't have CMake get it [here](https://cmake.org/download/).
If you need a C compiler, get MinGW for Windows or GCC for Linux.

The basic commands to build and install Worder are:

	$ mkdir build
	$ cd build
	$ cmake

If you prefer to use CMake GUI, that's fine. Configure the project as
necessary and generate a Makefile for your platform. After receiving the
Makefile, simply type:

	make

Or:

	mingw32-make

If all goes well, you should have an executable in the build folder.
