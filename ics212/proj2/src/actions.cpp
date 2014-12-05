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
// FILE:        actions.cpp
//
// DESCRIPTION: The definitions of the functions performed by the UI.
//
***********************************************************************/
#include "actions"


/**********************************************************************
//
//  Function name:      add_record
//
//  DESCRIPTION:        Asks user for necessary data for and executes
//                      the llist::addRecord method.
//
//  Parameters:         addrBook (llist&): An llist representing the
//                      address book.
//
//  Return values:      void
//
**********************************************************************/

void add_record(llist &addrBook)
{
    char *name = get_name();
    char *address = get_address();
    short yearofbirth = get_yearofbirth();
    char *telno = get_telno();
    addrBook.addRecord(name, address, yearofbirth, telno);
    return;
}


/**********************************************************************
//
//  Function name:      mod_record
//
//  DESCRIPTION:        Performs the necessary operations to modify
//                      a record in the address book.
//
//  Parameters:         addrBook (llist&): An llist representing the
//                      address book.
//                      err (int *): For setting errors if they occur.
//
//  Return values:      void
//
**********************************************************************/

void mod_record(llist &addrBook, int *err)
{
    if (addrBook.num_items < 1)
    {
        cout << "Address book is empty" << endl;
    }
    else 
    {
        cout << "Get record by name" << endl;
        char *name = get_name();
        if (addrBook.printRecord(name))
        {
            char *field = get_field();
            char *update = get_update(field);
            if (!(*err = addrBook.modifyRecord(name, field, update)));
            {
                cout << "Modified entry for " << name << endl;
                cout << "Set " << field << " to " << update << endl;
            }
        }
        else
        {
            cout << "There is no record that matches " << name << endl;
        }
    }
}


/**********************************************************************
//
//  Function name:      find_and_print
//
//  DESCRIPTION:        Searches the addrBook for a given name and
//                      prints it if found else prints not found mesg.
//
//  Parameters:         addrBook (llist&): An llist representing the
//                      address book.
//
//  Return values:      void
//
**********************************************************************/

void find_and_print(llist &addrBook)
{
    cout << "Get record by name" << endl;
    if (addrBook.num_items > 0)
    {
        if (!addrBook.printRecord(get_name()))
        {
            cout << "No record found." << endl;
        }
    }
    else 
    {
        cout << "Address book empty" << endl;
    }
}


/**********************************************************************
//
//  Function name:      print
//
//  DESCRIPTION:        Prints a string representation of the addrBook
//                      if not empty, else prints is empty mesg.
//
//  Parameters:         addrBook (llist&): An llist representing the
//                      address book.
//
//  Return values:      void
//
**********************************************************************/

void print(llist &addrBook)
{
    if (addrBook.num_items > 0)
    {
        addrBook.printAll();
    }
    else
    {
        cout << "Address book empty." << endl;
    }
}


/**********************************************************************
//
//  Function name:      del_record
//
//  DESCRIPTION:        Performs the operations necessary for deleting
//                      a record from the address book.
//
//  Parameters:         addrBook (llist&): An llist representing the
//                      address book.
//
//  Return values:      void
//
**********************************************************************/

void del_record(llist &addrBook)
{
    if (addrBook.num_items > 0)
    {
        int tally;
        cout << "Delete record by name" << endl;
        if ( (tally = addrBook.deleteRecord(get_name())) == 0 )
        {
            cout << "No match found" << endl;
        }
        else
        {
            cout << "Deleted " << tally << " matches" << endl;
        }
    }
    else
    {
        cout << "Address book empty." << endl;

    }
}
