/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    3 Part B
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        15 Sept 2014
//
// FILE:        main.c
//
// DESCRIPTION: A user-interface which allows the user a menu of choices
//              for a personal address book application.
//
***********************************************************************/
#include "addrBookUI.h"

int debug = 0;
struct record *start = NULL;

/**********************************************************************
//
//  Function name:      main
//
//  DESCRIPTION:        Implements the user interface.
//
//  Parameters:         void
//
//  Return values:      int 0
//
**********************************************************************/

int main(int argc, char *argv[])
{
    int error = 0;      /* error flag */
    int run = 1;        /* if not 1 program stops running */
    int action;         /* signal for action to perform */

    error = handle_args(argc, argv);

    run = !error;
    while (run)
    {
        if (debug) printf("main: run=%d\nmain: error=%d\n", run, error);
        
        if (!error)
        {
            action = get_selection();
        }

        perform(action, &error, &run);
    }

    if (debug) printf("main: action=%d\terror=%d\n", action, error);
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
//  Return values:      void
//
**********************************************************************/

int handle_args(int argc, char *argv[])
{
    int i = 0;
    int err = 0;
    char test[] = "debug";


    if ((argc == 2) && (strcmp(test, argv[1]) == 0))
    {
        debug = 1;
        printf("handle_args: debug=%d\n", debug);
        printf("handle_args: agrc=%d\n", argc);
        while (i < argc)
        {
            printf("handle_args: argv[%d]=%s\n", i, argv[i]);
            ++i;
        }
    }
    else if (argc > 1)
    {
        printf("addrBook: invalid argument\n");
        printf("usage:\n\taddrBook\n\taddrBook debug\n");
        err = 1;
    }
    
    return err;
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
    int user_choice;    /* Stores the users selection */
    int invalid_choice; /* Flag thrown when selection is invalid */
    int range_check;
    char tmp[2];
    user_choice = -1;
    invalid_choice = 0;

    print_menu();
    while (user_choice == -1)
    {
        if (invalid_choice)
        {
            printf("You've made an invalid selection.\n");
            printf("Please try again.\n\n");
            print_menu();
        }

        /* eat leading spaces and grab a char */
        while (isspace(tmp[0] = getchar()));  
        if (debug) printf("get_selection: got char %c\n", tmp[0]);

        clear_input_buff();
        invalid_choice = 0;

        if (isdigit(tmp[0]) && (range_check = inrange((tmp[0] - 48), 0, 5)))
        {
            user_choice = tmp[0] - 48;
        }
        else
        {
            invalid_choice = 1;
        }

        if (debug) printf("get_selection: inrange? %s\n",
                (range_check == 0)? "No" : "Yes")
            ;
    }
    
    if (debug) printf("get_selection: user_choice=%d\n", user_choice);
    return user_choice;
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
    int num_options = 6;
    int col_width = 20;
    char *opt[num_options];
    opt[0] = "Add a new record";
    opt[1] = "Modify a record";
    opt[2] = "Print a record";
    opt[3] = "Print all info";
    opt[4] = "Delete a record";
    opt[5] = "Quit the program";

    printf("What would you like to do?\n");

    int i = 0;
    while (i < num_options)
    {
        printf("%d:\t%*s\t%d:\t%*s\n", i, col_width, opt[i],
                i+1, col_width, i >= num_options?'\0':opt[i+1]);
        i = i + 2;
    }
}


/**********************************************************************
//
//  Function name:      perform
//
//  DESCRIPTION:        Call a function based on the action parameter.
//
//  Parameters:         action (int) : The code of the action to be
//                                     performed.
//  
//  Return values:      1 : Success, function called.
//                      0 : Failure, no function called.
//
**********************************************************************/

void perform(int action, int *error, int *run)
{
    if (debug)
    {
        printf("perform: action=%d\n", action);
        printf("perform: error=%d\n", *error);
        printf("perform: run=%d\n", *run);
    }

    switch(action)
    {
    case 0:
        addRecord(&start, get_name(), get_yearofbirth(), get_address(), get_telno());
        break;

    case 1:
        printf("Get record by name\n");
        modifyRecord(start, get_name(), "field", "update");
        break;

    case 2:
        printf("Get record by name\n");
        printRecord(start, get_name());
        break;

    case 3:
        printAllRecords(start);
        break;

    case 4:
        printf("Delete record by name\n");
        deleteRecord(&start, get_name());
        break;

    case 5:
        printf("Goodbye\n");
        *run = 0;
        break;

    default:
        *error = 1;
        break;
    }

    if (debug)
    {
        printf("perform: action=%d\n", action);
        printf("perform: error=%d\n", *error);
        printf("perform: run=%d\n", *run);
    }
}
