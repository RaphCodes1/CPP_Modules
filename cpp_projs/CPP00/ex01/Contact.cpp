#include <iostream>
#include <string>
#include "PhoneBook.hpp"
#include "Contact.hpp"

Contact::Contact()
{
    firstName = "";
    lastName = "";
    nickname = "";
    phoneNumber = "";
    darkestSecret = "";
}

Contact::~Contact(){;}

void Contact::setVal(std::string value, int index)
{
    if(index == 0)
        firstName = value;
    else if(index == 1)
        lastName = value;
    else if(index == 2)
        nickname = value;
    else if(index == 3)
        phoneNumber = value;
    else if(index == 4)
        darkestSecret = value;
}

void Contact::setGroupInfo()
{
    groupedInfo[0] = firstName;
    groupedInfo[1] = lastName;
    groupedInfo[2] = nickname;
    groupedInfo[3] = phoneNumber;
    groupedInfo[4] = darkestSecret;
}

std::string Contact::getInfo(int index)
{
    return(groupedInfo[index]);
}

bool Contact::isEmpty()
{
    if(firstName == "")
        return true;
    return false;
}