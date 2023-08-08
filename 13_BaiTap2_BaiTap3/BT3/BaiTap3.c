#include <stdio.h>
#include <stdint.h>

void nhapN(uint32_t *N)
{
    do
    {
        printf("Nhap mot so bat ky: ");
        scanf("%d", N);
    }while(*N > 4294967295);
}

long long luyThua(int a, int n)
{
    long long result = 1;
    for(int i=0; i<n; i++)
    {
        result *= a;
    }
    return result;
}

void printNumToString(int N)
{
    //-------------------------------------
    int arr[10], du=N;
    //-------------------------------------
    for(int i=0; i<10; i++)
    {
        arr[i] = du/(luyThua(10, 9-i));
        du = du % (luyThua(10, 9-i));
    }
    //-------------------------------------
    //arr:          0 1 2 3 4 5 6 7 8 9 
    //gtri:         4|2 9 4|9 6 7|2 9 5
    //vị trí arr:   0   1     2     3      4     5     6      7     8     9 
    //tên:          tỷ  trăm  mươi  triệu  trăm  mươi  nghìn  trăm  mươi  

    //luu y: 415 -> bon tram muoi lam CHỨ K PHẢI bon trăm mot mươi nam
    //c=5=lam <=> b!=0
    //b=1 <=> k can in
    char *num[] = {"khong", "mot", "hai", "ba", "bon", "nam", "sau", "bay", "tam", "chin", "lam"};
    char *unit[] = {"tram", "muoi", "ty", "trieu", "nghin", "le", "don vi"};
    int flag = 0, a = 0, b = 0, c = 0;
    for(int i=0; i<10; i++)
    {
        if(i==0)
        {
            if(arr[i]!=0)
            {
                printf("%s ", num[arr[i]]);
                printf("%s ", unit[2]);
            }
        }
        if((i==1)||(i==4)||(i==7))
        {
            a = arr[i];
        }
        if((i==2)||(i==5)||(i==8))
        {
            b = arr[i];
        }
        if((i==3)||(i==6)||(i==9))
        {
            c = arr[i];
            if((a!=0)&&(b!=0)&&(c!=0))
            {
                printf("%s ", num[a]);
                printf("%s ", unit[0]);
                if(b!=1) printf("%s ", num[b]);
                printf("%s ", unit[1]);
                if(c==5) printf("%s ", num[10]);
                else printf("%s ", num[c]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            //--------------------------------------------
            if((a==0)&&(b!=0)&&(c!=0))
            {
                if(b!=1) printf("%s ", num[b]);
                printf("%s ", unit[1]);
                if(c==5) printf("%s ", num[10]);
                else printf("%s ", num[c]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            if((a!=0)&&(b==0)&&(c!=0))
            {
                printf("%s ", num[a]);
                printf("%s ", unit[0]);
                printf("%s ", unit[5]);
                printf("%s ", num[c]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            if((a!=0)&&(b!=0)&&(c==0))
            {
                printf("%s ", num[a]);
                printf("%s ", unit[0]);
                if(b!=1) printf("%s ", num[b]);
                printf("%s ", unit[1]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            //-------------------------------------------------
            if((a==0)&&(b==0)&&(c!=0))
            {
                if(i==9)    printf("va ");
                printf("%s ", num[c]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            if((a==0)&&(b!=0)&&(c==0))
            {
                if(b!=1) printf("%s ", num[b]);
                printf("%s ", unit[1]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            if((a!=0)&&(b==0)&&(c==0))
            {
                printf("%s ", num[a]);
                printf("%s ", unit[0]);
                if(i==3)    printf("%s ", unit[3]);
                if(i==6)    printf("%s ", unit[4]);
                if(i==9)    printf("%s ", unit[6]);
            }
            //-------------------------------------------------
            if((a==0)&&(b==0)&&(c==0));
            a=b=c=0;
        }
    }
}

int main()
{
    uint32_t N=0; //N: 0 -> 4,294,967,295
    nhapN(&N);
    printNumToString(N);
    return 0;
}
