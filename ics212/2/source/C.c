/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    2 Part C
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        9 Sept 2014
//
// FILE:        C.c
//
// DESCRIPTION: A driver function to test functions strlen, strcmp,
//              strchr, strpbrk and strcpy functions
//
***********************************************************************/
#include <stdio.h>
#include <string.h>

void tell_if_eq(char str1[], char str2[]);
void str_replace(char haystack[], char needle, char replace);


int main()
{
    char teststr1[] = "";
    char teststr2[] = "string_is_13";

    printf("The test string1 is: %s\n", teststr1);
    printf("The length of the test string1 is: %d\n", strlen(teststr1));

    printf("The test string2 is: %s\n", teststr2);
    printf("The length of the test string2 is: %d\n", strlen(teststr2));

    tell_if_eq(teststr1, teststr2);

    printf("\nNow copy string 1 to string 2.\n");
    strcpy(teststr1, teststr2);
    printf("Now string 1 is: %s\n", teststr1);
    printf("Now string 2 is: %s\n", teststr2);

    tell_if_eq(teststr1, teststr2);

    str_replace(teststr1, '_', ' ');
    printf("\nUsing strchr to replace all '_' in string 1.\n");
    printf("Now string 1 is: %s\n", teststr1);

    tell_if_eq(teststr1, teststr2);

    printf("\nThe strings are still the same length.\n");
    printf("The length of the test string1 is: %d\n", strlen(teststr1));
    printf("The length of the test string2 is: %d\n", strlen(teststr2));

    printf("\nNow let's put back the underscores.\n");
    str_replace(teststr1, ' ', '_');
    printf("Now string 1 is: %s\n", teststr1);

    tell_if_eq(teststr1, teststr2);

    printf("\nLet's try to do the find and replace with the strpbrk function\n");
    char *strptr;
    while ((strptr = strpbrk(teststr2, "_")))
    {
        *strptr = ' ';
    }
    printf("Now string 2 is: %s\n", teststr2);
    tell_if_eq(teststr1, teststr2);

    while ((strptr = strpbrk(teststr2, "_")))
    {
        *strptr = '_';
    }
    printf("Now string 2 is: %s\n", teststr2);
    tell_if_eq(teststr1, teststr2);

    return 0;
}


void tell_if_eq(char str1[], char str2[])
/**********************************************************************
//
//  Function name:      tell_if_eq
//
//  DESCRIPTION:        Prints a message telling whether or not the two
//                      strings are equal.
//
//  Parameters:         str1 (char[]) : The first string to compare.
//                      str2 (char[]) : The second string to compare to
//                                      the first string.
//
//  Return values:      void
//
**********************************************************************/
{
    if (strcmp(str1, str2) == 0)
    {
        printf("The two strings are equal\n");
    }
    else
    {
        printf("The two strings not are equal\n");
    }
}


void str_replace(char haystack[], char needle, char replace)
/**********************************************************************
//
//  Function name:      str_replace
//
//  DESCRIPTION:        Find a char (needle) in a string (haystack) and
//                      replace it with the replacement char value.
//
//  Parameters:         haystack (char[]) : The string to search for
//                                          the needle char in.
//                      needle (char)     : The char to search the
//                                          haystack for.
//                      replace (char)    : If the needle is found
//                                          replace it in the haystack.
//
//  Return values:      void
//
**********************************************************************/
{
    char *c;
    while ((c = strchr(haystack, needle)))
    {
        *c = replace;
    }
}
