# C++ Module 01 – Memory Allocation, Pointers, References & File I/O

This repository contains the solutions for **CPP Module 01** from the 42 curriculum. The module focuses on **memory allocation, pointers to members, references, and the switch statement**.

---

## Key Concepts Covered

- **Dynamic memory allocation** (heap vs. stack)
- **Pointers and references**
- **Pointer to member functions**
- **File input/output streams**
- **String manipulation**
- **Memory management** (new/delete)

---

## Exercises

### Exercise 00: BraiiiiiiinnnzzzZ

**Objective:**  
Understand the difference between stack and heap allocation of objects.

**Files:**
- `Zombie.hpp`, `Zombie.cpp` – Zombie class definition
- `newZombie.cpp` – Creates a zombie on the heap
- `randomChump.cpp` – Creates a zombie on the stack
- `main.cpp` – Tests both allocation methods

**Zombie Class:**
- Constructor: `Zombie(std::string name)`
- Destructor: `~Zombie()`
- Method: `void announce(void)` – Prints "< name >: BraiiiiiiinnnzzzZ..."

**Functions:**
- `Zombie* newZombie(std::string name)` – Allocates zombie on heap, returns pointer
- `void randomChump(std::string name)` – Creates zombie on stack, announces, then destroys

**Key Learning:**
- **Heap allocation** (with `new`) persists until explicitly deleted
- **Stack allocation** is automatically destroyed when it goes out of scope
- Choose heap when the object needs to outlive the function scope
- Choose stack for temporary, short-lived objects

---

### Exercise 01: Moar brainz!

**Objective:**  
Allocate multiple objects at once using `new[]` and properly deallocate with `delete[]`.

**Files:**
- `Zombie.hpp`, `Zombie.cpp` – Zombie class
- `zombieHorde.cpp` – Creates an array of N zombies
- `main.cpp` – Tests zombie horde creation

**Function:**
```cpp
Zombie* zombieHorde(int N, std::string name);
```
- Allocates an array of `N` zombies on the heap
- Initializes each zombie with the given name
- Returns a pointer to the first zombie

**Key Learning:**
- Arrays of objects are allocated with `new[]`
- Must be deallocated with `delete[]` (not just `delete`)
- All zombies in the array must be properly initialized
- Handle edge cases (negative N, zero N)

---

### Exercise 02: HI THIS IS BRAIN

**Objective:**  
Understand the difference between pointers and references in C++.

**Files:**
- `main.cpp` – Demonstrates pointers and references

**Program:**
1. Creates a string variable
2. Creates a pointer (`stringPTR`) pointing to the string
3. Creates a reference (`stringREF`) to the string
4. Prints memory addresses of all three
5. Prints values accessed through all three

**Key Learning:**
- **Pointer** holds the memory address, must be dereferenced with `*`
- **Reference** is an alias for the original variable, no special syntax needed
- References cannot be null, cannot be reassigned
- Pointers can be null, can point to different objects
- References are safer and more convenient when you don't need reassignment

---

### Exercise 03: Unnecessary violence

**Objective:**  
Learn when to use references vs. pointers in class design.

**Files:**
- `Weapon.hpp`, `Weapon.cpp` – Weapon class with type getter/setter
- `HumanA.hpp`, `HumanA.cpp` – Human that always has a weapon (reference)
- `HumanB.hpp`, `HumanB.cpp` – Human that may not have a weapon (pointer)
- `main.cpp` – Tests both human types

**Weapon Class:**
- Private member: `std::string type`
- Methods: `getType()`, `setType()`

**HumanA Class:**
- Constructor: `HumanA(std::string name, Weapon& weapon)`
- Stores a **reference** to Weapon
- Why reference? HumanA always has a weapon, set at construction

**HumanB Class:**
- Constructor: `HumanB(std::string name)`
- Method: `setWeapon(Weapon& weapon)`
- Stores a **pointer** to Weapon
- Why pointer? HumanB might not have a weapon initially

**Key Learning:**
- Use **references** when the object must always exist and won't change
- Use **pointers** when the object is optional or might change
- References must be initialized in the constructor's initializer list
- Passing objects by reference avoids unnecessary copying

---

### Exercise 04: Sed is for losers

**Objective:**  
Implement a file manipulation program using C++ file streams.

**Files:**
- `main.cpp` – File replacement program

**Program:**
Takes 3 parameters: `<filename>`, `<s1>`, `<s2>`
1. Opens the file `<filename>`
2. Reads the entire content
3. Replaces every occurrence of `<s1>` with `<s2>`
4. Writes the result to `<filename>.replace`

**Key Concepts:**
- `std::ifstream` – Input file stream for reading
- `std::ofstream` – Output file stream for writing
- `std::string::find()` – Finds substring position
- `std::string::npos` – Indicates "not found"
- Error handling: file not found, empty search string

**Implementation Details:**
- Read file line by line with `std::getline()`
- Build complete content in memory
- Use `find()` and string manipulation to replace all occurrences
- Handle overlapping replacements correctly

---

### Exercise 05: Harl 2.0

**Objective:**  
Learn about pointers to member functions in C++.

**Files:**
- `Harl.hpp`, `Harl.cpp` – Harl class with complaint system
- `main.cpp` – Tests the Harl class

**Harl Class:**

Private methods (complaint levels):
- `void debug(void)` – Debug level message
- `void info(void)` – Info level message  
- `void warning(void)` – Warning level message
- `void error(void)` – Error level message

Public method:
- `void complain(std::string level)` – Calls appropriate private method

**Key Learning:**
- **Pointer to member function** syntax: `void (ClassName::*funcPtr)()`
- Array of function pointers to avoid long if-else chains
- Calling member function through pointer: `(this->*funcPtr)()`
- More elegant and maintainable than switch/if-else statements

**Implementation:**
```cpp
void (Harl::*func[])() = { 
    &Harl::debug,
    &Harl::info,
    &Harl::warning,
    &Harl::error
};
```

---

### Exercise 06: Harl filter

**Objective:**  
Use the switch statement with C++ to implement a filtering system.

**Files:**
- `Harl.hpp`, `Harl.cpp` – Modified Harl class with switch statement
- `main.cpp` – Command-line filter for Harl complaints

**Program:**
Takes 1 parameter: `<LEVEL>`
- Displays all messages from that level and above
- Example: "WARNING" shows WARNING and ERROR messages
- Uses **switch statement** with fall-through behavior

**Key Learning:**
- **Switch statement** in C++
- **Fall-through** behavior (no break statements)
- Command-line argument handling
- Filtering and level-based message display

---

## Compilation

Each exercise has its own Makefile. To compile an exercise:

```bash
cd ex00  # or any exercise directory
make
```

Common Makefile targets:
- `make` – Compile the program
- `make clean` – Remove object files
- `make fclean` – Remove object files and executable
- `make re` – Recompile everything

---

## Running the Programs

### Exercise 00:
```bash
./brainz
```

### Exercise 01:
```bash
./moar_brainz
```

### Exercise 02:
```bash
./brain
```

### Exercise 03:
```bash
./violence
```

### Exercise 04:
```bash
./replace <filename> <string_to_find> <replacement>
# Example:
./replace test.txt "hello" "hi"
```

### Exercise 05:
```bash
./harl
```

### Exercise 06:
```bash
./harlFilter <LEVEL>
# Example:
./harlFilter WARNING
```

---

## Important C++ Concepts

### Memory Management
- Always `delete` what you `new`
- Always `delete[]` what you `new[]`
- Memory leaks occur when allocated memory is not freed
- Use destructors to ensure proper cleanup

### References vs Pointers
| Feature | Reference | Pointer |
|---------|-----------|---------|
| Null value | Cannot be null | Can be null |
| Reassignment | Cannot reassign | Can reassign |
| Syntax | Transparent (like variable) | Requires * to dereference |
| When to use | Always exists, won't change | Optional or changeable |

### File Streams
- `std::ifstream` – Read from files
- `std::ofstream` – Write to files
- `std::fstream` – Read and write
- Always check if file opened successfully: `if (!file.is_open())`
- Streams automatically close when destroyed (RAII)

### Const References
- `const std::string&` – Efficient parameter passing
- No copying overhead (pass by reference)
- Cannot modify the original (const protection)
- Best practice for passing objects to functions

---

## Author

42 School Project - CPP Module 01
