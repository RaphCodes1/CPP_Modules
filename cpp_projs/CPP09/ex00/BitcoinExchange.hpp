#pragma once

#include <iostream>
#include <map>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <limits.h>

class Btc{
    private:
        std::map<std::string, double> _data;
    public:
        Btc();
        ~Btc();
        Btc(const Btc& src);
        Btc &operator=(const Btc& src);

        void errorFile();
        bool extractCSV(std::string file);
        void printInput();

        bool extractInput(std::string file);
        double finder(std::string val);
        
};


