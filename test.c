#include "hex_to_rgb.h"
#include <stdio.h>
#include <string.h>
#include <stddef.h>

int main(void) {
    int rgb[3];
    int result;
    const char *test_cases[] = {
        "#FF5733",
        "00FF00",
        "#000000",
        "FFFFFF",
        "#123ABC",
        "abc123"
    };

    printf("Testing hex_to_rgb conversion:\n\n");

    for (size_t i = 0; i < sizeof(test_cases) / sizeof(test_cases[0]); i++) {
        memset(rgb, 0, sizeof(rgb));
        result = hex_to_rgb(test_cases[i], rgb);

        if (result == 0) {
            printf("✓ %s -> RGB(%d, %d, %d)\n", 
                   test_cases[i], rgb[0], rgb[1], rgb[2]);
        } else {
            printf("✗ %s -> Error parsing\n", test_cases[i]);
        }
    }

    // Test error cases
    printf("\nTesting error cases:\n\n");

    // NULL pointer
    result = hex_to_rgb(NULL, rgb);
    printf("NULL hex_str: %s (expected HEX_TO_RGB_NULL_STRING=%d, got %d)\n", 
           result == HEX_TO_RGB_NULL_STRING ? "✓" : "✗", HEX_TO_RGB_NULL_STRING, result);

    result = hex_to_rgb("#FF5733", NULL);
    printf("NULL rgb array: %s (expected HEX_TO_RGB_NULL_ARRAY=%d, got %d)\n", 
           result == HEX_TO_RGB_NULL_ARRAY ? "✓" : "✗", HEX_TO_RGB_NULL_ARRAY, result);

    // Invalid length
    result = hex_to_rgb("#FF", rgb);
    printf("Short string (#FF): %s (expected HEX_TO_RGB_INVALID_LENGTH=%d, got %d)\n", 
           result == HEX_TO_RGB_INVALID_LENGTH ? "✓" : "✗", HEX_TO_RGB_INVALID_LENGTH, result);

    result = hex_to_rgb("FF", rgb);
    printf("Short string (FF): %s (expected HEX_TO_RGB_INVALID_LENGTH=%d, got %d)\n", 
           result == HEX_TO_RGB_INVALID_LENGTH ? "✓" : "✗", HEX_TO_RGB_INVALID_LENGTH, result);

    result = hex_to_rgb("#FFFFFFFF", rgb);
    printf("Long string (#FFFFFFFF): %s (expected HEX_TO_RGB_INVALID_LENGTH=%d, got %d)\n", 
           result == HEX_TO_RGB_INVALID_LENGTH ? "✓" : "✗", HEX_TO_RGB_INVALID_LENGTH, result);

    // Invalid characters
    result = hex_to_rgb("#GGGGGG", rgb);
    printf("Invalid chars (#GGGGGG): %s (expected HEX_TO_RGB_INVALID_CHAR=%d, got %d)\n", 
           result == HEX_TO_RGB_INVALID_CHAR ? "✓" : "✗", HEX_TO_RGB_INVALID_CHAR, result);

    result = hex_to_rgb("#FF57Z3", rgb);
    printf("Invalid chars (#FF57Z3): %s (expected HEX_TO_RGB_INVALID_CHAR=%d, got %d)\n", 
           result == HEX_TO_RGB_INVALID_CHAR ? "✓" : "✗", HEX_TO_RGB_INVALID_CHAR, result);

    return 0;
}

