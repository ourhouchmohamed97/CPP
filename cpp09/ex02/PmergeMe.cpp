#include "PmergeMe.hpp"

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
    for (int i = 1; i < argc; ++i) {
        std::string token(argv[i]);

        if (token.empty())
            throw std::runtime_error("empty token");

        for (size_t j = 0; j < token.size(); ++j) {
            if (!std::isdigit(static_cast<unsigned char>(token[j])))
                throw std::runtime_error("invalid character: " + token);
        }

        long val = std::strtol(token.c_str(), NULL, 10);
        if (val <= 0 || val > INT_MAX)
            throw std::runtime_error("out of range: " + token);

        int num = static_cast<int>(val);
        _vec.push_back(num);
        _deq.push_back(num);
        _original.push_back(num);
    }

    if (_vec.empty())
        throw std::runtime_error("no input");
}

// ─────────────────────────────────────────────
//  Jacobsthal order helper
//  Returns pend indices in Ford-Johnson insertion order.
//  e.g. for n=5 pend elements → [1, 3, 2, 5, 4]
// ─────────────────────────────────────────────

std::vector<int> PmergeMe::getJacobsthalOrder(int n) {
    std::vector<int> jacob;
    jacob.push_back(0);
    jacob.push_back(1);
    while (jacob.back() < n)
        jacob.push_back(jacob[jacob.size()-1] + 2 * jacob[jacob.size()-2]);

    std::vector<int> order;
    for (size_t k = 1; k < jacob.size(); ++k) {
        int high = std::min(jacob[k], n);
        int low = jacob[k-1] + 1;
        for (int idx = high; idx >= low; --idx)
            order.push_back(idx);
        if (high >= n) break;
    }
    return order;
}

// ─────────────────────────────────────────────
//  Binary insert
// ─────────────────────────────────────────────

void PmergeMe::binaryInsertVec(std::vector<int> &chain, int val, int end) {
    int left = 0, right = end;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, val);
}

void PmergeMe::binaryInsertDeq(std::deque<int> &chain, int val, int end) {
    int left = 0, right = end;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (chain[mid] < val)
            left = mid + 1;
        else
            right = mid;
    }
    chain.insert(chain.begin() + left, val);
}

// ─────────────────────────────────────────────
//  Ford-Johnson sort — std::vector
// ─────────────────────────────────────────────
 
void PmergeMe::fordJohnsonVec(std::vector<int> &seq) {
    int n = static_cast<int>(seq.size());
    if (n <= 1)
        return;
 
    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? seq[n - 1] : 0;

    std::vector<std::pair<int,int> > pairs;
    int limit = n - (hasStraggler ? 1 : 0);
    for (int i = 0; i + 1 < limit; i += 2) {
        if (seq[i] >= seq[i + 1])
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            pairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }
 
    std::vector<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
 
    fordJohnsonVec(winners);
 
    std::vector<std::pair<int,int> > sortedPairs;
    std::vector<std::pair<int,int> > remaining = pairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < remaining.size(); ++j) {
            if (remaining[j].first == winners[i]) {
                sortedPairs.push_back(remaining[j]);
                remaining.erase(remaining.begin() + j);
                break;
            }
        }
    }

    std::vector<int> chain;
    chain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        chain.push_back(sortedPairs[i].first);

    int pendCount = static_cast<int>(sortedPairs.size()) - 1;
    if (pendCount > 0) {
        std::vector<int> order = getJacobsthalOrder(pendCount);
        for (size_t k = 0; k < order.size(); ++k) {
            int idx       = order[k];
            int val       = sortedPairs[idx].second;
            int winnerVal = sortedPairs[idx].first;
 
            int bound = static_cast<int>(
                std::lower_bound(chain.begin(), chain.end(), winnerVal) - chain.begin()
            ) + 1;
 
            binaryInsertVec(chain, val, bound);
        }
    }

    if (hasStraggler)
        binaryInsertVec(chain, straggler, static_cast<int>(chain.size()));

    seq = chain;
}

// ─────────────────────────────────────────────
//  Ford-Johnson sort — std::deque
// ─────────────────────────────────────────────

void PmergeMe::fordJohnsonDeq(std::deque<int> &seq) {
    int n = static_cast<int>(seq.size());
    if (n <= 1)
        return;

    bool hasStraggler = (n % 2 != 0);
    int  straggler    = hasStraggler ? seq[n - 1] : 0;
 
    std::deque<std::pair<int,int> > pairs;
    int limit = n - (hasStraggler ? 1 : 0);
    for (int i = 0; i + 1 < limit; i += 2) {
        if (seq[i] >= seq[i + 1])
            pairs.push_back(std::make_pair(seq[i], seq[i + 1]));
        else
            pairs.push_back(std::make_pair(seq[i + 1], seq[i]));
    }
 
    std::deque<int> winners;
    for (size_t i = 0; i < pairs.size(); ++i)
        winners.push_back(pairs[i].first);
 
    fordJohnsonDeq(winners);

    std::deque<std::pair<int,int> > sortedPairs;
    std::deque<std::pair<int,int> > remaining = pairs;
    for (size_t i = 0; i < winners.size(); ++i) {
        for (size_t j = 0; j < remaining.size(); ++j) {
            if (remaining[j].first == winners[i]) {
                sortedPairs.push_back(remaining[j]);
                remaining.erase(remaining.begin() + j);
                break;
            }
        }
    }

    std::deque<int> chain;
    chain.push_back(sortedPairs[0].second);
    for (size_t i = 0; i < sortedPairs.size(); ++i)
        chain.push_back(sortedPairs[i].first);
 
    int pendCount = static_cast<int>(sortedPairs.size()) - 1;
    if (pendCount > 0) {
        std::vector<int> order = getJacobsthalOrder(pendCount);
        for (size_t k = 0; k < order.size(); ++k) {
            int idx       = order[k];
            int val       = sortedPairs[idx].second;
            int winnerVal = sortedPairs[idx].first;
 
            int bound = static_cast<int>(
                std::lower_bound(chain.begin(), chain.end(), winnerVal) - chain.begin()
            ) + 1;
 
            binaryInsertDeq(chain, val, bound);
        }
    }

    if (hasStraggler)
        binaryInsertDeq(chain, straggler, static_cast<int>(chain.size()));
 
    seq = chain;
}

// ─────────────────────────────────────────────
//  sort() — time both algorithms
// ─────────────────────────────────────────────

static double elapsedUs(struct timespec &start, struct timespec &end) {
    return (end.tv_sec  - start.tv_sec)  * 1e6
         + (end.tv_nsec - start.tv_nsec) / 1e3;
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
//  display()
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