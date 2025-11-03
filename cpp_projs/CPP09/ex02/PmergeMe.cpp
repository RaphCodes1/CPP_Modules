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
        mainChain.insert(mainChain.begin(),b[0]);

    std::vector<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while(jacobsthal.back() < b.size())
    {
        size_t next = jacobsthal[jacobsthal.size() - 1] + (2 * jacobsthal[jacobsthal.size() - 2]);
        jacobsthal.push_back(next);
    }

    std::vector<size_t> insertOrder;
    size_t lastInsert = 0;

    for(size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t currentJacob = jacobsthal[i];
        size_t prevJacob = jacobsthal[i - 1];

        size_t start = std::min(currentJacob, b.size() - 1);
        size_t end = prevJacob;

        for(size_t i = start; i > end && i < b.size(); i--)
        {
            if(i < b.size() && i > lastInsert)
                insertOrder.push_back(i);
        }
        if(start >= b.size() - 1)
            break;
    }

    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];
        std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(),mainChain.end(), b[index]);
        mainChain.insert(mainIt,b[index]);
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