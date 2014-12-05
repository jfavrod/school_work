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
// FILE:        Bird.h
//
// DESCRIPTION: Bird class definition.
//
***********************************************************************/
#ifndef BIRD_H
#define BIRD_H

#include "Animal.h"
#include <string.h>
#include <iostream>

class Bird: public Animal
{
    public:
        Bird();
        ~Bird();
        void display_data(void);
};

#endif
