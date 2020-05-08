#include <iostream>
#include <string>


using namespace std;


//prototypes

void printline(char, int);
bool name_valid(string);
bool mob_valid(string);

class Address
{
private:
    string add1;

public:
    Address() {}
    Address(string address)
    {
        add1 = address;
    }

    void set_add1(string new_address)
    {
        add1 = new_address;
    }
    string get_add1()
    {
        return add1;
    }
};

class Email
{
private:
    string email1;

public:
    Email() {}
    Email(string email)
    {
        email1 = email;
    }

    void set_email1(string new_email)
    {
        email1 = new_email;
    }
    string get_email1()
    {
        return email1;
    }
};

class Gender
{
private:
    string gender1;

public:
    Gender() {}
    Gender(string gender)
    {
        gender1 = gender;
    }

    void set_gender1(string new_gender)
    {
        gender1 = new_gender;
    }
    string get_gender1()
    {
        return gender1;
    }
};

class contact
{
    string name;
    string mob;
    Address address;
    Gender gender;
    Email email;
public:
    //Initialize the contact by a default value
    contact() : name(""), mob(""), address(Address()), email(Email()), gender(Gender())
    {}

    // Shows all contacts
    bool show()
    {
        if (name != "")
        {
            cout << name << "\t" << mob << "\t" << address.get_add1() << email.get_email1() << "\t" << gender.get_gender1() << endl;

            return 1; //Indicates success
        }
        else
            return 0; //Indicates failure
    }

    //Search
    bool show(string search_term)
    {
        if (search_term == name)
        {
            cout << name << "\t" << mob << "\t" << address.get_add1() << endl;
            return 1;
        }
        else
            return 0;
    }

    //Checks whether the name exists or not
    bool name_exists(string tname)
    {
        if (tname == name)
            return 1;
        else
            return 0;
    }

    //The contact object is initialized by valid values
    bool add(string new_name, string new_mob, string new_address, string new_email, string new_gender)
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

    //Edits the contact details
    bool edit(string);

    //Sets the contact details to default values
    //That is, the contact details are thus erased
    bool erase(string new_name)
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
};


//Edits the contact
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
        cout << "Enter new address"; cin >> new_address;
        cout << "Enter new address"; cin >> new_email;
        cout << "Enter gender"; cin >> new_gender;

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
#pragma once
