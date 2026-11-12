# C Preprocessor

## About the Project

This project is a simple C Preprocessor tool developed using C programming. It takes a C source file as input and performs comment removal, file inclusion, and macro substitution. After processing, it generates an extended source file with a `.i` extension.

## Features

- **Comment Removal:** Removes single-line (`//`) and multi-line (`/* */`) comments.
- **File Inclusion:** Reads the specified header file and replaces the `#include` statement with its contents.
- **Macro Substitution:** Replaces defined macros with their corresponding values.
- **Simple Macros:** Supports macros such as `#define PI 3.14`.
- **Function-like Macros:** Supports macros with arguments such as `#define SQUARE(x) ((x)*(x))`.
- **Output Generation:** Creates a processed `.i` file.

## Technologies Used

- C Programming
- File Handling
- String Handling
- Structures and Pointers
- Modular Programming
- Makefile

## Project Structure

Update the filenames below according to your actual project files.

```text
C-Preprocessor/
│
├── main.c
├── comment_removal.c
├── file_inclusion.c
├── macro_handler.c
├── preprocessor.h
├── Makefile
└── README.md
```

## Compilation

Compile the project using:

```bash
make
```

This creates an executable named `mypreprocessor`.

## How to Run

Pass the C source filename as a command-line argument:

```bash
./mypreprocessor inputfile.c
```

After successful processing, an output file named `inputfile.i` will be generated.

## Learning Outcome

Through this project, I gained practical experience in C file handling, string manipulation, macro processing, and modular programming. It also helped me understand how basic preprocessing operations are performed before compilation.

---

**Project Name:** C Preprocessor  
**Language:** C  
**Build Tool:** Makefile
