#include <iostream>
#include <string>
#include "Contactdetails.h"
#include "menu.h"
#pragma once


using namespace std;


//prototypes

void printline(char, int);
bool name_valid(string);
bool mob_valid(string);


class contact : public Menu
{
    string name;
    string mob;
    Address address;
    Gender gender;
    Email email;
public:
    //Initialize the contact by a default value
    contact() : name(""), mob(""), address(Address()), email(Email()), gender(Gender()) {}

    // Shows all contacts
    bool show();

    //Search
    bool show(string search_term);
    
    //Checks whether the name exists or not
    bool name_exists(string tname);

    //The contact object is initialized by valid values
    bool add(string new_name, string new_mob, string new_address, string new_email, string new_gender);

    //Edits the contact details
    bool edit(string);

    //Sets the contact details to default values
    //That is, the contact details are thus erased
    bool erase(string new_name);
};