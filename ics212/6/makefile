#!/bin/bash
CC=gcc -ansi -Wall

all :
	make addrBook
	make clean

addrBook : helpers.o actions.o addrBookUI.o
	$(CC) -o addrBook helpers.o actions.o addrBookUI.o

helpers.o : helpers.c helpers.h
	$(CC) -c helpers.c

actions.o : actions.c actions.h record.h
	$(CC) -c actions.c

addrBookUI.o : addrBookUI.c addrBookUI.h record.h
	$(CC) -c addrBookUI.c

clean :
	mv *.o bld/
	sccs clean

record.h :
	if [ ! -f "record.h" ]; then \
	    /usr/ccs/bin/sccs get record.h; \
	fi;

helpers.h : 
	if [ ! -f "helpers.h" ]; then \
	    /usr/ccs/bin/sccs get helpers.h; \
	fi;

helpers.c : 
	if [ ! -f "helpers.c" ]; then \
	    /usr/ccs/bin/sccs get helpers.c; \
	fi;

actions.h :
	if [ ! -f "actions.h" ]; then \
	    /usr/ccs/bin/sccs get actions.h; \
	fi;

actions.c :
	if [ ! -f "actions.c" ]; then \
	    /usr/ccs/bin/sccs get actions.c; \
	fi;

addrBookUI.h : 
	if [ ! -f "addrBookUI.h" ]; then \
	    /usr/ccs/bin/sccs get addrBookUI.h; \
	fi

addrBookUI.c : 
	if [ ! -f "addrBookUI.c" ]; then \
	    /usr/ccs/bin/sccs get addrBookUI.c; \
	fi
