# C++ Module 03 – Inheritance

This repository contains the solutions for **CPP Module 03** from the 42 curriculum.  The module focuses on **inheritance, derived classes, and the diamond problem in C++**.

---

## Key Concepts Covered

- **Inheritance** and derived classes
- **Protected members** vs private/public
- **Constructor/destructor chaining** in inheritance
- **Method overriding** in derived classes
- **Virtual inheritance** (solving the diamond problem)
- **Multiple inheritance**

---

## Exercises

### Exercise 00: Aaaaand...  OPEN! 

**Objective:**  
Create a base class `ClapTrap` that will be used as the foundation for derived classes.

**Files:**
- `ClapTrap.hpp`, `ClapTrap.cpp` – Base ClapTrap class
- `main.cpp` – Tests the ClapTrap class

**ClapTrap Class:**

**Private Members:**
- `std::string _name` – Name of the ClapTrap
- `int _hitPoints` – Hit points (initialized to 10)
- `int _energyPoints` – Energy points (initialized to 10)
- `int _attackDamage` – Attack damage (initialized to 0)

**Public Methods:**
- `ClapTrap()` – Default constructor
- `ClapTrap(std::string name)` – Parameterized constructor
- `ClapTrap(const ClapTrap& other)` – Copy constructor
- `ClapTrap& operator=(const ClapTrap& other)` – Copy assignment operator
- `~ClapTrap()` – Destructor
- `void attack(const std::string& target)` – Attack a target (costs 1 energy point)
- `void takeDamage(unsigned int amount)` – Take damage (reduces hit points)
- `void beRepaired(unsigned int amount)` – Repair (costs 1 energy point, restores hit points)

**Behavior:**
- Each action (attack/repair) costs **1 energy point**
- Cannot perform actions if **hit points** or **energy points** are 0
- All actions print descriptive messages to the console

**Key Learning:**
- Basic class structure with encapsulation
- Managing object state (HP, energy)
- Implementing member functions with conditions
- Proper constructor/destructor messages for debugging

---

### Exercise 01: Serena, my love! 

**Objective:**  
Create a derived class `ScavTrap` that inherits from `ClapTrap` with different attributes and behaviors.

**Files:**
- `ClapTrap.hpp`, `ClapTrap.cpp` – Base class
- `ScavTrap.hpp`, `ScavTrap.cpp` – Derived ScavTrap class
- `main.cpp` – Tests both classes

**ScavTrap Class:**

Inherits from `ClapTrap` with modified attributes:
- `_hitPoints` = **100**
- `_energyPoints` = **50**
- `_attackDamage` = **20**

**Special Method:**
- `void guardGate()` – Activates Gate Keeper protocol (special ScavTrap ability)

**Constructor/Destructor Chain:**
- ScavTrap constructor calls ClapTrap constructor first
- Destructor order: ScavTrap → ClapTrap

**Method Override:**
- `void attack(const std::string& target)` – Overrides ClapTrap's attack with ScavTrap-specific message

**Key Learning:**
- **Inheritance syntax**:  `class ScavTrap : public ClapTrap`
- **Protected members**: Derived class can access base class protected members
- **Constructor chaining**: Base constructor is called before derived constructor
- **Destructor order**: Derived destructor is called before base destructor
- **Method overriding**: Derived class can provide its own implementation

---

### Exercise 02: Repetitive work

**Objective:**  
Create another derived class `FragTrap` with its own unique attributes and abilities.

**Files:**
- `ClapTrap.hpp`, `ClapTrap.cpp` – Base class
- `ScavTrap.hpp`, `ScavTrap.cpp` – ScavTrap derived class
- `FragTrap.hpp`, `FragTrap.cpp` – FragTrap derived class
- `main.cpp` – Tests all three classes

**FragTrap Class:**

Inherits from `ClapTrap` with modified attributes:
- `_hitPoints` = **100**
- `_energyPoints` = **100**
- `_attackDamage` = **30**

**Special Method:**
- `void highFivesGuys(void)` – Requests a positive high five (FragTrap special ability)

**Key Learning:**
- Creating multiple derived classes from the same base
- Each derived class has its own unique attributes and methods
- Understanding constructor/destructor chaining with multiple derived classes
- Proper implementation of Orthodox Canonical Form in derived classes

---

### Exercise 03: Now it's weird! 

**Objective:**  
Implement multiple inheritance and solve the **diamond problem** using virtual inheritance.

**Files:**
- `ClapTrap.hpp`, `ClapTrap.cpp` – Base class
- `ScavTrap.hpp`, `ScavTrap.cpp` – First derived class (virtual inheritance)
- `FragTrap.hpp`, `FragTrap.cpp` – Second derived class (virtual inheritance)
- `DiamondTrap.hpp`, `DiamondTrap.cpp` – Diamond inheritance class
- `main.cpp` – Tests the diamond inheritance

**DiamondTrap Class:**

Inherits from **both** `ScavTrap` and `FragTrap`:
```cpp
class DiamondTrap : public ScavTrap, public FragTrap
```

**The Diamond Problem:**
```
        ClapTrap
        /      \
   ScavTrap  FragTrap
        \      /
      DiamondTrap
```

Without virtual inheritance, `DiamondTrap` would have **two copies** of `ClapTrap` members! 

**Solution:  Virtual Inheritance**
```cpp
class ScavTrap :  virtual public ClapTrap { ... };
class FragTrap : virtual public ClapTrap { ... };
```

**DiamondTrap Attributes:**
- Private member: `std::string _name` (DiamondTrap's own name)
- `ClapTrap:: _name` is set to `<name>_clap_name`
- `_hitPoints` from **FragTrap** (100)
- `_energyPoints` from **ScavTrap** (50)
- `_attackDamage` from **FragTrap** (30)

**Special Methods:**
- `void attack(const std::string& target)` – Uses **ScavTrap's** attack
- `void whoAmI()` – Displays both DiamondTrap name and ClapTrap name

**Key Learning:**
- **Multiple inheritance**: Class inherits from more than one base class
- **Diamond problem**: Ambiguity when multiple inheritance paths lead to same base
- **Virtual inheritance**: `virtual public` keyword ensures only one base class instance
- **Constructor complexity**: DiamondTrap must explicitly call ClapTrap constructor
- **Name shadowing**: Derived class can have a member with same name as base class
- **Scope resolution**: Use `ClassName::member` to access specific base class members

---

## Compilation

Each exercise has its own Makefile.  To compile an exercise:

```bash
cd ex00  # or any exercise directory
make
```

Common Makefile targets:
- `make` – Compile the program
- `make clean` – Remove object files
- `make fclean` – Remove object files and executable
- `make re` – Recompile everything

**Compilation Flags:**
- Compiler: `c++`
- Flags: `-Wall -Wextra -Werror -std=c++98`

---

## Running the Programs

### Exercise 00:
```bash
./ClapTrap
```

### Exercise 01:
```bash
./ScavTrap
```

### Exercise 02:
```bash
./FragTrap
```

### Exercise 03:
```bash
./DiamondTrap
```

---

## Key Takeaways

### Inheritance Basics
- **Public inheritance** means "is-a" relationship
- Derived class inherits all members (but can only access public/protected)
- Base class constructor is called before derived constructor
- Derived class destructor is called before base destructor

### Access Specifiers
| Specifier | Accessible in Class | Accessible in Derived | Accessible Outside |
|-----------|---------------------|----------------------|-------------------|
| **private** | ✓ | ✗ | ✗ |
| **protected** | ✓ | ✓ | ✗ |
| **public** | ✓ | ✓ | ✓ |

### Constructor Chaining
```cpp

// Base constructor is called automatically (or explicitly)
DerivedClass::DerivedClass() : BaseClass() {
    // Initialize derived members
}
```

### Virtual Inheritance
- Solves the diamond problem
- Ensures only **one instance** of the base class
- Most derived class is responsible for initializing the virtual base
- Slight performance overhead due to indirection

### When to Use What
- **Simple inheritance**: One base, one or more derived classes
- **Multiple inheritance**: Derive from multiple unrelated bases
- **Virtual inheritance**: Only when solving the diamond problem

---

## Important Notes

1. **Always use virtual inheritance** when you anticipate diamond inheritance patterns
2. **Protected members** are essential for inheritance (allow derived class access)
3. **Constructor order**:  Base → Derived
4. **Destructor order**:  Derived → Base
5. **Name hiding**: Derived class member hides base class member with same name
6. Use **scope resolution operator** (`::`) to access hidden base members

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 03