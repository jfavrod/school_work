h39003
s 00011/00001/00469
d D 1.5 14/10/11 09:50:33 favrod 5 4
c Implemented the code for printAllRecords; Fixed assignment of start to a pointer err 
c in deleteRecord.
e
s 00029/00002/00441
d D 1.4 14/10/11 09:29:11 favrod 4 3
c Added the deleteRecord algo.
e
s 00015/00000/00428
d D 1.3 14/10/10 22:18:18 favrod 3 2
c Added printRec function.
e
s 00035/00004/00393
d D 1.2 14/10/08 17:31:18 favrod 2 1
c Beginning to implement addrecord function
e
s 00397/00000/00000
d D 1.1 14/10/08 15:43:24 favrod 1 0
c date and time created 14/10/08 15:43:24 by favrod
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
// HOMEWORK:    3 Part B
//
// CLASS:       ICS 212
//
// INSTRUCTOR:  Ravi Narayan
//
// DATE:        17 Sept 2014
//
// FILE:        actions.c
//
// DESCRIPTION: Holds the functions that perform the actions initiated
//              by the UI.
//
***********************************************************************/
#include "actions.h"
I 3
void printRec(struct record rec);
E 3

enum validation_codes {
    name_vc,
    yob_vc,
    telno_vc,
    addr_vc,
    addr0=addr_vc*10,
    addr1=(addr_vc*10)+1,
    addr2=(addr_vc*10)+2,
};


/**********************************************************************
//
//  Function name:      addrecord
//
//  DESCRIPTION:        Adds a record to the address book 'database.'
//
//  Parameters:         struct record **
//                      name (char[])
//                      yearofbirth (int)
//                      address (char[])
//                      telno (char[])
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

D 2
int addRecord(struct record **ptr, char name[], int yearofbirth, char address[], char telno[])
E 2
I 2
int addRecord(struct record **start, char name[], int yearofbirth, char address[], char telno[])
E 2
{
    int error = 0;
I 2
    struct record *end;
    struct record *temp;
E 2

    if (debug)
    {
D 2
        printf("addRecords: ptr=%p\n", ptr);
E 2
I 2
        printf("addRecords: start=%p\n", *start);
E 2
        printf("addrecord: name=%s\n", name);
        printf("addrecord: yearofbirth=%d\n", yearofbirth);
        printf("addrecord: address=\n%s", address);
        printf("addrecord: telno=%s\n", telno);
    }

I 2
    end = *start;
    if (end != NULL)
    {
        while ((*end).next != NULL)
        {
            end = (*end).next;
        }
    }

    temp = (struct record*)malloc(sizeof(struct record));
    strcpy((*temp).name, name);
    (*temp).yearofbirth = yearofbirth;
    strcpy((*temp).address, address);
    strcpy((*temp).telno, telno);
    (*temp).next = NULL;

    if (*start == NULL)
    {
        *start = temp;
    }
    else if ((**start).next == NULL)
    {
        (**start).next = temp;
    }
    else
    {
        (*end).next = temp;
    }

E 2
    return error;
}


/**********************************************************************
//
//  Function name:      modifyRecord
//
//  DESCRIPTION:        Modify a record from the 'database.'
//
//  Parameters:         struct record *
//                      key (char [])
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int modifyRecord(struct record *ptr, char key[], char field[], char update[])
{
    int error = 0;

    if (debug)
    {
        printf("modifyRecords: ptr=%p\n", ptr);
        printf("modifyRecord: key=%s\n", key);
    }

    return error;
}


/**********************************************************************
//
//  Function name:      printRecord
//
//  DESCRIPTION:        Prints a record from the 'database.'
//
//  Parameters:         struct record *
//                      key (char [])
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int printRecord(struct record *ptr, char key[])
{
    int error = 0;

    if (debug)
    {
        printf("printRecord: ptr=%p\n", ptr);
        printf("printRecord: key=%s\n", key);
    }

    return error;
}



/**********************************************************************
//
//  Function name:      printAllRecords
//
//  DESCRIPTION:        Prints all records from the 'database.'
//
//  Parameters:         struct record *
//
//  Return values:      void
//
**********************************************************************/

D 2
void printAllRecords(struct record *ptr)
E 2
I 2
void printAllRecords(struct record *start)
E 2
{
I 5
    struct record *current;

E 5
    if (debug)
    {
D 2
        printf("printAllRecords: ptr=%p\n", ptr);
E 2
I 2
        printf("printAllRecords: start=%p\n", start);
E 2
    }
I 5

    current = start;

    while (current != NULL)
    {
        printRec(*current);
        current = current->next;
    }
E 5
}


I 3
/*
 *
 */

void printRec(struct record rec)
{
    printf("{name:%s,\naddress:%s,\nyob:%d,\ntelno:%s,\nnext:%p}\n",
            rec.name, rec.address, rec.yearofbirth, rec.telno, rec.next);
    return;
}


E 3
/**********************************************************************
//
//  Function name:      deleteRecord
//
//  DESCRIPTION:        Deletes a records from the 'database.'
//
//  Parameters:         struct record *
//                      key (char[]) : The name of the record to delete.
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

D 4
int deleteRecord(struct record **ptr, char key[])
E 4
I 4
int deleteRecord(struct record **start, char key[])
E 4
{
    int error = 0;
I 4
    short match = 0;
    struct record *last;
    struct record *current;
E 4

    if (debug)
    {
D 4
        printf("deleteRecord: ptr=%p\n", ptr);
E 4
I 4
        printf("deleteRecord: ptr=%p\n", *start);
E 4
        printf("deleteRecord: key=%s\n", key);
    }

I 4
    current = *start;
E 4
I 3

I 4
    while (current != NULL)
    {
        if (strcmp(current->name, key) == 0)
        {
            match = 1;
            if (*start == current)
            {
D 5
                start = current->next;
E 5
I 5
                start = &(current->next);
E 5
            }
            else
            {
                last->next = current->next;
            }
        }
        last = current;
        current = current->next;
E 4

I 4
        if (match)
        {
            free(last);
            match = 0;
        }
    }

E 4
E 3
    return error;
}


/**********************************************************************
//
//  Function name:      get_name
//
//  DESCRIPTION:        Asks the user for a name and stores it in the
//                      variable pointed to by the given pointer.
//
//  Parameters:         void
//
//  Return values:      name (char[]) :
//
**********************************************************************/

char *get_name(void)
{
    static char name[MAX_NAME];
    int validation_code = name_vc;
    int invalid = 0;
    int i = 0;

    do
    {
        if (invalid)
        {
            printf("The name you entered was invalid\n");
            invalid = 0;
        }

        printf("Name: ");
        /* eat leading spaces */
        while (isspace(name[i] = getchar()) || i++); 
        for (i = i; ((name[i++] = getchar()) != '\n') && i < MAX_NAME;)
            ;

        name[--i] = '\0';
    }
    while((invalid = invalidate(name, validation_code)));

    if (debug) printf("get_name: name=%s\n", name);
    return name;
}


/**********************************************************************
//
//  Function name:      get_yearofbirth
//
//  DESCRIPTION:        Asks the user for a year of birth.
//
//  Parameters:         void
//
//  Return values:      yob (int) : A valid year of birth. 
//
**********************************************************************/

int get_yearofbirth(void)
{
    int validation_code = yob_vc;
    int invalid = 0;
    int yob;
    char yob_str[5];

    do
    {
        if (invalid)
        {
            printf("The year of birth you entered was invalid\n");
            invalid = 0;
        }

        printf("Year of Birth: ");
        scanf("%d", &yob);
        sprintf(yob_str, "%d", yob);
        clear_input_buff();

    }
    while ((invalid = invalidate(yob_str, validation_code)));

    if (debug) printf("get_yearofbirth: yob=%d\n", yob);
    return yob;
}


/**********************************************************************
//
//  Function name:      get_address
//
//  DESCRIPTION:        Asks the user for an address and returns it.
//
//  Parameters:         void
//
//  Return values:      address (char[]) : A valid address.
//
**********************************************************************/

char *get_address(void)
{
    static char addr[MAX_ADDR] = {'\0'};
    int validation_code = addr_vc * 10;
    char *question[PARTS_OF_ADDR];
    question[0] = "Street Address: ";
    question[1] = "Address Line2: ";
    question[2] = "City State, Zip: ";
    int question_asked = 0;                          
    int pos_in_str;

    while (question_asked < PARTS_OF_ADDR && strlen(addr) < MAX_ADDR)
    {
        char answer[MAX_ADDR_LINE] = {'\0'};

        printf("%s", question[question_asked]);
        for (pos_in_str = 0; (answer[pos_in_str++] = getchar()) != '\n' && pos_in_str < MAX_ADDR_LINE;)
            ;

        if (debug) printf("get_address: chars=%d answer=%s", pos_in_str, answer);
        
        if (invalidate(answer, validation_code + question_asked))
        {
            printf("invalid input for: %s\n", question[question_asked]);
            pos_in_str = 0;
        }
        else
        {
            strncat(addr, answer, pos_in_str);
            question_asked++;
        }
    }

    if (debug) printf("get_address: addr=\n%s", addr);
    return addr;
}


/**********************************************************************
//
//  Function name:      get_telno
//
//  DESCRIPTION:        Asks the user for a tel number and returns it.
//
//  Parameters:         void
//
//  Return values:      name (char[]) : A valid telephone number.
//
**********************************************************************/

char *get_telno(void)
{
    static char telno[MAX_TELNO] = {'\0'};
    int validate_code = telno_vc;
    int invalid = 0;
    int i = 0;

    do 
    {
        if (invalid)
        {
            printf("The telephone number you entered was invalid.\n");
            invalid = 0;
        }

        printf("Telephone Number: ");
        while (isspace(telno[i] = getchar()) || i++)
            ; /* eat leading whitespace */
        for (i = i; (telno[i++] = getchar()) != '\n' && i < MAX_TELNO;)
            ;
        telno[--i] = '\0';
    }
    while ((invalid = invalidate(telno, validate_code)));

    if (debug) printf("get_telno: telno=%s\n", telno);
    return telno;
}


/**********************************************************************
//
//  Function name:      invalidate
//
//  DESCRIPTION:        Used to validate 'database' input.
//
//  Parameters:         entry (char *) : An entry to validate.
//                      code (int)     : Tells the invalidate function
//                                       how to validate.
//
//  Return values:      name (char[]) : A valid telephone number.
//
//  TODO:               Break this up into separate functions.
//
**********************************************************************/

int invalidate(char *entry, int code)
{
    int invalid = 0;
    if (debug)
    {
        printf("invalidate: entry=%s\n", entry);
        printf("invalidate: code=%d\n", code);
    }

    switch (code)
    {
    case name_vc:
    break;

    case yob_vc:
        invalid = !inrange(atoi(entry), MIN_YEAR, MAX_YEAR);
    break;

    case telno_vc:
    break;
    
    case addr0:
        invalid = (strlen(entry) == 1);
    break;

    case addr1:
    break;

    case addr2:
        invalid = (strlen(entry) == 1);
    break;
    }

    if (debug) printf("invalidate: %s\n", invalid? "invalid" : "valid");
    return invalid;
}
E 1
