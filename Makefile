FILES = src/data.c src/prompt.c src/score.c src/main.c

CC = gcc

OUT = worder.exe

all: worder

worder:
	$(CC) $(FILES) -O2 -Wall -Werror -std=c99 -o $(OUT)
