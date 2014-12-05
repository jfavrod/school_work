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
// FILE:        Cow.cc
//
// DESCRIPTION: A Cow Animal implementation.
//
***********************************************************************/
#include "Cow.h"


/**********************************************************************
//
//  Method name:        Cow
//
//  DESCRIPTION:        Constructor for the Cow Animal.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/
Cow::Cow()
{
    this->data = 0;

    this->data = this->data | 4;
    strcpy(this->sound, "Moo");
}


/**********************************************************************
//
//  Method name:    ~
//
//  DESCRIPTION:    Destructor for the Cow class.
//
//  Parameters:     void
//
//  Return values:  void
//
**********************************************************************/

Cow::~Cow(void)
{
    return;
}


/**********************************************************************
//
//  Method name:        display_data
//
//  DESCRIPTION:        Prints the values stored in the data byte.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

void Cow::display_data(void)
{
    std::cout << "Sound: " << this->sound << std::endl
    << "Number of legs: " << int(this->data & this->leg_mask) << std::endl
    << "Fly: " << (this->data & this->fly_mask ? "Can":"No Can") << std::endl;
    std::cout << std::endl;
}
