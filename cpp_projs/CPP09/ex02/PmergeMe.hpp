#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <limits.h>
#include <utility>

class PmergeMe{
    private:
        std::list<int> main;
        std::list<int> sorted;
        std::vector<std::pair<int,int> > pairs;
        std::list<int> a;
        std::list<int> b;
        int straggler;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        bool inputCheck(std::string &s);
        void fordJohnsonAlgorithm();
};
