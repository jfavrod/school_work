/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    8
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        10 Nov 2014
//
// FILE:        temp_convert.h
//
// DESCRIPTION: Header file for temp_convert.cpp.
//
***********************************************************************/
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include "helpers.h"

using namespace std;

void print_menu(void);
void get_input(int *fahrenheit, int *err);
void print_conversion_table(int max);
void convertftoC(int f, float &c);
