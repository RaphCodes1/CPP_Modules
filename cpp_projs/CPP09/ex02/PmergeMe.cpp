#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){
    this->straggler = -1;
};

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
        main.push_back(result);
    }
    else
        return false;
    return true;

}

void PmergeMe::fordJohnsonAlgorithm(){

    int sizeMain = main.size();
    if(sizeMain % 2 != 0)
    {
        straggler = main.back();
        sizeMain -= 1;
    }

    std::list<int>::iterator begin = main.begin();
    for(int i = sizeMain; i != 0; i /= 2)
    {
        pairs.push_back(std::make_pair(*begin,*(++begin)));
        begin++;
    }

    for(size_t i = 0; i < pairs.size(); i++)
    {
        if(pairs[i].first > pairs[i].second)
            std::swap(pairs[i].first, pairs[i].second);
    }

    for(size_t i = 0; i < pairs.size(); i++)
    {
        a.push_back(pairs[i].second);
        b.push_back(pairs[i].first);
    }
    
    //pushing a to sorted;
    a.sort();
    for(std::list<int>::iterator begin = a.begin(); begin != a.end(); begin++)
        sorted.push_back(*begin);
    
    //pushing b to sorted;
    std::list<int>::iterator it;
    for(std::list<int>::iterator bVal = b.begin(); bVal != b.end(); bVal++)
    {
        it = std::lower_bound(sorted.begin(),sorted.end(),*bVal);
        sorted.insert(it,*bVal);
    }

    //push straggler to sorted if it exists
    if(straggler != -1)
    {
        it = std::lower_bound(sorted.begin(),sorted.end(),straggler);
        sorted.insert(it,straggler);
    }
    

    // std::cout << "First: ";
    // for(size_t i = 0; i < pairs.size(); i++)
    //     std::cout << pairs[i].first << " ";
    // std::cout << std::endl;
    // std::cout << "Second: ";
    // for(size_t i = 0; i < pairs.size(); i++)
    //     std::cout << pairs[i].second << " ";
    // std::cout << std::endl;
    // std::cout << "Straggler: " << straggler << std::endl;

    // std::cout  << "a: ";
    // for(std::list<int>::iterator begin = a.begin(); begin != a.end(); begin++)
    //     std::cout << *begin << " ";
    // std::cout << std::endl;

    std::cout << "Before: ";
    for(std::list<int>::iterator begin = main.begin(); begin != main.end(); begin++)
    {
        std::cout << *begin << " ";
    }
    std::cout << std::endl;

    std::cout << "After: ";
    for(std::list<int>::iterator begin = sorted.begin(); begin != sorted.end(); begin++)
        std::cout << *begin << " ";
    std::cout << std::endl;
}