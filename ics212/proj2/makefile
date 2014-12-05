#!/bin/bash
# makefile for project 2

CC=g++ -ansi -Wall
SCCS=sccs -d $(HOME)/hw
SRC=src
BLDS=blds


all :
	make addrBook
	make clean


addrBook : proj2.cpp getters.o helpers.o actions.o llist.o record.h
	$(CC) -o addrBook helpers.o getters.o llist.o actions.o proj2.cpp

debug : proj2.cpp getters.o helpers.o actions.o llist.o record.h
	$(CC) -D DEBUG -o addrBookdb helpers.o getters.o llist.o actions.o proj2.cpp
	make clean


proj2.cpp : proj2.h
	mv $(SRC)/proj2.cpp .

proj2.h : getters actions
	mv $(SRC)/proj2.h .

getters.o : getters.cpp
	$(CC) -c getters.cpp

helpers.o : helpers.c
	$(CC) -c helpers.c

actions.o : actions.cpp
	$(CC) -c actions.cpp

llist.o : llist.cpp
	$(CC) -c llist.cpp

getters.cpp : getters
	mv $(SRC)/getters.cpp .

helpers.c : helpers.h
	mv $(SRC)/helpers.c .

actions.cpp : actions
	mv $(SRC)/actions.cpp .

llist.cpp : llist.h
	mv $(SRC)/llist.cpp .

getters : record.h helpers.h
	mv $(SRC)/getters .

helpers.h : 
	mv $(SRC)/helpers.h .

actions : llist.h getters
	mv $(SRC)/actions .

llist.h : record.h getters
	mv $(SRC)/llist.h .

record.h :
	mv $(SRC)/record.h .

clean :
	if [ -f *.o ]; then \
	    mv *.o $(BLDS); \
	fi
	if [ -f *.c* ]; then \
	    mv *.c* $(SRC); \
	fi
	if [ -f *.h ]; then \
	    mv *.h $(SRC); \
	fi
	if [ -f actions ]; then \
	    mv actions $(SRC); \
	fi
	if [ -f getters ]; then \
	    mv getters $(SRC); \
	fi
