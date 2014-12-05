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
// FILE:        Bird.cpp
//
// DESCRIPTION: A Bird Animal implementation.
//
***********************************************************************/
#include "Bird.h"


/**********************************************************************
//
//  Method name:        Bird
//
//  DESCRIPTION:        Constructor for the Bird Animal.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

Bird::Bird()
{
    this->data = 0;

    this->data = this->data | this->fly_mask;
    this->data = this->data | 2;
    strcpy(this->sound, "Chirp");
}


/**********************************************************************
//
//  Method name:    ~
//
//  DESCRIPTION:    Destructor for the Bird class.
//
//  Parameters:     void
//
//  Return values:  void
//
**********************************************************************/

Bird::~Bird(void)
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

void Bird::display_data(void)
{
    std::cout << "Sound: " << this->sound << std::endl
    << "Fly: " << (this->data & this->fly_mask ? "Can":"No Can")
    << "\n" << std::endl;
}
