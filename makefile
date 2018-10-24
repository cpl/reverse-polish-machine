
CC ?= gcc
FLAGS = -std=c99 -Wall


all:
	$(CC) $(FLAGS) -o rpm src/rpm.c
