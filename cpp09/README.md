# C++ Module 09 – STL

In this module, we explore the Standard Template Library (STL) in C++. The STL provides a rich set of template classes and functions that facilitate data manipulation and algorithm implementation.

---

## Key Concepts Covered
- STL containers
- Iterators
- Algorithms
- Parsing/Validation
- Associative containers
- Stack usage
- Performance measurement
- Complexity

## Exercises

### ex00 BitcoinExchange
**Objective:** Understand how to manage and validate currency values in a given dataset.
- **Files:** BitcoinExchange.hpp/cpp, main.cpp, data.csv, input.txt, Makefile.
- **Behavior & Key Learning:** You will work with maps for storage, implement file parsing to read data, and validate dates and values to ensure legitimate data processing.

### ex01 RPN
**Objective:** Evaluate expressions given in Reverse Polish Notation (RPN).
- **Files:** RPN.hpp/cpp, main.cpp, Makefile.
- **Key Learning:** Learn about stack usage for expression evaluation, implement parsing techniques, and handle potential errors effectively.

### ex02 PmergeMe
**Objective:** Implement merge-insert sort using the Ford-Johnson approach on both vector and deque.
- **Files:** PmergeMe.hpp/cpp, main.cpp, file.txt, Makefile.
- **Key Learning:** Compare performance and behaviors between vector and deque while considering timing and complexity aspects of the sorting algorithm.

## Building and Running
For each exercise, you can use the following standard make targets and commands:

### ex00: BitcoinExchange
```bash
make
./BitcoinExchange input.txt
date
```
### ex01: RPN
```bash
make
./RPN
```
### ex02: PmergeMe
```bash
make
./PmergeMe file.txt
```

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 09