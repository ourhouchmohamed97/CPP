#pragma once

#include <vector>
#include <deque>

class PmergeMe {
    public :
        PmergeMe();
        PmergeMe( const PmergeMe& other );
        PmergeMe& operator=( const PmergeMe& other );
        ~PmergeMe();
        
        void parseInput(int argc, char **argv); // validate + fill containers
        void sort();                            // run both sorts + time them
        void display() const;                   // print Before/After/Times

        void sortVector( std::vector<int>& vec );
        void sortDeque( std::deque<int>& deq );

    private :
        std::vector<int> _vec;
        std::deque<int>  _deq;
        std::vector<int> _original;
        double _vecTime;
        double _deqTime;

        // Ford-Johnson for vector
        void fordJohnsonVec(std::vector<int> &seq);
        void binaryInsertVec(std::vector<int> &chain, int val, int end);

        // Ford-Johnson for deque
        void fordJohnsonDeq(std::deque<int> &seq);
        void binaryInsertDeq(std::deque<int> &chain, int val, int end);

        // Jacobsthal helper
        std::vector<int> getJacobsthalOrder(int n);
};