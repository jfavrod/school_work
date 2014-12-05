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
// FILE:        fileio.c
//
// DESCRIPTION: Functions for reading and writing array of account
//              structures from and to files.
//
***********************************************************************/

#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include "account.h"
#include "helpers.h"

struct account_str {
    char name[MAX_NAME];
    char account_no[MAX_ACCT_NO];
    char balance[MAX_BAL];
};

extern int debug;

struct account_str account_toString(struct account acct);
struct account parse_entry(char entry[]);


/**********************************************************************
//
//  Function name:      readfile
//
//  DESCRIPTION:        reads accounts from a formatted file.
//
//  Parameters:         acct_array (account[]) : An array that holds
//                                               the accounts read from
//                                               the file.
//                      num_customers (int *) : Points to a location
//                                              where the number of
//                                              accounts found in the
//                                              file is stored.
//                      acct_db_file (char []) : the name of the
//                                               persistance file.
//
//  Return values:      0 : Success.
//                      1 : Could not open file.
//                      61 : Data in file not valid.
//
**********************************************************************/

int readfile(struct account acct_array[], int *num_customers, char acct_db_file[])
{
    int err = 0;
    FILE* accountsDB;
    
    if ( (accountsDB = fopen(acct_db_file, "r")) )
        ;
    else
        err = 1;

    if (!err)
    {
        char c;
        char entry[MAX_ENTRY] = {'\0'};
        int char_count = 0;
        int account_count = 0;

        while ((c = fgetc(accountsDB)) != EOF)
        {
            ++char_count;
            entry[strlen(entry)] = c;
            if (c == '\n')
            {
                acct_array[account_count++] = parse_entry(entry);
                clear_string(entry);
            }
        }
        
        if (char_count + account_count == 0)
            err = 61;
        else
            *num_customers = account_count;
    }
    
    fclose(accountsDB);
    return err;
}


/**********************************************************************
//
//  Function name:      writefile
//
//  DESCRIPTION:        Writes the bankone array to a file.
//
//  Parameters:         bankone (account[]) : An array of accounts to
//                                            write to the persistance
//                                            file.
//                      num_customers (int) : number of accounts in the
//                                            bankone array.
//                      acct_db_filename    : the persistance file.
//
//  Return values:      0 : Success
//
**********************************************************************/

int writefile(struct account bankone[], int num_customers, char acct_db_filename[])
{
    int err = 0;
    int counter = 0;
    FILE *acct_db_file;
    struct account_str acct_str;

    acct_db_file = fopen(acct_db_filename, "w"); 

    for (counter = 0; counter < num_customers; counter++)
    {
        /* get a string version of the account */
        acct_str = account_toString(bankone[counter]);

        if (debug) printf("* writefile: writing=%s\n", acct_str.name);
        fprintf(acct_db_file, "%s", acct_str.name);
        fprintf(acct_db_file, "%s", "|");

        if (debug) printf("* writefile: writing=%s\n", acct_str.account_no);
        fprintf(acct_db_file, "%s", acct_str.account_no);
        fprintf(acct_db_file, "%s", "|");

        if (debug) printf("* writefile: writing=%s\n", acct_str.balance);
        fprintf(acct_db_file, "%s", acct_str.balance);
        fprintf(acct_db_file, "%s", "\n");
    }

    fclose(acct_db_file);
    return err;
}


/**********************************************************************
//
//  Function name:      parse_entry
//
//  DESCRIPTION:        Takes a line from the persistance file and
//                      returns a struct account of the data.
//
//  Parameters:         entry (char[]) : An entry from the persistance
//                                       file.
//
//  Return values:      struct account : An account based on the fields
//                                       stored in the persistance file.
//                      NULL : Null pointer on failure.
//
**********************************************************************/

struct account parse_entry(char entry[])
{
    if (debug) printf("* parse_entry: entry=%s\n", entry);

    struct account new_account;
    int num_fields = 3;
    enum {name, account_no, balance};
    int current_field = name;
    char tmp_str[MAX_ENTRY] = {'\0'};
    int tmp_str_char = 0;
    int entry_char = 0;

    for (current_field = name; current_field < num_fields; current_field++)
    {
        /* 
         * For each field:
         * Grab the chars until the delimiting char then handle the
         * string accourdingly.
         */
        while (entry_char < strlen(entry))
        {
            tmp_str[tmp_str_char] = entry[entry_char++];

            if (tmp_str[tmp_str_char] == '|' || tmp_str[tmp_str_char] == '\n')
            {
                if (str_replace('|', tmp_str, '\0'))
                    ;
                else
                    str_replace('\n', tmp_str, '\0');

                if (debug) printf("* parse_enrty: parsed field=%s\n", tmp_str);

                if (current_field == name)
                    strcpy(new_account.name, tmp_str);
                else if (current_field == account_no)
                    new_account.account_no = atoi(tmp_str);
                else
                    new_account.balance = (float)atof(tmp_str);

                current_field++;
                clear_string(tmp_str);
                tmp_str_char = 0;
            }
            else
            {
                tmp_str_char++;
            }
        }
    }

    if (debug)
    {
        printf("* parse_entry: new_account=\n");
        printf("* parse_entry: %s\n", new_account.name);
        printf("* parse_entry: %d\n", new_account.account_no);
        printf("* parse_entry: %f\n", new_account.balance);
    }

    return new_account;
}


/**********************************************************************
//
//  Function name:      account_toString
//
//  DESCRIPTION:        Takes a given account structure and converts
//                      its members to strings.
//
//  Parameters:         name (type) : Description.
//
//  Return values:      Number of needles found.
//
**********************************************************************/

struct account_str account_toString(struct account acct)
{
    struct account_str acct_str;
    sprintf(acct_str.name, "%s", acct.name);
    sprintf(acct_str.account_no, "%d", acct.account_no);
    sprintf(acct_str.balance, "%f", acct.balance);

    return acct_str;
}
