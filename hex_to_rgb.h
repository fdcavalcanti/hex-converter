#ifndef HEX_TO_RGB_H
#define HEX_TO_RGB_H

/**
 * Error codes for hex_to_rgb function
 */
enum hex_to_rgb_error {
    HEX_TO_RGB_SUCCESS = 0,        /* Success */
    HEX_TO_RGB_NULL_STRING = -1,   /* hex_str is NULL */
    HEX_TO_RGB_NULL_ARRAY = -2,    /* rgb array is NULL */
    HEX_TO_RGB_INVALID_LENGTH = -3, /* Invalid string length (not 6 hex digits) */
    HEX_TO_RGB_INVALID_CHAR = -4   /* Invalid hex character found */
};

/**
 * Converts a hex color string to RGB values.
 * 
 * @param hex_str The hex color string (e.g., "#FF5733" or "FF5733")
 * @param rgb Array of 3 integers to store R, G, B values (0-255)
 * @return HEX_TO_RGB_SUCCESS (0) on success, error code on failure
 */
int hex_to_rgb(const char *hex_str, int *rgb);

#endif /* HEX_TO_RGB_H */

