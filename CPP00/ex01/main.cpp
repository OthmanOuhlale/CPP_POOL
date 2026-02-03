#include "PhoneBook.hpp"

int main() {
    PhoneBook pb;
    std::string cmd;

    while (1)
    {
        std::cout << "Enter the command (ADD, SEARCH, EXIT): ";
        if (!std::getline(std::cin, cmd))
            return (1);
        if (cmd == "ADD") {
            pb.addContact();
        }
        else if (cmd == "SEARCH") {
            pb.displayContacts();
            pb.displaySummary();
        }
        else if (cmd == "EXIT")
            return (0);
        else
            std::cout << "Enter a correct command !" << "\n";
    }
    return (0);
}