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

bool Btc::fileExtract(std::string file){
    std::ifstream inputFile(file);
    if(!inputFile.is_open())
    {
        errorFile();
        return (false);
    }

    char delimiter = ',';
    
    std::string line;
    while (std::getline(inputFile,line)){
        std::cout << line << std::endl;
    }
    
    inputFile.close();
    return (true);
}