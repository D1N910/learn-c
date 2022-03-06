#include <stdio.h>

#define MK_ID(n) i##n
#undef MK_ID
#define MK_ID(n) i1##n

#define GENERIC_MAX(type)           \
type type##_max(type x, type y)    \
{                                   \
    return (x) > (y) ? (x) : (y);    \
}

GENERIC_MAX(float);

int main(void) {
    float MK_ID(0), MK_ID(1), MK_ID(2);
    i10 = 2.0f;
    i12 = 3.0f;
    printf("%f \n", float_max(i10, i12));
    return 0;
}