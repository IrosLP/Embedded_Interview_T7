#include <stdio.h>



int main()
{
    static int x;
    int *ptr = &x;
    //*px = 15;  // ERROR do cố ghi lại giá trị cho vùng nhớ qua con trỏ hằng
    // ptr = &y;   // OK
    // *ptr = 15;    // OK
    printf("%d", *ptr);
    return 0;
} 