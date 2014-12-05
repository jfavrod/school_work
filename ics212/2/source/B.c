/*****************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    2 Part B
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        6 Sept 2014
//
// FILE:        B.c
//
// DESCRIPTION: A driver function to test find_index_of_max and
//              strappend functions.
//
******************************************************************/
#include "../includes/header.h"


int main()
{
    float fa[MAX_ARRAY_SIZE];

    populate_float_array(fa, MAX_ARRAY_SIZE);
    printf("The test float array is:\n");
    print_float_array(fa, MAX_ARRAY_SIZE);
    printf("The index of the max float is: %d\n\n",
            find_index_of_max(fa, MAX_ARRAY_SIZE));

    populate_float_array(fa, MAX_ARRAY_SIZE);
    printf("The test float array is:\n");
    print_float_array(fa, MAX_ARRAY_SIZE);
    printf("The index of the max float is: %d\n\n",
            find_index_of_max(fa, MAX_ARRAY_SIZE));

    float fa2[MAX_ARRAY_SIZE] = {};
    printf("The test float array is:\n");
    print_float_array(fa2, MAX_ARRAY_SIZE);
    printf("The index of the max float is: %d\n\n",
            find_index_of_max(fa2, MAX_ARRAY_SIZE));

    char test_string1[MAX_STRING_SIZE] = "Test String1\0";
    char test_string2[MAX_STRING_SIZE] = "Test String2\0";

    printf("String 1 is: %s\nString 2 is: %s\n",
            test_string1, test_string2);
    strappend(test_string1, test_string2);
    printf("After we append string 2 to string 1,\nString 1 is: %s\n\n",
            test_string1);

    printf("Let's leave the strings unchanged\n");
    printf("String 1 is: %s\nString 2 is: %s\n",
            test_string1, test_string2);
    strappend(test_string1, test_string2);
    printf("After we append string 2 to string 1,\nString 1 is: %s\n\n",
            test_string1);

    printf("Now let's set both strings to null char\n");
    test_string1[0] = '\0';
    test_string2[0] = '\0';
    printf("String 1 is: %s\nString 2 is: %s\n",
            test_string1, test_string2);
    strappend(test_string1, test_string2);
    printf("After we append string 2 to string 1,\nString 1 is: %s\n\n",
            test_string1);

    return 0;
}


void populate_float_array(float fa[], int size_array)
/**********************************************************************
//
// Function name:       populate_float_array
//
// DESCRIPTION:         Fills the given array with psudo-random values.
//
// Parameters:          fa (float[])     : The array to be filled.
//                      size_array (int) : The size of the array to be
//                                         filled
//
// Return values:       void
//
***********************************************************************/
{
    int i;
    for (i = 0; i < size_array; ++i)
    {
        fa[i] = gen_rand_float();
    }
}


float gen_rand_float()
/**********************************************************************
//
// Function name:       gen_ran_float 
//
// DESCRIPTION:         Generates a psudo-random float value.
//
// Parameters:          void
//
// Return values:       float : A random float value.
//
***********************************************************************/
{
    return rand() * 1.0;
}


void print_float_array(float float_array[], int array_size)
/**********************************************************************
//
// Function name:       print_float_array
//
// DESCRIPTION:         Prints formatted output of a float array.
//
// Parameters:          float_array (float[]) : The array to be printed
//                      array_size  (int)     : The size of the array to
//                                              be printed.
//
// Return values:       void
//
***********************************************************************/
{
    int i;

    printf("[ ");
    for (i=0; i < (array_size - 1); i++)
    {
        printf("%.2f, ", float_array[i]);
    }
    printf("%.2f ]\n", float_array[i]);
}


int str_len(char string[])
/**********************************************************************
//
// Function name:       str_len
//
// DESCRIPTION:         Gets the length of a string (char array).
//
// Parameters:          string (char[]) : The string whos length is to
//                                        be determined.
//
// Return values:       int : Length of the string argument.
//
***********************************************************************/
{
    int len = 0;
    while (string[len] != '\0')
    {
        len++;
    }
    return len;
}
