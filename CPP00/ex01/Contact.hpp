#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <cstdlib>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickName;
    std::string phoneNumber;
    std::string darkestSecret;
public:
    Contact();
    bool isPrintable(std::string input);
    bool isDigits(std::string phoneNbr);
    std::string readValidInput(std::string prompt);
    std::string readPhoneNumber(std::string prompt);
    void setFirstName();
    std::string getFisrtName() const; 
    void setLastName();
    std::string getLastName() const;
    void setNickName();
    std::string getNickName() const;
    void setPhoneNumber();
    std::string getPhoneNumber() const;
    void setDarkestSecret();
    std::string getDarkestSecret() const;
};

#endif