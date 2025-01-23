# ft_printf

A custom implementation of the printf function in C.

## Description

This project recreates the printf function from the C standard library, implementing various format specifiers and flags. The function supports formatting and printing text to standard output with various options for formatting numbers, strings, and other data types.

## Features

### Format Specifiers
- `%c` - Print a single character
- `%s` - Print a string
- `%p` - Print a pointer address
- `%d` - Print a decimal (base 10) number
- `%i` - Print an integer in base 10
- `%u` - Print an unsigned decimal number
- `%x` - Print a number in hexadecimal (base 16) lowercase
- `%X` - Print a number in hexadecimal (base 16) uppercase
- `%%` - Print a percent sign

### Flags
- `-` : Left-justify within the given field width
- `+` : Forces to precede the result with a plus or minus sign
- ` ` : (space) If no sign is going to be written, a blank space is inserted before the value
- `#` : Used with x or X specifiers the value is preceded with 0x or 0X
- `0` : Left-pads the number with zeroes instead of spaces
- `.` : Precision specification

### Compilation

To compile the program, use the following command:

```bash
make
```
