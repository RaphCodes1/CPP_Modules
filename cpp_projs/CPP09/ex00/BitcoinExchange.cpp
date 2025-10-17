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

// std::map<std::string, double>::iterator Btc::finder(std::string val){
//     std::map<std::string, double>::iterator findKey = _data.lower_bound(val);
//     if(findKey != _data.begin()){
//         --findKey;
//     } else {
//         std::cout << "Error: " << _data.begin()->first << " => No date earlier found." << std::endl;
//     }
//     return findKey;
// }

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
            std::cout << "Error: bad input => " << line << std::endl;
            continue;
        }

        key = line.substr(0, delimeter_pos);
        val = line.substr(delimeter_pos + 1);

        trimSpaces(key);
        trimSpaces(val);

        num = atof(val.c_str());
        if(num < 0)
        {
            std::cout << "Error: not a positive number." << std::endl;
            continue;
        }
        else if(num > INT_MAX)
        {
            std::cout << "Error: too large of a number." << std::endl;
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