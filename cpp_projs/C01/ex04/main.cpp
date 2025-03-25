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
    exit(1);
}

bool has_permissions(std::string filename)
{
    return(access(filename.c_str(), R_OK | W_OK) == 0);
}

void check_valid(std::string str)
{
    if(std::any_of(str.begin(),str.end(), ::isspace))
        error_exit("File Not valid!");
    if(!has_permissions(str))
        error_exit("File Does Not Have Permissions!");
}

int main(int ac, char **av)
{   
    if(ac == 4)
    {   
        check_valid(av[1]);
        std::string replace = ".replace";
        std::string fileName = av[1];
        std::string concantenated = fileName + replace;
        
        std::ifstream currFile(fileName);
        std::ofstream newFile(concantenated);

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