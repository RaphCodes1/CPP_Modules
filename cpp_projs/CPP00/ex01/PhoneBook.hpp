#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{   
    private:
        std::string name;
        std::string truncate(const std::string& str);
        std::string text_output[5];
        std::string input[5];
        Contact contact[8];
    public:
        static int counter;
        PhoneBook();
        ~PhoneBook();
        void printHeader();
        int addFunction();
        int searchFunction();
        void addContact();
        int numCheck(std::string str);
        int strCheck(std::string str);
        int spaceOnly(std::string str);
        void textOutInit();
}; 


#endif