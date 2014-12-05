h39879
s 00025/00000/00000
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
E 1
