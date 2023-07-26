#include <stdio.h>

typedef struct{
    int maSV;
    char ten[10];
    int tuoi;
    float diemToan, diemVan, diemAnh, diemTB;
}sinhVien;

void inThongTinSV(sinhVien sv) 
{
    printf("Thong tin sinh vien:");
    printf("Ma sinh vien: %d\n", sv.maSV);
    printf("Ten sinh vien: %s\n", sv.ten);
    printf("Tuoi sinh vien: %d\n", sv.tuoi);
    printf("Diem toan: %f\n", sv.diemToan);
    printf("Diem van: %f\n", sv.diemVan);
    printf("Diem anh: %f\n", sv.diemAnh);
}

int main()
{
    sinhVien sv;
    sv.maSV = 123;
    strcpy(sv.ten, "Loc");
    sv.tuoi = 23;
    sv.diemToan = 6;
    sv.diemVan = 7;
    sv.diemAnh = 8;
    inThongTinSV(sv);
    
    return 0;
}
