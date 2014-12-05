h55125
s 00001/00000/00025
d D 1.2 14/10/03 22:49:10 favrod 2 1
c Including string.h.
e
s 00025/00000/00000
d D 1.1 14/10/03 15:24:21 favrod 1 0
c date and time created 14/10/03 15:24:21 by favrod
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
// FILE:        helpers.h
//
// DESCRIPTION: Header file for helpers.c.
//
***********************************************************************/
#include <stdio.h>
#include <ctype.h>
I 2
#include <string.h>
E 2

void clear_input_buff(void);
int get_int(void);
int inrange(int x, int low, int high);
int clear_string(char str[]);
int str_replace(char needle, char haystack[], char replace);
E 1
