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
// FILE:        record.h
//
// DESCRIPTION: A shared definition of the struct record.
//
***********************************************************************/
#ifndef RECORD_H
#define RECORD_H

#define MAX_ENTRY 125

struct record
{
    char name[25];
    int  yearofbirth;
    char address[80];
    char telno[15];
    struct record* next;
};

enum {NAME, YEAROFBIRTH, ADDRESS, TELNO};

#endif
