#include <iostream>
#include <string>
#include "menu.h"
#include "contact.h"

#pragma once

using namespace std;


//prototypes

void printline(char, int);


int Menu :: showmenu(){
    int choice;
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
    return choice;
    
}
