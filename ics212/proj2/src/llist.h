/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    Proj2
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        24 Nov 2014
//      
// FILE:        llist.h
//
// DESCRIPTION: The header file describing the llist class.
//
***********************************************************************/
#ifndef LLIST_H
#define LLIST_H
#include "record.h"
#include "getters"
#include <iostream>

using namespace std;


class llist
{
    public:
        int num_items;

        llist();
        llist(char []);
        ~llist();

        int addRecord(char[], char[], int, char[]);
        int printRecord(char []);
        void printRec(struct record rec);
        int modifyRecord(char[], char[], char[]);
        void printAll();
        int deleteRecord(char []);
        void reverse();

    private:
        record *start;
        char filename[16];

        int readfile();
        int writefile();
        record * reverse(record *);
        void cleanup();
        friend std::ostream& operator<<(std::ostream &os, const llist &ll);
};

#endif
