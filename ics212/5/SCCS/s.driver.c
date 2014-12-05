h43066
s 00079/00019/00243
d D 1.11 14/10/04 20:18:56 favrod 11 10
c Added Comments and Edited Debug statements.
e
s 00007/00006/00255
d D 1.10 14/10/04 11:31:05 favrod 10 9
c Edited debug statement
e
s 00000/00019/00261
d D 1.9 14/10/03 15:09:08 favrod 9 8
c Removed clear_input_buff function.
e
s 00067/00012/00213
d D 1.8 14/10/03 12:53:13 favrod 8 7
c Added handle_args function and debug global.
e
s 00002/00000/00223
d D 1.7 14/10/03 10:03:42 favrod 7 6
c It looks like we have a first draft.
e
s 00000/00000/00223
d D 1.6 14/10/02 07:57:31 favrod 6 5
c 
e
s 00009/00007/00214
d D 1.5 14/10/01 22:54:34 jason 5 4
c Tweek while working on writefile.
e
s 00027/00006/00194
d D 1.4 14/10/01 18:23:06 favrod 4 3
c Working on comments.
e
s 00001/00001/00199
d D 1.3 14/10/01 17:15:11 favrod 3 2
c Dereferencing a pointer in printf instead of passing the pointer as an arg.
e
s 00196/00001/00004
d D 1.2 14/10/01 17:04:39 favrod 2 1
c Initial work on the UI
e
s 00005/00000/00000
d D 1.1 14/10/01 12:47:09 favrod 1 0
c date and time created 14/10/01 12:47:09 by favrod
e
u
U
f e 0
t
T
I 2
/**********************************************************************
//
// NAME:        Jason Favrod
//
D 11
// HOMEWORK:
E 11
I 11
// HOMEWORK:    5
E 11
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
D 11
// DATE:
E 11
I 11
// DATE:        4 Oct 2014
E 11
//
D 11
// FILE:
E 11
I 11
// FILE:        driver.c
E 11
//
D 11
// DESCRIPTION:
E 11
I 11
// DESCRIPTION: A driver for readfile and writefile functions.
E 11
//
***********************************************************************/

#include <stdio.h>
#include <ctype.h>
I 8
#include <string.h>
E 8
#include "account.h"

D 8
int readfile(struct account acct_array[], int *num_customers, char filename[]);
int writefile(struct account acct_array[], int num_customers, char filename[]);
E 8
I 8
int handle_args(int argc, char *argv[]);
E 8
int get_num_customers(int *num_customers);
int get_info(struct account *new_acct);
int get_name(char name[]);
D 5
int get_accountno(int *customer_accountno);
E 5
I 5
int get_account_no(int *customer_account_no);
E 5
int get_balance(float *customer_balance);
I 8
int writefile(struct account acct_array[], int num_customers, char filename[]);
int readfile(struct account acct_array[], int *num_customers, char filename[]);
I 11
struct account_str account_toString(struct account acct);
void print_account(struct account acct);
void print_bankone(struct account bankone[], int num_customers);
E 11
E 8
D 9
void clear_input_buff(void);
E 9

I 8
int debug = 0;
E 8
I 4

I 8

E 8
E 4
/**********************************************************************
//
D 4
//  Function name:
E 4
I 4
//  Function name:      main
E 4
//
D 4
//  DESCRIPTION:
E 4
I 4
//  DESCRIPTION:        A driver for reading and writing an array of
//                      struct accounts.
E 4
//
D 11
//  Parameters:         name (type) : Description.
E 11
I 11
//  Parameters:         int argc  & *argv[] : Command line args count
//                                            and string(s).
E 11
//
D 4
//  Return values:
E 4
I 4
//  Return values:      0 : Success
//                      1 : Failure
E 4
//
**********************************************************************/

E 2
I 1
int main(int argc, char *argv[])
{
D 2
    err = 0;
E 2
I 2
    int err = 0;
    int num_customers = 0;
    int counter = 0;
D 5
    char persist_file[] = "alice.txt";
E 5
I 5
    char persist_file[] = "accounts.db";
E 5
    struct account bankone[5] = {};
    struct account new_acct;

D 8
    get_num_customers(&num_customers);
E 8
I 8
    err = handle_args(argc, argv);
E 8

D 8
    for (counter = 0; counter < num_customers; counter++)
E 8
I 8
    if (!err)
E 8
    {
D 8
        get_info(&new_acct);
        bankone[counter] = new_acct;
    }
E 8
I 8
        get_num_customers(&num_customers);
E 8

D 8
    for (counter = 0; counter < num_customers; counter++)
    {
        printf("name: %s\n", bankone[counter].name);
D 5
        printf("account number: %d\n", bankone[counter].accountno);
E 5
I 5
        printf("account number: %d\n", bankone[counter].account_no);
E 5
        printf("balance: %f\n", bankone[counter].balance);
E 8
I 8
        for (counter = 0; counter < num_customers; counter++)
        {
            get_info(&new_acct);
            bankone[counter] = new_acct;
        }
I 11
    }
E 11

D 11
        if (debug)
E 11
I 11
    printf("writing bankone:\n");

    if (debug)
    {
        for (counter = 0; counter < num_customers; counter++)
E 11
        {
D 11
            for (counter = 0; counter < num_customers; counter++)
            {
D 10
                printf("name: %s\n", bankone[counter].name);
                printf("account number: %d\n", bankone[counter].account_no);
                printf("balance: %f\n", bankone[counter].balance);
E 10
I 10
                printf("* main: customer count=%d\n", counter);
                printf("* main: name=%s\n", bankone[counter].name);
                printf("* main: account number=%d\n", bankone[counter].account_no);
                printf("* main: balance=%f\n", bankone[counter].balance);
E 10
            }
E 11
I 11
            printf("* main: customer count=%d\n", counter);
            printf("* main: name=%s\n", bankone[counter].name);
            printf("* main: account number=%d\n", bankone[counter].account_no);
            printf("* main: balance=%f\n", bankone[counter].balance);
E 11
        }
E 8
    }

I 11
    print_bankone(bankone, num_customers);
E 11
E 2
I 5
    writefile(bankone, num_customers, persist_file);

I 7
    readfile(bankone, &num_customers, persist_file);
I 11
    printf("read into bankone from file:\n");
    print_bankone(bankone, num_customers);
E 11

E 7
E 5
    return err;
I 2
}
I 8


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
D 10
        printf("handle_args: debug=%d\n", debug);
        printf("handle_args: agrc=%d\n", argc);
E 10
I 10
        printf("* handle_args: debug=%d\n", debug);
        printf("* handle_args: agrc=%d\n", argc);
E 10
        while (i < argc)
        {
D 10
            printf("handle_args: argv[%d]=%s\n", i, argv[i]);
E 10
I 10
            printf("* handle_args: argv[%d]=%s\n", i, argv[i]);
E 10
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
E 8


/**********************************************************************
//
D 4
//  Function name:
E 4
I 4
//  Function name:      get_num_customers
E 4
//
D 4
//  DESCRIPTION:
E 4
I 4
//  DESCRIPTION:        Askes the customer for the number of customers
//                      that will be recorded and stores the number in
//                      the num_customer parameter.
E 4
//
//  Parameters:         name (type) : Description.
//
D 4
//  Return values:
E 4
I 4
//  Return values:      0 : Success
//                      1 : Failure
E 4
//
**********************************************************************/

int get_num_customers(int *num_customers)
{
    int err = 0;

    printf("please enter the number of customers\n");
    scanf("%d", num_customers);
D 3
    printf("num_customers: %d\n", num_customers);
E 3
I 3
    printf("num_customers: %d\n", *num_customers);
E 3

    return err;
}

I 4

/**********************************************************************
//
//  Function name:      get_info
//
D 11
//  DESCRIPTION:        
E 11
I 11
//  DESCRIPTION:        Gets the required infomation for the given
//                      account.
E 11
//
D 11
//  Parameters:         name (type) : Description.
E 11
I 11
//  Parameters:         new_acct (account) : An account to populate.
E 11
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

E 4
int get_info(struct account *new_acct)
{
    int err = 0;

    get_name((*new_acct).name);
D 5
    get_accountno(&(*new_acct).accountno);
E 5
I 5
    get_account_no(&(*new_acct).account_no);
E 5
    get_balance(&(*new_acct).balance);

    return err;
}

I 4

E 4
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
D 5
//  Function name:      get_accountno
E 5
I 5
//  Function name:      get_account_no
E 5
//
//  DESCRIPTION:        Asks the user for an account number and stores
//                      it in the .
//
D 11
//  Parameters:         void
E 11
I 11
//  Parameters:         A pointer to where to store the account number
//                      retireved from the user.
E 11
//
D 11
//  Return values:      name (char[]) : A valid telephone number.
E 11
I 11
//  Return values:      0 : Success
E 11
//
**********************************************************************/

D 5
int get_accountno(int *customer_accountno)
E 5
I 5
int get_account_no(int *customer_account_no)
E 5
{
    int err = 0;

    printf("Account Number: ");
D 5
    scanf("%d", customer_accountno);
E 5
I 5
    scanf("%d", customer_account_no);
E 5

    return err;
}


/**********************************************************************
//
//  Function name:      get_balance
//
//  DESCRIPTION:        Asks the user for an account balance & stores
//                      it in the customer_balance pointer parameter.
//
D 11
//  Parameters:         void
E 11
I 11
//  Parameters:         customer_balance (float *) : Where to store the
//                                                   account number
//                                                   input by the user.
E 11
//
D 11
//  Return values:      name (char[]) : A valid telephone number.
E 11
I 11
//  Return values:      0 : Success
E 11
//
**********************************************************************/

int get_balance(float *customer_balance)
{
    int err = 0;

    printf("Account Balance: ");
    scanf("%f", customer_balance);

    return err;
I 11
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
E 11
D 9
}


/**********************************************************************
//
//  Function name:      clear_input_buff
//
//  DESCRIPTION:        Clears the input buffer.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

void clear_input_buff(void)
{
    while ( getchar() != '\n' );
E 9
E 2
}
E 1
