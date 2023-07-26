#include <stdio.h>

#define SIZE 20

#define SUM(a,b) a+b

int main()
{
    int array[SIZE];
    printf("Tong a va b la %d", SUM(5,6));
    return 0;
}
//để chạy Preprocessor gõ: gcc -E Compiler.c -o Compiler.i
//để chạy Compiler gõ: gcc Compiler.i -S -o Compiler.s
//để chạy Assembler gõ: gcc -c Compiler.s -o Compiler.o