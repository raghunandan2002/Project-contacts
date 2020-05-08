#include <iostream>
#include <string>
#include "header.h"


using namespace std;


int main()
{
    contact person[100];

    string temp_name, temp_mob, temp_address, temp_email, temp_gender;

    int choice, i, counter;
    bool flag;
    bool cancel_flag;

    cout << "* PHONEBOOK *" << endl;


    do
    {
        cout << "\n\n\n";
        printline('-', 20);
        cout << "0. Show contacts" << endl
            << "1. Add Contact" << endl
            << "2. Edit Contact" << endl
            << "3. Delete Contact" << endl
            << "4. Search" << endl
            << "5. Quit" << endl << endl
            << "Your choice...";
        cin >> choice;

        system("clear");
        printline('-', 20);
        cancel_flag = 0;
        flag = 0;
        counter = 0;

        switch (choice)
        {
        case 0:
            cout << "Showing Contacts" << endl;
            printline('-', 20);

            for (i = 0; i < 100; i++)
                if (person[i].show())
                    flag = 1;

            if (!flag)
                cout << "No contacts found!" << endl;
            break;

        case 1:
            cout << "Add New Contact\t\t\t\tpress $ to cancel" << endl;
            printline('-', 20);


            //Loop until correct name and mobile number are entered
            do
            {
                flag = 0;
                if (counter >= 100)
                    cout << "Try again\t\t\t\tpress $ to cancel"
                    << endl;

                cout << "Name: "; cin >> temp_name;

                //Cancel operation
                if (temp_name == "$")
                {
                    cancel_flag = 1;
                    break;
                }
                cout << "Mobile No.: "; cin >> temp_mob;

                //Cancel operation
                if (temp_mob == "$")
                {
                    cancel_flag = 1;
                    break;
                }
                cout << "Address :";
                cin >> temp_address;

                cout << "Email:";
                cin >> temp_email;

                cout << "Gender :";
                cin >> temp_gender;

                //Check whether name exists
                for (i = 0; i < 100; i++)
                    if (person[i].name_exists(temp_name))
                    {
                        cout << "The name you entered is already there"
                            "in the phonebook, enter a different name."
                            << endl;
                        flag = 1;
                        break;
                    }
                if (!flag) {
                    if (person[counter].add(temp_name, temp_mob, temp_address, temp_email, temp_gender)) {
                        counter++;
                        flag = 1;
                        cout << "Contact added successfully!" << endl;
                    }
                }

            } while (!flag);

            if (cancel_flag)
            {
                system("clear");
                break;
            }

            break;

        case 2:
            cout << "Enter a contact name to edit:"
                "\t\t\t\tpress $ to cancel\n";
            cin >> temp_name;

            //Cancel Operation
            if (temp_name == "$")
            {
                system("cls");
                break;
            }

            for (i = 0; i < 100; i++)
                if (person[i].edit(temp_name))
                {
                    cout << "Edited Successfully!" << endl;
                    flag = 1;
                    break;
                }

            if (!flag)
                cout << "Contact name not found!" << endl;
            break;

        case 3:

            if (counter <= 0)
                cout << "Try again" << endl;

            cout << "Enter a contact name to delete:"
                "\t\t\tpress $ to cancel\n";
            cin >> temp_name;

            //Cancel Operation
            if (temp_name == "$")
            {
                system("clear");
                break;
            }


            //Final Confirmation
            for (i = 0; i < 100; i++)
                if (person[i].name_exists(temp_name))
                {
                    flag = 1;
                    cout << "Are you sure you want to delete? (1/0)"
                        << endl;
                    int yes;
                    cin >> yes;
                    if (!yes)
                    {
                        system("clear");
                        cancel_flag = 1;
                        flag = 0;
                    }
                    break;
                }

            if (!flag)
                cout << "Contact name not found!" << endl;

            if (cancel_flag)
                break;

            // This code deletes the contact
            if (flag)
            {

                if (person[i].erase(temp_name))
                {
                    cout << "Deleted successfully!" << endl;
                    counter--;
                    break;
                }
            }


            break;

        case 4:

            if (counter <= 0)
                cout << "Try again" << endl;

            cout << "Search a name: \t\t\t\tpress $ to cancel\n";
            cin >> temp_name;

            //Cancel Operation
            if (temp_name == "$")
            {
                system("clear");
                break;
            }

            for (i = 0; i < 100; i++)
                if (person[i].show(temp_name))
                {
                    flag = 1;
                    break;
                }

            if (!flag)
                cout << "Contact name not found" << endl;


            break;

        case 5:
            return 0;
            break;

        }
    } while (1);


    return 0;
}

//prints a line
void printline(char ch, int size)
{
    for (int i = 0; i < size; i++)
        cout << ch;
    cout << "\n";
}


//Contact name validation
bool name_valid(string tname)
{

    if (tname.size() > 20)
    {
        cout << "Invalid Name!\nEnter a name within 20 characters!"
            << endl;
        return 0;
    }
    else if (tname == "")
    {
        cout << "Invalid Name!\nName cannot be blank!" << endl;
        return 0;
    }
    else
        return 1;
}

//mobile number validation
bool mob_valid(string tmob)
{
    if (tmob.size() > 13 || tmob.size() < 10)
    {
        cout << "Invalid mobile no.\nEnter a no."
            "between 10 and 13 digits" << endl;
        return 0;
    }
    else if (tmob == "")
    {
        cout << "Invalid mobile no.\nMobile"
            "no cannot be blank" << endl;
        return 0;
    }
    else
        return 1;
}