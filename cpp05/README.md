# C++ Module 05 – Repetition and Exceptions

This repository contains the solutions for **CPP Module 05** from the 42 curriculum. The module focuses on **exception handling, try-catch blocks, custom exceptions, and the Orthodox Canonical Form with exceptions**.

---

## Key Concepts Covered

- **Exception handling** with `try`, `catch`, `throw`
- **Custom exception classes** (nested classes)
- **Standard exception hierarchy** (`std::exception`)
- **Exception specifications** (`throw()`)
- **Abstract classes** with pure virtual functions
- **Factory pattern** for object creation
- **Const correctness** with member variables
- **RAII** (Resource Acquisition Is Initialization)

---

## Exercises

### Exercise 00: Mommy, when I grow up, I want to be a bureaucrat!

**Objective:**  
Create a `Bureaucrat` class with grade validation and custom exceptions.

**Files:**
- `Bureaucrat.hpp`, `Bureaucrat.cpp` – Bureaucrat class with exceptions
- `main.cpp` – Tests exception handling

**Bureaucrat Class:**

**Private Members:**
- `const std::string _name` – Name of the bureaucrat (immutable)
- `int _grade` – Grade (1 to 150, where 1 is highest)

**Public Methods:**
- `Bureaucrat()` – Default constructor
- `Bureaucrat(const std::string& name, int grade)` – Parameterized constructor
- `Bureaucrat(const Bureaucrat& other)` – Copy constructor
- `Bureaucrat& operator=(const Bureaucrat& other)` – Copy assignment operator
- `~Bureaucrat()` – Destructor
- `const std::string& getName() const` – Returns name
- `int getGrade() const` – Returns current grade
- `void incrementGrade()` – Decreases grade number by 1 (makes it better)
- `void decrementGrade()` – Increases grade number by 1 (makes it worse)

**Exception Classes (Nested):**
```cpp
class GradeTooHighException : public std::exception {
    public:
        const char* what() const throw();
};

class GradeTooLowException : public std::exception {
    public:
        const char* what() const throw();
};
```

**Grade Rules:**
- Valid range: **1 (highest) to 150 (lowest)**
- Incrementing grade 1 → Throws `GradeTooHighException`
- Decrementing grade 150 → Throws `GradeTooLowException`
- Invalid construction (grade < 1 or > 150) → Throws exception

**Stream Operator:**
```cpp
std::ostream& operator<<(std::ostream& os, const Bureaucrat& bureaucrat);
```
Output format: `<name>, bureaucrat grade <grade>`

**Key Learning:**
- **Exception classes** inherit from `std::exception`
- **Nested classes** keep related exceptions together
- **`const throw()`** specification (C++98 style, deprecated in C++11)
- **`what()`** method returns error message
- Exceptions thrown in **constructors** prevent object creation
- **Const member variables** must be initialized in initializer list
- Grade semantics: lower number = higher rank

---

### Exercise 01: Form up, maggots!

**Objective:**  
Create a `Form` class that requires certain grades to sign and execute.

**Files:**
- `Bureaucrat.hpp`, `Bureaucrat.cpp` – Bureaucrat class from ex00
- `Form.hpp`, `Form.cpp` – Form class with grade requirements
- `main.cpp` – Tests form signing

**Form Class:**

**Private Members:**
- `const std::string _name` – Name of the form
- `bool _isSigned` – Whether the form is signed (initialized to false)
- `const int _signGrade` – Minimum grade required to sign
- `const int _execGrade` – Minimum grade required to execute

**Public Methods:**
- `Form()` – Default constructor
- `Form(const std::string& name, int signGrade, int execGrade)` – Constructor
- `Form(const Form& other)` – Copy constructor
- `Form& operator=(const Form& other)` – Copy assignment operator
- `~Form()` – Destructor
- `const std::string& getName() const` – Returns form name
- `bool getIsSigned() const` – Returns signed status
- `int getSignGrade() const` – Returns required sign grade
- `int getExecGrade() const` – Returns required execution grade
- `void beSigned(const Bureaucrat& bureaucrat)` – Sign the form

**Exception Classes:**
- `GradeTooHighException` – Thrown when grade requirement is invalid (< 1)
- `GradeTooLowException` – Thrown when grade requirement is invalid (> 150) or bureaucrat's grade is too low

**Bureaucrat New Method:**
```cpp
void signForm(Form& form);
```
- Attempts to sign the form
- Prints success or failure message

**Signing Logic:**
- Form can only be signed if bureaucrat's grade ≥ required sign grade
- If grade is too low → Throw `GradeTooLowException`
- Form remembers signed status

**Stream Operator:**
```cpp
std::ostream& operator<<(std::ostream& os, const Form& form);
```
Output format: `Form <name>, sign grade <grade>, exec grade <grade>, signed: <yes/no>`

**Key Learning:**
- Multiple `const` member variables
- **Boolean state** tracking (signed/unsigned)
- **Grade comparison** for authorization
- Exceptions for **access control**
- Forward declarations to avoid circular dependencies
- Relationship between classes (Bureaucrat signs Form)
- **Copy assignment with const members** (cannot reassign const members)

---

### Exercise 02: No, you need form 28B, not 28C...

**Objective:**  
Make Form abstract and create concrete form types with specific behaviors.

**Files:**
- `Bureaucrat.hpp`, `Bureaucrat.cpp` – Bureaucrat class (updated)
- `AForm.hpp`, `AForm.cpp` – Abstract Form base class
- `ShrubberyCreationForm.hpp`, `ShrubberyCreationForm.cpp` – Creates ASCII tree file
- `RobotomyRequestForm.hpp`, `RobotomyRequestForm.cpp` – Robotomizes target (50% success)
- `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp` – Presidential pardon
- `main.cpp` – Tests all form types

**AForm Abstract Class:**

**Changes from ex01:**
- Renamed `Form` to `AForm` (Abstract Form)
- Added pure virtual method:
  ```cpp
  virtual void execute(Bureaucrat const & executor) const = 0;
  ```
- Virtual destructor: `virtual ~AForm()`

**Execution Requirements:**
- Form must be **signed**
- Executor's grade must be ≥ execution grade
- If not signed → Throw exception
- If grade too low → Throw `GradeTooLowException`

**Bureaucrat New Method:**
```cpp
void executeForm(AForm const & form);
```
- Attempts to execute the form
- Prints success or failure message

**Concrete Form Classes:**

**1. ShrubberyCreationForm**
- Sign grade: **145**
- Exec grade: **137**
- Target: Name of file to create
- Action: Creates `<target>_shrubbery` file with ASCII trees

**2. RobotomyRequestForm**
- Sign grade: **72**
- Exec grade: **45**
- Target: Name of robot to robotomize
- Action: Makes drilling noises, 50% success rate for robotomization

**3. PresidentialPardonForm**
- Sign grade: **25**
- Exec grade: **5**
- Target: Name of person to pardon
- Action: Announces presidential pardon from Zaphod Beeblebrox

**Implementation Details:**

**ShrubberyCreationForm:**
- Opens file `<target>_shrubbery` for writing
- Writes ASCII art trees (multiple trees for better effect)
- Handles file I/O errors

**RobotomyRequestForm:**
- Prints "drilling noises"
- Uses random number (50% chance) to determine success
- Success: "<target> has been robotomized successfully"
- Failure: "Robotomization failed"

**PresidentialPardonForm:**
- Prints: "<target> has been pardoned by Zaphod Beeblebrox"

**Key Learning:**
- **Abstract base classes** with pure virtual functions
- **Virtual destructors** for polymorphic deletion
- **Template Method Pattern** (execute checks then calls specific action)
- **File I/O** in C++ with `std::ofstream`
- **Random number generation** with `rand()` and `srand()`
- Different **concrete implementations** of abstract interface
- **Polymorphism** through base class pointers/references
- Separation of **authorization** (signing) and **execution**

---

### Exercise 03: At least this beats coffee-making

**Objective:**  
Implement an `Intern` class that uses the Factory Pattern to create forms dynamically.

**Files:**
- `Bureaucrat.hpp`, `Bureaucrat.cpp` – Bureaucrat class
- `AForm.hpp`, `AForm.cpp` – Abstract Form class
- `ShrubberyCreationForm.hpp`, `ShrubberyCreationForm.cpp` – Shrubbery form
- `RobotomyRequestForm.hpp`, `RobotomyRequestForm.cpp` – Robotomy form
- `PresidentialPardonForm.hpp`, `PresidentialPardonForm.cpp` – Presidential pardon form
- `Intern.hpp`, `Intern.cpp` – Intern class (Factory)
- `main.cpp` – Tests dynamic form creation

**Intern Class:**

**Public Methods:**
- `Intern()` – Default constructor
- `Intern(const Intern& other)` – Copy constructor
- `Intern& operator=(const Intern& other)` – Copy assignment operator
- `~Intern()` – Destructor
- `AForm* makeForm(const std::string& formName, const std::string& target)` – Factory method

**makeForm() Method:**

Creates a form based on the form name:
- `"shrubbery creation"` → `new ShrubberyCreationForm(target)`
- `"robotomy request"` → `new RobotomyRequestForm(target)`
- `"presidential pardon"` → `new PresidentialPardonForm(target)`
- Unknown form name → Returns `NULL` and prints error message

**Usage:**
```cpp
Intern intern;
AForm* form = intern.makeForm("robotomy request", "Bender");
if (form) {
    // Use form
    delete form; // Important: Caller must delete!
}
```

**Implementation Approaches:**

**Approach 1: If-else chain**
```cpp
if (formName == "shrubbery creation")
    return new ShrubberyCreationForm(target);
else if (formName == "robotomy request")
    return new RobotomyRequestForm(target);
// ...
```

**Approach 2: Array of function pointers (more elegant)**
- Create helper functions to instantiate each form type
- Use array of function pointers with corresponding names
- Loop through array to find match

**Key Learning:**
- **Factory Pattern** – Centralizes object creation
- **Dynamic memory allocation** with polymorphic types
- **Returning pointers** to base class (polymorphism)
- **Caller responsibility** for memory deallocation
- **NULL pointer checking** for error handling
- **String comparison** for selecting object types
- **Function pointers** as an alternative to if-else chains
- **Encapsulation** of instantiation logic
- **Separation of concerns** – Intern handles creation, caller handles usage

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
./Bureaucrat

# Exercise 01
cd ex01
make
./Form

# Exercise 02
cd ex02
make
./Forms

# Exercise 03
cd ex03
make
./Intern
```

---

## Key Takeaways

### Exception Handling

**Basic Syntax:**
```cpp
try {
    // Code that might throw
    throw SomeException();
}
catch (const std::exception& e) {
    // Handle exception
    std::cout << e.what() << std::endl;
}
```

**Custom Exceptions:**
```cpp
class MyException : public std::exception {
    public:
        const char* what() const throw() {
            return "My custom error message";
        }
};
```

**Key Points:**
1. **Always inherit from `std::exception`** for standard exception interface
2. **`what()` method** returns error description
3. **`const throw()`** indicates function won't throw (C++98 style)
4. **Catch by reference** (`const std::exception&`) to avoid slicing
5. Exceptions in **constructors** prevent object creation
6. **Virtual destructors** needed in exception hierarchies if derived exceptions exist

### Exception Safety Levels

1. **No-throw guarantee** – Function never throws exceptions
2. **Strong guarantee** – If exception thrown, program state unchanged
3. **Basic guarantee** – If exception thrown, no memory leaks, invariants maintained
4. **No guarantee** – Undefined behavior on exception

### Design Patterns

**Factory Pattern:**
- Centralizes object creation
- Hides instantiation details
- Returns base class pointers for polymorphism
- Allows runtime type selection

**Template Method Pattern:**
- Base class defines algorithm structure
- Derived classes implement specific steps
- Example: `execute()` in AForm checks preconditions, derived classes implement action

### RAII (Resource Acquisition Is Initialization)

- Resources acquired in constructor
- Resources released in destructor
- Exceptions in constructor prevent resource leaks
- Destructor should not throw exceptions

---

## Common Patterns and Best Practices

### 1. Exception Hierarchy
```cpp
std::exception (base)
    ├─ GradeTooHighException
    └─ GradeTooLowException
```

### 2. Nested Exception Classes
- Keep related exceptions together
- Access: `Bureaucrat::GradeTooHighException`
- Advantages: Organization, namespace encapsulation

### 3. Const Correctness
- **Const member variables:** Set once in initializer list
- **Const methods:** Don't modify object state
- **Const parameters:** Prevent accidental modification

### 4. Forward Declarations
```cpp
class Bureaucrat;  // Forward declaration

class Form {
    void beSigned(const Bureaucrat& bureaucrat);
};
```
- Avoids circular dependencies
- Only works with pointers/references

### 5. Memory Management
- **Delete what you new**
- **Virtual destructors** for polymorphic classes
- **NULL check** after dynamic allocation
- Caller deletes objects from factory

---

## Common Pitfalls

❌ **Catching exceptions by value** → Slicing  
✅ **Catch by const reference:** `catch (const std::exception& e)`

❌ **Non-virtual destructor in polymorphic base** → Memory leak  
✅ **Virtual destructor:** `virtual ~AForm()`

❌ **Forgetting to delete factory-created objects** → Memory leak  
✅ **Delete after use:** `delete form;`

❌ **Exception in destructor** → Terminate program  
✅ **Destructors should not throw**

❌ **Not checking NULL from factory** → Segfault  
✅ **NULL check:** `if (form != NULL)`

❌ **Throwing in constructor without cleanup** → Resource leak  
✅ **RAII pattern or try-catch in constructor**

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 05