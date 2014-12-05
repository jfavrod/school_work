/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    proj 2
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        24 Nov 2014
//
// FILE:        proj2.h
//
// DESCRIPTION: The header file for proj2.cpp.
//
***********************************************************************/
#include "getters"
#include "actions"
#include "llist.h"

#define MENU_OPTS 7

int handle_args(int argc, char *argv[]);
void print_menu(void);
int perform(int action, llist &addrBook, short *addrBook_error, short *run);
int get_selection(void);
