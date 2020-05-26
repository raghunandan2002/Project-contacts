#include <iostream>
#include <string>
#pragma once

using namespace std;

class Address {
private:
    string add1;

public:
    Address() {}
    Address(string address)
    {
        add1 = address;
    }
    void set_add1(string new_address);

    string get_add1();
};

class Email {
private:
    string email1;

public:
    Email() {}
    Email(string email)
    {
        email1 = email;
    }
    void set_email1(string new_email);

    string get_email1();
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
    void set_gender1(string new_gender);

    string get_gender1(); 
};