#include <stdio.h>

struct sinhVien1{
  int maSV;
  double diemTB;
  int tuoi;
  char TenSV[5];
};

struct sinhVien2{
  int maSV;
  int tuoi;
  char TenSV[5];
  double diemTB;
};

int main()
{
    printf("Size sinhVien1: %d\n", sizeof(struct sinhVien1));
    printf("Size sinhVien2: %d\n", sizeof(struct sinhVien2));
    return 0;
}