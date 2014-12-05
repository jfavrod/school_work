h53345
s 00030/00000/00000
d D 1.1 14/10/08 15:43:24 favrod 1 0
c date and time created 14/10/08 15:43:24 by favrod
e
u
U
f e 0
t
T
I 1
/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    3 Part B
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        17 Sept 2014
//
// FILE:        addrBookUI.h
//
// DESCRIPTION: The header for addrBookUI.c.
//
***********************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "helpers.h"
#include "actions.h"

#define MAX_INPUT 1

int handle_args(int argc, char *argv[]);
int get_selection(void);
void print_menu(void);
void print_args(int argc, char *argv[]);
void perform(int, int *, int *);
E 1
