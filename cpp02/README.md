# C++ Module 02 – Fixed-Point Numbers & Operator Overloading

This repository contains the solutions for **CPP Module 02** from the 42 curriculum. The module focuses on **ad-hoc polymorphism, operator overloading, and the Orthodox Canonical Form**. 

---

## Key Concepts Covered

- **Orthodox Canonical Form** (OCF) - The Rule of Three
- **Fixed-point arithmetic** representation
- **Operator overloading** (arithmetic, comparison, increment/decrement)
- **Stream insertion operator** (`<<`)
- **Static member functions**
- **Float to fixed-point conversion** and vice versa

---

## Exercises

### Exercise 00: My First Class in Orthodox Canonical Form

**Objective:**  
Implement a simple Fixed-point number class following the Orthodox Canonical Form (OCF).

**Files:**
- `Fixed.hpp`, `Fixed.cpp` – Fixed-point number class
- `main.cpp` – Tests the Fixed class

**Fixed Class:**
- Private members: 
  - `int value` – Stores the fixed-point value
  - `static const int fractional = 8` – Number of fractional bits
- Public methods:
  - `Fixed()` – Default constructor (initializes to 0)
  - `Fixed(const Fixed& other)` – Copy constructor
  - `Fixed& operator=(const Fixed& other)` – Copy assignment operator
  - `~Fixed()` – Destructor
  - `int getRawBits(void) const` – Returns raw value
  - `void setRawBits(int const raw)` – Sets raw value

**Key Learning:**
- **Orthodox Canonical Form** requires: 
  1. Default constructor
  2. Copy constructor
  3. Copy assignment operator
  4. Destructor
- Fixed-point numbers store fractional values as integers by scaling
- 8 fractional bits means values are multiplied by 256 (2^8)
- Proper self-assignment check in copy assignment operator

---

### Exercise 01: Towards a more useful fixed-point number class

**Objective:**  
Extend the Fixed class with constructors for int and float, conversion methods, and stream insertion operator.

**Files:**
- `Fixed.hpp`, `Fixed.cpp` – Enhanced Fixed-point class
- `main.cpp` – Tests conversions and output

**New Features:**
- Constructors: 
  - `Fixed(const int n)` – Converts int to fixed-point
  - `Fixed(const float f)` – Converts float to fixed-point
- Conversion methods:
  - `float toFloat(void) const` – Converts to floating-point
  - `int toInt(void) const` – Converts to integer
- Overloaded operator:
  - `std::ostream& operator<<(std::ostream& os, const Fixed& fixed)` – Stream insertion

**Implementation Details:**
- **Int to fixed:** `value = n << fractional` (multiply by 256)
- **Float to fixed:** `value = roundf(f * (1 << fractional))` (scale and round)
- **Fixed to float:** `return (float)value / (1 << fractional)` (divide by 256)
- **Fixed to int:** `return value >> fractional` (divide by 256, truncate)

**Key Learning:**
- Bit shifting for efficient multiplication/division by powers of 2
- Using `roundf()` for proper float conversion
- Stream insertion operator must be a non-member function
- Proper use of `const` in conversion methods

---

### Exercise 02: Now we're talking

**Objective:**  
Implement a complete set of operator overloads for the Fixed class.

**Files:**
- `Fixed.hpp`, `Fixed.cpp` – Fully overloaded Fixed class
- `main.cpp` – Tests all operators

**Overloaded Operators:**

**Comparison operators:**
- `bool operator<(const Fixed& other) const`
- `bool operator<=(const Fixed& other) const`
- `bool operator>(const Fixed& other) const`
- `bool operator>=(const Fixed& other) const`
- `bool operator==(const Fixed& other) const`
- `bool operator!=(const Fixed& other) const`

**Arithmetic operators:**
- `Fixed operator+(const Fixed& other) const`
- `Fixed operator-(const Fixed& other) const`
- `Fixed operator*(const Fixed& other) const`
- `Fixed operator/(const Fixed& other) const`

**Increment/Decrement operators:**
- `Fixed& operator++()` – Pre-increment
- `Fixed operator++(int)` – Post-increment
- `Fixed& operator--()` – Pre-decrement
- `Fixed operator--(int)` – Post-decrement

**Static member functions:**
- `static Fixed& min(Fixed& a, Fixed& b)` – Returns reference to smaller
- `static const Fixed& min(const Fixed& a, const Fixed& b)` – Const version
- `static Fixed& max(Fixed& a, Fixed& b)` – Returns reference to larger
- `static const Fixed& max(const Fixed& a, const Fixed& b)` – Const version

**Key Implementation Notes:**
- Comparison:  Compare raw `value` directly
- Addition/Subtraction: Operate on raw values directly
- **Multiplication**:  `result.value = (this->value * other.value) >> fractional`
  - Multiply then right-shift to correct scale
- **Division**: `result.value = (this->value << fractional) / other.value`
  - Left-shift numerator before dividing
- Pre-increment:  Increment then return reference to self
- Post-increment: Save copy, increment, return old copy

**Key Learning:**
- Difference between pre and post increment/decrement operators
- Fixed-point multiplication requires shifting result back
- Fixed-point division requires scaling dividend first
- Static member functions for utility operations
- Function overloading with const and non-const versions

---

### Exercise 03: BSP (Binary Space Partitioning)

**Objective:**  
Implement a function to determine if a point is inside a triangle using the Fixed class.

**Files:**
- `Fixed.hpp`, `Fixed.cpp` – Fixed class from ex02
- `Point.hpp`, `Point.cpp` – Point class with const Fixed coordinates
- `bsp.cpp` – Binary Space Partitioning implementation
- `main.cpp` – Tests point-in-triangle detection

**Point Class:**
- Private members:
  - `const Fixed x` – X coordinate
  - `const Fixed y` – Y coordinate
- Public methods:
  - `Point()` – Default constructor
  - `Point(const float f1, const float f2)` – Constructor with coordinates
  - `Point(const Point& other)` – Copy constructor
  - `Point& operator=(const Point& other)` – Copy assignment
  - `~Point()` – Destructor
  - `Fixed getX() const` – Returns x coordinate
  - `Fixed getY() const` – Returns y coordinate

**BSP Function:**
```cpp
bool bsp(Point const a, Point const b, Point const c, Point const point);
```
- Returns `true` if point is strictly inside the triangle ABC
- Returns `false` if point is on edge or vertex
- Returns `false` if point is outside

**Algorithm:**
Uses the sign of cross products to determine position:
1. Calculate `sign()` for three sub-triangles formed with the point
2. If all signs are the same, point is inside
3. If any sign is zero, point is on an edge (return false)
4. If signs differ, point is outside

**Key Learning:**
- Using `const` member variables (must be initialized in initializer list)
- Copy assignment with const members (cannot reassign)
- Practical application of Fixed-point arithmetic
- Geometric algorithms with custom numeric types
- Cross product for point-triangle orientation testing

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

---

## Key Takeaways

1. **Orthodox Canonical Form** is essential for proper resource management
2. **Operator overloading** makes custom types behave like built-in types
3. **Fixed-point arithmetic** is useful for embedded systems and deterministic calculations
4. **Bit shifting** provides efficient multiplication/division by powers of 2
5. **Const correctness** improves code safety and allows method overloading
6. **Static member functions** provide utility operations without requiring an instance

---

## Author
Mohamed OURHOUCH
42 School Project - CPP Module 02
