#include "PhoneBook.hpp"
#include "Contact.hpp"

void forLoopInput(PhoneBook *pb)
{   
    int num = 777;
    int x = 0;
    for(int i = 0; i < 8; i++)
    {   
        char bullshit = 'a';
        bullshit += x;
        for(int f = 0; f < 5; f++)
        {   
            if(f == 3)
                pb->people[i][f] = num++;
            else
                pb->people[i][f] = bullshit;
        }
        x += 1;
    }
}

int main()
{
    PhoneBook phonebook;
    Contact contact;
    std::string choice;
    int end = 0;

    forLoopInput(&phonebook);
    while(end == 0)
    {
        if(std::cin.eof())
            return (0);
        std::cout << "ADD, SEARCH and EXIT: ";
        std::getline(std::cin, choice);
        if(std::cin.eof())
            return (0);
        else if(choice == "ADD")
            contact.add_function(phonebook);
        else if(choice == "SEARCH")
            phonebook.search_func();
        else if(choice == "EXIT")
        {   
            std::cout << "Thanks for using PhoneBook\n";
            end = 1;
        }
        else
            std::cout << "Enter a valid value.\n";
    }
    return (0);
}
