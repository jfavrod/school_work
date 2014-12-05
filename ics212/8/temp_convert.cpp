/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    8
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        10 Nov 2014
//
// FILE:        temp_convert.cpp
//
// DESCRIPTION: Displays a dynamic temperature (F to C) conversion table.
//
***********************************************************************/
#include "temp_convert.h"


/*****************************************************************
 *
 *  Function name:      main
 *
 *  DESCRIPTION:        User Interface of the temp_convert program.
 *
 *  Parameters:         void
 *
 *  Return values:      0: Success
 *
 ****************************************************************/

int main(void)
{
    int err = 0;
    int fahrenheit = -1;

    do
    {
        err = 0;
        print_menu();
        get_input(&fahrenheit, &err);
    }
    while (err);

    print_conversion_table(round_up(fahrenheit, 5));

    return err;
}


/*****************************************************************
 *
 *  Function name:      print_menu 
 *
 *  DESCRIPTION:        Prints a menu to prompt the user for
 *                      input.
 *
 *  Parameters:         void
 *
 *  Return values:      void
 *
 ****************************************************************/
void print_menu(void)
{
    cout << "To display a conversion table for Fahrenheit to Celsius,"
         << endl
         << "Please enter a maximum temperature in Fahrenheit (F): ";
    return;
}


/**********************************************************************
//
//  Function name:      get_input
//
//  DESCRIPTION:        Gets the user input from the input buffer. If
//                      input is invalid an error message is printed and
//                      error flag passed is set; else the fahrenheit
//                      parameter is dereferanced and set to the user input.
//
//  Parameters:         fahrenheit (int*): The address of fahrenheit
//                      from main.
//                      err (int*): The address of the err var from main. 
//
//  Return values:      0: Success
//
**********************************************************************/

void get_input(int *fahrenheit, int *err)
{
    int tmp = 0;
    string input("");

    cin >> input;
    tmp = atoi(input.c_str());

    if (tmp <= 0)
    {
        *err = 1;
        cout << "** Invalid fahrenheit temperature." << endl
             << "*  Temp must be a positive integer." << endl;
    }
    else
    {
        *fahrenheit = tmp;
    }

    return;
}


/**********************************************************************
//
//  Function name:      print_conversion
//
//  DESCRIPTION:        Prints a conversion table.
//
//  Parameters:         max (int): The max value (F) in the conversion
//                      table.
//
//  Return values:      void
//
**********************************************************************/

void print_conversion_table(int max)
{
    int i = 0;
    float celsius = 0;
    float &c = celsius;

    cout << setw(20) << "Temp in F" << setw(20) << "Temp in C" << endl;
    while (i <= max)
    {
        convertftoC(i, c);

        cout << setw(20) << i
             << setw(20) << fixed << setprecision(2) << celsius << endl;
        i += 5;
    }
    return;
}


/**********************************************************************
//
//  Function name:      convertftoC
//
//  DESCRIPTION:        Performs a conversion from fahrenheit to
//                      celsius.
//
//  Parameters:         f (int): A given fahrenheit temp.
//                      c (float&): A referance to the float in which
//                      the celsius conversion will be stored.
//
//  Return values:      void
//
**********************************************************************/

void convertftoC(int f, float &c)
{
    c = 5 * ((float)f - 32) / 9;
}
