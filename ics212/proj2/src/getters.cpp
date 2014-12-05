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
// FILE:        getters.c
//
// DESCRIPTION: Provides all the getting functionallity for the addrBook
//              program.
//
***********************************************************************/
#include "getters"


/**********************************************************************
//
//  Function name:      get_name
//
//  DESCRIPTION:        Asks the user for a name and stores it in the
//                      variable pointed to by the given pointer.
//
//  Parameters:         void
//
//  Return values:      name (char[]) : The name entered by the user
//                                      without the newline character.
//
**********************************************************************/

char *get_name(void)
{
    short valid = 0;
    static char name[MAX_NAME] = {'\0'};

    do
    {
        str_clear(name);
        valid = 1;

        cout << "Name (24 char max): ";
        cin.getline(name, MAX_NAME);

        if (!strlen(name))
        {
            cout << "Name can not be empty" << endl;
            valid = 0;
        }
        else if (cin.fail() || cin.eof())
        {
            cout << "The name you entered was invalid." << endl;
            valid = 0;
            cin.clear();
            cin.ignore(MAX_NAME, '\n');
        }
    }
    while(!valid);

#ifdef DEBUG
    {
        cout << "* get_name: returning=" << name << endl;
    }
#endif

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
    short valid = 0;
    int yob;
    char yob_str[5] = {'\0'};

    do
    {
        str_clear(yob_str);

        cout << "Year of Birth [1900 - 2014]: ";
        cin.getline(yob_str, 5);
        yob = atoi(yob_str);

        if (!strlen(yob_str))
        {
            cout << "Year of birth required." << endl;
        }
        else if (cin.eof() || cin.fail() || !inrange(yob, MIN_YEAR, MAX_YEAR))
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "The year of birth you entered was invalid" << endl;
        }
        else
        {
            valid = 1;
        }
    }
    while (!valid);

#ifdef DEBUG
    {
        cout << "* get_yearofbirth: returning=" << yob << endl;
    }
#endif
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
    static char addr[MAX_ADDR] = "";
    char tmpstr[MAX_ADDR] = "";
    short valid = 0;
    short count = 0;

    str_clear(addr);
    cout << "Enter address then hit enter twice." << endl;

    while (count < 1 || !valid)
    {
        cin.getline(tmpstr, MAX_ADDR, '\n');

        if (strlen(tmpstr) == 0) 
        {
            ++count;
        }
        else
        { 
            strcat(addr, tmpstr);
            strcat(addr, "\n");
            str_clear(tmpstr);
        }

        if (strlen(addr) && count > 0)
        {
            valid = 1;
        }
        else if (!strlen(addr) && count > 0)
        {
            cout << "Address required. Please enter address." << endl;
            --count;
        }
    }

    memset(&(addr[strlen(addr)-1]), '\0', 1);

#ifdef DEBUG
    {
        cout << "* get_address: returning=" << addr << endl;
    }
#endif
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
    short valid = 0;
    static char telno[MAX_TELNO] = {'\0'};

    do 
    {
        str_clear(telno);

        cout << "Telephone Number: ";
        cin.getline(telno, MAX_TELNO, '\n');

        if (!strlen(telno))
        {
            cout << "Telephone number required" << endl;
        }
        else if (cin.eof() || cin.fail())
        {
            cout << "The telephone number you entered was invalid." << endl;
        }
        else 
        {
            valid = 1;
        }
    }
    while (!valid);

#ifdef DEBUG
    {
        cout << "* get_telno: telno=" << telno << endl;
    }
#endif
    return telno;
}


/**********************************************************************
//
//  Function name:      get_field
//
//  DESCRIPTION:        Asks the user to select a record field, then
//                      returns that field.
//
//  Parameters:         void
//
//  Return values:      field (char[]) : The user chosen field.
//
**********************************************************************/

char *get_field(void)
{
    const short num_fields = 2;
    short selected = -1;
    short valid = 0;
    short count = 0;
    char *field[num_fields] = {"address", "telno"};
    static char got_field[8] = {'\0'};

    do 
    {
        str_clear(got_field);

        cout << "Please select a field to modify 0-" << (num_fields-1) << endl;
        for (count = 0; count < num_fields; count++)
        {
            cout << "[" << count << "]" << field[count] << endl;
        }

        selected = cin.peek() - 48;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (inrange(selected, 0, num_fields - 1))
        {
            valid = 1;
        }
        else
        {
            cout << "Invalid selection." << endl;
        }
    } 
    while (!valid);

    strcpy(got_field, field[selected]);
#ifdef DEBUG
    {
        cout << "* get_field: returning=" << got_field << endl;
    }
#endif
    return got_field;
}


/**********************************************************************
//
//  Function name:      get_update
//
//  DESCRIPTION:        Asks the user the pr
//
//  Parameters:         field (char[]) : The type of field to get an
//                      update.
//
//  Return values:      
//
**********************************************************************/

char *get_update(char field[])
{
#ifdef DEBUG
    {
        cout << "* get_update: (arg) field=" << field << endl;
    }
#endif

    static char update[80] = {'\0'};
    str_clear(update);

    if (strcmp(field, "address") == 0)
    {
        strcpy(update, get_address());
    }
    else if (strcmp(field, "telno") == 0)
    {
        strcpy(update, get_telno());
    }

#ifdef DEBUG
    {
        cout << "* get_update: returning: " << update << endl;
    }
#endif
    
    return update;
}


/**********************************************************************
//
//  Function name:      get_new_record
//
//  DESCRIPTION:        Returns a new record based on the input string
//                      (persist_file_entry).
//
//  Parameters:         persist_file_entry (char[]) : A line from the
//                      persistance file.
//
//  Return values:      new_rec (struct record) : Success
//
**********************************************************************/

struct record get_new_record(char persist_file_entry[])
{
    struct record new_record;
    short current_field = 0;
    short i = 0;
    short j = 0;
    char temp_str[80] = {'\0'};
    
    do
    {
        if ((persist_file_entry[i] != '|') && (persist_file_entry[i] != '\n'))
        {
            temp_str[j++] = persist_file_entry[i];
        }
        else
        {
            switch (current_field)
            {
                case (NAME):
                    strcpy(new_record.name, temp_str);
                break;
                case (YEAROFBIRTH):
                    new_record.yearofbirth = atoi(temp_str);
                break;
                case (ADDRESS):
                    strcpy(new_record.address, temp_str);
                break;
                case (TELNO):
                    strcpy(new_record.telno, temp_str);
                break;
            }

            j = 0;
            str_clear(temp_str);
            ++current_field;
        }
    }
    while ((persist_file_entry[i++] != '\n'));

    return new_record;
}
