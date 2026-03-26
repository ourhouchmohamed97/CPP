#include "PmergeMe.hpp"
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <climits>
#include <ctime>
#include <algorithm>

PmergeMe::PmergeMe() : _vecTime(0.0), _deqTime(0.0) {}
 
PmergeMe::PmergeMe( const PmergeMe& other ) 
        : _vec(other._vec), _deq(other._deq),
        _original(other._original),
        _vecTime(other._vecTime), _deqTime(other._deqTime)
        {}
 
PmergeMe& PmergeMe::operator=( const PmergeMe& other ) {
    if (this != &other) {
        _vec = other._vec;
        _deq = other._deq;
        _original = other._original;
        _vecTime = other._vecTime;
        _deqTime = other._deqTime;
    }
    return *this;
}
 
PmergeMe::~PmergeMe() {}

// ─────────────────────────────────────────────
//  Input parsing
// ─────────────────────────────────────────────


void PmergeMe::parseInput(int argc, char **argv) {
    for (int i = 0; i < argc; i++) {
        std::string token(argv[i]);

        if (token.empty())
            throw std::runtime_error("Empty token rejected");

        for (size_t j = 0; j < token.size(); j++) {
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("Invalid chaaracter: " + token);
        }

        long val = std::strtol(token.c_str(), NULL, 10);
        if (val <= 0 || val > INT_MAX)
            throw std::runtime_error("Out Of range: " + token);

        int num = static_cast<int>(val);
        _vec.push_back(num);
        _deq.push_back(num);
        _original.push_back(num);
    }
    if (_vec.empty())
        throw std::runtime_error("No input");
}

// ─────────────────────────────────────────────
//  Jacobsthal order helper
//  Returns pend indices in Ford-Johnson insertion order.
//  e.g. for n=5 pend elements → [1, 3, 2, 5, 4]
// ─────────────────────────────────────────────

std::vector<int> PmergeMe::getJacobsthalOrder(int n) {
    // Build Jacobsthal sequence up to the first value > n
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);

    std::vector<int> order;
    for (size_t k = 2; k < jacob.size(); ++k) {
        int hi = std::min(jacob[k], n);   // clamp to actual pend size
        int lo = jacob[k-1] + 1;
        for (int idx = hi; idx >= lo; --idx)
            order.push_back(idx);
        if (hi >= n) break;
    }
    return order;
}


// ─────────────────────────────────────────────
//  Binary insert helpers
//  Insert `val` into chain[0..end-1] (end is the exclusive upper bound).
// ─────────────────────────────────────────────

void PmergeMe::binaryInsertVec(std::vector<int> &chain, int val, int end) {
    int lo = 0, hi = end;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &chain, int val, int end) {
    int lo = 0, hi = end;
    while (lo < hi) {
        int mid = lo + (hi - lo) / 2;
        if (chain[mid] < val)
            lo = mid + 1;
        else
            hi = mid;
    }
    chain.insert(chain.begin() + lo, val);
}

// ─────────────────────────────────────────────
//  Ford-Johnson sort — std::vector
// ─────────────────────────────────────────────


void PmergeMe::fordJohnsonVec(std::vector<int> &seq) {}

void PmergeMe::fordJohnsonDeq(std::deque<int> &seq) {}





// ─────────────────────────────────────────────
//  Sorting
// ─────────────────────────────────────────────

static double elapsedUs(struct timespec &start, struct timespec &end) {
    return (end.tv_sec -  start.tv_sec) * 1e6 + (end.tv_nsec - start.tv_nsec) / 1e3;
}

void PmergeMe::sort() {
    struct timespec t0, t1;

    // ── vector ────────────────────────────────────────────────────────────
    clock_gettime(CLOCK_MONOTONIC, &t0);
    fordJohnsonVec(_vec);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    _vecTime = elapsedUs(t0, t1);

    // ── deque ─────────────────────────────────────────────────────────────
    clock_gettime(CLOCK_MONOTONIC, &t0);
    fordJohnsonDeq(_deq);
    clock_gettime(CLOCK_MONOTONIC, &t1);
    _deqTime = elapsedUs(t0, t1);
}


// ─────────────────────────────────────────────
//  Display
// ─────────────────────────────────────────────

void PmergeMe::display() const {
    // Before
    std::cout << "Before:";
    for (size_t i = 0; i < _original.size(); ++i)
        std::cout << " " << _original[i];
    std::cout << "\n";

    // After
    std::cout << "After:";
    for (size_t i = 0; i < _vec.size(); ++i)
        std::cout << " " << _vec[i];
    std::cout << "\n";

    // Timings
    std::cout << std::fixed;
    std::cout.precision(5);
    std::cout << "Time to process a range of " << _vec.size()
              << " elements with std::vector : " << _vecTime << " us\n";
    std::cout << "Time to process a range of " << _deq.size()
              << " elements with std::deque  : " << _deqTime << " us\n";
}