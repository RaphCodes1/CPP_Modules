#ifndef CONTACT_HPP
# define CONTACT_HPP

#include <iostream>
#include <string>
#include "PhoneBook.hpp"


class Contact
{
    private:
        std::string input[5];
        std::string text_output[5];
    public:
        int add_function(PhoneBook pb);
        void text_output_init();
};

#endif