#include <stdio.h>
#include <stdint.h>
#include <string.h>

typedef union{
    struct{
        uint8_t id[1];
        uint8_t data[4];
        uint8_t checkSum[1];
    }object;
    uint8_t array[6];
}dataFrame;

int main()
{
    dataFrame frame1;
    frame1.object.id[0] = 1;
    frame1.object.data[0] = 0;
    frame1.object.data[1] = 1;
    frame1.object.data[2] = 2;
    frame1.object.data[3] = 3;
    frame1.object.checkSum[0] = 8;
    for(int i=0; i<6; i++)
    {
        printf("%d ",frame1.array[i]);
    }
    return 0;
}