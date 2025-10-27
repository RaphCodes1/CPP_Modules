#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){};

PmergeMe::~PmergeMe(){};

PmergeMe::PmergeMe(const PmergeMe& src){
    *this = src;
}

PmergeMe &PmergeMe::operator=(const PmergeMe& src){
    if(this != &src)
    {
        *this = src;
    }
    return *this;
}

bool PmergeMe::inputCheck(std::string &s)
{
    long long result;
    
    std::istringstream stream(s);

    if(stream >> result)
    {
        if(result < 0 || result > INT_MAX)
            return false;
        // std::cout << result << std::endl;
        _mainVector.push_back(result);
    }
    else
        return false;
    return true;

}


std::vector<int> PmergeMe::fordJohnsonAlgorithmVector(std::vector<int> main){

    if(main.size() < 2)
        return main;

    std::vector<std::pair<int,int> > pairs;
    int straggler = 0;
    bool hasStraggler = false;

    if(main.size() % 2 != 0)
    {
        straggler = main.back();
        hasStraggler = true;
        main.pop_back();
    }

    std::vector<int>::iterator begin = main.begin();
    while(std::distance(begin,main.end()) >= 2){
        int firstVal = *(begin++);
        int secondVal = *(begin++);

        if(firstVal > secondVal)
            pairs.push_back(std::make_pair(secondVal, firstVal));
        else
            pairs.push_back(std::make_pair(firstVal, secondVal));
    }

    std::vector<int> a;
    std::vector<int> b;
    for(std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
    {
        a.push_back(it->second);
        b.push_back(it->first);
    }

    std::vector<int> mainChain = fordJohnsonAlgorithmVector(a);

    if(!b.empty())
    {
        mainChain.insert(mainChain.begin(),b.front());
        b.erase(b.begin());
    }

    // std::vector<int>::iterator mainIt;
    // for(std::vector<int>::iterator itB = b.begin(); itB != b.end();itB++)
    // {
    //     mainIt = std::lower_bound(mainChain.begin(),mainChain.end(),*itB);
    //     mainChain.insert(mainIt,*itB);
    // }

    //j = prev + (2 * curr);
    size_t prevIndex = 1;
    size_t currIndex = 1;
    size_t j = currIndex + (2 * prevIndex);
    bool end = false;
    bool overshot = false;
    while(!end)
    {   
        if(j > b.size())
        {
            while(j > b.size())
                j--;
            overshot = true;
        }
        std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(), mainChain.end(),b[j]);
        mainChain.insert(mainIt,b[j]);
        for(size_t i = j; i > currIndex; i--)
        {
            std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(), mainChain.end(),b[i]);
            mainChain.insert(mainIt,b[i]);
        }
        if(overshot)
            end = true;
        else{
            int temp = currIndex;
            prevIndex = temp;
            currIndex = j;
            j = currIndex + (2 * prevIndex);
        }

        // if(j <= b.size())
        // {
        //     std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(), mainChain.end(),b[j]);
        //     mainChain.insert(mainIt,b[j]);
        //     for(size_t i = j; i >= currIndex; i--)
        //     {
        //         std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(), mainChain.end(),b[i]);
        //         mainChain.insert(mainIt,b[i]);
        //     }
        //     currIndex = j;
        //     j = currIndex + (2 * prevIndex);
        // }
        // else
        //     end = true;
    }

    if(hasStraggler)
    {
        std::vector<int>::iterator addStraggler = std::lower_bound(mainChain.begin(),mainChain.end(), straggler);
        mainChain.insert(addStraggler, straggler);
    }
    return mainChain;
}

void PmergeMe::doAlgorithm()
{
    _sortedVector = fordJohnsonAlgorithmVector(_mainVector);
    for(std::vector<int>::iterator it = _sortedVector.begin(); it != _sortedVector.end(); it++)
        std::cout << *it << " ";
}