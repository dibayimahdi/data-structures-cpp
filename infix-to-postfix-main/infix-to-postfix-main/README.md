# 🔢 Infix to Postfix Converter & Stack Machine Simulation (C++)

This C++ program demonstrates:

- ✅ Conversion from **infix** to **postfix** notation
- ⚙️ Simulation of a **stack-based machine** generating intermediate code
- 📊 Evaluation of postfix expressions

It uses a custom `Stack` class to handle all stack operations and implements operator precedence for proper conversion.

---

## 📁 Files

- `infix_to_postfix.cpp` – Main program (the code you've provided)

---

## ⚙️ Features

### 🔄 Infix to Postfix Conversion

Handles operators like:

+, -, *, /, %, <, >, <=, >=, ==, !=, &&, ||, !

- Supports parentheses `()`
- Based on **operator precedence**
- Output postfix string

### 🛠 Stack Machine Simulation

- Interprets postfix expressions
- Generates simple **intermediate assembly-like** instructions
- Uses **TEMP** variables for intermediate results

### 🧮 Expression Evaluation

- Evaluates postfix expressions containing **digits only**
- Supports `+`, `-`, `*`, `/` operators
- Uses ASCII manipulation (`char - '0'`) to convert digits to integers

---

## 💻 How to Run

This code is compatible with **Turbo C++** or older compilers that support `<conio.h>` and `clrscr()`.

If using a modern compiler like GCC or Code::Blocks:
- Replace `#include<iostream.h>` with `#include<iostream>`
- Replace `#include<conio.h>` with modern alternatives (or remove UI parts like `clrscr()` and `gotoxy()`)

Compile and run:

```bash


✏️ TODOs
Improve compatibility with modern compilers (remove conio.h)

Extend evaluation to support variables

Add error handling for malformed expressions

👨‍💻 Author
Mahdi — 2021
Educational use only



