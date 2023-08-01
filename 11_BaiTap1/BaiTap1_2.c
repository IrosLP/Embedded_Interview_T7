#include <stdio.h>
#include <stdbool.h>

bool isEqual(const char arr1[], const char arr2[]){
    while(*(arr1++) == *(arr2++))
    {
        if(*(arr1-1) == '\0') return true;
    }
    return false;
}

int countChar(const char string[])
{
    int NumOfChar=1;
    int i=0;
    while(string[i] != '\0')
    {
        NumOfChar++;
        i++;
    }
    return NumOfChar;
}

int countWord(const char string[])
{
    int NumOfWord=1;
    int i=0;
    while(string[i] != '\0')
    {
        if(string[i] == ' ') NumOfWord++;
        i++;
    }
    return NumOfWord;
}

//Ý TƯỞNG: tạo 1 mảng có kích thước bằng số từ và cho toàn bộ giá trị của mảng đó bằng 1 
//đếm xong phần tử nào => đưa phần tử đã đếm về 0

//n: số thứ tự TỪ kiểm tra          (mang đi kiểm tra)
//m: số thứ tự TỪ bị kiểm tra       (bị kiểm tra)

//i: số thứ tự KÝ TỰ kiểm tra       (mang đi kiểm tra)     
//j: số thứ tự KÝ TỰ bị kiểm tra    (bị kiểm tra)

//c: số thứ tự KÝ TỰ arr1           (để gán từ ký tự từ string[] vào arr1[])
//d: số thứ tự KÝ TỰ arr2           (để gán từ ký tự từ string[] vào arr2[])
void dem(const char string[])
{
    char arr1[10], arr2[10];
    int flag[100];
    int n=0;
    for(int i=0; i<countChar(string); i++) flag[i] = 1;
    for(int i=0; string[i] != '\0'; i++)
    {
        int count = 1;
        //------------arr1[i]----------------- //nếu phần này viết thành hàm thì input parameter là
        int c=0;
        while(string[i] != ' ')
        {
            if(string[i] == '\0') break;
            arr1[c] = string[i];
            i++;
            c++;
        }
        arr1[c] = '\0';
        //---------------------------------
        if(string[i] == '\0') break;
        //---------------------------------
        if(flag[n] == 1)
        {
            flag[n] = 0;
            int m=n+1;
            for(int j=i+1; string[j] != '\0'; j++)
            {
                //------------arr2[j]-----------------
                int d=0;
                while((string[j] != ' '))
                {
                    if(string[j] == '\0') break;
                    arr2[d] = string[j];
                    j++;
                    d++;
                }
                arr2[d] = '\0';
                //-------------So sánh 2 từ----------------
                if(isEqual(arr1, arr2) == 1)
                {
                    count++;
                    flag[m] = 0;
                }
                //---------------------------------
                if(string[j] == ' ') m++;
                if(string[j] == '\0') break;
            }
            printf("%s da xuat hien %d lan\n", arr1, count);
        }
        if(string[i] == ' ') n++;
    }
}

int main()
{
    char string[] = "nhat hoang tuan nam nhat tuan hoang nhat nam bao quoc nam nhat nam bao quoc nam";
    dem(string);
    
    // printf("%d\n\n", countWord(string));
    // int abc[countWord(string)];
    // for(int i=0; i<countWord(string); i++)
    // {
    //     abc[i] = i;
    // }
    // for(int i=0; i<countWord(string); i++)
    // {
    //     printf("%d\n", abc[i]);
    // }
    return 0;
}
