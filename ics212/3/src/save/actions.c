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
// FILE:        actions.c
//
// DESCRIPTION: Holds the functions that perform the actions initiated
//              by the UI.
//
***********************************************************************/
#include "actions.h"


/**********************************************************************
//
//  Function name:      addRecord
//
//  DESCRIPTION:        
//
//  Parameters:        
//
//  Return values:    
//
**********************************************************************/



/**********************************************************************
//
//  Function name:      get_name
//
//  DESCRIPTION:        Asks the user for a name and stores it in the
//                      variable pointed to by the given pointer.
//
//  Parameters:         name (pointer) : Points to where you want to
//                                       store the given name.
//
//  Return values:      void
//
**********************************************************************/

int get_name(char name[])
{
    int error = 0;
    int i = 0;

    printf("Name: ");
    while (isspace(name[i] = getchar()) || i++); /* eat leading spaces */
    for (i = i; (name[i++] = getchar()) != '\n' && i < MAX_NAME;);

    if (i < MAX_NAME) {
        name[--i] = '\0';
    }
    !debug? : printf("Got name: %s\n", name);

    return error;
}


/**********************************************************************
//
//  Function name:      get_yearofbirth
//
//  DESCRIPTION:
//
//  Parameters:
//
//  Return values:
//
**********************************************************************/

int get_yearofbirth(int *yearofbirth)
{
    int error = 0;
    printf("Year of Birth: ");
    scanf("%d", yearofbirth);
    !debug? :printf("Got year: %d\n", *yearofbirth);
    return error;
}


/**********************************************************************
//
//  Function name:      get_address
//
//  DESCRIPTION:
//
//  Parameters:
//
//  Return values:
//
**********************************************************************/



/**********************************************************************
//
//  Function name:      get_telno
//
//  DESCRIPTION:
//
//  Parameters:
//
//  Return values:
//
**********************************************************************/

