*This project has been created as part of the 42 curriculum by ahoumdi.*

# ft_printf

## Description

**ft_printf** is a recreation of the standard C `printf()` function, developed as part of the 42 Common Core curriculum.

Its objective is to implement formatted output by processing format specifiers, retrieving variadic arguments, and converting different data types into printable representations.

The project focuses on variadic functions, format parsing, data representation, low-level output operations, and error handling.

The resulting static library, `libftprintf.a`, provides a custom implementation of formatted output.

The project is written in C and compiled using `-Wall -Wextra -Werror`.

## Contents

### Supported conversions

The implementation covers the mandatory conversions specified by the 42 ft_printf subject.

| Specifier | Argument type | Description | Output format |
|---|---|---|---|
| `%c` | `int` | Prints a single character. | Character |
| `%s` | `char *` | Prints a string. | String |
| `%p` | `void *` | Prints a pointer address. | Hexadecimal with `0x` prefix |
| `%d` | `int` | Prints a signed decimal integer. | Base 10 |
| `%i` | `int` | Prints a signed integer. | Base 10 |
| `%u` | `unsigned int` | Prints an unsigned decimal integer. | Base 10 |
| `%x` | `unsigned int` | Prints an unsigned hexadecimal integer. | Base 16, lowercase |
| `%X` | `unsigned int` | Prints an unsigned hexadecimal integer. | Base 16, uppercase |
| `%%` | None | Prints a literal percent sign. | `%` |

### Variadic argument handling

The implementation uses the standard C variadic argument interface provided by `<stdarg.h>`.

| Macro | Purpose |
|---|---|
| `va_start` | Initializes access to the variadic arguments. |
| `va_arg` | Retrieves the next argument with the specified type. |
| `va_end` | Ends the traversal of the variadic arguments. |

### Important implementation requirements

- The function must return the number of characters printed, excluding the terminating null byte.
- If an output operation fails, the function must propagate an error by returning `-1`.
- `%d` and `%i` handle signed integers, including negative values.
- `%u`, `%x`, and `%X` must handle the full range of unsigned integers.
- `%p` prints pointer addresses in hexadecimal with the required `0x` prefix.
- `%%` must print a literal percent character without consuming a variadic argument.
- The implementation must respect the argument types and default argument promotions required by C.

## Design notes

The implementation separates format processing from individual conversion routines, keeping argument retrieval, conversion, and output responsibilities distinct.

- **Variadic argument handling:** Uses `va_list` and the associated macros to retrieve arguments according to their conversion specifiers.
- **Format processing:** Examines the format string, identifies conversion specifiers, and dispatches them to their corresponding printing functions.
- **Number conversion:** Handles signed and unsigned integer representations, including decimal and hexadecimal bases.
- **Pointer representation:** Converts pointer values into hexadecimal output with the appropriate prefix.
- **Output:** Uses the `write()` system call to send characters to the standard output file descriptor.
- **Character counting:** Tracks the number of successfully printed characters and propagates output errors.
- **Error handling:** Ensures that failed output operations are reflected in the function's return value.

## Instructions

### Compilation

From the project directory:

```sh
make          # Builds libftprintf.a
make clean    # Removes object files
make fclean   # Removes object files and libftprintf.a
make re       # Performs a clean rebuild
```

The Makefile:

- Compiles source files using `cc -Wall -Wextra -Werror`.
- Creates the static library using `ar rcs`.
- Tracks source and header dependencies when building object files.

### Usage

Include the project header in your source file:

```c
#include "ft_printf.h"
```

Use `ft_printf()` as you would use the standard `printf()` function:

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello %s! Number: %d\n", "world", 42);
    return (0);
}
```

Compile and link your program against the static library:

```sh
cc -Wall -Wextra -Werror main.c -I. libftprintf.a -o main
```

Run the resulting executable:

```sh
./main
```

## Resources

### References

- **42 ft_printf subject:** Official project specifications, conversion requirements, and implementation constraints.
- **ISO/IEC 9899 (C Standard):** Reference for variadic functions, integer types, argument promotions, and language behavior.
- **`man 3 printf`:** Standard formatted output behavior and conversion specifications.
- **`man 3 stdarg`:** Documentation for variadic argument handling.
- **`man 2 write`:** Documentation for the `write()` system call, return values, and error handling.
- **System V AMD64 ABI:** Calling conventions, register usage, stack organization, and variadic function argument handling.
- **GNU Make Manual:** Build rules, dependencies, and phony targets.
- **`ar(1)` manual page:** Documentation for creating and managing static libraries.

### AI Usage

AI was used to explore underlying concepts and find relevant learning resources and technical documentation.
