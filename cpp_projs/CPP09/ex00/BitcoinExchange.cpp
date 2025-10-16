#include "BitcoinExchange.hpp"

Btc::Btc(){};

Btc::~Btc(){};

Btc::Btc(const Btc& src){
    *this = src;
};

Btc &Btc::operator=(const Btc& src){
    if(this != &src)
    {
        *this = src;
    }
    return *this;
};

void Btc::errorFile(){
    std::cerr << "Error: could not open file." << std::endl;
}

void Btc::printInput(){
    std::map<std::string, double>::const_iterator it;

    for(it = _input.begin(); it != _input.end(); it++)
    {
        std::cout << it->first << " => " << it->second << std::endl; 
    }
}


bool Btc::fileExtract(std::string file){
    std::ifstream inputFile(file);
    if(!inputFile.is_open())
    {
        errorFile();
        return (false);
    }

    std::string line;
    if(std::getline(inputFile,line)){}

    while (std::getline(inputFile,line)){
        size_t delimeter_pos = line.find('|');
        
        if(delimeter_pos == std::string::npos)
            continue;
        
        std::string key = line.substr(0, delimeter_pos - 1);
        std::string val = line.substr(delimeter_pos - 2);
        
        try{
            double num = std::stod(val);
            this->_input[key] += num;
        } catch(const std::exception &e){
            std::cerr << e.what() << std::endl;
        }
        

        
        
        
    }
    
    inputFile.close();
    return (true);
}