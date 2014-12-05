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
