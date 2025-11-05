# Hex to RGB Converter

A simple C library for converting hexadecimal color codes to RGB values.

## Features

- Converts hex color strings (with or without `#` prefix) to RGB values
- Error handling with specific error codes
- Static library for easy integration
- Simple test suite

## Building

### Build the static library and test program

```bash
make
```

This will create:
- `libhex_to_rgb.a` - Static library
- `test` - Test program

### Clean build artifacts

```bash
make clean
```

### Run tests

```bash
./test
```

## Usage

### Including the library

```c
#include "hex_to_rgb.h"
```

### Linking

When compiling your program, link against the static library:

```bash
gcc your_program.c -L. -lhex_to_rgb -o your_program
```

### Example

```c
#include "hex_to_rgb.h"
#include <stdio.h>

int main(void) {
    int rgb[3];
    int result;

    result = hex_to_rgb("#FF5733", rgb);
    if (result == HEX_TO_RGB_SUCCESS) {
        printf("RGB: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);
        // Output: RGB: (255, 87, 51)
    } else {
        printf("Error: %d\n", result);
    }

    return 0;
}
```

## API Reference

### Function

```c
int hex_to_rgb(const char *hex_str, int *rgb);
```

Converts a hexadecimal color string to RGB values.

**Parameters:**
- `hex_str` - The hex color string (e.g., `"#FF5733"` or `"FF5733"`)
- `rgb` - Array of 3 integers to store R, G, B values (0-255)

**Returns:**
- `HEX_TO_RGB_SUCCESS` (0) on success
- Error code on failure (see Error Codes below)

**Notes:**
- The hex string can include or omit the `#` prefix
- Must be exactly 6 hexadecimal digits
- Case-insensitive (accepts both uppercase and lowercase)

### Error Codes

All error codes are defined in `hex_to_rgb.h`:

| Code | Constant | Description |
|------|----------|-------------|
| 0 | `HEX_TO_RGB_SUCCESS` | Success |
| -1 | `HEX_TO_RGB_NULL_STRING` | `hex_str` parameter is NULL |
| -2 | `HEX_TO_RGB_NULL_ARRAY` | `rgb` array parameter is NULL |
| -3 | `HEX_TO_RGB_INVALID_LENGTH` | Invalid string length (not 6 hex digits) |
| -4 | `HEX_TO_RGB_INVALID_CHAR` | Invalid hexadecimal character found |

## Project Structure

```
hex-converter/
├── hex_to_rgb.h      # Header file with API and error codes
├── hex_to_rgb.c      # Implementation
├── test.c            # Test program
├── Makefile          # Build configuration
└── README.md         # This file
```

## Requirements

- GCC compiler
- Make
- C99 standard support

## License

This project is provided as-is for educational and development purposes.

