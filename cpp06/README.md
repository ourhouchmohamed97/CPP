# C++ Module 06 – Type Casting

This repository contains the solutions for **CPP Module 06** from the 42 curriculum. The module focuses on **C++ type casting, including static_cast, reinterpret_cast, dynamic_cast, and scalar type conversions**.

---

## Key Concepts Covered

- **Type casting** in C++
- **static_cast** for compile-time conversions
- **reinterpret_cast** for low-level pointer conversions
- **dynamic_cast** for runtime type identification
- **const_cast** for removing const qualifiers
- **Scalar type conversions** (char, int, float, double)
- **Type detection** and **validation**
- **Serialization** and **deserialization**
- **Runtime type identification (RTTI)**
- **Pseudo-literals** (nan, inf)

---

## Exercises

### Exercise 00: Conversion of scalar types

**Objective:**  
Create a `ScalarConverter` class that converts string representations to all scalar types (char, int, float, double).

**Files:**
- `ScalarConverter.hpp`, `ScalarConverter.cpp` – Conversion logic
- `check.cpp` – Helper functions for type detection
- `main.cpp` – Tests the converter

**ScalarConverter Class:**

**Private Members:**
- Private constructors and destructor (non-instantiable class)
- Copy constructor and assignment operator (non-instantiable)

**Public Static Methods:**
- `static void convert(const std::string& value)` – Main conversion function
- `static void toChar(double d)` – Converts to char
- `static void toInt(double d)` – Converts to int
- `static void toFloat(double d)` – Converts to float
- `static void toDouble(double d)` – Converts to double

**Helper Functions (check.cpp):**
- `bool isPseudo(const std::string& value)` – Detects pseudo-literals (nan, inf)
- `bool isChar(const std::string& value)` – Detects single character input
- `bool isInt(const std::string& value)` – Detects integer format
- `bool isFloat(const std::string& value)` – Detects float format (ends with 'f')
- `bool isDouble(const std::string& value)` – Detects double format

**Input Types:**
- **Char literals**: `'a'`, `'z'`, `'0'` (single non-digit character)
- **Integer literals**: `0`, `42`, `-42`, `+42`
- **Float literals**: `0.0f`, `42.42f`, `-42.0f`
- **Double literals**: `0.0`, `42.42`, `-42.0`
- **Pseudo-literals**: `nan`, `nanf`, `+inf`, `-inf`, `+inff`, `-inff`

**Output Format:**
```
char: 'c'
int: 42
float: 42.0f
double: 42.0
```

**Special Cases:**
- **impossible**: Conversion not possible (e.g., "nan" to int)
- **Non displayable**: Character exists but cannot be displayed

**Key Learning:**
- **static_cast<>()** for standard type conversions
- **Type detection** using string parsing
- **std::strtod()** for string to double conversion
- **std::isnan()**, **std::isinf()** for special float/double values
- **std::isprint()** for checking displayable characters
- **std::numeric_limits** for type boundaries
- **Non-instantiable classes** with private constructors
- Static-only classes for utility functions

---

### Exercise 01: Serialization

**Objective:**  
Implement a `Serializer` class that converts pointers to integers and back using reinterpret_cast.

**Files:**
- `Serializer.hpp`, `Serializer.cpp` – Serialization logic
- `main.cpp` – Tests serialization and deserialization

**Data Structure:**
```cpp
struct Data {
    int value;
};
```

**Serializer Class:**

**Private Members:**
- Private constructors and destructor (non-instantiable)
- Copy constructor and assignment operator

**Public Static Methods:**
- `static uintptr_t serialize(Data* ptr)` – Converts pointer to integer
- `static Data* deserialize(uintptr_t raw)` – Converts integer back to pointer

**Serialization Process:**
1. Create a `Data` object
2. Get its pointer
3. Serialize: Convert pointer to `uintptr_t` using `reinterpret_cast`
4. Deserialize: Convert `uintptr_t` back to pointer using `reinterpret_cast`
5. Verify that original and deserialized pointers are identical

**Usage Example:**
```cpp
Data data;
data.value = 42;

Data* originalPtr = &data;
uintptr_t raw = Serializer::serialize(originalPtr);
Data* deserializedPtr = Serializer::deserialize(raw);

// originalPtr == deserializedPtr (should be true)
```

**Key Learning:**
- **reinterpret_cast<>()** for low-level pointer conversions
- **uintptr_t** type for storing pointer values as integers
- **Serialization** concept (converting objects to storable/transmittable format)
- **Pointer arithmetic** and memory addresses
- **Non-instantiable utility classes**
- Pointer-to-integer and integer-to-pointer conversions
- **#include <cstdint>** for fixed-width integer types

---

### Exercise 02: Identify real type

**Objective:**  
Use dynamic_cast to identify the actual type of objects at runtime.

**Files:**
- `Base.hpp`, `Base.cpp` – Base class and derived classes (A, B, C)
- `main.cpp` – Tests type identification

**Class Hierarchy:**
```cpp
class Base {
    public:
        virtual ~Base();  // Virtual destructor for polymorphism
};

class A : public Base {};
class B : public Base {};
class C : public Base {};
```

**Functions:**

**1. generate()**
```cpp
Base* generate(void);
```
- Randomly instantiates `A`, `B`, or `C`
- Returns as `Base*` pointer
- Uses `rand()` for random selection

**2. identify(Base* p)**
```cpp
void identify(Base* p);
```
- Identifies actual type using **pointer** parameter
- Uses `dynamic_cast<A*>`, `dynamic_cast<B*>`, `dynamic_cast<C*>`
- Prints `"A"`, `"B"`, or `"C"`
- Returns `NULL` if cast fails

**3. identify(Base& p)**
```cpp
void identify(Base& p);
```
- Identifies actual type using **reference** parameter
- Uses `dynamic_cast<A&>`, `dynamic_cast<B&>`, `dynamic_cast<C&>`
- **Cannot use NULL check** (references don't have NULL)
- Uses **try-catch blocks** to catch `std::bad_cast` exception
- Prints `"A"`, `"B"`, or `"C"`

**Implementation Differences:**

**Pointer Version:**
```cpp
void identify(Base* p) {
    if (dynamic_cast<A*>(p))
        std::cout << "A" << std::endl;
    else if (dynamic_cast<B*>(p))
        std::cout << "B" << std::endl;
    else if (dynamic_cast<C*>(p))
        std::cout << "C" << std::endl;
}
```

**Reference Version (must use exceptions):**
```cpp
void identify(Base& p) {
    try {
        (void)dynamic_cast<A&>(p);
        std::cout << "A" << std::endl;
        return;
    } catch(...) {}
    
    try {
        (void)dynamic_cast<B&>(p);
        std::cout << "B" << std::endl;
        return;
    } catch(...) {}
    
    try {
        (void)dynamic_cast<C&>(p);
        std::cout << "C" << std::endl;
        return;
    } catch(...) {}
}
```

**Key Learning:**
- **dynamic_cast<>()** for runtime type identification
- **RTTI (Runtime Type Information)** mechanism
- **Virtual functions** required for dynamic_cast to work
- **Polymorphism** through base class pointers/references
- **dynamic_cast with pointers**: Returns `NULL` on failure
- **dynamic_cast with references**: Throws `std::bad_cast` on failure
- **Exception handling** for reference casting
- **Random object generation** with `rand()` and `srand()`
- **Virtual destructors** for proper polymorphic deletion

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
./convert 42
./convert 42.0f
./convert 'c'
./convert nan
./convert +inf

# Exercise 01
cd ex01
make
./Serializer

# Exercise 02
cd ex02
make
./identify
```

---

## Key Takeaways

### C++ Type Casting Operators

**1. static_cast<>()**
- **Purpose**: Standard type conversions known at compile-time
- **Use cases**: 
  - Numeric conversions (int ↔ float ↔ double)
  - Pointer conversions in inheritance hierarchies (upcasting)
  - Explicit conversions that would otherwise be implicit
- **Safety**: Compile-time checking, no runtime overhead
- **Example**: `static_cast<int>(42.5)` → `42`

**2. reinterpret_cast<>()**
- **Purpose**: Low-level bitwise reinterpretation
- **Use cases**:
  - Pointer to integer conversions
  - Integer to pointer conversions
  - Pointer type changes (dangerous!)
- **Safety**: No safety checks, programmer responsible
- **Example**: `reinterpret_cast<uintptr_t>(ptr)`

**3. dynamic_cast<>()**
- **Purpose**: Safe downcasting with runtime type checking
- **Requirements**: 
  - Source class must have at least one virtual function
  - Only works with polymorphic types (classes with virtual methods)
- **Behavior**:
  - With pointers: Returns `NULL` on failure
  - With references: Throws `std::bad_cast` on failure
- **Use cases**: Runtime type identification (RTTI)
- **Example**: `dynamic_cast<Derived*>(basePtr)`

**4. const_cast<>()**
- **Purpose**: Add or remove const/volatile qualifiers
- **Use cases**: Rarely needed, mostly for legacy API compatibility
- **Warning**: Modifying originally const objects is undefined behavior
- **Example**: `const_cast<char*>(constString)`

### Type Casting Comparison Table

| Cast Type | Runtime Check | Works With | Use Case | Safety |
|-----------|---------------|------------|----------|--------|
| **static_cast** | ❌ | Any type | Standard conversions | ⚠️ Medium |
| **reinterpret_cast** | ❌ | Pointers/integers | Low-level reinterpretation | ⚠️⚠️ Low |
| **dynamic_cast** | ✅ | Polymorphic classes | Safe downcasting | ✅ High |
| **const_cast** | ❌ | Const/volatile | Remove const qualifier | ⚠️⚠️ Low |
| **C-style (Type)** | ❌ | Any type | Not recommended | ⚠️⚠️⚠️ Very Low |

### When to Use Which Cast

**Use static_cast when:**
- Converting between numeric types
- Upcasting in inheritance (derived → base)
- Making implicit conversions explicit
- You know the conversion is safe at compile-time

**Use reinterpret_cast when:**
- Converting pointers to integers (serialization)
- Converting integers to pointers (deserialization)
- Low-level memory manipulation
- Interfacing with hardware or external APIs

**Use dynamic_cast when:**
- Downcasting in inheritance (base → derived)
- You need runtime type checking
- Working with polymorphic types
- Type identification is required

**Use const_cast when:**
- Interfacing with legacy non-const APIs
- You guarantee the object is not originally const
- VERY RARELY – usually indicates design issues

---

## Important Concepts

### Runtime Type Information (RTTI)

**Requirements:**
- Class must have at least one virtual function
- Compiler flag: `-frtti` (enabled by default)

**Components:**
1. **dynamic_cast**: Safe type casting
2. **typeid**: Type identification operator
3. **type_info**: Type information class

**Example:**
```cpp
Base* ptr = new Derived();
if (Derived* d = dynamic_cast<Derived*>(ptr)) {
    // Successful cast
}
```

### Non-Instantiable Classes

**Pattern:**
```cpp
class Utility {
    private:
        Utility();  // Private constructor
        Utility(const Utility&);  // Private copy constructor
        Utility& operator=(const Utility&);  // Private assignment
        ~Utility();  // Private destructor
    public:
        static void doSomething();  // Only static methods
};
```

**Purpose:**
- Utility classes with only static methods
- Prevent object creation
- Namespace-like behavior in C++98

### Type Detection Patterns

**String Analysis:**
- Check length, format, special characters
- Validate numeric format with sign handling
- Detect floating-point notation
- Handle edge cases (empty strings, invalid formats)

**Conversion Strategy:**
1. Detect input type
2. Convert to intermediate type (usually double)
3. Convert intermediate to all target types
4. Handle special values (nan, inf)
5. Check bounds for each target type

---

## Common Patterns and Best Practices

### 1. Type Casting Safety

✅ **Prefer static_cast** for compile-time known conversions  
✅ **Use dynamic_cast** when runtime checking is needed  
❌ **Avoid C-style casts** – they're unsafe and unclear  
❌ **Avoid reinterpret_cast** unless absolutely necessary  
⚠️ **Never modify const objects** even after const_cast

### 2. Dynamic Cast Patterns

**With Pointers:**
```cpp
if (Derived* d = dynamic_cast<Derived*>(basePtr)) {
    // Safe to use d
} else {
    // Cast failed, handle error
}
```

**With References (must use try-catch):**
```cpp
try {
    Derived& d = dynamic_cast<Derived&>(baseRef);
    // Safe to use d
} catch (std::bad_cast& e) {
    // Cast failed
}
```

### 3. Virtual Functions and Polymorphism

**Requirements for dynamic_cast:**
- Base class must have virtual function(s)
- Virtual destructor recommended for polymorphic classes

```cpp
class Base {
    public:
        virtual ~Base() {}  // Makes class polymorphic
};
```

### 4. Serialization Patterns

**Pointer to Integer:**
```cpp
uintptr_t raw = reinterpret_cast<uintptr_t>(ptr);
```

**Integer to Pointer:**
```cpp
Type* ptr = reinterpret_cast<Type*>(raw);
```

**Important:** Only safe if pointer not deallocated!

---

## Common Pitfalls

❌ **Using dynamic_cast on non-polymorphic types** → Compile error  
✅ **Ensure class has virtual function**

❌ **Forgetting to check dynamic_cast pointer result** → Segfault  
✅ **Always check for NULL before using**

❌ **Using reinterpret_cast for type conversions** → Undefined behavior  
✅ **Use static_cast for standard conversions**

❌ **Modifying const objects via const_cast** → Undefined behavior  
✅ **Only use const_cast with originally non-const objects**

❌ **C-style casts: (int)value** → Unclear, unsafe  
✅ **Use C++ named casts: static_cast<int>(value)**

❌ **Assuming dynamic_cast always succeeds** → Crash  
✅ **Handle failure cases appropriately**

---

## Additional Notes

### Pseudo-Literals

**For float:**
- `nanf` – Not a Number (float)
- `+inff` – Positive infinity (float)
- `-inff` – Negative infinity (float)

**For double:**
- `nan` – Not a Number (double)
- `+inf` – Positive infinity (double)
- `-inf` – Negative infinity (double)

**Checking:**
```cpp
std::isnan(value)  // Check if NaN
std::isinf(value)  // Check if infinity
```

### Numeric Limits

```cpp
#include <limits>

std::numeric_limits<int>::max()   // Maximum int value
std::numeric_limits<int>::min()   // Minimum int value
```

### Character Classification

```cpp
#include <cctype>

std::isprint(c)   // Is printable character?
std::isdigit(c)   // Is digit 0-9?
```

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 06
