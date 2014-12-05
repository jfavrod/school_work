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
#include "record.h"
#include "ctype.h"

#define MAX_NAME 50
#define MAX_ADDR 80

extern int debug;

int get_name(char name[]);
int get_address(char address[]);
int get_yearofbirth(int *yearofbirth);
int get_telnumber(char telnumber[]);

int addRecord (struct record **,char [],char [],int, char []);
int addrecord(void);
int printRecord (struct record *, char []);    
int modifyRecord (struct record *, char [],char [], char []);       
void printAllRecords(struct record *);
int deleteRecord(struct record **, char []);
