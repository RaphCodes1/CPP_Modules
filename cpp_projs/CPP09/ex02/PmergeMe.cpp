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
        _mainDeque.push_back(result);
    }
    else
        return false;
    return true;

}


std::vector<int> PmergeMe::fordJohnsonAlgorithmVector(const std::vector<int>& input){

    std::vector<int> main = input;
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

    std::vector<int> higherNumber;
    std::vector<int> b;
    for(std::vector<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        higherNumber.push_back(it->second);

    std::vector<int> mainChain = fordJohnsonAlgorithmVector(higherNumber);

    higherNumber = mainChain;

    //used to deal with duplicate numbers;
    std::vector<char> used(pairs.size(), 0);

    for(size_t i = 0; i < mainChain.size();i++)
    {   
        int lead = mainChain[i];
        for(size_t k = 0; k < pairs.size(); k++)
        {
            if(!used[k] && pairs[k].second == lead)
            {
                b.push_back(pairs[k].first);
                used[k] = 1;
                break;
            }
        }
    }

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

    if(b.size() > 1)
        insertOrder.push_back(1);

    for(size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t currentJacob = jacobsthal[i];
        size_t prevJacob = jacobsthal[i - 1];

        size_t start = std::min(currentJacob, b.size() - 1);

        for(size_t j = start; j > prevJacob; j--)
        {
            if(j < b.size())
                insertOrder.push_back(j);
        }
        if(start >= b.size() - 1)
            break;
    }
   
    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];

        std::vector<int>::iterator pairedPos = std::find(mainChain.begin(),mainChain.end(),higherNumber[index]);
        std::vector<int>::iterator mainIt = std::lower_bound(mainChain.begin(),pairedPos, b[index]);
        mainChain.insert(mainIt,b[index]);
    }

    if(hasStraggler)
    {
        std::vector<int>::iterator addStraggler = std::lower_bound(mainChain.begin(),mainChain.end(), straggler);
        mainChain.insert(addStraggler, straggler);
    }

    return mainChain;
}

std::deque<int> PmergeMe::fordJohnsonAlgorithmDeque(const std::deque<int>& input){

    std::deque<int> main = input;
    if(main.size() < 2)
        return main;

    std::deque<std::pair<int,int> > pairs;
    int straggler = 0;
    bool hasStraggler = false;

    if(main.size() % 2 != 0)
    {
        straggler = main.back();
        hasStraggler = true;
        main.pop_back();
    }

    std::deque<int>::iterator begin = main.begin();
    while(std::distance(begin,main.end()) >= 2){
        int firstVal = *(begin++);
        int secondVal = *(begin++);

        if(firstVal > secondVal)
            pairs.push_back(std::make_pair(secondVal, firstVal));
        else
            pairs.push_back(std::make_pair(firstVal, secondVal));
    }

    std::deque<int> higherNumber;
    std::deque<int> b;
    for(std::deque<std::pair<int, int> >::iterator it = pairs.begin(); it != pairs.end(); it++)
        higherNumber.push_back(it->second);

    std::deque<int> mainChain = fordJohnsonAlgorithmDeque(higherNumber);

    higherNumber = mainChain;

    //used to deal with duplicate numbers;
    std::deque<char> used(pairs.size(), 0);

    for(size_t i = 0; i < mainChain.size();i++)
    {   
        int lead = mainChain[i];
        for(size_t k = 0; k < pairs.size(); k++)
        {
            if(!used[k] && pairs[k].second == lead)
            {
                b.push_back(pairs[k].first);
                used[k] = 1;
                break;
            }
        }
    }

    if(!b.empty())
        mainChain.insert(mainChain.begin(),b[0]);

    std::deque<size_t> jacobsthal;
    jacobsthal.push_back(0);
    jacobsthal.push_back(1);

    while(jacobsthal.back() < b.size())
    {   
        size_t next = jacobsthal[jacobsthal.size() - 1] + (2 * jacobsthal[jacobsthal.size() - 2]);
        jacobsthal.push_back(next);
    }

    std::deque<size_t> insertOrder;

    if(b.size() > 1)
        insertOrder.push_back(1);

    for(size_t i = 2; i < jacobsthal.size(); i++)
    {
        size_t currentJacob = jacobsthal[i];
        size_t prevJacob = jacobsthal[i - 1];

        size_t start = std::min(currentJacob, b.size() - 1);

        for(size_t j = start; j > prevJacob; j--)
        {
            if(j < b.size())
                insertOrder.push_back(j);
        }
        if(start >= b.size() - 1)
            break;
    }
   
    for(size_t i = 0; i < insertOrder.size(); i++)
    {
        size_t index = insertOrder[i];

        std::deque<int>::iterator pairedPos = std::find(mainChain.begin(),mainChain.end(),higherNumber[index]);
        std::deque<int>::iterator mainIt = std::lower_bound(mainChain.begin(),pairedPos, b[index]);
        mainChain.insert(mainIt,b[index]);
    }

    if(hasStraggler)
    {
        std::deque<int>::iterator addStraggler = std::lower_bound(mainChain.begin(),mainChain.end(), straggler);
        mainChain.insert(addStraggler, straggler);
    }

    return mainChain;
}

void PmergeMe::doAlgorithm()
{   
    std::cout << "Before: ";
    for(std::vector<int>::iterator it = _mainVector.begin(); it != _mainVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    
    clock_t startVec = clock();
    _sortedVector = fordJohnsonAlgorithmVector(_mainVector);
    clock_t endVec = clock();
    
    clock_t startDeq = clock();
    _sortedDeque = fordJohnsonAlgorithmDeque(_mainDeque);
    clock_t endDeq = clock();
    
    std::cout << "After: ";
    for(std::vector<int>::iterator it = _sortedVector.begin(); it != _sortedVector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    double elapsedSecsVec = static_cast<double>(endVec - startVec) / CLOCKS_PER_SEC;
    double elapsedSecsDeq = static_cast<double>(endDeq - startDeq) / CLOCKS_PER_SEC;

    double usecsVec = elapsedSecsVec * 1000000.0;
    double usecsDeq = elapsedSecsDeq * 1000000.0;

    std::cout << "Time to process a range of " << _mainVector.size() << " elements with std::vector : " << usecsVec << " us" << std::endl;
    std::cout << "Time to process a range of " << _mainDeque.size() << " elements with std::deque : " << usecsDeq << " us" << std::endl;

    // std::cout << "Deque: ";
    // for(std::deque<int>::iterator it = _sortedDeque.begin(); it != _sortedDeque.end(); it++)
    //     std::cout << *it << " ";
    // std::cout << std::endl;
}