#include "PhoneBook.hpp"

int PhoneBook::counter = 0;

PhoneBook::PhoneBook(){
    textOutInit();
}

PhoneBook::~PhoneBook(){;}

std::string PhoneBook::truncate(const std::string&  str)
{
    return (str.length() > 10) ? str.substr(0, 9) + "." : str;
}

void PhoneBook::addContact()
{
    if(counter == 8)
        counter = 0;
    for(int i = 0; i < 5; i++)
        contact[counter].setVal(input[i],i);
    contact[counter].setGroupInfo();
    counter += 1;
}

int PhoneBook::searchFunction()
{
    int end = 0;
    std::string index;
    textOutInit();
    if(contact[0].isEmpty())
    {
        std::cout << "please enter input first.\n";
        return (0);
    }
    printHeader();    
    for(int i = 0; i < 8; i++)
    {   
        if(!contact[i].isEmpty())
        {
            std::cout << std::setw(10) << i << "|";
            for (size_t f = 0; f < 3; f++)
                std::cout<< std::setw(10) << truncate(contact[i].getInfo(f)) << "|";
            std::cout << "\n";
        }
    }
    while (end == 0)
    {   
        std::cout << "Enter Index or EXIT: ";
        std::getline(std::cin,index);
        if(std::cin.eof())
            return (0);
        if(index == "EXIT")
            return (1);
        if((index[0] >= '0' && index[0] <= '7') && index[1] == '\0')
        {   
            int i = index[0] - '0';
            if(!contact[i].isEmpty())
            {   
                std::cout << "---------------------------------------------\n";
                for (size_t f = 0; f < 5; f++)
                    std::cout << text_output[f] << contact[i].getInfo(f) << "\n"; 
                std::cout << "---------------------------------------------\n";

                return (1);
            }
            else
                std::cout << "Enter a Valid Index.\n";
        }
        else
            std::cout << "Enter a Valid Index.\n";
    }
    return (1);
}

int PhoneBook::addFunction()
{   
    int i = 0;
    int all_true;
    while(i < 5)
    {   
        all_true = 1;
        std::cout << text_output[i];
        std::getline(std::cin, input[i]);
        if(std::cin.eof())
            return (0);
        if(input[i].empty() || !spaceOnly(input[i]))
        {
            std::cout << "enter valid value\n";
            all_true = 0;
        }
        if(i == 3)
        {
            if(!numCheck(input[i]))
            {
                std::cout << "enter valid number\n";
                all_true = 0;
            }
        }
        else if(!strCheck(input[i]))
        {
            std::cout << "enter valid value\n";
            all_true = 0;
        }
        if(all_true == 1)
            i++;
    }
    addContact();
    std::cout << "Info succesfully saved!\n";
    return (1);
}
    
