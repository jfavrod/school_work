h49685
s 00045/00019/00203
d D 1.14 14/10/04 20:05:10 favrod 14 13
c Removed unused account_str variable; Changed record to account where present;
c Added debugging statements and comments/documentation.
e
s 00005/00005/00217
d D 1.13 14/10/04 11:31:05 favrod 13 12
c Edited debug statement
e
s 00005/00006/00217
d D 1.12 14/10/03 23:41:57 favrod 12 11
c Adding parsed entries to the acct_array (in readfile); edited debuging statements.
e
s 00006/00063/00217
d D 1.11 14/10/03 18:29:24 favrod 11 10
c Moved common functions to helpers.c
e
s 00009/00005/00271
d D 1.10 14/10/03 12:58:32 favrod 10 9
c Added debug.
e
s 00003/00000/00273
d D 1.9 14/10/03 12:40:21 favrod 9 8
c Now closing files after use.
e
s 00000/00001/00273
d D 1.8 14/10/03 10:21:10 favrod 8 7
c Minor edits.
e
s 00000/00002/00274
d D 1.7 14/10/03 10:15:58 favrod 7 6
c Removed some whitespace.
e
s 00001/00000/00275
d D 1.6 14/10/03 10:09:01 favrod 6 5
c Added necessary include for atoX functions.
e
s 00167/00015/00108
d D 1.5 14/10/03 10:02:35 favrod 5 4
c It looks like we have a first draft
e
s 00018/00005/00105
d D 1.4 14/10/02 07:57:02 favrod 4 3
c writefile first working version; writes a string rep of an acct struct.
e
s 00031/00005/00079
d D 1.3 14/10/01 22:53:41 jason 3 2
c Begin writing the writefile function.
e
s 00001/00000/00083
d D 1.2 14/10/01 20:44:31 favrod 2 1
c 
e
s 00083/00000/00000
d D 1.1 14/10/01 17:05:16 favrod 1 0
c date and time created 14/10/01 17:05:16 by favrod
e
u
U
f e 0
t
T
I 1
/**********************************************************************
//
// NAME:        Jason Favrod
//
D 14
// HOMEWORK:
E 14
I 14
// HOMEWORK:    5
E 14
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
D 14
// DATE:
E 14
I 14
// DATE:        4 Oct 2014
E 14
//
D 14
// FILE:
E 14
I 14
// FILE:        fileio.c
E 14
//
D 14
// DESCRIPTION:
E 14
I 14
// DESCRIPTION: Functions for reading and writing array of account
//              structures from and to files.
E 14
//
***********************************************************************/

#include <stdio.h>
I 2
#include <errno.h>
I 5
#include <string.h>
I 6
#include <stdlib.h>
E 6
E 5
E 2
#include "account.h"
I 11
#include "helpers.h"
E 11

I 3
struct account_str {
    char name[MAX_NAME];
    char account_no[MAX_ACCT_NO];
    char balance[MAX_BAL];
};

I 10
extern int debug;

E 10
D 5
struct account_str parse_record(struct account acct);
E 5
I 5
D 14
struct account_str record_toString(struct account acct);
E 14
I 14
struct account_str account_toString(struct account acct);
E 14
D 11
int clear_string(char str[]);
E 11
struct account parse_entry(char entry[]);
D 11
int str_replace(char needle, char haystack[], char replace);
E 11
E 5

E 3

/**********************************************************************
//
D 5
//  Function name:
E 5
I 5
//  Function name:      readfile
E 5
//
D 5
//  DESCRIPTION:
E 5
I 5
D 14
//  DESCRIPTION:        
E 14
I 14
//  DESCRIPTION:        reads accounts from a formatted file.
E 14
E 5
//
D 14
//  Parameters:         name (type) : Description.
E 14
I 14
//  Parameters:         acct_array (account[]) : An array that holds
//                                               the accounts read from
//                                               the file.
//                      num_customers (int *) : Points to a location
//                                              where the number of
//                                              accounts found in the
//                                              file is stored.
//                      acct_db_file (char []) : the name of the
//                                               persistance file.
E 14
//
D 14
//  Return values:
E 14
I 14
//  Return values:      0 : Success.
//                      1 : Could not open file.
//                      61 : Data in file not valid.
E 14
//
**********************************************************************/

D 3
int readfile(struct account acct_array[], int *num_customers, char filename[])
E 3
I 3
int readfile(struct account acct_array[], int *num_customers, char acct_db_file[])
E 3
{
    int err = 0;
D 3
    FILE* fp;
E 3
I 3
    FILE* accountsDB;
E 3
    
D 3
    if ( (fp = fopen(filename, "r")) )
E 3
I 3
    if ( (accountsDB = fopen(acct_db_file, "r")) )
E 3
        ;
    else
        err = 1;

    if (!err)
    {
        char c;
I 5
        char entry[MAX_ENTRY] = {'\0'};
E 5
        int char_count = 0;
D 5
        int line_count = 0;
E 5
I 5
D 14
        int record_count = 0;
        struct account_str acct_str;
E 14
I 14
        int account_count = 0;
E 14
E 5

D 3
        while ((c = fgetc(fp)) != EOF)
E 3
I 3
        while ((c = fgetc(accountsDB)) != EOF)
E 3
        {
D 5
            if (c != '\n')
                ++char_count;
            else 
                ++line_count;
E 5
I 5
            ++char_count;
            entry[strlen(entry)] = c;
            if (c == '\n')
            {
D 12
                ++record_count;
                parse_entry(entry);
E 12
I 12
D 14
                acct_array[record_count++] = parse_entry(entry);
E 14
I 14
                acct_array[account_count++] = parse_entry(entry);
E 14
E 12
                clear_string(entry);
            }
E 5
        }
        
D 5
        if (char_count + line_count == 0)
E 5
I 5
D 14
        if (char_count + record_count == 0)
E 14
I 14
        if (char_count + account_count == 0)
E 14
E 5
            err = 61;
I 5
        else
D 14
            *num_customers = record_count;
E 14
I 14
            *num_customers = account_count;
E 14
E 5
    }
I 9
    
    fclose(accountsDB);
E 9
    return err;
}


/**********************************************************************
//
D 5
//  Function name:
E 5
I 5
//  Function name:      writefile
E 5
//
D 5
//  DESCRIPTION:
E 5
I 5
//  DESCRIPTION:        Writes the bankone array to a file.
E 5
//
D 14
//  Parameters:         name (type) : Description.
E 14
I 14
//  Parameters:         bankone (account[]) : An array of accounts to
//                                            write to the persistance
//                                            file.
//                      num_customers (int) : number of accounts in the
//                                            bankone array.
//                      acct_db_filename    : the persistance file.
E 14
//
D 14
//  Return values:
E 14
I 14
//  Return values:      0 : Success
E 14
//
**********************************************************************/

D 3
int writefile(struct account acct_array[], int num_customers, char filename[])
E 3
I 3
int writefile(struct account bankone[], int num_customers, char acct_db_filename[])
E 3
{
    int err = 0;
I 4
    int counter = 0;
E 4
I 3
    FILE *acct_db_file;
I 4
    struct account_str acct_str;
E 4

    acct_db_file = fopen(acct_db_filename, "w"); 
D 4
    char ts[] = "Test string";
E 4

D 4
    fputs(ts, acct_db_file);
    parse_record(bankone[0]);
E 4
I 4
    for (counter = 0; counter < num_customers; counter++)
    {
        /* get a string version of the account */
D 5
        acct_str = parse_record(bankone[counter]);
E 5
I 5
D 14
        acct_str = record_toString(bankone[counter]);
E 14
I 14
        acct_str = account_toString(bankone[counter]);
E 14
E 5
E 4
E 3

D 4
    return 0;
E 4
I 4
D 10
        printf("Writing: %s\n", acct_str.name);
E 10
I 10
D 12
        if (debug) printf("Writing: %s\n", acct_str.name);
E 12
I 12
D 13
        if (debug) printf("writefile: writing=%s\n", acct_str.name);
E 13
I 13
        if (debug) printf("* writefile: writing=%s\n", acct_str.name);
E 13
E 12
E 10
        fprintf(acct_db_file, "%s", acct_str.name);
D 5
        fprintf(acct_db_file, "%s", " ");
E 5
I 5
        fprintf(acct_db_file, "%s", "|");
E 5
D 10
        printf("Writing: %s\n", acct_str.account_no);
E 10
I 10

D 12
        if (debug) printf("Writing: %s\n", acct_str.account_no);
E 12
I 12
D 13
        if (debug) printf("writefile: writing=%s\n", acct_str.account_no);
E 13
I 13
        if (debug) printf("* writefile: writing=%s\n", acct_str.account_no);
E 13
E 12
E 10
        fprintf(acct_db_file, "%s", acct_str.account_no);
D 5
        fprintf(acct_db_file, "%s", " ");
E 5
I 5
        fprintf(acct_db_file, "%s", "|");
E 5
D 10
        printf("Writing: %s\n", acct_str.balance);
E 10
I 10

D 12
        if (debug) printf("Writing: %s\n", acct_str.balance);
E 12
I 12
D 13
        if (debug) printf("writefile: writing=%s\n", acct_str.balance);
E 13
I 13
        if (debug) printf("* writefile: writing=%s\n", acct_str.balance);
E 13
E 12
E 10
        fprintf(acct_db_file, "%s", acct_str.balance);
        fprintf(acct_db_file, "%s", "\n");
    }

I 9
    fclose(acct_db_file);
E 9
    return err;
E 4
I 3
}

D 5
struct account_str parse_record(struct account acct)
E 5
I 5

/**********************************************************************
//
//  Function name:      parse_entry
//
//  DESCRIPTION:        Takes a line from the persistance file and
//                      returns a struct account of the data.
//
D 14
//  Parameters:         name (type) : Description.
E 14
I 14
//  Parameters:         entry (char[]) : An entry from the persistance
//                                       file.
E 14
//
//  Return values:      struct account : An account based on the fields
//                                       stored in the persistance file.
//                      NULL : Null pointer on failure.
//
**********************************************************************/

struct account parse_entry(char entry[])
E 5
{
I 5
D 10
    printf("parse_entry: entry=%s\n", entry);
E 10
I 10
D 13
    if (debug) printf("parse_entry: entry=%s\n", entry);
E 13
I 13
    if (debug) printf("* parse_entry: entry=%s\n", entry);
E 13
E 10

    struct account new_account;
    int num_fields = 3;
    enum {name, account_no, balance};
    int current_field = name;
    char tmp_str[MAX_ENTRY] = {'\0'};
    int tmp_str_char = 0;
    int entry_char = 0;

    for (current_field = name; current_field < num_fields; current_field++)
    {
D 11
        /* for each field, grab the chars until the delimiting char then handle the string accourdingly */
E 11
I 11
        /* 
         * For each field:
         * Grab the chars until the delimiting char then handle the
         * string accourdingly.
         */
E 11
        while (entry_char < strlen(entry))
        {
            tmp_str[tmp_str_char] = entry[entry_char++];

            if (tmp_str[tmp_str_char] == '|' || tmp_str[tmp_str_char] == '\n')
            {
                if (str_replace('|', tmp_str, '\0'))
                    ;
                else
                    str_replace('\n', tmp_str, '\0');

D 10
                printf("the tmp_str: %s\n", tmp_str);
E 10
I 10
D 12
                if (debug) printf("the tmp_str: %s\n", tmp_str);
E 12
I 12
D 13
                if (debug) printf("parse_enrty: the tmp_str=%s\n", tmp_str);
E 13
I 13
                if (debug) printf("* parse_enrty: parsed field=%s\n", tmp_str);
E 13
E 12
E 10

                if (current_field == name)
                    strcpy(new_account.name, tmp_str);
                else if (current_field == account_no)
                    new_account.account_no = atoi(tmp_str);
                else
                    new_account.balance = (float)atof(tmp_str);

I 14
                current_field++;
E 14
                clear_string(tmp_str);
                tmp_str_char = 0;
            }
            else
            {
                tmp_str_char++;
            }
        }
D 7


E 7
    }
I 14

    if (debug)
    {
        printf("* parse_entry: new_account=\n");
        printf("* parse_entry: %s\n", new_account.name);
        printf("* parse_entry: %d\n", new_account.account_no);
        printf("* parse_entry: %f\n", new_account.balance);
    }

E 14
D 8

E 8
    return new_account;
}


/**********************************************************************
//
D 14
//  Function name:      record_toString
E 14
I 14
//  Function name:      account_toString
E 14
//
//  DESCRIPTION:        Takes a given account structure and converts
//                      its members to strings.
//
//  Parameters:         name (type) : Description.
//
//  Return values:      Number of needles found.
//
**********************************************************************/

D 14
struct account_str record_toString(struct account acct)
E 14
I 14
struct account_str account_toString(struct account acct)
E 14
{
E 5
    struct account_str acct_str;
    sprintf(acct_str.name, "%s", acct.name);
    sprintf(acct_str.account_no, "%d", acct.account_no);
    sprintf(acct_str.balance, "%f", acct.balance);
D 4
    printf("%s\n", acct_str.balance);
E 4

    return acct_str;
I 5
D 11
}


/**********************************************************************
//
//  Function name:      clear_string
//
//  DESCRIPTION:        Starting at the beginning of the given string
//                      sets all characters to null, until the first
//                      null character is encountered.
//
//  Parameters:         str (char[]) : Any properly formated c string.
//
//  Return values:      0 : Success
//
**********************************************************************/

int clear_string(char str[])
{
    int err = 0;
    int i;
    int str_length = strlen(str);

    for(i = 0; i <= str_length; str[i++] = '\0')
        ; /* clear the string contents */

    return err;
}


/**********************************************************************
//
//  Function name:      str_replace
//
//  DESCRIPTION:        Replaces all occurrences of the needle char in
//                      the haystack string with the replace char.
//
//  Parameters:         name (type) : Description.
//
//  Return values:      Number of needles found.
//
**********************************************************************/

int str_replace(char needle, char haystack[], char replace)
{
    int i = 0;
    int matches = 0;

    while (haystack[i] != '\0')
    {
        if (haystack[i] == needle)
        {
            haystack[i] = replace;
            matches++;
        }

        i++;
    }
    
    return matches;
E 11
E 5
E 3
}
E 1
