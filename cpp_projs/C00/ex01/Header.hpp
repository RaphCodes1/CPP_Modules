#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iostream>
#include <string>
#include <iomanip>

class PhoneBook
{   
    private:
        std::string name;
        std::string contact[5];
        std::string truncate(const std::string& str);
    public:
        static int counter;
        static std::string people[8][5];
        PhoneBook(std::string perName);
        ~PhoneBook();
        int add_contact(std::string input[]);
        int search_func();
}; 

int number_check(std::string str);
int char_check(std::string str);
int valid_contact(std::string contact[]);

#endif