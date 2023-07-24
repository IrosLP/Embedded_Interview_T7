<details>
<summary>C Programming Language</summary>

<details>
<summary>Kiểu dữ liệu</summary>

- `uint8_t` = `unsigned char` là biến có 8 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[0 \to (2^8-1)]$ hay $[0 \to 255]$
- `int8_t` = `char` là biến có 8 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[(-\frac{2^8}{2}) \to (\frac{2^8}{2}-1)]$ hay $[(-128) \to 127]$
- `uint16_t` = `unsigned short` là biến có 16 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[0 \to (2^{16}-1)]$ hay $[0 \to 65,535]$
- `int16_t` = `short` là biến có 16 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[(-\frac{2^{16}}{2}) \to (\frac{2^{16}}{2}-1)]$ hay $[(-32,768) \to 32,767]$
- `uint32_t` = `unsigned int` là biến có 32 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[0 \to (2^{32}-1)]$ hay $[0 \to 4,294,967,295]$
- `int32_t` = `int` là biến có 32 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[(-\frac{2^{32}}{2}) \to (\frac{2^{32}}{2}-1)]$ hay $[(-2,147,483,648) \to 2,147,483,647]$
- `uint64_t` = `unsigned long long` là biến có 64 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[0 \to (2^{64}-1)]$ hay $[0 \to 18,446,744,073,709,551,615]$
- `int64_t` = `long long` là biến có 64 bit (ô nhớ), giá trị của biến này nằm trong khoảng từ $[(-\frac{2^{64}}{2}) \to (\frac{2^{64}}{2}-1)]$ hay $[(-9,223,372,036,854,775,808) \to 9,223,372,036,854,775,807]$
- Nếu biến nằm ngoài khoảng giá trị của nó thì chương trình sẽ báo lỗi.

</details>

<details>
<summary>Typedef</summary>

- Cú pháp: 
```c 
typedef <Kiểu dữ liệu cũ> (<Kiểu dữ liệu tham số> tham số);
```
- `typedef` được sử dụng để định nghĩa một cái tên mới cho một kiểu dữ liệu đã tồn tại. 
Bằng cách sử dụng `typedef`, chúng ta có thể đặt một tên dễ nhớ và sử dụng lại cho một kiểu dữ liệu phức tạp hoặc có tên dài. 
- Ví dụ: 
```c
typedef int typeInt; //typeInt chính là int
typeInt a = 10;      //= int a = 10;
``` 
- Việc sử dụng `typedef` có thể giúp mã lệnh dễ đọc và dễ hiểu hơn, đặc biệt là khi bạn đang làm việc với các kiểu dữ liệu phức tạp như struct, con trỏ hoặc danh sách liên kết.

</details> 

<details>
<summary>Hàm</summary>

- Cú pháp: 
```c
<kiểu trả về> <tên hàm>(<tham số 1>, <tham số 2>, ...) 
{
  // Mã lệnh 
  // ...
  //return ...; (nếu kiểu trả về khác kiểu void)
}
```
- Ví dụ:
```c
int tinhTong(int a, int b) 
{
  return a+b; 
}
```
- Hàm đơn giản cũng chỉ là 1 chương trình
- Hàm được sử dụng khi cần lặp đi lặp lại 1 công việc giống nhau nhiều lần.
</details>
<details>
<summary>Struct</summary>

- Cú pháp: 
```c
struct <tên struct>
{
  // <kiểu dữ liệu 1> biến1;
  // <kiểu dữ liệu 2> biến2;
  // ...
};
```
- Ví dụ:
```c
struct sinhVien
{
  float diem;
  int tuoi;
};
```
- Struct dùng để định nghĩa một kiểu dữ liệu mới, bao gồm nhiều kiểu dữ liệu khác nhau.
- Có nhiều cách để khai báo phần tử cho biến có kiểu dữ liệu từ struct
- Cách 1:
```c
struct sinhVien sv1;
sv1.diem = 9.3;
sv1.tuoi = 20;
```
- Cách 2:
```c
struct sinhVien sv1;
sv1 = {.diem = 9.3, .tuoi = 20};
//hoặc sv1 = {.tuoi = 20, .diem = 9.3};
```
- Cách 3:
```c
struct sinhVien sv1;
sv1 = {9.3, 20};
```
- Ví dụ:
```c
struct sinhVien
{
  float diem;
  int tuoi;
};

int main()
{
  struct sinhVien sv1; //khai báo biến sv1 thuộc kiểu dữ liệu sinhVien
  //gán giá trị cho từng phần tử của sv1
  sv1.diem = 9.3;
  sv1.tuoi = 20;
  printf("%f %d", sv1.diem, sv1.tuoi);
  return 0;
}
```
Output: `9.300000 20`
</details>

<details>
<summary> Vòng lặp 'for()'</summary>

- Cú pháp:
```c
for(<vùng khởi tạo biến ban đầu>; <vùng điều kiện>; <vùng thuật toán>)
{
  //câu lệnh sẽ được thực hiện nếu điều kiện đúng
}
```
- Ví dụ:
```c
for(int i=0; i<10; i++)
{
  printf("%d ",i);
}
```
Output: `0 1 2 3 4 5 6 7 8 9`
- Cách vòng lặp for chạy:
  - Bước 1. Khởi tạo biến ban đầu
  - Bước 2. So sánh với điều kiện
  - Bước 3. Thực hiện chương trình bên trong vòng lặp (nếu điều kiện đúng)
  - Bước 4. Tăng giá trị
  - Bước 5. Thực hiện lại Bước 1 cho đến khi điều kiện sai
- Vùng khởi tạo biến ban đầu:
  - Ta có thể khởi tạo biến gì cũng được
  - Hoặc không khởi tạo biến (để trống vùng đó cũng được)
- Vùng điều kiện:
  - Thường vùng này sẽ là một lệnh so sánh (chương trình sẽ dừng khi điều kiện sai).
  - Đôi khi ta có thể để trống vùng này được.
  - Khi để trống thì điều kiện là luôn đúng (vòng for chạy mãi mãi)
- Vùng thuật toán:
  - Ta có thể để trống vùng này được
  - Vùng thuật toán sẽ được thực hiện sau khi chạy xong code ở bên trong vòng lặp for
</details>

<details>
<summary>Vòng lặp 'while()' </summary>

- Cú pháp:
```c
while(điều kiện)
{
  //câu lệnh sẽ được thực hiện nếu điều kiện đúng
}
```
- Ví dụ:
```c
int i = 0;
while(i<10)
{
  printf("%d ",i);
  i++;
}
```
Output: `0 1 2 3 4 5 6 7 8 9`
- Cách vòng lặp `while()` chạy:
  - Bước 1. Tạo biến ban đầu bên ngoài vòng `while()`.
  - Bước 2. So sánh với điều kiện.
  - Bước 3. Thực hiện chương trình bên trong vòng lặp (nếu điều kiện đúng).
  - Bước 4. Tăng giá trị cho biến.
  - Bước 5. Thực hiện lại Bước 1 cho đến khi điều kiện sai.
- Lưu ý:
  - Đôi khi vòng lặp `while()` sẽ không có câu lệnh so sánh trong điều kiện.
  - Khi đó `while(0)` (điều kiện bằng 0)-> vòng lặp sẽ không bao giờ chạy.
  - Khi đó `while(1)` (điều kiện khác 0) -> vòng lặp sẽ lặp lại vô hạn lần.
  - Chỉ khi có tác động từ bên ngoài để kích hoạt `exit(1)` thì `while(1)` mới dừng.
</details>

<details>
<summary> Vòng lặp 'do-while()' </summary>

- Cú pháp:
```c
do
{
  //câu lệnh sẽ được thực hiện đầu tiên hoặc nếu điều kiện đúng ở lần lặp thứ 2 trở đi
} while(điều kiện);
```
- Ví dụ:
```c
int i = 10;
do
{
  printf("%d ",i);
  i++;
} while(i<10);
```
Output: `10`
- Cách vòng lặp `do-while()` chạy:
  - Bước 1. Tạo biến ban đầu bên ngoài vòng `do-while()`.
  - Bước 2. Thực hiện chương trình bên trong vòng lặp (nếu là lần đầu chạy vòng lặp hoặc điều kiện đúng).
  - Bước 3. Tăng giá trị cho biến.
  - Bước 4. So sánh với điều kiện.
  - Bước 5. Thực hiện lại Bước 1 cho đến khi điều kiện sai.
- Lưu ý:
  - Vòng lặp `do-while()` khác với `while()` là sẽ thực hiện chương trình bên trong vòng lặp ít nhất 1 lần (kể cả khi điều kiện có sai).
  - Ứng dụng cho việc nhập dữ liệu từ bàn phím.
</details>

<details>
<summary>Break</summary>

- Cú pháp:
```c
break;
```
- Ví dụ:
```c
for(int i=0; i<10; i++)
{
  if(i==5) break;
  printf("%d\n",i);
}
```
Output: `0 1 2 3 4`
- `break` dùng để thoát ra khỏi vòng lặp ngay lặp tức
</details>

<details>
<summary>Continue</summary>

- Cú pháp:
```c
continue;
```
- Ví dụ:
```c
for(int i=0; i<10; i++)
{
  if(i==5) continue;
  printf("%d\n",i);
}
```
Output: `0 1 2 3 4 6 7 8 9`
- `continue` dùng để thoát ra khỏi vòng lặp hiện tại và thực hiện tiếp vòng lặp mới
</details>

<details>
<summary> Cấu trúc rẽ nhánh 'if() - else if() - else' </summary>

- Cú pháp:
```c
if(điều kiện)
{
  //câu lệnh sẽ được thực hiện nếu điều kiện đúng.
}
else if(điều kiện)
{
  //câu lệnh sẽ được thực hiện nếu điều kiện đúng.
}
else
{
  //câu lệnh sẽ được thực hiện nếu tất cả các điều kiện trên không đúng.
}
```
- Ví dụ:
```c
float diem = 9;
if(diem >= 8)
{
  printf("Gioi\n");
}
else if(diem >= 6.5)
{
  printf("Kha\n");
}
else if(diem >= 5)
{
  printf("Trung Binh\n");
}
else
{
  printf("Yeu\n");
}
```
Output: `10`
- Cách cấu trúc rẽ nhánh `if()` chạy:
  - Bước 1. Tạo biến ban đầu bên ngoài vòng `if()`.
  - Bước 2. So sánh tuần tự tất cả các điều kiện
  - Bước 3. Khi gặp điều kiện đúng, thực hiện chương trình bên trong điều kiện đó
  - Bước 4. Thoát ra khỏi cấu trúc `if() - else if() - else` (kể cả điều kiện phía sau có đúng).
- Lưu ý:
  - `if() - else if() - else` chỉ thực hiện so sánh tuần tự tất cả các điều kiện.
  - Chương trình sẽ thoát ra khỏi cấu trúc `if() - else if() - else` sau khi thực hiện hết chương trình bên trong điều kiện đúng đầu tiên.
  - Và không so sánh những điều kiện còn lại dù điều kiện sau đó có đúng.
</details>

<details>
<summary> Cấu trúc lựa chọn 'switch() - case' </summary>

- Cú pháp:
```c
switch(biến)
{
  case constant1:
    //lệnh
    break;
  case constant2:
    //lệnh
    break;
  .
  .
  .
  default:
    //lệnh
}
```
- Ví dụ:
```c
int a = 1;
switch a:
{
  case 0:
    printf("0\n");
    break;
  case 1:
    printf("1\n");
    break;
  .
  .
  .
  default:
    printf("dafault\n");
}
```
Output: `1`
- Cách cấu trúc lựa chọn `switch() - case` chạy:
  - Bước 1. Tạo biến ban đầu bên ngoài vòng `switch() - case`.
  - Bước 2. So sánh tuần tự biến có bằng một trong số các giá trị có trong `case` hay không. Nếu không có thì sẽ thực hiện chương trình ở `default`.
  - Bước 3. Khi gặp giá trị đúng, thực hiện chương trình bên trong `case` đó.
  - Bước 4. Thoát ra khỏi cấu trúc `switch() - case`.
- Lưu ý:
  - Mỗi `case` đều phải có `break;`. 
  - Trừ `default` mới không cần `break;`
  - Nếu không có `break;` thì chương trình sẽ bắt đầu chạy từ case đúng cho đến hết tất cả các lệnh của code block trong `switch() - case`
</details>

<details>
<summary>Enum</summary>

- Cú pháp:
```c
enum <tên kiểu dữ liệu mới> {giá trị 1, giá trị 2,...,giá trị n};
```
- Ví dụ:
```c
enum Thu {Thu2, Thu3, Thu4,..., CN};
enum Thu thu = Thu2; //`thu` có kiểu dữ liệu là `Thu` và giá trị bằng `Thu2` (hay là 0)
```
- Hoặc sử dụng `typedef`
```c
typedef enum {Thu2, Thu3, Thu4 = 4, Thu5, Thu6, Thu7 = 10, CN}Thu;
Thu thu = Thu2; //`thu` có kiểu dữ liệu là `Thu` và giá trị bằng `Thu2` (hay là 0)
printf("%d\n", Thu2); //Output: 0
printf("%d\n", Thu3); //Output: 1
printf("%d\n", Thu4); //Output: 4
printf("%d\n", Thu5); //Output: 5
printf("%d\n", Thu6); //Output: 6
printf("%d\n", Thu7); //Output: 10
printf("%d\n", CN);   //Output: 11
```
- `enum` được dùng để đặt tên cho những con số
- Mục đích là để người đọc dễ hiểu code.
- Phần tử đầu tiên trong `enum` có giá trị là 0 (nếu không gán giá trị).
- Và các phần tử tiếp theo có giá trị tăng thêm 1 so với phần tử trước đó.
- Ta cũng có thể gán giá trị cho từng phần từ bằng toán tử `=` trong khai báo `enum`
- Lúc đó, những phần tử theo sau phần tử được gán giá trị sẽ được tăng thêm 1 so với phần tử trước nó (ví dụ ở trên).
</details>

<details>
<summary>Pointer</summary>

- Cú pháp:
```c
<kiểu dữ liệu của biến mà con trỏ trỏ tới> *<tên con trỏ>;
```
- Ví dụ:
```c
int *ptr;
```
- Sử dụng:
```c
int a = 10;
int *ptr = &a;
printf("Địa chỉ của ptr: %p\n", &ptr);
printf("Giá trị của ptr: %p\n", ptr);
printf("Giá trị mà con trỏ ptr trỏ tới: %d\n", *ptr);
printf("Địa của biến a: %p\n", &a);
printf("Giá trị của biến a: %d\n", a);
```
Output: 
```c
Địa chỉ của ptr: 0x7ffebeaeb7c0
Giá trị của ptr: 0x7ffebeaeb7bc
Giá trị mà con trỏ ptr trỏ tới: 10
Địa của biến a: 0x7ffebeaeb7bc
Giá trị của biến a: 10
```
- Con trỏ (Pointer) có 3 giá trị chính là: `&ptr`, `ptr` và `*ptr`.
- `&ptr` là địa chỉ của con trỏ.
- `ptr` là giá trị của con trỏ = địa chỉ của biến mà con trỏ trỏ tới.
- `*ptr` là giá trị của biến mà con trỏ trỏ tới.
- Lưu ý:
  - Kiểu dữ liệu trả về của con trỏ phải trùng với kiểu dữ liệu mà biến của con trỏ trỏ tới.
- Con trỏ `void`
  - Kiểu dữ liệu `void` khi được khai báo cho con trỏ, con trỏ đó có thể trỏ đến mọi kiểu dữ liệu.
  - Khi là con trỏ `void` ta vẫn có lấy địa chỉ và giá trị con trỏ được.
  - Nhưng không lấy được giá trị mà con trỏ trỏ đến.
  - Để lấy giá trị mà con trỏ `void` trỏ đến, ta phải gán kiểu dữ liệu cho con trỏ mới có thể truy xuất giá trị của biến mà con trỏ đó trỏ tới.
- Ví dụ:
```c
int a = 10;
void *ptr = &a;
printf("Địa chỉ của ptr: %p\n", &ptr);
printf("Giá trị của ptr: %p\n", ptr);
printf("Giá trị mà con trỏ ptr trỏ tới: %d\n", *ptr);
printf("Địa của biến a: %p\n", &a);
printf("Giá trị của biến a: %d\n", a);
```
Output: `error`
```c
int a = 10;
void *ptr = &a;
printf("Địa chỉ của ptr: %p\n", &ptr);
printf("Giá trị của ptr: %p\n", ptr);
printf("Giá trị mà con trỏ ptr trỏ tới: %d\n", *(int*)ptr);
printf("Địa của biến a: %p\n", &a);
printf("Giá trị của biến a: %d\n", a);
```
Output: 
```c
Địa chỉ của ptr: 0x7fffca9a82e0
Giá trị của ptr: 0x7fffca9a82dc
Giá trị mà con trỏ ptr trỏ tới: 10
Địa của biến a: 0x7fffca9a82dc
Giá trị của biến a: 10
```
</details>

<details>
<summary>Pointer NULL</summary>

- Vấn đề thực tế:
```c
#include <stdio.h>

int main()
{
    int *ptr;
    printf("%p\n",&ptr);
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    return 0;
}
```
Output: 
```c
0061FF1C
00400080
17744
```
- Khi này con trỏ mà ta khai báo trỏ đến vùng nhớ không xác định
- Không thể kiểm soát vùng nhớ, dễ gây ra hiện lấy hoặc thay đổi sai giá trị làm sai cả chương trình.
- Giải pháp:
- Ta cần khai báo con trỏ chưa dùng đến bằng `NULL` để con trỏ không trỏ vào đâu cả.
- Cú pháp:
```c
<kiểu dữ liệu của biến mà con trỏ trỏ tới> *<tên con trỏ> = NULL;
```
- Ví dụ:
```c
int *ptr = NULL;
```
- Khắc phục:
```c
#include <stdio.h>

int main()
{
    int *ptr = NULL;
    printf("%p\n",&ptr);
    printf("%p\n",ptr);
    printf("%d\n",*ptr);
    return 0;
}
```
Output:
```c
0061FF1C
00000000

```
- Nhìn vào Output của đoạn code trên, ta có thể thấy:
  - Con trỏ `NULL` vẫn có địa chỉ.
  - Nhưng con trỏ `NULL` không có giá trị cũng như giá trị của biến mà con trỏ trỏ đến.
- Lưu ý:
  - Khi khai báo con trỏ mà chưa sử dụng. Ta nên khai báo con trỏ đó bằng `NULL`.
  - Sau khi sử dụng xong con trỏ. Ta cũng nên khai báo con trỏ đó bằng `NULL`.
</details>

<details>
<summary>Function Pointer</summary>

- Cú pháp:
```c
<kiểu dữ liệu của hàm mà con trỏ trỏ tới> (*<tên con trỏ>)(<kiểu dữ liệu tham số 1>, <kiểu dữ liệu tham số 2>,...);
```
- Ví dụ:
```c
int (*phepTinh)(int, int);
```
- Sử dụng:
```c
#include <stdio.h>

int tong(int a, int b)
{
  return a+b;
}

int main()
{
    int a = 10, b = 20;
    int (*phepTinh)(int, int) = tong;
    printf("%d + %d = %d", a, b, phepTinh(a,b));
    return 0;
}
```
Output: `10 + 20 = 30`
- Con trỏ hàm dùng để thay thế cho hàm.
- Con trỏ hàm phải cùng kiểu dữ liệu trả về và tham số truyền vào giống như hàm
- Ứng dụng để tạo một hàm tổng quát, mà hàm tổng quát đó có thể gọi nhiều hàm con có cùng kiểu dữ liệu trả về và tham số giống nhau (sử dụng con trỏ hàm là input parameter).
- Ví dụ:
```c
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

void tinhToan(void (*phepTinh)(int, int), int a, int b)
{
  phepTinh(a,b);
}

int main()
{
  tinhToan(tong, 9, 3);
  tinhToan(hieu, 9, 3);
  tinhToan(tich, 9, 3);
  return 0;
}
```
- Ép kiểu con trỏ thường `void *ptr` về thành con trỏ hàm `void (*ptr)(int, int)`
```c
int *ptr = tong;
((void (*)(int, int))ptr)(9,8);
```
Output: `9 + 8 = 17`
</details>

<details>
<summary>Array of Function Pointer</summary>

- Cú pháp:
```c
<kiểu dữ liệu của hàm mà con trỏ trỏ tới> (*<tên con trỏ>[])(<kiểu dữ liệu tham số 1>, <kiểu dữ liệu tham số 2>,...) = {địa chỉ hàm 1, địa chỉ hàm 2,...};
```
- Ví dụ:
```c
int (*phepTinh[])(int, int) = {tong, hieu, tich};
```
- Sử dụng:
```c
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
  return 0;
}
```
Output: 
```c
10 + 20 = 30
10 - 20 = -10
10 * 20 = 200
```
- Mảng con trỏ hàm dùng để gọi nhiều hàm có cùng kiểu dữ liệu trả về và tham số đầu vào

</details>

<details>
<summary>Pointer to Pointer</summary>

- Cú pháp:
```c
<kiểu dữ liệu mà con trỏ cấp 1 trỏ đến> **<tên con trỏ cấp 2>;
```
- Ví dụ:
```c
int **ptrToPtr;
```
- Con trỏ cấp 2 chứa địa chỉ của con trỏ cấp 1.
- Con trỏ cấp 2 có 4 giá trị:
  - `&ptrToPtr` là địa chỉ của con trỏ cấp 2.
  - `ptrToPtr` là giá trị của con trỏ cấp 2 - địa chỉ của con trỏ cấp 1.
  - `*ptrToPtr` là giá trị của con trỏ cấp 1 - địa chỉ của biến.
  - `**ptrToPtr` là giá trị của biến.
</details>

<details>
<summary>Sizeof(Pointer)</summary>

- Kích thước của con trỏ phụ thuộc vào kiến trúc của vi xử lý
  - Kiến 64bit -> kích thước con trỏ = 8 bytes
  - Kiến 32bit -> kích thước con trỏ = 4 bytes
  - Kiến 16bit -> kích thước con trỏ = 2 bytes
</details>

<details>
<summary>Phân vùng nhớ</summary>

- Phân vùng nhớ trên bộ nhớ RAM:
<img src="https://imgur.com/a/JKkQYsL">
</details>

</details>
