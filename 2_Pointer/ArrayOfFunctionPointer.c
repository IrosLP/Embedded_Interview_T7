#include <stdio.h>

void tong(int a, int b)
{
  printf("%d + %d = %d\n", a, b, a+b);
}

void hieu(int a, int b)
{
  printf("%d - %d = %d\n", a, b, a-b);
}

void tich(int a, int b)
{
  printf("%d * %d = %d\n", a, b, a*b);
}

int main()
{
  void (*phepToan[])(int, int) = {tong, hieu, tich};
  phepToan[0](10, 20);
  phepToan[1](10, 20);
  phepToan[2](10, 20);
  //hoặc
  enum PhepToan{tong, hieu, tich};
  printf("\nSu dung enum\n");
  phepToan[tong](10, 20);
  phepToan[hieu](10, 20);
  phepToan[tich](10, 20);
  return 0;
}