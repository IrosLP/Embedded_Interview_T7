#include <stdio.h>
#include <stdbool.h>

char a1[100], a2[100];
int b[100];

bool isEqual(const char arr1[], const char arr2[]){
    while(*(arr1++) == *(arr2++))
    {
        if(*(arr1-1) == '\0') return true;
    }
    return false;
}

char string[] = "nhat hoang tuan nam nhat tuan hoang nhat nam bao quoc hoang nam hoang";

//ý tưởng: tạo 1 mảng có kích thước bằng số từ và gán toàn bộ giá trị của mảng đó bằng 1 
//-> đếm xong đến phần tử nào thì cho phần tử đã đếm về 0
void dem()
{
    for(int i=0; i<100; i++)
        b[i] = 1;
    int n=0;
    for(int i=0; string[i] != '\0'; i++)
    {
        int count = 1;
        //------------a1[i]-----------------
        int c=0;
        while(string[i] != ' ')
        {
            if(string[i] == '\0') break;
            a1[c] = string[i];
            i++;
            c++;
        }//thoát khỏi while -> a1[i] = ' ';
        a1[c] = '\0';
        if(string[i] == '\0') break;
        //---------------------------------
        if(b[n] == 1)
        {
            b[n] = 0;
            int m=n+1;
            for(int j=i+1; string[j] != '\0'; j++)
            {
                //------------a2[j]-----------------
                int d=0;
                while((string[j] != ' '))
                {
                    if(string[j] == '\0') break;
                    a2[d] = string[j];
                    j++;
                    d++;
                }

                a2[d] = '\0';
                //---------------------------------
                if(isEqual(a1, a2) == 1)
                {
                    count++;
                    b[m] = 0;
                }
                if(string[j] == ' ') m++;
                if(string[j] == '\0') break;
            }
            printf("%s da xuat hien %d lan\n", a1, count);
        }
        if(string[i] == ' ') n++;
    }
}

int main()
{
    dem();
    return 0;
}
