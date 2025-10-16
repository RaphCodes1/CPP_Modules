#include "BitcoinExchange.hpp"
int main(int ac, char **av)
{
    Btc btcObj;
    if(ac == 2)
    {   
        if(!btcObj.fileExtract(av[1]))
            return (1);
        btcObj.printInput();
        return (0);
    }
    else
    {
        btcObj.errorFile();
        return (1);
    }
}