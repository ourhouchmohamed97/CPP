# C++ Module 08 – Templated Containers, Iterators and Algorithms

This repository contains the solutions for **CPP Module 08** from the 42 curriculum. The module focuses on **C++ Standard Template Library (STL) containers, iterators, and algorithms**.

---

## Key Concepts Covered

- **STL containers** (vector, list, stack, etc.)
- **Iterators** for container traversal
- **STL algorithms** (find, sort, min_element, max_element)
- **Template specialization** with STL
- **Container adaptors** (stack)
- **Custom iterators** for STL compatibility
- **Exception handling** with containers
- **Range operations** with iterators
- **Container inheritance** and extension

---

## Exercises

### Exercise 00: Easy find

**Objective:**  
Create a function template `easyfind` that finds the first occurrence of an integer in any STL container.

**Files:**
- `easyfind.hpp` – Template function definition
- `main.cpp` – Tests the easyfind function

**easyfind Function Template:**

```cpp
template <typename T>
void easyfind(const T& container, int value);
```

**Parameters:**
- `container` – An STL container (vector, list, deque, etc.)
- `value` – Integer value to search for

**Behavior:**
- Uses `std::find()` algorithm to search for the value
- Throws `std::exception` if value is not found
- Works with any container that provides `begin()` and `end()` iterators

**Implementation:**
```cpp
template <typename T>
void easyfind(const T& a, int b) {
    if (std::find(a.begin(), a.end(), b) == a.end())
        throw std::exception();
}
```

**Usage Example:**
```cpp
std::vector<int> vec;
vec.push_back(10);
vec.push_back(20);
vec.push_back(30);

try {
    easyfind(vec, 20);  // Success - value found
    std::cout << "Value found!" << std::endl;
    
    easyfind(vec, 99);  // Throws exception - not found
} catch (std::exception& e) {
    std::cout << "Value not found" << std::endl;
}

// Works with list too
std::list<int> lst;
lst.push_back(5);
lst.push_back(10);

try {
    easyfind(lst, 5);   // Success
} catch (std::exception& e) {
    std::cout << "Value not found" << std::endl;
}
```

**Key Learning:**
- **STL algorithms** work with any container providing iterators
- **std::find()** searches for a value in a range
- **Iterators** provide uniform interface across containers
- **begin()** and **end()** define the searchable range
- **Template functions** can work with any STL container
- **Exception-based error handling** for search failures
- **Container-agnostic algorithms** through templates
- **Iterator equality comparison** to detect end of range

---

### Exercise 01: Span

**Objective:**  
Create a `Span` class that stores integers and can find the shortest and longest span between stored numbers.

**Files:**
- `Span.hpp`, `Span.cpp` – Span class implementation
- `main.cpp` – Tests the Span class

**Span Class:**

```cpp
class Span {
    private:
        unsigned int N;              // Maximum capacity
        std::vector<int> integers;   // Storage container
    
    public:
        Span(unsigned int N);
        Span(const Span& other);
        Span& operator=(const Span& other);
        ~Span();
        
        void addNumber(int value);
        int shortestSpan();
        int longestSpan();
};
```

**Private Members:**
- `unsigned int N` – Maximum number of integers that can be stored
- `std::vector<int> integers` – Vector to store the integers

**Public Methods:**

**Constructor:**
```cpp
Span(unsigned int N);
```
- Initializes the Span with maximum capacity N
- Vector starts empty

**addNumber:**
```cpp
void addNumber(int value);
```
- Adds a single integer to the Span
- Throws `std::exception` if Span is already full (size >= N)
- Uses `vector::push_back()` to add elements

**shortestSpan:**
```cpp
int shortestSpan();
```
- Returns the shortest span (difference) between any two numbers
- Throws `std::exception` if less than 2 numbers stored
- **Algorithm:**
  1. Create a copy of the vector
  2. Sort the copy using `std::sort()`
  3. Find minimum difference between adjacent elements
  4. Return the smallest difference found

**longestSpan:**
```cpp
int longestSpan();
```
- Returns the longest span (difference) between stored numbers
- Throws `std::exception` if less than 2 numbers stored
- **Algorithm:**
  1. Find minimum element using `std::min_element()`
  2. Find maximum element using `std::max_element()`
  3. Return `max - min`

**Implementation Details:**

**shortestSpan Implementation:**
```cpp
int Span::shortestSpan() {
    if (integers.size() < 2)
        throw std::exception();

    std::vector<int> tmp(integers);
    std::sort(tmp.begin(), tmp.end());

    int shortest = tmp[1] - tmp[0];

    for (size_t i = 1; i < integers.size() - 1; i++) {
        int diff = tmp[i + 1] - tmp[i];
        if (diff < shortest)
            shortest = diff;
    }
    return shortest;
}
```

**longestSpan Implementation:**
```cpp
int Span::longestSpan() {
    if (integers.size() < 2)
        throw std::exception();
    
    int min = *std::min_element(integers.begin(), integers.end());
    int max = *std::max_element(integers.begin(), integers.end());

    return max - min;
}
```

**Usage Example:**
```cpp
// Create Span with capacity 5
Span sp(5);

sp.addNumber(6);
sp.addNumber(3);
sp.addNumber(17);
sp.addNumber(9);
sp.addNumber(11);

std::cout << sp.shortestSpan() << std::endl;  // 2 (11-9 or 9-6 in sorted: 3,6,9,11,17)
std::cout << sp.longestSpan() << std::endl;   // 14 (17-3)

// Exception handling
try {
    sp.addNumber(42);  // Throws - already full
} catch (std::exception& e) {
    std::cout << "Span is full" << std::endl;
}

Span empty(10);
try {
    empty.shortestSpan();  // Throws - less than 2 elements
} catch (std::exception& e) {
    std::cout << "Not enough elements" << std::endl;
}
```

**Bonus - Adding Multiple Numbers:**

For efficiency, you could add a method to fill the Span with a range of iterators:

```cpp
template <typename Iterator>
void addRange(Iterator begin, Iterator end) {
    while (begin != end) {
        addNumber(*begin);
        ++begin;
    }
}

// Usage:
std::vector<int> numbers;
// ... fill numbers ...
sp.addRange(numbers.begin(), numbers.end());
```

**Key Learning:**
- **std::vector** for dynamic storage
- **std::sort()** for sorting containers
- **std::min_element()** and **std::max_element()** for finding extremes
- **Iterator-based algorithms** from STL
- **Capacity management** with size checking
- **Exception handling** for error conditions
- **Sorted vs unsorted** algorithm approaches
- **Adjacent element comparison** for minimum differences
- **Vector copying** for non-destructive operations
- **STL algorithm complexity**: O(n log n) for sort, O(n) for min/max

---

### Exercise 02: Mutant stack

**Objective:**  
Create a `MutantStack` class that inherits from `std::stack` and adds iterator support, making it iterable like other STL containers.

**Files:**
- `MutantStack.hpp` – Template class definition
- `main.cpp` – Tests the MutantStack class

**MutantStack Class Template:**

```cpp
template <typename T>
class MutantStack : public std::stack<T> {
    public:
        typedef typename std::stack<T>::container_type::iterator iterator;

        MutantStack();
        MutantStack(const MutantStack& other);
        MutantStack& operator=(const MutantStack& other);
        ~MutantStack();

        iterator begin();
        iterator end();
};
```

**Key Features:**
- **Inherits from std::stack<T>** – Gets all stack functionality
- **Adds iterator support** – Makes stack iterable
- **Exposes underlying container** – Uses protected member `c`

**Type Definition:**
```cpp
typedef typename std::stack<T>::container_type::iterator iterator;
```
- Defines `iterator` type from the underlying container
- `container_type` is the underlying container (typically `std::deque`)
- `typename` keyword required for dependent types in templates

**Iterator Methods:**

**begin():**
```cpp
iterator begin() {
    return this->c.begin();
}
```
- Returns iterator to the beginning of underlying container
- `c` is protected member of `std::stack` (the underlying container)
- Allows forward iteration through stack elements

**end():**
```cpp
iterator end() {
    return this->c.end();
}
```
- Returns iterator to the end of underlying container
- Allows detecting end of iteration

**Why "Mutant"?**
- `std::stack` is a **container adaptor** that restricts access
- Normal stacks only allow top(), push(), pop()
- MutantStack "mutates" this behavior by exposing iterators
- Makes stack behave like a full container

**Implementation Details:**

**Constructors:**
```cpp
MutantStack() {}  // Default constructor
```

**Copy Constructor:**
```cpp
MutantStack(const MutantStack& other) : std::stack<T>(other) {}
```
- Calls base class copy constructor
- Copies underlying container

**Assignment Operator:**
```cpp
MutantStack& operator=(const MutantStack& other) {
    std::stack<T>::operator=(other);
    return *this;
}
```
- Calls base class assignment operator
- Returns reference for chaining

**Usage Example:**
```cpp
MutantStack<int> mstack;

// Use like a normal stack
mstack.push(5);
mstack.push(17);

std::cout << mstack.top() << std::endl;  // 17

mstack.pop();
std::cout << mstack.size() << std::endl;  // 1

mstack.push(3);
mstack.push(5);
mstack.push(737);
mstack.push(0);

// NEW: Iterate through the stack (not possible with std::stack)
MutantStack<int>::iterator it = mstack.begin();
MutantStack<int>::iterator ite = mstack.end();

while (it != ite) {
    std::cout << *it << std::endl;
    ++it;
}

// Can also use with range-based for loop (C++11)
// for (int value : mstack) {
//     std::cout << value << std::endl;
// }

// Convert to std::stack (loses iterator capability)
std::stack<int> s(mstack);
```

**Comparison with std::list:**

MutantStack should produce the same output as std::list:

```cpp
// Using std::list
std::list<int> lst;
lst.push_back(5);
lst.push_back(17);
lst.pop_back();
lst.push_back(3);
lst.push_back(5);
lst.push_back(737);
lst.push_back(0);

// Iterate
for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it)
    std::cout << *it << std::endl;

// Should produce same output as MutantStack iteration
```

**Key Learning:**
- **Container adaptors** (stack, queue, priority_queue)
- **Inheritance from STL classes** (possible but use with care)
- **Protected members** of STL classes (`c` in stack)
- **Iterator type definitions** with `typedef`
- **typename keyword** for dependent types in templates
- **Exposing underlying container** of adaptors
- **begin()** and **end()** methods for STL compatibility
- **Container adaptor limitations** and how to overcome them
- **std::stack internals** (usually uses std::deque)
- **Template inheritance** syntax
- **Why stacks normally don't have iterators** (LIFO access pattern)

---

## Building and Running

Each exercise contains a Makefile with the following targets:

```bash
make        # Compile the program
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

**Compilation:**
- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`

**Running:**

```bash
# Exercise 00
cd ex00
make
./easyfind

# Exercise 01
cd ex01
make
./Span

# Exercise 02
cd ex02
make
./MutantStack
```

---

## Key Takeaways

### STL Containers Overview

**Sequence Containers:**
- `std::vector` – Dynamic array, fast random access
- `std::list` – Doubly-linked list, fast insertion/deletion
- `std::deque` – Double-ended queue, fast at both ends

**Container Adaptors:**
- `std::stack` – LIFO (Last In, First Out)
- `std::queue` – FIFO (First In, First Out)
- `std::priority_queue` – Sorted queue

**Associative Containers:**
- `std::set` – Sorted unique elements
- `std::map` – Key-value pairs, sorted by key
- `std::multiset`, `std::multimap` – Allow duplicates

### Iterators

**What are Iterators?**
- Objects that point to elements in a container
- Provide uniform access across different container types
- Work like generalized pointers
- Enable generic algorithms

**Iterator Categories:**

1. **Input Iterator** – Read only, forward only (once)
2. **Output Iterator** – Write only, forward only
3. **Forward Iterator** – Read/write, forward only (multi-pass)
4. **Bidirectional Iterator** – Read/write, forward and backward
5. **Random Access Iterator** – Read/write, jump to any position

**Common Operations:**
```cpp
*it        // Dereference (access element)
++it       // Move to next element
it++       // Move to next element (post-increment)
--it       // Move to previous element (bidirectional+)
it + n     // Jump n positions (random access)
it == it2  // Compare iterators
it != it2  // Compare iterators
```

**Usage Pattern:**
```cpp
for (Container::iterator it = container.begin(); 
     it != container.end(); 
     ++it) {
    std::cout << *it << std::endl;
}
```

### STL Algorithms

**Search Algorithms:**
```cpp
std::find(begin, end, value)           // Find first occurrence
std::find_if(begin, end, predicate)    // Find with condition
std::binary_search(begin, end, value)  // Binary search (sorted)
std::count(begin, end, value)          // Count occurrences
```

**Sorting Algorithms:**
```cpp
std::sort(begin, end)                  // Sort ascending
std::sort(begin, end, comparator)      // Sort with custom comparison
std::reverse(begin, end)               // Reverse order
```

**Min/Max Algorithms:**
```cpp
std::min_element(begin, end)           // Find minimum
std::max_element(begin, end)           // Find maximum
std::minmax_element(begin, end)        // Find both (C++11)
```

**Modifying Algorithms:**
```cpp
std::copy(src_begin, src_end, dst_begin)       // Copy elements
std::fill(begin, end, value)                   // Fill with value
std::transform(begin, end, out, function)      // Apply function
std::replace(begin, end, old_val, new_val)     // Replace values
```

**Important Notes:**
- Most algorithms work with **iterator ranges** `[begin, end)`
- `end` iterator points **one past** the last element
- Algorithms are **generic** – work with any container providing compatible iterators
- Many algorithms require **sorted ranges** (binary_search, lower_bound, etc.)

### Container Adaptor Pattern

**What are Container Adaptors?**
- Provide restricted interface to underlying container
- Implement specific data structure behaviors
- Use composition, not full container features

**std::stack:**
```cpp
// Underlying container: std::deque (default)
template <class T, class Container = std::deque<T>>
class stack;

// Operations:
push()    // Add to top
pop()     // Remove from top
top()     // Access top element
empty()   // Check if empty
size()    // Get number of elements
```

**Why No Iterators?**
- Stacks enforce LIFO access pattern
- Iteration would break encapsulation
- Use different container if iteration needed
- MutantStack breaks this rule intentionally

**Accessing Protected Members:**
- `std::stack` has protected member `c` (the container)
- Derived classes can access `c`
- Enables extending adaptor functionality

---

## Common Patterns and Best Practices

### 1. Using STL Algorithms

✅ **Use STL algorithms** instead of writing loops  
✅ **Include `<algorithm>`** for algorithm functions  
✅ **Use `begin()` and `end()`** for iterator ranges  
✅ **Check return values** (e.g., `find()` returns `end()` if not found)  
❌ **Don't modify containers** while iterating (undefined behavior)

**Example - Finding Elements:**
```cpp
// ❌ Manual loop
bool found = false;
for (size_t i = 0; i < vec.size(); i++) {
    if (vec[i] == value) {
        found = true;
        break;
    }
}

// ✅ STL algorithm
if (std::find(vec.begin(), vec.end(), value) != vec.end()) {
    // found
}
```

### 2. Iterator Usage

✅ **Use `const_iterator`** for read-only access  
✅ **Prefer prefix `++it`** over postfix `it++` (more efficient)  
✅ **Check for `end()`** before dereferencing  
❌ **Don't dereference `end()` iterator** (undefined behavior)

```cpp
// ✅ Correct
Container::iterator it = container.begin();
while (it != container.end()) {
    // Use *it
    ++it;
}

// ❌ Wrong
Container::iterator it = container.end();
std::cout << *it;  // Undefined behavior!
```

### 3. Exception Safety

✅ **Throw exceptions** for error conditions  
✅ **Use meaningful exception types** when possible  
✅ **Check preconditions** before operations  
✅ **Document exception behavior** in comments

```cpp
int Span::shortestSpan() {
    if (integers.size() < 2)
        throw std::exception();
    // ... implementation
}
```

### 4. Template Best Practices

✅ **Put template definitions in headers**  
✅ **Use `typename` for dependent types**  
✅ **Document template requirements** (what types work)  
✅ **Test with multiple types** (int, string, custom classes)

```cpp
// Document requirements
// T must support:
// - begin() and end() methods
// - Iterator with operator++, operator*, operator==
template <typename T>
void easyfind(const T& container, int value);
```

### 5. Container Choice

**Use `std::vector` when:**
- Need fast random access
- Elements added/removed at end
- Memory efficiency important

**Use `std::list` when:**
- Frequent insertion/deletion in middle
- Don't need random access
- Iterator stability important

**Use `std::deque` when:**
- Need fast insertion at both ends
- Need random access
- Used internally by stack/queue

### 6. Inheriting from STL Classes

⚠️ **Use with caution** – STL classes not designed for inheritance  
⚠️ **No virtual destructors** – don't delete derived through base pointer  
✅ **OK for adding functionality** – like MutantStack  
❌ **Don't override behavior** – will break STL assumptions

```cpp
// ✅ OK - Adding functionality
class MutantStack : public std::stack<T> {
    // Add iterators
};

// ❌ Dangerous - Deleting through base
std::stack<int>* s = new MutantStack<int>();
delete s;  // Won't call MutantStack destructor!
```

---

## Important Concepts

### Iterators vs Pointers

**Similarities:**
- Both can be dereferenced (`*it`, `*ptr`)
- Both can be incremented (`++it`, `++ptr`)
- Both represent positions

**Differences:**
- Iterators are **objects**, pointers are **built-in types**
- Iterators are **type-safe**, pointers are not
- Iterators work with **any container**, pointers only with arrays
- Iterators can be **invalidated** by container modifications

### Iterator Invalidation

**When are iterators invalidated?**

**std::vector:**
- `push_back()` – May invalidate if reallocation occurs
- `insert()` – Invalidates all iterators
- `erase()` – Invalidates at and after erase point

**std::list:**
- `push_back()`, `push_front()` – No invalidation
- `insert()` – No invalidation
- `erase()` – Only erased element's iterator

**Rule of thumb:** Don't modify containers while iterating!

### Algorithm Complexity

**O(1) – Constant:**
- `vector::push_back()` (amortized)
- `stack::push()`, `stack::pop()`
- `list::push_front()`, `list::push_back()`

**O(n) – Linear:**
- `std::find()` – Must check each element
- `std::min_element()`, `std::max_element()`
- `vector::insert()` at beginning

**O(n log n) – Log-linear:**
- `std::sort()` – Quicksort/introsort

**O(log n) – Logarithmic:**
- `std::binary_search()` (on sorted range)
- `map::find()`, `set::find()`

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 08
