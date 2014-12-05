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
struct record
{
    char name[25];
    char address[80];
    int  yearofbirth;
    char telno[15];
    struct record* next;
}; 
