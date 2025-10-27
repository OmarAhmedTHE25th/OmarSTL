# OmarSTL

### A Custom Implementation of Core C++ Data Structures

OmarSTL is a personal educational project that re-implements fundamental data structures from the C++ Standard Template Library (STL).
The goal is to deepen understanding of pointers, dynamic memory management, and the internal mechanisms behind STL containers.

---

## 📘 Overview

This project contains clean, modular, and well-structured implementations of several core data structures, each with its own test driver.
All data structures are implemented entirely from scratch, without using any pre-built STL containers.

---

## 🧩 Implemented Data Structures

* **Linked List** — includes insertion, deletion, traversal, and proper destructor handling.
* **Stack** — built using linked list logic, supporting push, pop, and peek operations.
* **Deque (Double-Ended Queue)** — efficient O(1) operations for both ends.
* **Mini Vector (List)** — a simplified dynamic array supporting resizing and element access.
* **Binary Search Tree (BST)** — complete with insertion, deletion, search, traversal, update, copy constructor, and destructor.
* **HashMap** — a fully templated hash map supporting:

  * CRUD operations (`set`, `operator[]`, `remove`)
  * Key existence checks (`contains`, `findKey`)
  * Size and empty state (`size`, `Empty`, `maxSize`)
  * Copy constructor and assignment operator
  * Merging maps with `+` operator
  * Stream output via `<<`
  * Dynamic resizing and automatic bucket growth

---

## ⚙️ Features

* Full ownership and memory safety through manual management of dynamic memory.
* Object-oriented structure using classes and encapsulation.
* Copy constructors and destructors implemented for safe deep copying and cleanup.
* Separate driver files (`*_Driver.cpp`) for isolated testing and demonstration.
* No recursion used where iterative logic provides more control and efficiency.
* Template-based HashMap implementation, mimicking STL `std::map` functionality.

---

## 📂 Project Structure

```
OmarSTL/
├── LinkedList.hpp
├── Stack.hpp
├── Deque.hpp
├── List.hpp
├── BST.hpp
├── HashMap.hpp
├── LinkedList_Driver.cpp
├── Stack_Driver.cpp
├── Deque_Driver.cpp
├── List_Driver.cpp
├── BST_Driver.cpp
├── HashMap_Driver.cpp
└── README.md
```

---

## 🧠 Learning Goals

* Strengthen understanding of low-level memory management in C++.
* Practice building reusable, efficient, and clean object-oriented code.
* Gain insight into how STL containers are designed and optimized.
* Explore template programming and custom hash functions through the HashMap.

---

## 🚀 How to Run

1. Clone the repository:

   ```bash
   git clone https://github.com/OmarAhmedTHE25th/OmarSTL.git
   ```

2. Compile any driver you want to test:

   ```bash
   g++ HashMap_Driver.cpp -o HashMap
   ```

3. Run the executable:

   ```bash
   ./HashMap
   ```

---

## 👤 Author

**Omar Ahmed Abdel Hameed Abdel Qader**
Computer Engineering Student – Ain Shams University
📍 Cairo, Egypt

