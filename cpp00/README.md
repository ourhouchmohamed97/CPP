# C++ Module 00 – PhoneBook & Account Exercises

This repository contains the solutions for **CPP Module 00** from the 42 curriculum. The module covers **basic C++ classes, constructors, destructors, static members, and simple object-oriented programming concepts**.

---

## Exercises

### 1. PhoneBook (ex01)

**Objective:**  
Create a simple phonebook application that can store, search, and display contacts.

**Classes:**

- **Contact**  
  - Fields:
    - `firstName`, `lastName`, `nickName`, `phoneNumber`, `darkestSecret`
  - Methods:
    - Setters: `setFirstName()`, `setLastName()`, etc.
    - Getters: `getFirstName()`, `getLastName()`, etc.
- **PhoneBook**  
  - Stores up to 8 `Contact` objects.
  - Methods:
    - `add()` – add a new contact
    - `search()` – display contacts list and show full contact details

**Key Points:**

- Each contact must have **all fields filled**.
- Display of contacts:
  - Table format with **4 columns**: index, first name, last name, nickname.
  - Columns are **10 characters wide**, right-aligned.
  - Strings longer than 10 characters are **truncated with a dot** (`.`).

---

### 2. The Job of Your Dreams (ex02)

**Objective:**  
Implement an `Account` class simulating a simple banking system.

**Class:** `Account`

**Private Members:**

- Static:
  - `_nbAccounts` – total accounts
  - `_totalAmount` – total money
  - `_totalNbDeposits` – total deposits
  - `_totalNbWithdrawals` – total withdrawals
  - `_displayTimestamp()` – prints the timestamp
- Non-static:
  - `_accountIndex` – account ID
  - `_amount` – current balance
  - `_nbDeposits` – number of deposits for this account
  - `_nbWithdrawals` – number of withdrawals for this account

**Public Members:**

- Constructor & Destructor:
  - `Account(int initial_deposit)` – creates account, updates totals, prints log
  - `~Account()` – prints closing log
- Static Getters:
  - `getNbAccounts()`, `getTotalAmount()`, `getNbDeposits()`, `getNbWithdrawals()`
  - `displayAccountsInfos()` – prints global account info
- Methods:
  - `makeDeposit(int deposit)` – updates account and global totals, prints log
  - `makeWithdrawal(int withdrawal)` – withdraw if possible, prints log; returns `bool`
  - `checkAmount()` – returns current balance
  - `displayStatus()` – prints account info

**Important Points:**

- **Static members** track **global bank data**.
- Every operation prints a **log line with timestamp**, matching the **tester’s expected output**.
- Withdrawals must handle the **refused case** if funds are insufficient.

---

## Compilation

To compile:

```bash
make
```
---
## Author
Mohamed OURHOUCH
42 School Project - CPP Module 00