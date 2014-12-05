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
void printRec(struct record rec);

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

int addRecord(struct record **start, char name[], int yearofbirth, char address[], char telno[])
{
    int error = 0;
    struct record *end;
    struct record *temp;

    if (debug)
    {
        printf("addRecords: start=%p\n", *start);
        printf("addrecord: name=%s\n", name);
        printf("addrecord: yearofbirth=%d\n", yearofbirth);
        printf("addrecord: address=\n%s", address);
        printf("addrecord: telno=%s\n", telno);
    }

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

void printAllRecords(struct record *start)
{
    struct record *current;

    if (debug)
    {
        printf("printAllRecords: start=%p\n", start);
    }

    current = start;

    while (current != NULL)
    {
        printRec(*current);
        current = current->next;
    }
}


/*
 *
 */

void printRec(struct record rec)
{
    printf("{name:%s,\naddress:%s,\nyob:%d,\ntelno:%s,\nnext:%p}\n",
            rec.name, rec.address, rec.yearofbirth, rec.telno, rec.next);
    return;
}


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

int deleteRecord(struct record **start, char key[])
{
    int error = 0;
    short match = 0;
    struct record *last;
    struct record *current;

    if (debug)
    {
        printf("deleteRecord: ptr=%p\n", *start);
        printf("deleteRecord: key=%s\n", key);
    }

    current = *start;

    while (current != NULL)
    {
        if (strcmp(current->name, key) == 0)
        {
            match = 1;
            if (*start == current)
            {
                start = &(current->next);
            }
            else
            {
                last->next = current->next;
            }
        }
        last = current;
        current = current->next;

        if (match)
        {
            free(last);
            match = 0;
        }
    }

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
