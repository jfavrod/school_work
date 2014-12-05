/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    9
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        28 Nov 2014
//
// FILE:        Animal.h
//
// DESCRIPTION: Animal class definition.
//
***********************************************************************/
#ifndef ANIMAL_H
#define ANIMAL_H

#include <iostream>
#include <string.h>

#define MAX_SOUND 10

class Animal
{
    public:
        Animal(void);
        virtual ~Animal(void);
        virtual void display_data(void);

    protected:
        unsigned char data;     /* Flags for num legs & fly-ability.
                                 * bits: FLLL
                                 * (F: flying, L: legs)
                                 */
        char sound[MAX_SOUND];
        unsigned char fly_mask;
        unsigned char leg_mask;
};

#endif
