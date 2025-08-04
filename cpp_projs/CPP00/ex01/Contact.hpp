#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include "PhoneBook.hpp"


class Contact
{
    private:
        std::string firstName;
        std::string lastName;
        std::string nickname;
        std::string phoneNumber;
        std::string darkestSecret;
        std::string groupedInfo[5];
    public:
        Contact();
        ~Contact();
        void setGroupInfo();
        std::string getInfo(int index);
        void setVal(std::string value, int index);
        bool isEmpty();
};

#endif