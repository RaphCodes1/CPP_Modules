#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(): AForm("ShrubberyCreationForm",145,137), _target("Default"){
    std::cout << "Default ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) 
: AForm("ShrubberyCreationForm",145,137), _target(target)
{   
    std::cout << "ShrubberyCreationForm Constructor called" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm(){
    std::cout << "ShrubberyCreationForm Destructor called" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src)
:AForm(src), _target(src._target) 
{
    std::cout << "ShrubberyCreationForm Copy Constructor called" << std::endl;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if(this != &src)
    {
        AForm::operator=(src);
        this->_target=src._target;
    }
    return(*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
    AForm::execute(executor);
    std::string filename = _target + "_shrubbery";
    std::ofstream outfile(filename.c_str());

    if(outfile.is_open()){
        outfile << "      ###" << std::endl;
        outfile << "    #######" << std::endl;
        outfile << "  ###########" << std::endl;
        outfile << " #############" << std::endl;
        outfile << "###############" << std::endl;
        outfile << "      | |" << std::endl;
        outfile << "      | |" << std::endl;
        outfile << "      | |" << std::endl;
        outfile.close();

        std::cout << "Shrubbery creation successful for " << _target << std::endl;
    } else{
        std::cerr << "Error: Could not open/create file." << std::endl;
    }
}