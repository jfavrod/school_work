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
#define ROUND 5

int round_up(int);
float convertftoC(int fahrenheit);


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


float convertftoC(int fahrenheit)
{
    double celcius;
    celcius = 5 * ((double)fahrenheit - 32) / 9;
    return celcius;
}
