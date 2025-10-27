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
        std::vector<int> _mainVector;
        std::vector<int> _sortedVector;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        bool inputCheck(std::string &s);
        std::vector<int> fordJohnsonAlgorithmVector(std::vector<int> input);

        void doAlgorithm();
};

