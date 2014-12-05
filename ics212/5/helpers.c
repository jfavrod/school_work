/**********************************************************************
//
// AUTHOR:      Jason Favrod
//
// DATE:        17 Sept 2014
//
// FILE:        helpers.c
//
// DESCRIPTION: A collection of helper functions.
//
***********************************************************************/
#include "helpers.h"


/**********************************************************************
//
//  Function name:      clear_input_buff
//
//  DESCRIPTION:        Clears the input buffer.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/
void clear_input_buff(void)
{
    while ( getchar() != '\n' );
}


/**********************************************************************
//
//  Function name:      get_int
//
//  DESCRIPTION:        Get's a int from the keyboard.
//
//  Parameters:         void
//
//  Return values:      int : The first int found in the input buffer.
//
**********************************************************************/
int get_int(void)
{
    char input[1];
    int i = 0;

    do 
    {
        input[i] = getchar();
        if (isdigit(input[i]))
        {
            ++i;
        }
    }
    while (i < 1);

    clear_input_buff();
    return (input[0] - 48);
}


/**********************************************************************
//
//  Function name:      inrange
//
//  DESCRIPTION:        Answers whether or not the given int x is in the
//                      range from low to high.
//
//  Parameters:         int x    : The int to check.
//                      int low  : The lower value in the range.
//                      int high : The upper value in the range.
//  
//  Return values:      1 : Affirmative, x is in range.
//                      0 : Negitive, x is not in range.
//
**********************************************************************/
int inrange(int x, int low, int high)
{
    int inrange = 0;

    if (x >= low && x <= high)
    {
        inrange = 1;
    }

    return inrange;
}


/**********************************************************************
//
//  Function name:      clear_string
//
//  DESCRIPTION:        Starting at the beginning of the given string
//                      sets all characters to null, until the first
//                      null character is encountered.
//
//  Parameters:         str (char[]) : Any properly formated c string.
//
//  Return values:      0 : Success
//
**********************************************************************/

int clear_string(char str[])
{
    int err = 0;
    int i;
    int str_length = strlen(str);

    for(i = 0; i <= str_length; str[i++] = '\0')
        ; /* clear the string contents */

    return err;
}


/**********************************************************************
//
//  Function name:      str_replace
//
//  DESCRIPTION:        Replaces all occurrences of the needle char in
//                      the haystack string with the replace char.
//
//  Parameters:         name (type) : Description.
//
//  Return values:      Number of needles found.
//
**********************************************************************/

int str_replace(char needle, char haystack[], char replace)
{
    int i = 0;
    int matches = 0;

    while (haystack[i] != '\0')
    {
        if (haystack[i] == needle)
        {
            haystack[i] = replace;
            matches++;
        }

        i++;
    }
    
    return matches;
}
