/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    Homework #1
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        Aug 27 2014
//
// FILE:        temp_convert.c
//
// DESCRIPTION: A program that converts between celcius and fahrenheit.
//
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

#define INCREMENT 5
#define COLWIDTH 10
#define INPUTLIMIT 79
#define ROUND 5

void print_menu();
void get_input(char[]);
int validate(char input[]);
int round_up(int);
void print_conversion_table(int max_temp);
double convertftoC(int fahrenheit);
void clear_input_buff();


int main()
{
    char user_input[INPUTLIMIT];
    int fahrenheit_temp;

    do
    {
        get_input(user_input);
    }
    while (!validate(user_input));

    sscanf(user_input, "%d", &fahrenheit_temp);
    print_conversion_table(round_up(fahrenheit_temp));

    return 1;
}


/*****************************************************************
 *
 *  Function name:      get_input
 *
 *  DESCRIPTION:        Calls the menu and caputres user input.
 *
 *  Parameters:         input (char[]) : Storage for user input.
 *
 *  Return values:      void
 *
 ****************************************************************/
void get_input(char input[])
{
    print_menu();
    scanf("%s", input);
}


/*****************************************************************
 *
 *  Function name:      print_menu 
 *
 *  DESCRIPTION:        Prints a menu to prompt the user for
 *                      input.
 *
 *  Parameters:         
 *
 *  Return values:       void
 *
 ****************************************************************/
void print_menu()
{
    char m0[] = "To display a conversion table for Fahrenheit to Celcius,";
    char m1[] = "Please enter a maximum temperature in Fahrenheit (F): ";
    printf("%s\n%s", m0, m1);
}


int validate(char input[])
/*****************************************************************
 *
 *  Function name:      validate
 *
 *  DESCRIPTION:        Parces the user input.
 *
 *  Parameters:         input (char[]) : Contains user input. 
 *
 *  Return values:       0 : success
 *                      -1 : the value was not found
 *
 ****************************************************************/
{
    int valid = 1;
    int count = 0;

    while (input[count] != '\0')
    {
        char current_char = input[count];
        if (!iscntrl(current_char) && (!isdigit(current_char)))
        {
            input[count] = 0;
            valid = 0;
        }
        count++;
    }

    if (valid && atoi(input) == 0)
    {
        valid = 0;
    }

    if (!valid) 
    {
        char m0[] = "! YOUR INPUT CONTAINS INVALID CHARACTERS !";
        char m1[] = "Valid (F) temperatures can only be integers > 0";
        printf("\n%s\n%s\n\n", m0, m1);
    }

    clear_input_buff();
    return valid;
}


/*****************************************************************
 *
 *  Function name:      round_up
 *
 *  DESCRIPTION:        Rounds temp up to the nears ROUNDs place.
 *
 *  Parameters:         temp (int) :  The temp parsed from user
 *                                    input.
 *
 *  Return values:       rounded (int) : The round value.
 *
 ****************************************************************/
int round_up(int temp)
{
    int remainder = temp % ROUND;
    int rounded = (remainder == 0) ? temp : ((temp - remainder) + ROUND);
    return rounded;
}


void print_conversion_table(int max_temp)
{
    int current_temp = 0;
    printf("%10s%*s\n", "Fahrenheit", COLWIDTH, "Celcius");
    while (current_temp <= max_temp) 
    {
        printf("%*d%*.2f\n", COLWIDTH, current_temp,
                COLWIDTH, convertftoC(current_temp));
        current_temp = current_temp + INCREMENT;
    }
}


double convertftoC(int fahrenheit)
{
    double celcius;
    celcius = 5 * ((double)fahrenheit - 32) / 9;
    return celcius;
}


void clear_input_buff()
{
    while ( getchar() != '\n' );
}
