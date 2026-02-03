#include "PhoneBook.hpp"

PhoneBook::PhoneBook() : index(0), count(0) {};

void PhoneBook::addContact() {
    contacts[index].setFirstName();
    contacts[index].setLastName();
    contacts[index].setNickName();
    contacts[index].setPhoneNumber();
    contacts[index].setDarkestSecret();

    if (index < 7)
        index++;
    else
        index = 0;
    if (count < 8)
        count++;
}

void PhoneBook::displayColumn(std::string str) {
{
    int i;
    if (str.length() > 10)
        std::cout << str.substr(0, 9) << ".";
    else
    {
        i = 0;
        while (i < 10 - (int)str.length()) {
            std::cout << " ";
            i++;
        }
        std::cout << str;
    }
}
}

void PhoneBook::displayContacts() {
    int i;
    if (count == 0)
    {
        std::cout << "      Your Phone Book Is Empty\n";
    }
    else {
        std::cout << "---------------------------------------------\n";
        std::cout << "|   INDEX  |FIRST NAME| LAST NAME| NICKNAME |\n";
        std::cout << "---------------------------------------------\n";
    }
    i = 0;
    while (i < count)
    {
        std::cout << "|";

        std::string idx = "";
        idx += ('0' + i);
        displayColumn(idx);
        std::cout << "|";

        displayColumn(contacts[i].getFisrtName());
        std::cout << "|";

        displayColumn(contacts[i].getLastName());
        std::cout << "|";

        displayColumn(contacts[i].getNickName());
        std::cout << "|\n";
        i++;
    }
    std::cout << "---------------------------------------------\n";
}

void PhoneBook::displaySummary() {
    std::string input;
    int         index;

    if (count != 0)
    {
        std::cout << "Enter index of the contact : ";
        if (!std::getline(std::cin, input))
            return ;
        if (input.length() != 1 || !isdigit(input[0]))
        {
            std::cout << "Invalid Index !" << "\n";
            return ;
        }
        index = input[0] - '0';
        if (index >= count)
        {
            std::cout << "Index out of range !" << "\n";
            return ;
        }
        std::cout << "First Name    : " << contacts[index].getFisrtName() << "\n";
        std::cout << "Last Name     : " << contacts[index].getLastName() << "\n";
        std::cout << "Nick Name     : " << contacts[index].getNickName() << "\n";
        std::cout << "Phone Number  : " << contacts[index].getPhoneNumber() << "\n";
        std::cout << "Darkest Secret: " << contacts[index].getDarkestSecret() << "\n";
    }
}
