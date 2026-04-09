#include "BitcoinExchange.hpp"

void BitcoinExchange::processInput(const std::string& filename)
{
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }

    std::string line;
    getline(file, line);

    while (getline(file, line))
    {
        if (line.empty())
            continue;

        size_t pos = line.find('|');


        if (parseLine(line, pos))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string date = line.substr(0, pos);
        std::string valueStr = line.substr(pos + 1);

        while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
            date.erase(date.size() - 1);

        while (!valueStr.empty() && (valueStr[0] == ' ' || valueStr[0] == '\t'))
            valueStr.erase(0, 1);

        if (parseDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        double value;
        try
        {
            value = std::stod(valueStr);
        }
        catch (...)
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        if (parseRate(value))
            continue;

        std::map<std::string, double>::iterator it = _data.lower_bound(date);

        if (it == _data.end() || it->first != date)
        {
            if (it == _data.begin())
            {
                std::cout << "Error: no valid date" << std::endl;
                continue;
            }
            it--;
        }

        double result = it->second * value;

        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}