# Arbitrary Precision Multiplication in C

![Language](https://img.shields.io/badge/language-C-blue.svg)
![Build](https://img.shields.io/badge/build-CMake-green.svg)
![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20macOS-lightgrey.svg)
![License](https://img.shields.io/badge/license-GPLv3-blue.svg)
![Repo Size](https://img.shields.io/github/repo-size/sukrugumustas/arbitrary-multiplication-c?color=orange)
![Last Commit](https://img.shields.io/github/last-commit/sukrugumustas/arbitrary-multiplication-c?color=red)

A robust, modular C application that performs arbitrary-precision multiplication using linked lists. This program overcomes the size limitations of standard C data types (like `unsigned long long`) by treating numbers as dynamic lists of digits, allowing for the multiplication of integers with virtually unlimited length.

## ✨ Features

- **Unlimited Precision:** Multiply numbers with thousands of digits.
- **Memory Safe:** Full dynamic memory management with zero leaks.
- **Cross-Platform:** Runs on Linux and macOS (POSIX compliant).
- **Mathematical Correctness:** Handles negative numbers $(0 \times N)$, zero cases, and identity cases $(1 \times N)$.

## 🛠 Tech Stack

**Language:** C (Standard C17)

**Build System:** CMake (3.10+)

**Key Libraries:** POSIX Standard Library (`<unistd.h>`, `getline`), Standard C Library

## 🚀 Installation & Run Locally

1. **Prerequisites**

   A C compiler (GCC/Clang) and CMake
 
2. **Clone the repository**

   ```shell
   git clone https://github.com/sukrugumustas/arbitrary-multiplication-c.git
   cd arbitrary-multiplication-c
   ```

3. **Build with CMake**

   ```shell
   mkdir build && cd build
   cmake ..
   cmake -- build .
   ```

4. **Run the application**

   ```shell
   ./arbitrary-multiplication-c
   ```

## 💡 Usage / Examples

The program accepts input via `stdin`.

```shell
$ ./arbitrary-multiplication-c
Please enter number 1:
123456789123456789
Please enter number 2:
987654321987654321
Result: 121932631356500531347203169112635269
```

### Supported Inputs

- **Large Integers:** `10000000...`
- **Negative Numbers:*** `-50`, `-20`
- **Zero:** `0`

## ⚡ Optimizations

This project implements several algorithmic optimizations over a naive linked-list approach:

- **LSD-First Storage:** Numbers are stored in "Least Significant Digit" first order (reversed), aligning the data structure with the mathematical flow of multiplication and addition.

- **O(1) Tail Appending:** The linked list implementation maintains a `tail` pointer, allowing new digits to be appended in constant time $O(1)$ rather than traversing the entire list $O(N)$ for every insertion.

- **Modular Arithmetic:** The multiplication logic is decoupled into atomic operations (`multiply_by_digit`, `shift`, `add`), making the complex $O(N \times M)$ operation easier to maintain and debug.

## 🧠 Lessons Learned

- **POSIX Compliance:** Using `getline` for safe input handling on Unix-like systems.
- **Manual Memory Management:** Ensuring every `malloc` has a corresponding `free` to prevent leaks in a long-running calculation.
- **Data Structures:** Designing custom nodes to handle data that exceeds CPU register size (64-bit).

## 🤝 Contributing

Contributions are always welcome!

1. Fork the project

2. Create your Feature Branch
   
   ```shell
   git checkout -b feature/your-feature-name
   ```

3. Commit your changes

   ```shell
   git commit -m 'Added some feature'
   ```

4. Push to the Branch

   ```shell
   git push origin feature/your-feature-name
   ```

5. Open a Pull Request

## 📜 License

Distributed under the [GNU GPLv3](https://choosealicense.com/licenses/gpl-3.0/) License. See `LICENSE`for more information.

## ✍️ Authors

- [@sukrugumustas](https://www.github.com/sukrugumustas)

## 👏 Acknowledgements

### 🛠 Tools & Environment

- JetBrains CLion - The primary IDE used for development, debugging, and refactoring.
- CMake - For providing a robust, cross-platform build system configuration.
- Git - For version control and source code management.

### 📚 Standards & Libraries

- ISO C17 Standard - The core language standard used, ensuring modern C practices and type safety.
- POSIX.1-2008 - Specifically for the getline() function, enabling safe and dynamic user input handling on Unix-like systems.

### 🎨 Assets

- Shields.io - For the status badges used in this README.