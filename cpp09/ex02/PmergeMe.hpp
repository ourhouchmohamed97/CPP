#pragma once

#include <iostream>
#include <vector>
#include <deque>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <algorithm>

class PmergeMe {
    public :
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
        ~PmergeMe();
        
        void parseInput(int argc, char **argv);
        void sort();
        void display() const;

    private :
        std::vector<int> _vec;
        std::deque<int>  _deq;
        std::vector<int> _original;
        double _vecTime;
        double _deqTime;

        void fordJohnsonVec(std::vector<int> &seq);
        void binaryInsertVec(std::vector<int> &chain, int val, int end);

        void fordJohnsonDeq(std::deque<int> &seq);
        void binaryInsertDeq(std::deque<int> &chain, int val, int end);

        std::vector<int> getJacobsthalOrder(int n);
};