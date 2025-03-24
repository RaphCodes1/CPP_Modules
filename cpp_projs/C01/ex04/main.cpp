#include "Header.hpp"

std::string replaceStr(std::string str, char delimiter)
{
    std::stringstream ss(str);

    
}
int main(int ac, char **av)
{   
    if(ac == 4)
    {   
        std::string replace = ".replace";
        std::string fileName = av[1];
        std::string concantenated = fileName + replace;
        
        std::ifstream currFile(fileName);
        std::ofstream newFile(concantenated, std::ios::app);

        if(!currFile || !newFile)
        {
            std::cerr << "Invalid File!" << std::endl;
            return (1);
        }

        std::string line;

        while(std::getline(currFile, line))
        {
            std::cout << line << std::endl;
            newFile << line << std::endl;
        }
        currFile.close();
    }
    else
        std::cout << "Invalid Args" << std::endl;
}