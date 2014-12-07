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
#include "Hw10.h"

#define ROUND 5


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
JNIEXPORT jint JNICALL Java_Hw10_round_1up (JNIEnv *env, jclass jc, jint temp)
{
    int remainder = temp % ROUND;
    int rounded = (remainder == 0) ? temp : ((temp - remainder) + ROUND);
    return rounded;
}


/*****************************************************************
 *
 *  Function name:      convertFtoC
 *
 *  DESCRIPTION:        Performs the Fahrenheit to Celcius conversion.
 *
 *  Parameters:         fahrenheit (jint): An int passed in from a
 *                      java UI; the Fahrenheit temp.
 *
 *  Return values:      int : The Celcius conversion.
 *
 ****************************************************************/

JNIEXPORT jfloat JNICALL Java_Hw10_convertFtoC (JNIEnv *env, jclass jclass, jint fahrenheit)
{
    float celcius;
    celcius = 5 * ((float)fahrenheit - 32) / 9;
    return celcius;
}
