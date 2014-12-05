h30665
s 00046/00000/00000
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
// FILE:        actions.h
//
// DESCRIPTION: Header file for actions.c.
//
***********************************************************************/
#include <stdio.h>
#include <string.h>
#include "record.h"
#include <ctype.h>
#include <stdlib.h>

#define MAX_NAME 50
#define MAX_ADDR 80
#define MAX_TELNO 15
#define MAX_YEAR 2014
#define MIN_YEAR 1900
#define MAX_ADDR_LINE MAX_ADDR/2
#define PARTS_OF_ADDR 3

extern int debug;
extern void clear_input_buff(void);
extern int inrange(int x, int low, int high);

char *get_name(void);
int get_yearofbirth(void);
char *get_address(void);
char *get_telno(void);
int invalidate(char *, int);

int addRecord(struct record **, char name[], int yearofbirth, char address[], char telno[]);
int printRecord (struct record *, char []);    
int modifyRecord (struct record *, char key[],char field[], char update[]);       
void printAllRecords(struct record *);
int deleteRecord(struct record **, char key[]);
E 1
