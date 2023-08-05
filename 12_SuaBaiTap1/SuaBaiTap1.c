#include <stdio.h>
#include <stdbool.h>
#include <stdint.h>
#include <stdlib.h>

typedef struct{
    char *ptr;
    uint8_t length;
}words;

typedef struct{
    char *words;
    uint8_t length;
}wordsArray;

int count = 3;

char string[] = "nhat hang tuan nam nhat tuan hang nhat nam bao quoc nam";

bool isEqual(const char arr1[], const char arr2[])
{
    while (*arr1 == *arr2)
    {
        if(*arr1 == '\0')
        {
            return true;
        }
        arr1++;
        arr2++;
    }
    return false;
}

bool isLarger(const char arr1[], const char arr2[])
{
    while (*arr1 == *arr2)
    {
        if(*arr1 == '\0')
        {
            return false;
        }
        arr1++;
        arr2++;
    }
    if(*arr1 > *arr2)
    {
        return true;
    }
    return false;
}

//-------------------------tìm số từ---------------------
int numOfWord(char string[])
{
    uint8_t size = 1;
    char *ptr = string;
    while(*ptr != '\0')
    {
        if(*ptr == ' ') size++;
        ptr++;
    }
    return size;
}

words* splitString(char string[])
{
    //-------------------------tìm số từ---------------------
    int size = numOfWord(string);
    //-------------------------tạo mảng - gán từng từ vào mảng----------------------
    words *array = (words *)malloc(sizeof(words) * size);
    uint8_t index = 0, count = 1;
    array[index].ptr = string;
    while(*string != '\0')
    {
        if(*string == ' ')
        {
            *string = '\0';
            count = 1;
            string++;
            array[++index].ptr = string;
        }
        else
        {
            count++;
            string++;
        }
        array[index].length = count;
    }
    //-----------------trả về mảng------------------
    return array;
}

void sortAlphabet(words array[], int size)
{
    for(int i=0; i<size-1; i++)
    {
        words temp;
        for(int j=i+1; j<size; j++)
        {
            //--------------nếu array[i].ptr > array[j].ptr => đổi chỗ----------------
            if(isLarger(array[i].ptr, array[j].ptr))
            {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

void test(words test)
{
    for(int i=0; i<test.length; i++)
    {
        printf("%c", test.ptr[i]);
    }
}

void countSameWord(words *listWord, int size)
{
    int count = 1;
    int after = 0;
    int current;
    for(current = 0; current < size-1; current++) //curr:     0->11
    {                                           //after:    1->12
        after = current + 1;
        if(isEqual(listWord[current].ptr, listWord[after].ptr))
        {
            count++;
            if(current == size-2)
            {
                test(listWord[current]);
                printf("\t%d\n", count);
            }
        }
        else
        {
            test(listWord[current]);
            printf("\t%d\n", count);
            count = 1;
            if(current == size-2)
            {
                test(listWord[after]);
                printf("\t%d\n", count);
            }
        }
    }
}

int main()
{
    // char arr1[] = "hello";
    // char arr2[] = "hello"; 
    //printf("%d\n", isEqual(arr1, arr2));

    //---------tạo con trỏ ptr -> mảng từ từ
    int size = numOfWord(string);
    words *listWord = splitString(string);
    sortAlphabet(listWord, size);
    // for(int i=0; i<size ; i++)
    // {
    //     test(listWord[i]);
    //     printf("\n");
    // }
    countSameWord(listWord, size);
    return 0;
}