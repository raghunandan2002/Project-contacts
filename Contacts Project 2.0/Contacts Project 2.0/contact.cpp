#include <iostream>
#include <string>
#include "Contact.h"

using namespace std;

bool contact :: show() {

    if (name != "")
    {
        cout << name << "\t" << mob << "\t" << address.get_add1() << "\t" << email.get_email1() << "\t" << gender.get_gender1() << endl;

        return 1; //Indicates success
    }
    else
        return 0; //Indicates failure
}

bool contact :: show(string search_term)
{
    if (search_term == name)
    {
        cout << name << "\t" << mob << "\t" << address.get_add1() << "\t" << email.get_email1() << "\t" << gender.get_gender1() << endl;
        return 1;
    }
    else
        return 0;
}

bool contact :: name_exists(string tname)
{
    if (tname == name)
        return 1;
    else
        return 0;
}

bool contact :: add(string new_name, string new_mob, string new_address, string new_email, string new_gender)
{
    if (name == "")
    {
        name = new_name;
        mob = new_mob;
        address = Address(new_address);
        email = Email(new_email);
        gender = Gender(new_gender);
        return 1; // Success
    }
    else
        return 0; // Failure

}

bool contact :: erase(string new_name)
{
    if (new_name == name)
    {
        name = "";
        mob = "";
        // address = "";
        return 1;
    }
    else
        return 0;
}

bool contact::edit(string new_name)
{
    string new_mob;
    string new_address;
    string new_email;
    string new_gender;
    if (new_name == name)
    {
        cout << "Enter new name: "; cin >> new_name;
        cout << "Enter new mobile no: "; cin >> new_mob;
        cout << "Enter new address:"; cin >> new_address;
        cout << "Enter new address:"; cin >> new_email;
        cout << "Enter gender:"; cin >> new_gender;

        name = new_name;
        mob = new_mob;
        address = Address(new_address);
        email = Email(new_email);
        gender = Gender(new_gender);

        return 1;
    }
    else
        return 0;
}