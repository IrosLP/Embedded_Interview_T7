#include <stdio.h>

const int a = 10; //biến a được lưu vào vùng nhớ text - chỉ đọc.
int b = 20; //b là biến global và được khai báo giá trị nên được lưu vào vùng nhớ data.
int c; //c là biến global và được khai báo giá trị nên được lưu vào vùng nhớ bss.

void tong(int n, int m)
{
    int t = n + m; //3 biến n, m ,t là biến cục bộ nên được lưu vào vùng nhớ Stack
    printf("%d + %d = %d", n, m, t); //biến lưu ở vùng nhớ Stack sẽ bị xóa sau khi thoát ra khỏi hàm.
}

int main()
{
    //a = 20; //lỗi vì a chỉ có thể đọc không thê rghi giá trị.
    int *ptr = (int *)malloc(10*sizeof(int)); //biến ptr được cấp phát động nên sẽ được lưu vào vùng nhớ Heap. Biến chỉ được giải phóng khi gọi hàm free()
    free(ptr); //hàm free() để giải phóng vùng nhớ sau khi được cấp phát động 
}