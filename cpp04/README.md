# C++ Module 04 – Subtype Polymorphism, Abstract Classes & Interfaces

This repository contains the solutions for **CPP Module 04** from the 42 curriculum. The module focuses on **subtype polymorphism, abstract classes, interfaces, and deep vs shallow copy**.

---

## Key Concepts Covered

- **Virtual functions** and **polymorphism**
- **Virtual destructors** (why they're necessary)
- **Abstract classes** (pure virtual functions)
- **Interfaces** in C++
- **Deep copy** vs **shallow copy**
- **Memory management** with polymorphic objects
- **The Orthodox Canonical Form** with dynamic memory

---

## Exercises

### Exercise 00: Polymorphism

**Objective:**  
Implement a base `Animal` class with virtual functions and derived classes that override them. Also create `WrongAnimal` to demonstrate what happens without virtual functions.

**Files:**
- `Animal.hpp`, `Animal.cpp` – Base Animal class with virtual functions
- `Dog.hpp`, `Dog.cpp` – Dog derived from Animal
- `Cat.hpp`, `Cat.cpp` – Cat derived from Animal
- `WrongAnimal.hpp`, `WrongAnimal.cpp` – Non-virtual base class
- `WrongCat.hpp`, `WrongCat.cpp` – Derived from WrongAnimal
- `main.cpp` – Tests polymorphism

**Animal Class:**

**Protected Members:**
- `std::string _type` – Type of the animal

**Public Methods:**
- `Animal()` – Default constructor
- `Animal(std::string const &type)` – Parameterized constructor
- `Animal(const Animal& other)` – Copy constructor
- `Animal& operator=(const Animal& other)` – Copy assignment operator
- `virtual ~Animal()` – **Virtual destructor** (critical for polymorphism!)
- `std::string const &getType() const` – Returns type
- `virtual void makeSound() const` – Virtual method to override

**Derived Classes (Dog & Cat):**
- Override `makeSound()` with specific animal sounds
- Properly call base class constructors

**WrongAnimal/WrongCat:**
- Identical structure but **without** `virtual` keyword
- Demonstrates that polymorphism won't work without virtual functions

**Key Learning:**
- **Virtual functions** enable runtime polymorphism
- **Virtual destructor** ensures derived class destructor is called when deleting through base pointer
- Without `virtual`, the **static type** determines which function is called
- The `virtual` keyword only needs to be in base class declaration
- Proper use of `const` in virtual methods

---

### Exercise 01: I don't want to set the world on fire

**Objective:**  
Extend the Animal classes with a `Brain` class to demonstrate deep copy vs shallow copy.

**Files:**
- `Animal.hpp`, `Animal.cpp` – Base class (same as ex00)
- `Dog.hpp`, `Dog.cpp` – Dog with Brain
- `Cat.hpp`, `Cat.cpp` – Cat with Brain
- `Brain.hpp`, `Brain.cpp` – Brain class with ideas
- `WrongAnimal.hpp`, `WrongAnimal.cpp` – Wrong implementation
- `WrongCat.hpp`, `WrongCat.cpp` – Wrong implementation
- `main.cpp` – Tests deep copy

**Brain Class:**

**Private Members:**
- `std::string ideas[100]` – Array of 100 ideas

**Public Methods:**
- `Brain()` – Default constructor
- `Brain(const Brain& other)` – Copy constructor (deep copy)
- `Brain& operator=(const Brain& other)` – Copy assignment (deep copy)
- `~Brain()` – Destructor

**Modified Dog/Cat Classes:**

**Private Members:**
- `Brain* catBrain` or `Brain* dogBrain` – Pointer to Brain object

**Implementation Requirements:**
- **Allocate Brain on heap** in constructor (`new Brain()`)
- **Deep copy** in copy constructor: `new Brain(*other.catBrain)`
- **Deep copy** in assignment operator:
  1. Delete old brain
  2. Allocate new brain with copied data
- **Delete brain** in destructor

**Key Learning:**
- **Shallow copy** copies pointers (both objects point to same memory)
- **Deep copy** creates new memory with copied data
- With dynamic memory, **default copy constructor/assignment does shallow copy**
- Must **manually implement** deep copy in copy constructor and assignment operator
- **Rule of Three:** If you need custom destructor, you likely need custom copy constructor and assignment operator
- Proper **memory leak prevention** with `delete` in destructor
- **Self-assignment check** in assignment operator (`if(this != &other)`)

---

### Exercise 02: Abstract class

**Objective:**  
Make the `Animal` class abstract so it cannot be instantiated directly.

**Files:**
- `Animal.hpp`, `Animal.cpp` – Abstract base class (`AAnimal`)
- `Dog.hpp`, `Dog.cpp` – Concrete Dog class
- `Cat.hpp`, `Cat.cpp` – Concrete Cat class
- `Brain.hpp`, `Brain.cpp` – Brain class (same as ex01)
- `WrongAnimal.hpp`, `WrongAnimal.cpp` – Wrong implementation
- `WrongCat.hpp`, `WrongCat.cpp` – Wrong implementation
- `main.cpp` – Tests abstract class

**Abstract AAnimal Class:**

```cpp
virtual void makeSound() const = 0;
```

**What Changed:**
- Renamed `Animal` to `AAnimal` (Abstract Animal)
- Made `makeSound()` a **pure virtual function** with `= 0`
- Cannot create instances: `AAnimal animal;` ❌ Won't compile
- Can only use as pointer/reference: `AAnimal* dog = new Dog();` ✅

**Implementation:**
- Dog and Cat **must override** `makeSound()`
- If derived class doesn't override pure virtual function, it remains abstract
- All other features from ex01 remain (Brain, deep copy, etc.)

**Key Learning:**
- **Pure virtual function:** `virtual void function() = 0;`
- Class with at least one pure virtual function is **abstract**
- **Abstract classes cannot be instantiated**
- Used to define **interface** or **common base** for derived classes
- Forces derived classes to implement certain methods
- Pointers/references to abstract class enable polymorphism
- Useful for **preventing accidental instantiation** of base class

---

### Exercise 03: Interface & Recap

**Objective:**  
Implement a Materia system using interfaces and abstract classes. This exercise combines all concepts: polymorphism, interfaces, deep copy, and memory management.

**Files:**
- `AMateria.hpp`, `AMateria.cpp` – Abstract Materia class
- `ICharacter.hpp` – Character interface
- `Character.hpp`, `Character.cpp` – Character implementation
- `IMateriaSource.hpp` – MateriaSource interface
- `MateriaSource.hpp`, `MateriaSource.cpp` – MateriaSource implementation
- `Ice.hpp`, `Ice.cpp` – Ice Materia
- `Cure.hpp`, `Cure.cpp` – Cure Materia
- `main.cpp` – Tests the system

**System Overview:**

**AMateria (Abstract Class):**
- Protected: `std::string _type`
- Pure virtual: `AMateria* clone() const = 0`
- Virtual: `void use(ICharacter& target)`

**Ice & Cure (Concrete Materia):**
- Inherit from `AMateria`
- Implement `clone()` (returns `new Ice(*this)` or `new Cure(*this)`)
- Override `use()` with specific messages

**ICharacter (Interface):**
```cpp
virtual ~ICharacter() {}
virtual std::string const & getName() const = 0;
virtual void equip(AMateria* m) = 0;
virtual void unequip(int idx) = 0;
virtual void use(int idx, ICharacter& target) = 0;
```

**Character (Implementation):**
- Private: `std::string _name` and `AMateria* _inventory[4]`
- Implements all interface methods
- **Deep copy** in copy constructor and assignment
- Properly manages inventory memory

**IMateriaSource (Interface):**
```cpp
virtual ~IMateriaSource() {}
virtual void learnMateria(AMateria*) = 0;
virtual AMateria* createMateria(std::string const & type) = 0;
```

**MateriaSource (Implementation):**
- Stores up to 4 learned Materias
- `learnMateria()` stores a Materia template
- `createMateria()` returns a clone of stored Materia

**Key Implementation Points:**

1. **Inventory Management:**
   - Initialize to `NULL`
   - Check for `NULL` before operations
   - Don't delete on `unequip()` (caller's responsibility)

2. **Deep Copy:**
   - Clone all Materias in copy constructor
   - Delete old Materias before copying in assignment

3. **Memory Safety:**
   - Delete all Materias in destructor
   - Check for `NULL` pointers
   - Self-assignment check

**Key Learning:**
- **Interface pattern** in C++ (pure virtual class)
- **Factory pattern** (MateriaSource creates Materias)
- **Clone pattern** (`clone()` for polymorphic copying)
- Managing **arrays of polymorphic pointers**
- **Responsibility assignment** (who deletes what)
- Complex **memory management** scenarios
- Combining **multiple design patterns**

---

## Compilation

To compile each exercise:

```bash
cd ex00  # or ex01, ex02, ex03
make
```

To run:

```bash
./Animals      # ex00, ex01
./AAnimal      # ex02
./Interface    # ex03
```

To clean:

```bash
make clean    # remove object files
make fclean   # remove executable
make re       # rebuild
```

---

## Important Concepts Summary

### Virtual Functions
- Enable **runtime polymorphism**
- Base class decides which function to call at **runtime**
- Always use **virtual destructor** in polymorphic base classes

### Abstract Classes
- Have at least one **pure virtual function** (`= 0`)
- **Cannot be instantiated**
- Used as **interfaces** or **base classes**

### Deep Copy
- Copy **data**, not **pointers**
- Required when class has **dynamic memory**
- Implement in **copy constructor** and **assignment operator**

### Memory Management
- **Delete through base pointer** requires virtual destructor
- **Unequip ≠ Delete** (ownership matters)
- Always check for **NULL** before operations
- **Self-assignment check** in assignment operator

---

## Common Pitfalls

❌ **Forgetting virtual destructor** → Memory leaks  
❌ **Shallow copy with pointers** → Double delete/segfault  
❌ **Missing self-assignment check** → Undefined behavior  
❌ **Deleting NULL pointer** → Usually safe, but check first  
❌ **Not initializing pointers** → Undefined behavior  

---

## Author
Mohamed OURHOUCH  
42 School Project - CPP Module 04
