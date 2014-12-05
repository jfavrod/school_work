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
    int run = 1;        /* if !0 program stops running */
    int action;         /* signal for action to perform */

    error = handle_args(argc, argv);
    !debug? : print_args(argc, argv);

    run = !error;
    while (run)
    {
        !debug? : printf("error:%d\trun:%d\n", error, run);
        
        if (error != 1)
        {
            !debug? : printf("Getting user selection.\n");
            action = get_selection();
        }

        perform(action, &error, &run);
    }

    !debug? : printf("error:\t%d\naction:\t%d\n", error, action);
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
    int invalid = 0;
    char tmp[] = "debug";

    if ((argc == 2) && (strcmp(tmp, argv[1]) == 0))
    {
        debug = 1;
    }
    else if (argc > 1)
    {
        printf("addrBookUI: error\n");
        invalid = 1;
    }
    
    return invalid;
}


/**********************************************************************
//
//  Function name:      print_args
//
//  DESCRIPTION:        Prints the values of argc and argv.
//
//  Parameters:         argc (int)      : The number of args.
//                      argv (char* []) : The actual cmd line args.
//
//  Return values:      void
//
**********************************************************************/

void print_args(int argc, char *argv[])
{
    printf("agrc:\t%d\n", argc);
    int i;
    for (i = 0; i < argc; i++)
    {
        printf("arg%d:\t%s\n", i, argv[i]);
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
    int user_choice;    /* Stores the users selection */
    int invalid_choice; /* Flag thrown when selection is invalid */
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

        char tmp[2];
        /* eat leading spaces */
        while (isspace(tmp[0] = getchar()));
        /*
        if ( ((tmp[1] = getchar()) == '\n') && putc('\n', stdin) && fputc(EOF, stdin)) {
            printf("hello\n");
        }
        */
        !debug? : printf("Got char:\t%c\n", tmp[0]);

        clear_input_buff();
        !debug? : printf("Cleared the input buffer\n");
        invalid_choice = 0;
        !debug? : printf("Reset invalid choice\n");

        int range_check;
        if (isdigit(tmp[0]) && (range_check = inrange((tmp[0] - 48), 0, 5)))
        {
            user_choice = tmp[0] - 48;
        }
        else
        {
            invalid_choice = 1;
        }
        !debug? : printf("inrange: %s\n", (range_check == 0)? "False" : "True");
    }
    
    !debug?:printf("The user entered: %d\n", user_choice);
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

    printf("What would you like to do?\n\n");

    int i;
    for (i = 0; i < num_options; i = i + 2)
    {
        printf("%d:\t%*s\t%d:\t%*s\n", i, col_width, opt[i],
                i+1, col_width, i >= num_options?'\0':opt[i+1]);
    }
    printf("\n");
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
    switch(action)
    {
    case 0:
        !debug?:printf("Performing action 0\n");
        addrecord();
        break;
    case 1:
        !debug?: printf("Performing action 1\n");
         printf("Performing action 1\n");
        break;
    case 2:
        !debug?: printf("Performing action 2\n");
         printf("Performing action 2\n");
        break;
    case 3:
        !debug?: printf("Performing action 3\n");
         printf("Performing action 3\n");
        break;
    case 4:
        !debug?: printf("Performing action 4\n");
         printf("Performing action 4\n");
        break;
    case 5:
        printf("Goodbye\n");
        *run = 0;
        break;
    default:
        *error = 1;
        !debug?: printf("Performing default action\n");
        break;
    }
}
