#include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {};

BitcoinExchange::~BitcoinExchange() {};

int BitcoinExchange::loadDatabase(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << std::endl;
        return (1);
    }
    std::string line;
    getline(file, line);
    while (getline(file, line))
    {
        size_t pos = line.find(',');
        if (pos == std::string::npos)
            continue;

        std::string date = line.substr(0, pos);
        std::string rateStr = line.substr(pos + 1);
        double rate = std::atof(rateStr.c_str());

        _data[date] = rate;
    }
    return (0);
}

int BitcoinExchange::parseLine(const std::string& line, size_t index)
{
    if (index == std::string::npos || index == 0 || index == line.size() - 1)
        return (1);

    if (line[index - 1] != ' ' || line[index + 1] != ' ')
        return (1);

    if (index >= 2 && line[index - 2] == ' ')
        return (1);

    if (index + 2 < line.size() && line[index + 2] == ' ')
        return (1);

    return (0);
}

int BitcoinExchange::parseDate(const std::string& date) {
    if (date.size() != 10)
        return (1);

    for (size_t i = 0; i < date.size(); i++)
    {
        if (i == 4 || i == 7)
        {
            if (date[i] != '-')
                return (1);
        }
        else
        {
            if (!isdigit(date[i]))
                return (1);
        }
    }

    int y = std::atoi(date.substr(0, 4).c_str());
    int m = std::atoi(date.substr(5, 2).c_str());
    int d = std::atoi(date.substr(8, 2).c_str());

    if (y < 2009 || y > 2022)
        return (1);
    if (m < 1 || m > 12)
        return (1);
    if (d < 1 || d > 31)
        return (1);
    return (0);
}

int BitcoinExchange::parseRate(const double rate) {
    if (rate < 0)
    {
        std::cout << "Error: not a positive number" << std:: endl;
        return (1);
    }
    if (rate > 1000)
    {
        std::cout << "Error: too large a number" << std::endl;
        return (1);
    }
    return (0);
}

void BitcoinExchange::processInput(const std::string& filename) {
    std::ifstream file(filename.c_str());
    if (!file.is_open())
    {
        std::cerr << "Error opening the file" << std::endl;
        return ;
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


        while (!date.empty() && (date[date.size() - 1] == ' ' || date[date.size() - 1] == '\t'))
            date.erase(date.size() - 1);
        
        if (parseDate(date))
        {
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        std::string rateStr = line.substr(pos + 1);


        while (!rateStr.empty() && (rateStr[0] == ' ' || rateStr[0] == '\t'))
            rateStr.erase(0, 1);

        double rate = std::atof(rateStr.c_str());

        if (parseRate(rate))
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

        double result = it->second * rate;

        std::cout << date << " => " << rate << " = " << result << std::endl;
        
    }
}
