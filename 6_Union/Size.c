#include <stdio.h>

union sinhVien{
  int maSV;
  int tuoi;
  char TenSV[5];
  double diemTB;
};

int main()
{
    printf("Size sinhVien: %d\n", sizeof(union sinhVien));
    return 0;
}