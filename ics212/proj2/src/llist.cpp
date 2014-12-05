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
// FILE:        llist.cpp
//
// DESCRIPTION: A linked list address book implementation.
//
***********************************************************************/
#include "llist.h"


/* Public Methods */

/**********************************************************************
//
//  Method name:        llist
//
//  DESCRIPTION:        Constructor for llist. Sets default value for
//                      (persistance) filename. Initialized start to NULL.
//                      Reads default filename for records.
//
//  Parameters:         void
//
//  Return values:      Returns a new llist.
//
**********************************************************************/

llist::llist(void)
{
    this->start = NULL;
    strcpy(this->filename, ".persist");
    this->num_items = this->readfile();
}


/**********************************************************************
//
//  Method name:        llist
//
//  DESCRIPTION:        Constructor for llist. Same as first constructor
//                      but sets filename to give string argument.
//
//  Parameters:         filename (char[]): The name of the persistance
//                      file.
//
//  Return values:      Returns a new llist.
//
**********************************************************************/

llist::llist(char filename[])
{
    this->start = NULL;
    strcpy(this->filename, filename);
    this->num_items = this->readfile();
    return;
}


/**********************************************************************
//
//  Method name:        ~
//
//  DESCRIPTION:        Destructor. Writes the list to the persistance
//                      file, calls cleanup.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

llist::~llist(void)
{
    this->writefile();
    this->cleanup();
    return;
}


/**********************************************************************
//
//  Method name:        addRecord
//
//  DESCRIPTION:        Adds a record to the llist.
//
//  Parameters:         name (char[]): The new record's name field.
//                      address (char[]): The new record's address field.
//                      yearofbirth (int): The new record's yearofbirth field.
//                      telno (char[]): The new record's telno field.
//
//  Return values:      error
//                      0 : No error.
//                      1 : error.
//
**********************************************************************/

int llist::addRecord(char name[], char address[], int yearofbirth, char telno[])
{
    int error = 0;
    struct record **start = &(this->start);
    struct record *end;
    struct record *temp;

#ifdef DEBUG
{
    cout << "* addRecords: start=" << *start << endl;
    cout << "* addrecord: name=" << name << endl;
    cout << "* addrecord: yearofbirth=" << yearofbirth << endl;
    cout << "* addrecord: address=" << address << endl;
    cout << "* addrecord: telno=" << telno << endl;
}
#endif

    end = *start;
    if (end != NULL)
    {
        while ((*end).next != NULL)
        {
            end = (*end).next;
        }
    }

    temp = (struct record*)malloc(sizeof(struct record));

    strcpy(temp->name, name);
    strcpy(temp->address, address);
    strcpy(temp->telno, telno);
    temp->yearofbirth = yearofbirth;
    temp->next = NULL;

    if (*start == NULL)
    {
        *start = temp;
    }
    else if ((**start).next == NULL)
    {
        (*start)->next = temp;
    }
    else
    {
        end->next = temp;
    }

    ++this->num_items;

#ifdef DEBUG
    cout << "* addRecord: returning=" << error << endl;
#endif
    
    return error;
}


/**********************************************************************
//
//  Function name:      modifyRecord
//
//  DESCRIPTION:        Modify a record in the llist.
//
//  Parameters:         name (char[]): The name field of the record to
//                      to modify.
//                      field (char[]): The field to modify.
//                      update (char[]): The update to the field.
//
//  Return values:      0 : Success
//                      1 : Failure
//
**********************************************************************/

int llist::modifyRecord(char name[], char field[], char update[])
{
    short error = 0;
    struct record *current = this->start;

#ifdef DEBUG
    {
        cout << "* modifyRecord: start=" << this->start << endl;
        cout << "* modifyRecord: name=" << name << endl;
        cout << "* modifyRecord: field=" << field << endl;
        cout << "* modifyRecord: update=" << update << endl;
    }
#endif

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            if (strcmp(field, "telno") == 0)
            {
                strcpy(current->telno, update);
            }
            else if (strcmp(field, "address") == 0)
            {
                strcpy(current->address, update);
            }
        }

        current = current->next;
    }

#ifdef DEBUG
    {
        cout << "* modifyRecord: returning=" << error << endl;
    }
#endif

    return error;
}


/**********************************************************************
//
//  Method name:        printAll
//
//  DESCRIPTION:        Prints out all items in the llist.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

void llist::printAll()
{
    struct record *current;

    current = this->start;

    while (current != NULL)
    {
        this->printRec(*current);
        current = current->next;
    }
    
    return;
}


/**********************************************************************
//
//  Method name:        printRec
//
//  DESCRIPTION:        Prints a give record.
//
//  Parameters:         rec (record): An arbitrary record.
//
//  Return values:      void
//
**********************************************************************/

void llist::printRec(struct record rec)
{
    str_replace(';', rec.address, '\n');
    cout << "\n-------------------------" << endl
         << "name:" << rec.name << endl
         << "address:" << rec.address << endl
         << "yob:" << rec.yearofbirth << endl
         << "telno:" << rec.telno << endl
         << "-------------------------\n" << endl;
    str_replace('\n', rec.address, ';');
    return;
}


/**********************************************************************
//
//  Method name:        printRecord
//
//  DESCRIPTION:        Finds a specific record that matches key.
//
//  Parameters:         key (char[]): The record to search the llist for.
//
//  Return values:      int number of matches found.
//
**********************************************************************/

int llist::printRecord(char key[])
{
    short match = 0;
    struct record *current;

#ifdef DEBUG
    {
        cout << "* printRecord: key=" << key << endl;
    }
#endif

    current = this->start;
    if (current != NULL)
    {
        do
        {
            if (strcmp(current->name, key) == 0)
            {
                match++;
                printRec(*current);
            }
            current = current->next;
        }
        while (current != NULL);
    }

#ifdef DEBUG
    {
        cout << "* printRecord: returning=" << match << endl;
    }
#endif

    return match;
}



/**********************************************************************
//
//  Method name:        deleteRecord
//
//  DESCRIPTION:        Deletes a given record(s) from the llist.
//
//  Parameters:         name (record): The name field of record(s) to be
//                      deleted.
//
//  Return values:      int: number of records deleted.
//
**********************************************************************/

int llist::deleteRecord(char name[])
{
    short match = 0;            /* Match Flag */
    int tally = 0;              /* Match tally */
    struct record *last;
    struct record *current;

#ifdef DEBUG
    {
        cout << "* deleteRecord: ptr=" << this->start << endl;
        cout << "* deleteRecord: name=" << name << endl;
    }
#endif

    current = this->start;
    last = current;

    while (current != NULL)
    {
        if (strcmp(current->name, name) == 0)
        {
            match = 1;

            if (this->start == current)
            {
                this->start = current->next;
            }
            else if (last == NULL)
            {
                last = this->start;
                while (last->next != current)
                {
                    last = last->next;
                }
                last->next = last->next->next;
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
            ++tally;--this->num_items;
            free(last);
            last = NULL;
            match = 0;
        }
    }

#ifdef DEBUG
    {
        cout << "* deleteRecord: freeing last" << endl;
    }
#endif
    
    return tally;
}


/**********************************************************************
//
//  Method name:        reverse
//
//  DESCRIPTION:        Reverses the llist.
//
//  Parameters:         void
//
//  Return values:      void
//
**********************************************************************/

void llist::reverse()
{
    llist::reverse(this->start);
}


/* Private */

/**********************************************************************
//
//  Method name:        readfile
//
//  DESCRIPTION:        Reads the filename and extracts found records.
//
//  Parameters:
//
//  Return values:      int: number of records read into the llist.
//
**********************************************************************/

int llist::readfile(void)
{
    int num_read = 0;
    char entry[MAX_ENTRY] = {'\0'};
    struct record temp_record;
    FILE *persistance_file;

    if ((persistance_file = fopen(this->filename, "r")))
    {
        while ( (fgets(entry, MAX_ENTRY, persistance_file) != NULL) &&
                (entry[0] != '\0') )
        {
            temp_record = get_new_record(entry);
            this->addRecord(temp_record.name, temp_record.address,
                    temp_record.yearofbirth, temp_record.telno);
            str_clear(entry);
            ++num_read;
        }

        fclose(persistance_file);
    }

#ifdef DEBUG
{
    cout << "* readfile: returning=" << num_read << endl;
}
#endif
    
    return num_read;
}


/**********************************************************************
//
//  Method name:        writefile
//
//  DESCRIPTION:        Writes records in the llist to the filename.
//
//  Parameters:         void
//
//  Return values:      int: number of records written to the file.
//
**********************************************************************/

int llist::writefile(void)
{
    int num_written = 0;
    char yob_str[4] = {'\0'};
    struct record *current = this->start;
    FILE *persistance_file;

#ifdef DEBUG
{
    cout << "* writefile: start=" << start << endl;
    cout << "* writefile: filename=" << persist_filename << endl;
}
#endif

    if ((persistance_file = fopen(this->filename, "w")))
    {
        while (current != NULL)
        {
            fputs(current->name, persistance_file);
            fputc('|', persistance_file);
            sprintf(yob_str, "%d|", current->yearofbirth);
            fputs(yob_str, persistance_file);
            fputs(current->address, persistance_file);
            fputc('|', persistance_file);
            fputs(current->telno, persistance_file);
            fputc('\n', persistance_file);
            ++num_written;
            current = current->next;
        }

        fclose(persistance_file);
    }

#ifdef DEBUG
{
    cout << "* writefile: returning num_written=" << num_written << endl;
}
#endif
    
    return num_written;
}


/**********************************************************************
//
//  Method name:        reverse
//
//  DESCRIPTION:        Performs the llist reversal.
//
//  Parameters:         rec (record *): A pointer to an llist item.
//
//  Return values:      record * NULL not used.
//
**********************************************************************/

record *llist::reverse(record *rec)
{
    if (rec != NULL)
    {
        if (rec->next == NULL)
        {
            this->start = rec;
        }
        else
        {
            this->reverse(rec->next);
            rec->next->next = rec;
            rec->next = NULL;
        }
    }
    return NULL;
}


/**********************************************************************
//
//  Method name:        cleanup
//
//  DESCRIPTION:        Traverses the linked list and frees list items.
//
//  Parameters:         void
//
//  Return values:      void
//                      
**********************************************************************/

void llist::cleanup()
{
    struct record *current = this->start;

#ifdef DEBUG
    {
        cout << "* cleanup: start=" << start << endl;
    }
#endif
    
    while (start != NULL)
    {
        start = current->next;
        free(current);
        current = start;
    }

#ifdef DEBUG
    {
        cout << "* cleanup: returning=" << start << endl;
    }
#endif

    return;
}


/**********************************************************************
//
//  Method name:        operator<<
//
//  DESCRIPTION:        Overloading of the << operator to perform a
//                      toString operation with cout and llist opperands.
//
//  Parameters:         os (ostream&): A referance to an ostream object.
//                      ll (llist &): A referance to an llist object.
//
//  Return values:      ostream&
//
**********************************************************************/

std::ostream& operator<<(std::ostream &os, const llist &ll)
{
    record *tmp = ll.start;
    while (tmp != NULL)
    {
        str_replace(';', tmp->address, '\n');
        os << "\n-------------------------" << endl;
        os << tmp->name << endl;
        os << tmp->address << endl;
        os << tmp->yearofbirth << endl;
        os << tmp->telno << endl;
        os << "-------------------------\n" << endl;
        str_replace('\n', tmp->address, ';');
        tmp = tmp->next;
    }
    os << flush;
    return os;
}
