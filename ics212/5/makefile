#!/bin/bash

CC=gcc -ansi -Wall

all:
	sccs get SCCS
	make driver
	make clean

driver : fileio.o driver.o helpers.o account.h
	$(CC) -o driver helpers.o fileio.o driver.o

driver.o : driver.c account.h
	$(CC) -c driver.c

fileio.o : fileio.c account.h helpers.h
	$(CC) -c fileio.c

helpers.o : helpers.c helpers.h
	$(CC) -c helpers.c

clean:
	rm *.o
	sccs clean
