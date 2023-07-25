#include <stdio.h>

void tong(int a, int b)
{
    printf("%d + %d = %d", a, b, a+b);
}

void hieu(int a, int b)
{
    printf("%d - %d = %d", a, b, a-b);
}

void tich(int a, int b)
{
    printf("%d * %d = %d", a, b, a*b);
}

void main()
{
    void *ptr[] = {tong, hieu, tich};
    ((void (*)(int, int))ptr[2])(7,5);
}