#include <iostream>
#include <string>
#include "Contactdetails.h"

using namespace std;

void Address :: set_add1(string new_address)
{
    add1 = new_address;
}
string Address:: get_add1()
{

    return add1;
}

void Email :: set_email1(string new_email)
{
    email1 = new_email;
}
string Email :: get_email1()
{
    return email1;
}

void Gender :: set_gender1(string new_gender)
{
    gender1 = new_gender;
}
string Gender :: get_gender1()
{
    return gender1;
}