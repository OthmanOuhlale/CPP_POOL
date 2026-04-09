#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <cstdlib>

class BitcoinExchange
{
    private:
        std::map<std::string, double> _data;
    public:
        BitcoinExchange();
        ~BitcoinExchange();

        int loadDatabase(const std::string& filename);
        int parseLine(const std::string& line, size_t index);
        int parseDate(const std::string& date);
        int parseRate(const double rate);
        void processInput(const std::string& filename);
        double getRate(std::string& date);
};

#endif
