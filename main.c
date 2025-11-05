#include "hex_to_rgb.h"
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    int rgb[3];
    int result;

    if (argc != 2) {
        return EXIT_FAILURE;
    }

    printf("Input: %s\n", argv[1]);

    result = hex_to_rgb(argv[1], rgb);
    
    if (result == HEX_TO_RGB_SUCCESS) {
        printf("RGB: (%d, %d, %d)\n", rgb[0], rgb[1], rgb[2]);
    }
    else {
        printf("Error: %d\n", result);
    }

    return result;
}
