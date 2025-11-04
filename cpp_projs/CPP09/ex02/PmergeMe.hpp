#pragma once

#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <sstream>
#include <limits.h>
#include <utility>
#include <deque>
#include <ctime>

class PmergeMe{
    private:
        std::vector<int> _mainVector;
        std::vector<int> _sortedVector;
        std::deque<int> _mainDeque;
        std::deque<int> _sortedDeque;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe &operator=(const PmergeMe &src);

        bool inputCheck(std::string &s);
        std::vector<int> fordJohnsonAlgorithmVector(const std::vector<int>& input);
        std::deque<int> fordJohnsonAlgorithmDeque(const std::deque<int>& input);

        void doAlgorithm();
};

