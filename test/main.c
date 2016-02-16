#include <stdio.h>
#include <stdlib.h>

#include "../lib.h"


int main(void) {
    float32 x0 = string_to_float32("-32");
    float32 x1 = string_to_float32("-0");
    float32 x2 = string_to_float32("0");
    float32 x3 = string_to_float32("32");
    printf("%f\n", (float) x0);
    printf("%f\n", (float) x1);
    printf("%f\n", (float) x2);
    printf("%f\n", (float) x3);
    return 0;
}
