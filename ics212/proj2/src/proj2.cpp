/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    proj 2
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        24 Nov 2014
//
// FILE:        proj2.cpp
//
// DESCRIPTION: The user interface for project 2.
//
***********************************************************************/
#include "proj2.h"


/**********************************************************************
//
//  Function name:      main
//
//  DESCRIPTION:        The user interface to project 2.
//
//  Parameters:         argc (int)      : The number of args.
//                      argv (char* []) : The actual cmd line args.
//
//  Return values:      0: Success
//                      1: Failure
//
**********************************************************************/

int main(int argc, char *argv[])
{
    short error = 0;      /* error flag */
    short run = 1;        /* if not 1 program stops running */
    short action;         /* signal for action to perform */

    if (!(error = handle_args(argc, argv)))
    {
        llist addrBook;
        llist &addrBookRef = addrBook;

        while (run)
        {
            action = get_selection();
            perform(action, addrBookRef, &error, &run);
        }
    }

    return error;
}


/**********************************************************************
//
//  Function name:      handle_args
//
//  DESCRIPTION:        Parses the cmd line args; prints an error mesg
//                      when provided with invalid arguments.
//
//  Parameters:         argc (int)      : The number of args.
//                      argv (char* []) : The actual cmd line args.
//
//  Return values:      0: Success
//                      1: Failure
//
**********************************************************************/

int handle_args(int argc, char *argv[])
{
    int err = 0;

    if (argc > 1)
    {
        cout << "addrBook: invalid argument" << endl;
        cout << "usage:\naddrBook" << endl;
        err = 1;
    }

    return err;    
}


/**********************************************************************
//
//  Function name:      print_menu
//
//  DESCRIPTION:        Prints the options menu for the addr program.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

void print_menu(void)
{
    int i = 0;
    char *opt[MENU_OPTS] = {
        "Add a new record",
        "Modify a record",
        "Print a record",
        "Print all info",
        "Delete a record",
        "Reverse the list",
        "Quit the program"
    };

    cout << "What would you like to do?" << endl;
    for (;i < MENU_OPTS; i++)
    {
        cout << i << ": " << opt[i] << endl;
    }
}


/**********************************************************************
//
//  Function name:      get_selection
//
//  DESCRIPTION:        Asks the user to select a menu option, when a
//                      valid option is selected it's returned.
//
//  Parameters:         void
//
//  Return values:      int : A valid menu selection.
//
**********************************************************************/

int get_selection(void)
{
    int selected;
    int valid = 0;

    do 
    {
        print_menu();

        selected = cin.peek() - 48;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (inrange(selected, 0, MENU_OPTS - 1))
        {
            valid = 1;
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    } 
    while (!valid);

    return selected;
}


/**********************************************************************
//
//  Function name:      perform
//
//  DESCRIPTION:        Call a function based on the action parameter.
//
//  Parameters:         action (int): The code of the action to be
//                      performed.
//                      addrBook (llist&): A reference to the addrBook.
//                      addrBook_error (short*): Points to the error in
//                      main.
//                      run (short *): Points to the run in main.
//  
//  Return values:      1 : Success, function called.
//                      0 : Failure, no function called.
//
**********************************************************************/

int perform(int action, llist &addrBook, short *addrBook_error, short *run)
{
    int err = 0;
    
#ifdef DEBUG
{
    cout << "* perform: action=" << action << endl;
    cout << "* perform: error=" << *addrBook_error << endl;
    cout << "* perform: run=" << *run << endl;
}
#endif
    
    if (action == 0)
    {
        add_record(addrBook);
    }
    if (action == 6)
    {
        cout << "Goodbye" << endl;
        *run = 0;
    }
    else if (addrBook.num_items == 0)
    {
        cout << "Address book is empty" << endl;
    }
    else if (action == 1)
    {
        mod_record(addrBook, &err);
    }
    else if (action == 2)
    {
        find_and_print(addrBook);
    }
    else if (action == 3)
    {
        cout << addrBook;
    }
    else if (action == 4)
    {
        del_record(addrBook);
    }
    else if (action == 5)
    {
        addrBook.reverse();
    }
    else
    {
        *addrBook_error = 1;
    }

#ifdef DEBUG
{
    cout << "* perform: action=" << action << endl;
    cout << "* perform: addrBook_error=" << *addrBook_error << endl;
    cout << "* perform: run=" << *run << endl;
    cout << "* perform: returning=" << err << endl;
}
#endif
    
    return err;
}
