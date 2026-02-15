# C++ Module 07 – Templates

This repository contains the solutions for **CPP Module 07** from the 42 curriculum. The module focuses on **C++ templates, function templates, class templates, and template specialization**.

---

## Key Concepts Covered

- **Function templates** for generic programming
- **Class templates** for generic containers
- **Template instantiation** at compile-time
- **Template parameters** (type and non-type)
- **Template specialization**
- **Generic algorithms** (swap, min, max)
- **Type-safe generic containers**
- **Deep copy** with templates
- **Exception handling** with templates

---

## Exercises

### Exercise 00: A few functions

**Objective:**  
Create function templates for common utility functions: `swap`, `min`, and `max`.

**Files:**
- `whatever.hpp` – Template function definitions
- `main.cpp` – Tests the template functions

**Function Templates:**

**1. swap**
```cpp
template <typename T>
void swap(T &a, T &b);
```
- Swaps the values of two arguments
- Works with any type that has copy assignment
- Parameters passed by reference to modify originals

**2. min**
```cpp
template <typename T>
T min(T a, T b);
```
- Returns the smaller of two values
- If values are equal, returns the second one
- Requires type T to support comparison operator `<`

**3. max**
```cpp
template <typename T>
T max(T a, T b);
```
- Returns the larger of two values
- If values are equal, returns the second one
- Requires type T to support comparison operator `>`

**Usage Example:**
```cpp
int a = 2;
int b = 3;

::swap(a, b);  // a = 3, b = 2
std::cout << ::min(a, b) << std::endl;  // 2
std::cout << ::max(a, b) << std::endl;  // 3

std::string c = "chaine1";
std::string d = "chaine2";

::swap(c, d);  // c = "chaine2", d = "chaine1"
std::cout << ::min(c, d) << std::endl;  // chaine1
std::cout << ::max(c, d) << std::endl;  // chaine2
```

**Key Learning:**
- **Function templates** allow writing generic, type-independent code
- **Template instantiation** happens at compile-time
- Templates work with any type that satisfies requirements (e.g., has `<` operator)
- **::** operator ensures we call our template functions, not std:: versions
- Templates are defined in **header files** (no separate .cpp)
- Type deduction from function arguments
- Same code works for `int`, `double`, `std::string`, and custom types

---

### Exercise 01: Iter

**Objective:**  
Create a function template `iter` that applies a function to each element of an array.

**Files:**
- `iter.hpp` – Template function definitions
- `main.cpp` – Tests the iter function

**iter Function Template:**

```cpp
template <typename T, typename F>
void iter(T *arr, const size_t len, F func);
```

**Parameters:**
- `arr` – Pointer to the first element of the array
- `len` – Length of the array
- `func` – Function to apply to each element (can be function pointer or function template)

**Implementation:**
- Iterates through the array from index 0 to `len - 1`
- Applies `func` to each element
- Works with any array type and any compatible function

**Helper Function Templates:**

**print**
```cpp
template <typename T>
void print(T const &x);
```
- Prints the value of x to standard output
- Works with any type that has `<<` operator

**increment**
```cpp
template <typename T>
void increment(T &x);
```
- Increments the value of x by 1
- Requires type T to support `++` operator
- Takes parameter by reference to modify original

**Usage Example:**
```cpp
int arr[] = {1, 2, 3, 4, 5};
size_t len = 5;

// Print all elements
iter(arr, len, print<int>);

// Increment all elements
iter(arr, len, increment<int>);

// Print again to see changes
iter(arr, len, print<int>);

// Works with strings too
std::string strs[] = {"hello", "world"};
iter(strs, 2, print<std::string>);
```

**Key Learning:**
- **Generic algorithms** that work with any array type
- **Function templates as parameters** to other templates
- **Two template parameters**: one for array type, one for function type
- **Type deduction** allows compiler to infer template arguments
- **Callback pattern** implemented with templates
- Templates enable **compile-time polymorphism** (no runtime overhead)
- `const` correctness with template parameters
- Array iteration without knowing the specific type

---

### Exercise 02: Array

**Objective:**  
Create a class template `Array` that implements a generic array with bounds checking.

**Files:**
- `Array.hpp` – Class template declaration
- `Array.tpp` – Class template implementation (included in .hpp)
- `main.cpp` – Tests the Array class template

**Array Class Template:**

```cpp
template <typename T>
class Array {
    private:
        T*              _arr;
        unsigned int    _size;
    
    public:
        Array();
        Array(unsigned int n);
        Array(const Array& other);
        Array& operator=(const Array& other);
        ~Array();
        
        T& operator[](unsigned int index);
        const T& operator[](unsigned int index) const;
        unsigned int size() const;
};
```

**Private Members:**
- `T* _arr` – Pointer to dynamically allocated array
- `unsigned int _size` – Size of the array

**Public Methods:**

**Constructors:**
- `Array()` – Default constructor, creates empty array (size 0)
- `Array(unsigned int n)` – Creates array of size n with default-initialized elements
- `Array(const Array& other)` – Copy constructor (performs deep copy)

**Assignment:**
- `Array& operator=(const Array& other)` – Copy assignment operator (deep copy)

**Destructor:**
- `~Array()` – Deallocates the array

**Access:**
- `T& operator[](unsigned int index)` – Subscript operator for element access
- `const T& operator[](unsigned int index) const` – Const version of subscript operator
- Throws `std::exception` if index is out of bounds

**Size:**
- `unsigned int size() const` – Returns the number of elements

**Implementation Details:**

**Default Constructor:**
```cpp
Array() : _arr(NULL), _size(0) {}
```

**Parameterized Constructor:**
```cpp
Array(unsigned int n) : _arr(new T[n]()), _size(n) {}
```
- Allocates array with `new T[n]()`
- `()` ensures default initialization (zeros for numeric types)

**Copy Assignment:**
```cpp
Array& operator=(const Array& other) {
    if (this != &other) {
        delete[] _arr;
        _size = other._size;
        _arr = new T[_size]();
        for (unsigned int i = 0; i < _size; i++)
            _arr[i] = other._arr[i];
    }
    return *this;
}
```
- Checks for self-assignment
- Deletes old array
- Allocates new array
- Copies all elements (deep copy)

**Subscript Operator:**
```cpp
T& operator[](unsigned int index) {
    if (index >= _size)
        throw std::exception();
    return _arr[index];
}
```
- Validates index is within bounds
- Throws exception if out of bounds
- Returns reference for modification

**Usage Example:**
```cpp
// Create empty array
Array<int> empty;
std::cout << empty.size() << std::endl;  // 0

// Create array of size 5
Array<int> numbers(5);
numbers[0] = 10;
numbers[1] = 20;

// Copy constructor (deep copy)
Array<int> copy(numbers);
copy[0] = 999;  // Does not affect numbers

// Assignment operator (deep copy)
Array<int> assigned;
assigned = numbers;
assigned[1] = 888;  // Does not affect numbers

// Out-of-bounds access throws exception
try {
    numbers[10] = 100;
} catch (std::exception &) {
    std::cout << "Index out of bounds" << std::endl;
}

// Works with any type
Array<std::string> strs(2);
strs[0] = "hello";
strs[1] = "world";
```

**Key Learning:**
- **Class templates** for generic containers
- **Template implementation in .tpp file** (included by .hpp)
- **Dynamic memory allocation** with templates
- **Deep copy** implementation (copy constructor and assignment operator)
- **RAII** (Resource Acquisition Is Initialization) pattern
- **Bounds checking** with exception throwing
- **Const overloading** for subscript operator
- **Self-assignment check** in assignment operator
- **Default initialization** with `new T[n]()`
- Templates work with built-in types and custom classes
- **Exception safety** in memory management

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
./whatever

# Exercise 01
cd ex01
make
./iter

# Exercise 02
cd ex02
make
./array
```

---

## Key Takeaways

### Template Basics

**Function Templates:**
```cpp
template <typename T>
T functionName(T param) {
    // Implementation
}
```

**Class Templates:**
```cpp
template <typename T>
class ClassName {
    T member;
public:
    T method(T param);
};
```

**Key Points:**
1. **Defined in header files** – Templates must be visible at compile-time
2. **Instantiated at compile-time** – Compiler generates code for each type used
3. **Type deduction** – Compiler can infer template arguments from function parameters
4. **Type-safe** – Each instantiation is type-checked
5. **No runtime overhead** – Templates resolved at compile-time

### Template Syntax

**typename vs class:**
```cpp
template <typename T>  // Preferred in modern C++
template <class T>     // Equivalent, but older convention
```

**Multiple template parameters:**
```cpp
template <typename T, typename U>
void function(T a, U b);
```

**Non-type template parameters:**
```cpp
template <typename T, int N>
class Array {
    T data[N];
};
```

### Template Implementation

**Why templates go in headers:**
- Compiler needs full definition to instantiate templates
- Cannot separate declaration and definition like regular classes
- Common pattern: `.hpp` includes `.tpp` (template implementation)

**Template instantiation:**
```cpp
Array<int> intArray;      // Compiler generates Array<int>
Array<std::string> strArray;  // Compiler generates Array<std::string>
```

### Deep Copy with Templates

**Critical for managing resources:**
```cpp
template <typename T>
class Container {
    T* data;
public:
    // Copy constructor
    Container(const Container& other) {
        data = new T[other.size];
        // Copy elements
    }
    
    // Assignment operator
    Container& operator=(const Container& other) {
        if (this != &other) {
            delete[] data;
            data = new T[other.size];
            // Copy elements
        }
        return *this;
    }
};
```

### Generic Programming Benefits

**1. Code Reusability:**
- Write once, use with any type
- Reduces code duplication

**2. Type Safety:**
- Compile-time type checking
- No need for casting

**3. Performance:**
- No runtime overhead
- Inlined by compiler

**4. Maintainability:**
- Single implementation to maintain
- Changes propagate to all uses

---

## Common Patterns and Best Practices

### 1. Template Organization

✅ **Keep templates in headers**  
✅ **Use .tpp extension for implementations** (optional but clear)  
✅ **Include .tpp at end of .hpp**  
❌ **Don't put template implementations in .cpp**

### 2. Template Constraints

**Requirements documentation:**
```cpp
// T must support:
// - Default constructor
// - Copy constructor
// - Assignment operator
// - Comparison operator <
template <typename T>
T min(T a, T b);
```

### 3. Const Correctness

**Two versions of subscript operator:**
```cpp
T& operator[](unsigned int index);           // Non-const access
const T& operator[](unsigned int index) const;  // Const access
```

### 4. Exception Safety

**Strong exception guarantee:**
- Operation either completes successfully or has no effect
- Important in copy assignment operator

**Example:**
```cpp
template <typename T>
Array<T>& Array<T>::operator=(const Array& other) {
    if (this != &other) {
        T* temp = new T[other._size]();  // Allocate first
        delete[] _arr;                    // Delete old
        _arr = temp;                      // Assign new
        // Copy data
    }
    return *this;
}
```

### 5. Self-Assignment Check

**Always check in assignment operator:**
```cpp
if (this != &other) {
    // Perform assignment
}
```

---

## Advanced Template Concepts

### Template Specialization

**Full specialization:**
```cpp
template <>
class Array<bool> {
    // Specialized implementation for bool
};
```

**Partial specialization (classes only):**
```cpp
template <typename T>
class Array<T*> {
    // Specialized for pointers
};
```

### Template Type Deduction

**Automatic deduction:**
```cpp
template <typename T>
void print(T value);

print(42);        // T deduced as int
print("hello");   // T deduced as const char*
```

**Explicit specification:**
```cpp
print<double>(42);  // T explicitly set to double
```

### SFINAE (Substitution Failure Is Not An Error)

**Advanced technique for template constraints:**
- Enables conditional compilation
- Used in C++98 for template metaprogramming
- Superseded by concepts in C++20

---


---

## Compilation Model

### Traditional Compilation (Non-Templates)

```
Header (.hpp) → Declaration only
Source (.cpp) → Implementation
Object (.o)   → Compiled code
Linking       → Combines object files
```

### Template Compilation

```
Header (.hpp) → Declaration + Implementation
Usage (main.cpp) → Compiler generates specific instantiation
No separate object file for templates
```

**Why?**
- Templates are not code, they are **blueprints for code**
- Compiler needs full definition to generate actual code
- Each instantiation is a different type

---

## Testing Strategy

### Test Cases for Templates

**1. Basic Functionality:**
- Default construction
- Parameterized construction
- Element access
- Size query

**2. Copy Semantics:**
- Copy constructor
- Assignment operator
- Verify deep copy (modifications don't affect original)

**3. Edge Cases:**
- Empty arrays
- Single element
- Large arrays
- Out-of-bounds access

**4. Multiple Types:**
- Built-in types (int, double, char)
- Standard library types (std::string)
- Custom classes

**5. Const Correctness:**
- Const objects
- Const member functions
- Const parameters

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 07
