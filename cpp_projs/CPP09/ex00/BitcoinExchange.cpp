#include "BitcoinExchange.hpp"

Btc::Btc(){
    extractCSV("data.csv");
};

Btc::~Btc(){};

Btc::Btc(const Btc& src){
    this->_data = src._data;
};

Btc &Btc::operator=(const Btc& src){
    if(this != &src)
    {
        this->_data = src._data;
    }
    return *this;
};

void Btc::errorFile(){
    std::cerr << "Error: could not open file." << std::endl;
}

void Btc::printInput(){
    std::map<std::string, double>::const_iterator it;
    for(it = _data.begin(); it != _data.end(); it++)
    {
        std::cout << it->first << " => " << it->second << std::endl; 
    }
}

bool Btc::extractCSV(std::string file){
    std::ifstream inputFile(file.c_str());
    if(!inputFile.is_open())
    {
        errorFile();
        return (false);
    }
    std::string line;
    std::string key;
    std::string val;
    if(std::getline(inputFile,line)){}

    while (std::getline(inputFile,line)){
        size_t delimeter_pos = line.find(',');
        
        if(delimeter_pos == std::string::npos)
            continue;
        
        key = line.substr(0, delimeter_pos);
        val = line.substr(delimeter_pos + 1);
        
        try{
            _data.insert(std::make_pair(key,atof(val.c_str())));
        } catch(const std::exception &e){
            std::cerr << e.what() << std::endl;
        }        
    }
    inputFile.close();
    return (true);
}

void startTrim(std::string &s){
    size_t start = s.find_first_not_of(" ");
    s.erase(0,start);
}

void endTrim(std::string &s){
    size_t end = s.find_last_not_of(" ");
    s.erase(end + 1);
}

void trimSpaces(std::string &s){
    startTrim(s);
    endTrim(s);
}

double Btc::finder(std::string val){
    std::map<std::string, double>::iterator findKey = _data.lower_bound(val);
    if(findKey != _data.begin()){
        --findKey;
    } else {
        std::cout << "Error: " << _data.begin()->first << " => No date earlier found." << std::endl;
        return (-1);
    }
    return findKey->second;
}

bool datesCheck(std::string &s)
{
    int year;
    int month;
    int day;
    char delimeterOne;
    char delimeterTwo;

    bool isLeapYear = false;
    int monthLength = 31;
    std::istringstream date(s);
    date >> year >> delimeterOne >> month >> delimeterTwo >> day;

    if(date.fail() || !date.eof())
        return false;

    if(month < 1 || month > 12)
        return false;

    if((year % 4 == 0 && (year % 100 != 0)) || (year % 400 == 0))
        isLeapYear = true;
    
    if(month == 4 || month == 6 || month == 9 || month == 11)
        monthLength = 30;
    else if(month == 2)
    {
        if(isLeapYear)
            monthLength = 29;
        else
            monthLength = 28;
    }
    
    if(day > monthLength || day < 1)
        return false;
    return true;  
}

bool validDate(std::string &s){
    if(s.length() != 10)
        return false;
    
    if(s[4] != '-' || s[7] != '-')
        return false;
    
    for(size_t i = 0; i < s.length(); i++)
    {
        if(i == 4 || i == 7)
            continue;
        if(!isdigit(static_cast<unsigned int>(s[i])))
            return false;
        if(i == 5)
        {    
            if(s[i] > '1') {
                return false;
            } else if(s[i] == '1' && s[i + 1] > '2'){
                return false;
            }
        }
        else if(i == 8)
        {
            if(s[i] > '3'){
                return false;
            } else if(s[i] == '3' && s[i + 1] > '1'){
                return false;
            }
        }
    }
    //check valid leap year
    if(!datesCheck(s))
        return false;
    return true;
}

bool validNum(const std::string &s){
    if(s.empty())
    {
        std::cerr << "Error: No valid number found." << std::endl;
        return false;
    }
    for(size_t i = 0; i < s.length(); i++)
    {
        if(!isdigit(static_cast<unsigned char>(s[i])))
        {
            if(s[i] == '.')
                continue;
            else if(s[i] == '-')
            {
                std::cerr << "Error: not a positive number." << std::endl;
                return false;
            }
            else
            {
                std::cerr << "Error: Invalid Number" << std::endl;
                return false;
            }
        }
    }
    return true;
}

bool Btc::extractInput(std::string file){
    std::ifstream inputFile(file.c_str());
    if(!inputFile.is_open())
    {
        errorFile();
        return (false);
    }
    std::string line;
    std::string key;
    std::string val;
    double num;
    if(std::getline(inputFile,line)){}

    while(std::getline(inputFile,line)){
        trimSpaces(line);
        size_t delimeter_pos = line.find('|');

        if(delimeter_pos == std::string::npos)
        {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }

        key = line.substr(0, delimeter_pos);
        val = line.substr(delimeter_pos + 1);

        trimSpaces(key);
        trimSpaces(val);
        if(!validDate(key))
        {
            std::cerr << "Error: Invalid Date" << std::endl;
            continue;
        }
        else if(!validNum(val))
            continue;

        num = atof(val.c_str());
        if(num > INT_MAX)
        {
            std::cerr << "Error: Too large of a number." << std::endl;
            continue;
        }
        else if(finder(key) == - 1)
            continue;
        double mapNum = finder(key);
        std::cout << key << " => " << num << " = " << num * mapNum << std::endl;
    }
    inputFile.close();
    return (true);
}