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
// FILE:        Animal.cpp
//
// DESCRIPTION: Implementation of the Animal Parent Class.
//
***********************************************************************/
#include "Animal.h"


/**********************************************************************
//
//  Method name:  Animal
//
//  DESCRIPTION:    Constructor for Animal Parent Class.
//
//  Parameters:     void
//
//  Return values:  A new Animal object with default values.
//
**********************************************************************/

Animal::Animal(void)
{
    this->fly_mask = 8;
    this->leg_mask = 7;
    this->data = 0;
    strcpy(this->sound, "");
}


/**********************************************************************
//
//  Method name:    ~
//
//  DESCRIPTION:    Destructor for the Animal class.
//
//  Parameters:     void
//
//  Return values:  void
//
**********************************************************************/

Animal::~Animal(void)
{
    return;
}


/**********************************************************************
//
//  Method name:    display_data
//
//  DESCRIPTION:    virtual Method implemented by subclasses.
//
//  Parameters:     void
//
//  Return values:  void
//
**********************************************************************/

void Animal::display_data(void)
{
    std::cout << "Sound: " << this->sound << std::endl
    << "Fly: " << (this->data & this->fly_mask ? "Can":"No Can")
    << "\n" << std::endl;
};
