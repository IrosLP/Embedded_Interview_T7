#include <stdio.h>

void testNormal()
{
    int n = 10;
    printf("Normal n = %d\n", n);
    n++;
}

void testStatic()
{
    static int s = 10;
    printf("Static s = %d\n\n", s);
    s++;
}

int main()
{
    printf("Goi lan 1\n");
    testNormal();
    testStatic();
    printf("Goi lan 2\n");
    testNormal();
    testStatic();
    printf("Goi lan 3\n");
    testNormal();
    testStatic();
    return 0;
}