/**********************************************************************
//
// NAME:        Jason Favrod
//
// HOMEWORK:    5
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        4 Oct 2014
//
// FILE:        driver.c
//
// DESCRIPTION: A driver for readfile and writefile functions.
//
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "account.h"

int handle_args(int argc, char *argv[]);
int get_num_customers(int *num_customers);
int get_info(struct account *new_acct);
int get_name(char name[]);
int get_account_no(int *customer_account_no);
int get_balance(float *customer_balance);
int writefile(struct account acct_array[], int num_customers, char filename[]);
int readfile(struct account acct_array[], int *num_customers, char filename[]);
struct account_str account_toString(struct account acct);
void print_account(struct account acct);
void print_bankone(struct account bankone[], int num_customers);

int debug = 0;


/**********************************************************************
//
//  Function name:      main
//
//  DESCRIPTION:        A driver for reading and writing an array of
//                      struct accounts.
//
//  Parameters:         int argc  & *argv[] : Command line args count
//                                            and string(s).
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int main(int argc, char *argv[])
{
    int err = 0;
    int num_customers = 0;
    int counter = 0;
    char persist_file[] = "accounts.db";
    struct account bankone[5] = {};
    struct account new_acct;

    err = handle_args(argc, argv);

    if (!err)
    {
        get_num_customers(&num_customers);

        for (counter = 0; counter < num_customers; counter++)
        {
            get_info(&new_acct);
            bankone[counter] = new_acct;
        }
    }

    printf("writing bankone:\n");

    if (debug)
    {
        for (counter = 0; counter < num_customers; counter++)
        {
            printf("* main: customer count=%d\n", counter);
            printf("* main: name=%s\n", bankone[counter].name);
            printf("* main: account number=%d\n", bankone[counter].account_no);
            printf("* main: balance=%f\n", bankone[counter].balance);
        }
    }

    print_bankone(bankone, num_customers);
    writefile(bankone, num_customers, persist_file);

    readfile(bankone, &num_customers, persist_file);
    printf("read into bankone from file:\n");
    print_bankone(bankone, num_customers);

    return err;
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
    char debug_flag[] = "-d";


    if ((argc == 2) && (strcmp(debug_flag, argv[1]) == 0))
    {
        debug = 1;
        printf("* handle_args: debug=%d\n", debug);
        printf("* handle_args: agrc=%d\n", argc);
        while (i < argc)
        {
            printf("* handle_args: argv[%d]=%s\n", i, argv[i]);
            ++i;
        }
    }
    else if (argc > 1)
    {
        printf("driver: invalid argument\n");
        printf("usage:\n\tdriver\n\tdriver -d\tenable debug mode\n");
        err = 1;
    }
    
    return err;
}


/**********************************************************************
//
//  Function name:      get_num_customers
//
//  DESCRIPTION:        Askes the customer for the number of customers
//                      that will be recorded and stores the number in
//                      the num_customer parameter.
//
//  Parameters:         name (type) : Description.
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int get_num_customers(int *num_customers)
{
    int err = 0;

    printf("please enter the number of customers\n");
    scanf("%d", num_customers);
    printf("num_customers: %d\n", *num_customers);

    return err;
}


/**********************************************************************
//
//  Function name:      get_info
//
//  DESCRIPTION:        Gets the required infomation for the given
//                      account.
//
//  Parameters:         new_acct (account) : An account to populate.
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int get_info(struct account *new_acct)
{
    int err = 0;

    get_name((*new_acct).name);
    get_account_no(&(*new_acct).account_no);
    get_balance(&(*new_acct).balance);

    return err;
}


/**********************************************************************
//
//  Function name:      get_name
//
//  DESCRIPTION:        Asks the user for an account's name and stores
//                      it in the name array parameter.
//
//  Parameters:         name (char[]) : Where the name received from
//                                      the user is stored.
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int get_name(char name[])
{
    int err = 0;
    int i = 0;

    printf("Name: ");
    while (isspace(name[i] = getchar()) || i++); /* eat leading spaces */
    for (i = i; ((name[i++] = getchar()) != '\n') && i < MAX_NAME;)
        ;

    name[--i] = '\0';

    return err;
}


/**********************************************************************
//
//  Function name:      get_account_no
//
//  DESCRIPTION:        Asks the user for an account number and stores
//                      it in the .
//
//  Parameters:         A pointer to where to store the account number
//                      retireved from the user.
//
//  Return values:      0 : Success
//
**********************************************************************/

int get_account_no(int *customer_account_no)
{
    int err = 0;

    printf("Account Number: ");
    scanf("%d", customer_account_no);

    return err;
}


/**********************************************************************
//
//  Function name:      get_balance
//
//  DESCRIPTION:        Asks the user for an account balance & stores
//                      it in the customer_balance pointer parameter.
//
//  Parameters:         customer_balance (float *) : Where to store the
//                                                   account number
//                                                   input by the user.
//
//  Return values:      0 : Success
//
**********************************************************************/

int get_balance(float *customer_balance)
{
    int err = 0;

    printf("Account Balance: ");
    scanf("%f", customer_balance);

    return err;
}



/**********************************************************************
//
//  Function name:      print_bankone
//
//  DESCRIPTION:        Prints the bankone array to stdout.
//
//  Parameters:         bankone (account[]) : The bankone array to print.
//                      num_customers (int) : The number of customers in
//                                            the bankone array.
//
//  Return values:      void
//
**********************************************************************/

void print_bankone(struct account bankone[], int num_customers)
{
    int i;

    for (i = 0; i < num_customers; i++)
    {
        printf("bankone[%d]:\n", i); 
        print_account(bankone[i]);
    }
}


/**********************************************************************
//
//  Function name:      print_account
//
//  DESCRIPTION:        Prints the given account to stdout.
//
//  Parameters:         acct (account) : The account to print.
//
//  Return values:      void
//
**********************************************************************/

void print_account(struct account acct)
{
    printf("{ name: %s,\n", acct.name);
    printf("  account_no: %d,\n", acct.account_no);
    printf("  balance: %f }\n", acct.balance);
}
