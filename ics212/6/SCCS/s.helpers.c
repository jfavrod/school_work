h02948
s 00088/00000/00000
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
E 1
