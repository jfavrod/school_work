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
// FILE:        Cow.h
//
// DESCRIPTION: Cow class definition.
//
***********************************************************************/
#ifndef COW_H
#define COW_H

#include "Animal.h"
#include <string.h>
#include <iostream>

class Cow : public Animal
{
    public:
        Cow();
        ~Cow();
        void display_data(void);
};

#endif
