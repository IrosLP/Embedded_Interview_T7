#include <stdio.h>

char string[] = "nhat hang tuan nam nhat tuan hang nhat nam bao quoc nam";

//-------------số từ------------
int numOfWord(const char string[])
{
    int size = 1;
    for(int i=0; *(string+i) != '\0'; i++)
    {
        if(*(string+i) == ' ') size++;
    }
    return size;
}

//-------------đảo từ----------------
void daoTu(char string[])
{
    int size = numOfWord(string);
    char *arr[size];
    int index = 0;
    arr[index] = string;
    while(*string != '\0')
    {
        if(*string == ' ') 
        {
            *string = '\0';
            index++;
            string++;
            arr[index] = string;
        }
        else
        {
            string++;
        }
    }
    for(int i=size-1; i>=0; i--)
    {
        printf("%s ", arr[i]);
    }
}

int main()
{
    daoTu(string);
    return 0;
}