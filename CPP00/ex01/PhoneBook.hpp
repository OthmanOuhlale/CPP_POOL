#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include "Contact.hpp"

class PhoneBook
{
private:
    Contact contacts[8];
    int     index;
    int     count;
public:
    PhoneBook();
    void    addContact();
    void    displayColumn(std::string str);
    void    displayContacts();
    void    displaySummary();
};

#endif