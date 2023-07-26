#include <stdio.h>

#define SIZE 20

int main()
{
    #if SIZE > 20
    printf("size lon hon 20");

    #elif SIZE == 20
    printf("size bang 20");

    #else
    printf("size nho hon 20");
    #endif
    return 0;
}