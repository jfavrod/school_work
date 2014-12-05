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
#ifndef HELPERS_H
#define HELPERS_H

#include <stdio.h>
#include <ctype.h>
#include <string.h>

void clear_input_buff(void);
int get_int(void);
int inrange(int x, int low, int high);
int str_clear(char str[]);
int str_replace(char needle, char haystack[], char replace);
int round_up(int x, int round);

#endif
