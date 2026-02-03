#include "Contact.hpp"

Contact::Contact() {};

bool Contact::isPrintable(std::string input) {
    size_t  i;

    i = 0;
    while (i < input.size())
    {
        if (input[i] < 32 || input[i] > 126)
            return (false);
        i++;
    }
    return (true);
}

std::string Contact::readValidInput(std::string prompt) {
    std::string input;
    do
    {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            exit(1);
        if (input.empty())
            std::cout << "     Field cannot be empty! Try Again\n";
        else if (!isPrintable(input))
            std::cout << "     Invalid characters detected! Try Again\n";
    } while (input.empty() || !isPrintable(input));
    return (input);
}

bool Contact::isDigits(std::string phoneNbr) {
    size_t i;

    if (phoneNbr.empty())
        return (false);
    i = 0;
    while (i < phoneNbr.size())
    {
        if (!isdigit(phoneNbr[i]))
            return (false);
        i++;
    }
    return (true);
}

std::string Contact::readPhoneNumber(std::string prompt) {
    std::string input;
    do
    {
        std::cout << prompt;
        if(!std::getline(std::cin, input))
            exit(1);
        if (input.empty())
            std::cout << "     Field cannot be empty! Try Again\n";
        else if (!isDigits(input))
            std::cout << "     Phone number must contain digits only! Try Agin\n";
    } while (input.empty() || !isDigits(input));
    return (input);
}

void    Contact::setFirstName() {
    firstName = readValidInput("   Enter First Name : ");
}

void    Contact::setLastName() {
    lastName = readValidInput("   Enter Last Name : ");
}

void    Contact::setNickName() {
    nickName = readValidInput("   Enter Nick Name : ");
}

void    Contact::setPhoneNumber() {
    phoneNumber = readPhoneNumber("   Enter Phone Number : ");
}

void    Contact::setDarkestSecret() {
    darkestSecret = readValidInput("   Enter Darkest Secret : ");
}

std::string  Contact::getFisrtName() const {
    return (firstName);
}

std::string Contact::getLastName() const {
    return (lastName);
}

std::string Contact::getNickName() const {
    return (nickName);
}

std::string Contact::getPhoneNumber() const {
    return (phoneNumber);
}

std::string Contact::getDarkestSecret() const {
    return (darkestSecret);
}
