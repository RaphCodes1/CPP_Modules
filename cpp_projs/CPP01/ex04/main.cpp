#include "Header.hpp"

std::string replaceStr(std::string str, std::string toReplace, std::string replace)
{   
    size_t start = 0;
    std::string result = str;
    while ((start = result.find(toReplace, start)) != std::string::npos) {
        result.erase(start, toReplace.length());         
        result.insert(start, replace);            
        start += replace.length();                
    }
    std::cout << result << std::endl;

    return (result);
}
void error_exit(std::string error_msg)
{
    std::cerr << error_msg << std::endl;
    return ;
}

bool has_permissions(std::string filename)
{
    return(access(filename.c_str(), R_OK | W_OK) == 0);
}

int check_valid(std::string str)
{
    for(size_t i = 0; i < str.length(); i++)
    {
        if(std::isspace(static_cast<unsigned char>(str[i])))
        {
            error_exit("File Not Valid!");
            return (0);
        }
    }
    if(!has_permissions(str))
    {
        error_exit("Invalid File!");
        return (0);
    }
    return (1);
}

int main(int ac, char **av)
{   
    if(ac == 4)
    {   
        if(!check_valid(av[1]))
            return (1);
        std::string replace = ".replace";
        std::string fileName = av[1];
        std::string concantenated = fileName + replace;
        
        std::ifstream currFile(fileName.c_str());
        std::ofstream newFile(concantenated.c_str());

        if(!currFile || !newFile)
        {
            std::cerr << "Invalid File!" << std::endl;
            return (1);
        }

        std::string line;

        while(std::getline(currFile, line))
        {
            std::string new_str = replaceStr(line, av[2], av[3]);
            newFile << new_str << std::endl;
        }
        currFile.close();
    }
    else
        std::cerr << "Invalid Args" << std::endl;
    return (0);
}