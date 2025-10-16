#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>

class Btc{
    private:
        std::map<std::string, double> _data;
        std::map<std::string, double> _input;

    public:
        Btc();
        ~Btc();
        Btc(const Btc& src);
        Btc &operator=(const Btc& src);

        void errorFile();
        bool fileExtract(std::string file);
        
};


