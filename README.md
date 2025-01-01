# _printf
## Overview
`_printf` is a custom impelementatin of the standard `printf` funtion in C based on the low-level Unix System Call `write`. The `_printf` function uses an impelemented `_putchar` function using `write` System Call.  
This project helped me showcaseing of a variadic function, useing low-level output funtion, and impelementing converting functions between (int, hexadecimal, and string), and knowing how buit-in functions are impelemented.
## Demo
![Sample Input](images/Sample_Input.png)
![Sample Output](images/Sample_Output.png)
## Features
1- Modular Design
- Separate files for the header file, core impelementation, and helping functions.
2- Supported Format Specifiers:
- `c`: Print a single character.
- `s`: Print a collection of characters.
- `d` or `i`: Print a signed int.
- `u`: Print an unsigned int.
- `f`: Print a floating-point number.
- `x`: Print a hexadecimal number.
- `p`: Print an address of memory.
- `%%`: Print a literal `%` character.
3- Cases Handling
- Handel case of NULL pointer by printing (nil)
4- Custom Features
- `.9s`: Print at max 9 characters of a string.
- `.2f`: Print 2 decimal numbers after the float point.
## Project Structure
```
|
|-- src/
|   |-- main.c              // Contain a sample test case.
|   |-- _printf.c           // The core impelementation of the _printf function.
|   |-- _putchar.c          // Impelementation of _putchar function using write funtion.
|   |-- convertingTypes.c   // Contain some conveting function such as intToString.
|   |-- main.h              // The header file which contains the functions prototypes.
|-- images/                 // Images used in the project.
```
## How to Compile and Run
1- Clone the repository:
```
https://github.com/Almahrouky/_printf.git
cd src\
```
2- Compile the project:
```
gcc main.c _printf.c _putchar.c convertingTypes.c -o main
```
3- Run the executable:
```
.\main
```