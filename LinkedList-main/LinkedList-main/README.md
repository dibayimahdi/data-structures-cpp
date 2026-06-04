# Static Linked List Manager (C++)

This project implements a **custom static memory pool-based linked list** manager in C++, designed to manage up to three separate linked lists using a preallocated array. It simulates dynamic memory allocation and provides basic operations like insertions, deletions, and traversals — all without using standard pointers.

## 🧠 Key Features

- Manages **3 independent linked lists** from a common memory pool
- Supports:
  - Add at beginning / end
  - Insert after / before a node
  - Delete a node
  - Count active nodes
  - Traverse or print in reverse
- Mimics pointer-based linked list logic using array indexing

## 📦 Requirements

- Turbo C++ or compatible compiler that supports:
  - `#include <conio.h>`
  - `clrscr()`, `gotoxy()`, `getch()`, etc.

> 🛠️ **Modernization Tip:** If using a modern C++ compiler (like g++, clang++, MSVC), replace non-standard headers (`<iostream.h>`, `<conio.h>`) and functions accordingly.

---

## 📄 License

This project is provided for educational purposes and has no license restrictions.

---

## 🚀 How to Use

### Run the Program:
1. Compile using Turbo C++ or DOSBox setup.
2. The program prompts for a function number:

```text
1) Add node
2) Add first
3) Insert after
4) Insert before
5) Delete
6) Traverse
7) Print reverse
8) Count



