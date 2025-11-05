#include "hex_to_rgb.h"
#include <string.h>

static int hex_char_to_int(char c) {
    if (c >= '0' && c <= '9') {
        return c - '0';
    }
    if (c >= 'A' && c <= 'F') {
        return c - 'A' + 10;
    }
    if (c >= 'a' && c <= 'f') {
        return c - 'a' + 10;
    }
    return -1;
}

int hex_to_rgb(const char *hex_str, int *rgb) {
    if (!hex_str) {
        return HEX_TO_RGB_NULL_STRING;
    }
    if (!rgb) {
        return HEX_TO_RGB_NULL_ARRAY;
    }

    int len = strlen(hex_str);
    int start_idx = 0;

    // Skip '#' if present
    if (hex_str[0] == '#') {
        start_idx = 1;
        len--;
    }

    // Must be exactly 6 hex digits
    if (len != 6) {
        return HEX_TO_RGB_INVALID_LENGTH;
    }

    // Parse each color component (2 hex digits each)
    for (int i = 0; i < 3; i++) {
        int high = hex_char_to_int(hex_str[start_idx + i * 2]);
        int low = hex_char_to_int(hex_str[start_idx + i * 2 + 1]);

        if (high < 0 || low < 0) {
            return HEX_TO_RGB_INVALID_CHAR;
        }

        rgb[i] = high * 16 + low;
    }

    return HEX_TO_RGB_SUCCESS;
}

