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
// FILE:        farm.cc
//
// DESCRIPTION: Homework Assignment #9.
//
***********************************************************************/
#include <iostream>
#include <vector>
#include <map>
#include "Animal.h"
#include "Bird.h"
#include "Cow.h"

using namespace std;


/**********************************************************************
//
//  Function name:  animal_display_data
//
//  DESCRIPTION:    Calls the given animal's display_data method.
//
//  Parameters:     animal (Animal *): A pointer to the given Animal.
//
//  Return values:  void
//
**********************************************************************/

void animal_display_data(Animal *animal)
{
    animal->display_data();
}


/**********************************************************************
//
//  Function name:      main
//
//  DESCRIPTION:        Driver for hw 9.
//
//  Parameters:         argc (int): Number of cmdline arguments.
//                      argv (*arcv[]): The cmdline arguments.
//
//  Return values:      0: Success
//
**********************************************************************/

int main(int argc, char *argv[])
{
    Animal A;
    Bird B;
    Cow C;

    vector<Animal*> animal;
    map<int, Animal*> farm;

    animal.push_back(&A);
    animal.push_back(&B);
    animal.push_back(&C);

    for (unsigned int i = 0; i < animal.size(); i++)
    {
        farm[i] = animal[i];
    }

    cout << "The Animal" << endl;
    animal_display_data(animal.at(0));

    cout << "The Bird" << endl;
    animal_display_data(farm[1]);

    cout << "The Cow" << endl;
    animal_display_data(farm[farm.size()-1]);

    return 0;
}
