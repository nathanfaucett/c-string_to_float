#ifndef __STRING_TO_FLOAT_H__
#define __STRING_TO_FLOAT_H__


#include "types/lib.h"


#define STRING_TO_FLOAT_HEADER(TYPE) \
    TYPE string_to_##TYPE(char* ascii);

#define STRING_TO_UINT_HEADER(TYPE) \
    TYPE string_to_##TYPE(char* ascii);


#define STRING_TO_FLOAT_SRC(TYPE) \
    TYPE string_to_##TYPE(char* ascii) {\
        if (!ascii || !*ascii) {\
            return 0;\
        } else {\
            TYPE integer_part = 0;\
            TYPE fraction_part = 0;\
            intsize divisor_for_fraction = 1;\
            intsize sign = 1;\
            bool in_fraction = false;\
            \
            if (*ascii == '-') {\
                ++ascii;\
                sign = -1;\
            } else if (*ascii == '+') {\
                ++ascii;\
            }\
            while (*ascii != '\0') {\
                if (*ascii >= '0' && *ascii <= '9') {\
                    if (in_fraction) {\
                        fraction_part = fraction_part*10 + (*ascii - '0');\
                        divisor_for_fraction *= 10;\
                    } else {\
                        integer_part = integer_part*10 + (*ascii - '0');\
                    }\
                } else if (*ascii == '.') {\
                    if (in_fraction) {\
                        return sign * (integer_part + fraction_part / divisor_for_fraction);\
                    } else {\
                        in_fraction = true;\
                    }\
                } else {\
                    return sign * (integer_part + fraction_part / divisor_for_fraction);\
                }\
                ++ascii;\
            }\
            return sign * (integer_part + fraction_part / divisor_for_fraction);\
        }\
    }\


STRING_TO_FLOAT_HEADER(float32);
STRING_TO_FLOAT_HEADER(float64);


#endif
