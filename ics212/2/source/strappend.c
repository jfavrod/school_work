/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    2 Part A
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        6 Sept 2014
//
// FILE:        strappend.c
//
// DESCRIPTION: A function which appends the second string argument to
//              the first string array. Assuming that the first string
//              is large enough to hold the combined string.
//
***********************************************************************/
#include "header.h"


void strappend(char strA[], char strB[])
/**********************************************************************
//
// Function name:       strappend
//
// DESCRIPTION:         Appends string B to string A.
//
// Parameters:          strA (char[]) : The string to be appended.
//                      strB (char[]) : The string to be appended to.
//
// Return values:       void
//
***********************************************************************/
{
    int len_a, len_b;
    len_a = str_len(strA);
    len_b = str_len(strB);

    char c;
    short i = 0;

    while ((c = strB[i++]))
    {
        strA[len_a++] = c;
    }
    strA[str_len(strA)+1] = '\0';
}
