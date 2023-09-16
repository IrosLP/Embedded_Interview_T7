<details>
<summary><h1>C Programming Language</h1></summary>
<!-- ----------------------------------C Bassic-------------------------------------------- -->
<details>
<summary><h2>C cơ bản</h2></summary>

<details>
<summary><h3>Kiểu dữ liệu</h3></summary>

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
<summary><h3>Typedef</h3></summary>

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
<summary><h3>Hàm</h3></summary>

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
<summary><h3>Struct</h3></summary>

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
<summary><h3>Vòng lặp</h3></summary>

<details>
<summary><h4>for()</h4></summary>

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
<summary><h4>while()</h4></summary>

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
<summary><h4>do - while()</h4></summary>

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
<summary><h4>Break</h4></summary>

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
<summary><h4>Continue</h4></summary>

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
</details>

<details>
<summary><h3>Cấu trúc rẽ nhánh</h3></summary>

<details>
<summary><h4>if() - else if() - else</h4></summary>

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
<summary><h4>switch() - case</h4></summary>

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
</details>

<details>
<summary><h3>Enum</h3></summary>

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
- `enum` được dùng để biến tên thành số.
- Mục đích là để người đọc dễ hiểu code.
- Phần tử đầu tiên trong `enum` có giá trị là 0 (nếu không gán giá trị).
- Và các phần tử tiếp theo có giá trị tăng thêm 1 so với phần tử trước đó.
- Ta cũng có thể gán giá trị cho từng phần từ bằng toán tử `=` trong khai báo `enum`
- Lúc đó, những phần tử theo sau phần tử được gán giá trị sẽ được tăng thêm 1 so với phần tử trước nó (ví dụ ở trên).
</details>
</details>
<!-- ----------------------------------Pointer-------------------------------------------- -->
<details>
<summary><h2>Con trỏ</h2></summary>

<details>
<summary><h4>Pointer</h4></summary>

- Cú pháp:
```c
<kiểu dữ liệu của biến mà con trỏ trỏ tới> *<tên con trỏ>;
```
- Ví dụ:
```c
int *ptr;
```
- Con trỏ (Pointer) có 3 giá trị chính là: `&ptr`, `ptr` và `*ptr`.
- `&ptr` là địa chỉ của con trỏ.
- `ptr` là giá trị của con trỏ = địa chỉ của biến mà con trỏ trỏ tới.
- `*ptr` là giá trị của biến mà con trỏ trỏ tới.
- Sử dụng:
```c
#include <stdio.h>

int main()
{
    int a = 10;
    int *ptr = &a;

    printf("Dia chi cua ptr _ &ptr = %p\n", &ptr);
    printf("Gia tri cua ptr _ ptr = %p\n", ptr);
    printf("Gia tri ma con tro ptr tro toi _ *ptr = %d\n", *ptr);
    printf("Dia chi cua bien a _ &a = %p\n", &a);
    printf("Gia tri cua bien a _ a = %d\n", a);

    return 0;
}
```
Output: 
```c
Dia chi cua ptr _ &ptr = 0061FF18
Gia tri cua ptr _ ptr = 0061FF1C
Gia tri ma con tro ptr tro toi _ *ptr = 10
Dia chi cua bien a _ &a = 0061FF1C
Gia tri cua bien a _ a = 10
```
- Như vậy ta thấy: `ptr = &a`, `*ptr = a`.
- Lưu ý:
  - Kiểu dữ liệu trả về của con trỏ phải trùng với kiểu dữ liệu mà biến của con trỏ trỏ tới.
- Con trỏ `void`
  - Kiểu dữ liệu `void` khi được khai báo cho con trỏ, con trỏ đó có thể trỏ đến mọi kiểu dữ liệu.
  - Khi là con trỏ `void` ta vẫn có lấy địa chỉ và giá trị con trỏ được.
  - Nhưng không lấy được giá trị mà con trỏ trỏ đến.
  - Để lấy giá trị mà con trỏ `void` trỏ đến, ta phải gán kiểu dữ liệu cho con trỏ mới có thể truy xuất giá trị của biến mà con trỏ đó trỏ tới.
- Ví dụ:
```c
#include <stdio.h>

int main()
{
    int a = 10;
    void *ptr = &a;
    
    printf("Dia chi cua ptr: %p\n", &ptr);
    printf("Gia tri cua ptr: %p\n", ptr);
    printf("Gia tri ma con tro ptr tro toi: %d\n", *ptr);
    printf("Dia chi cua bien a: %p\n", &a);
    printf("Gia tri cua bien a: %d\n", a);

    return 0;
}
```
Output: 
```c
Pointer.c: In function 'main':
Pointer.c:10:52: warning: dereferencing 'void *' pointer
     printf("Gia tri ma con tro ptr tro toi: %d\n", *ptr);
                                                    ^~~~
Pointer.c:10:5: error: invalid use of void expression
     printf("Gia tri ma con tro ptr tro toi: %d\n", *ptr);
     ^~~~~~
```
- Ép kiểu thành `int *`
```c
#include <stdio.h>

int main()
{
    int a = 10;
    void *ptr = &a;

    printf("Dia chi cua ptr: %p\n", &ptr);
    printf("Gia tri cua ptr: %p\n", ptr);
    printf("Gia tri ma con tro ptr tro toi: %d\n", *((int*)ptr));
    printf("Dia chi cua bien a: %p\n", &a);
    printf("Gia tri cua bien a: %d\n", a);

    return 0;
}
```
Output: 
```c
Dia chi cua ptr: 0061FF18
Gia tri cua ptr: 0061FF1C
Gia tri ma con tro ptr tro toi: 10
Dia chi cua bien a: 0061FF1C
Gia tri cua bien a: 10
```
</details>

<details>
<summary><h4>Pointer NULL</h4></summary>

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
<summary><h4>Function Pointer</h4></summary>

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
<summary><h4>Array of Function Pointer</h4></summary>

- Cú pháp:
```c
<kiểu dữ liệu của hàm mà con trỏ trỏ tới> (*<tên con trỏ>[])(<kiểu dữ liệu tham số 1>, <kiểu dữ liệu tham số 2>,...) = {địa chỉ hàm 1, địa chỉ hàm 2,...};
```
- Ví dụ:
```c
int (*phepTinh[])(int, int) = {tong, hieu, tich};
```
- Mục đích là gom nhóm những hàm có kiểu trả về và tham số giống nhau lại giúp dễ quản lý và sử dụng.
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
  //hoặc
  enum PhepToan{tong, hieu, tich};
  phepToan[tong](10, 20);
  phepToan[hieu](10, 20);
  phepToan[tich](10, 20);
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
<summary><h4>Pointer to Pointer</h4></summary>

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
<summary><h4>Sizeof(Pointer)</h4></summary>

- Kích thước của con trỏ phụ thuộc vào kiến trúc của vi xử lý
  - Kiến 64bit -> kích thước con trỏ = 8 bytes
  - Kiến 32bit -> kích thước con trỏ = 4 bytes
  - Kiến 16bit -> kích thước con trỏ = 2 bytes
</details>
</details>

<!-- ----------------------------------Phan Vung Nho---------------------------------------- -->
<details>
<summary><h2>Phân vùng nhớ</h2></summary>

- **Phân vùng nhớ trên bộ nhớ RAM:**
![markdown](https://i.imgur.com/EH12v2c.png)
- Khi chương trình được nạp vào vi xử lý thì sẽ được lưu vào phân vùng flash (khi tắt nguồn thì flash vẫn lưu thông tin)
- Khi chạy chương trình thì sẽ copy source code để đổ sang RAM
- Tại vì tốc độ truy xuất ở RAM sẽ nhanh hơn Flash
- Ưu điểm Flash: lưu dữ liệu được dù có tắt nguồn
- Nhược điểm Flash: tốc độ truy xuất rất chậm
- Ưu điểm RAM: tốc độ truy xuất rất chậm
- Nhược điểm RAM: dữ liệu bị xóa sau khi tắt nguồn (mất hết data)
- **Text:**
  - Khi chạy một chương trình thì sẽ copy câu lệnh từ bộ nhớ Flash sang bộ nhớ RAM và được lưu ở phân vùng Text.
  - Quyền truy cập chỉ Read và nó chưa lệnh để thực thi nên tránh sửa đổi instruction.
  - Chứa khai báo hằng số trong chương trình (.rodata)
- **Data:**
  - Quyền truy cập là read-write.
  - Chứa biến toàn cục or biến static với giá trị khởi tạo khác không.
  - Được giải phóng khi kết thúc chương trình.
- **Bss:**
  - Quyền truy cập là read-write.
  - Chứa biến toàn cục or biến static với giá trị khởi tạo bằng không or không khởi tạo.
  - Được giải phóng khi kết thúc chương trình.
- **Stack:**
  - Quyền truy cập là read-write.
  - Được sử dụng cấp phát cho biến local, input parameter của hàm,…
  - Sẽ được giải phóng khi ra khỏi block code/hàm
- **Heap:**
  - Quyền truy cập là read-write.
  - Được sử dụng để cấp phát bộ nhớ động như: Malloc, Calloc, Realloc…
  - Sẽ được giải phóng khi gọi hàm free,…

<details>
<summary><h3>Cấp phát động</h3></summary>

- Cấp phát động là cấp phát bộ nhớ trong quá trình chạy chương trình.
- Cấp phát động có cấp các địa chỉ bộ nhớ không cần liền kề nhau.
- Có 3 hàm thường dùng trong cấp phát động là: `Malloc()`, `Calloc()`, `Realloc()`.
- `Malloc()` và `Calloc()` là hai hàm dùng để cấp phát bộ nhớ động.
- `Realloc()`dùng để thay đổi kích thước của phần tử đã được cấp vùng nhớ động.
- Vùng nhớ chỉ được giải phóng khi gọi hàm `free()`.
- Cú pháp hàm `Malloc()`:
```c
void *malloc(<Kích thước bộ nhớ cần cấp (byte)>);
```
- Ví dụ cho việc sử dụng hàm `Malloc()`:
```c
int *ptr = (int *)malloc(10 * sizeof(int));
free(ptr);
```
- Trong đó:
  - `int *ptr` tạo ra con trỏ để chứa vùng nhớ sau khi cấp phát động.
  - `(int *)` ép hàm `malloc()` từ kiểu `void *` về kiểu `int *`.
  - `10` số lượng phần tử muốn cấp.
  - `sizeof(int)` kích thước (byte) của 1 biến kiểu int.
  - `(10*sizeof(int))` kích thước (byte) của 10 phần tử kiểu int.
  - `free(ptr)` giải phóng vùng nhớ sau khi cấp phát động.

- Cú pháp hàm `Calloc()`:
```c
void *calloc(<số lượng thành viên>, <Kích thước của kiểu dữ liệu thành viên>);
```
- Ví dụ cho việc sử dụng hàm `Calloc()`:
```c
int *ptr = (int *)calloc(10, sizeof(int));
free(ptr);
```
- Trong đó:
  - `int *ptr` tạo ra con trỏ để chứa vùng nhớ sau khi cấp phát động.
  - `(int *)` ép hàm `calloc()` từ kiểu `void *` về kiểu `int *`.
  - `10` số lượng phần tử muốn cấp.
  - `sizeof(int)` kích thước (byte) của 1 biến kiểu int.
  - `free(ptr)` giải phóng vùng nhớ sau khi cấp phát động.

- Cú pháp hàm `Realloc()`:
```c
void *realloc(<Con trỏ đã được cấp phát bộ nhớ động trước đó>, <Kích thước dữ liệu mới>);
```
- Ví dụ cho việc sử dụng hàm `Realloc()`:
```c
int *ptr = (int *)malloc(10*sizeof(int));
ptr = (int *)realloc(ptr, 15*sizeof(int));
free(ptr);
```
- Trong đó:
  - `ptr` con trỏ muốn thay đổi kích thước cấp phát động.
  - `(int *)` ép hàm `realloc()` từ kiểu `void *` về kiểu `int *`.
  - `15 * sizeof(int)` là kích thước dữ liệu mới.
  - `free(ptr)` giải phóng vùng nhớ sau khi cấp phát động.
</details>
</details>
<!-- -----------------------------------Bien------------------------------------------ -->
<details>
<summary><h2>Biến</h2></summary>

<details>
<summary><h3>Extern</h3></summary>

- Biến `extern` được sử dụng khi cần gọi biến hay hàm từ các file khác nhau.
- Biến `extern` bản chất là thông báo cho chương trình biết có thể sử dụng biến này từ file này sang file khác.
- Biến `extern` chỉ cần khai báo 1 lần ở 1 file duy nhất sau đó sử dụng như 1 biến global bình thường ở tất cả các file.
- ***Lưu ý:*** khi khai báo biến `extern` **không được gán giá trị** cho biến.
- Ví dụ:
```c
extern int a = 10; // lỗi

extern int b;
b = 10; //hợp lệ
```
</details>

<details>
<summary><h3>Static</h3></summary>

Biến `static` có hai loại đó là `static toàn cục` và `static cục bộ`:<br>
`Static cục bộ` 
- Biến `static `sẽ được lưu vào phân vùng nhớ data nên biến static sẽ được lưu hết vòng đời của chương trình.
- Vậy nên dù có ra khỏi code block thì biến `static cục bộ` vẫn giữ nguyên giá trị trước đó là không bị reset như những biến bình thường.
- Ví dụ:
```c
#include <stdio.h>

void testNormal()
{
    int n = 10;
    printf("Normal n = %d\n", n);
    n++;
}

void testStatic()
{
    static int s = 10;
    printf("Static s = %d\n\n", s);
    s++;
}

int main()
{
    printf("Goi lan 1\n");
    testNormal();
    testStatic();
    printf("Goi lan 2\n");
    testNormal();
    testStatic();
    printf("Goi lan 3\n");
    testNormal();
    testStatic();
    return 0;
}
```
Output:
```c
Goi lan 1
Normal n = 10
Static s = 10

Goi lan 2
Normal n = 10
Static s = 11

Goi lan 3
Normal n = 10
Static s = 12
```
`Static toàn cục` 
- Biến `Static toàn cục` sẽ chỉ được sử dụng trong file chứa nó.
- Biến `Static toàn cục` **không thể** gọi qua file khác bằng bất cứ cách nào. Dù có sử dụng từ khóa `extern` hay `#include<thư viện>` cũng không lấy được.
- Biến `Static toàn cục` được sử dụng khi hàm hay biến chỉ được phép sử dụng nội bộ trong file. Người code không muốn người khác lấy dữ liệu biến đó ra ngoài file.
</details>

<details>
<summary><h3>Volatile</h3></summary>

- Khi chạy chế độ optimize thì compiler sẽ xóa bớt những dòng lệnh giống nhau nhưng lặp lại quá nhiều lần.
- Điều này khiến chương trình dễ sai. Nhất là khi có ngắt trong hệ thống.
- Biến `volatile` được tạo ra để khắc phục vấn đề này.
- Biến `volatile` được sử dụng khi **không** muốn tối ưu biến khi chạy chế độ optimize.
- Khi đó toàn bộ chương trình sẽ được compiler optimize trừ những biến có khai báo từ khóa `static`.
- Ví dụ:
```c
volatile int a; //chương trình sẽ không tối ưu biến a
```
</details>

<details>
<summary><h3>Register</h3></summary>

- Khi chạy chương trình thì **RAM** sẽ gửi dữ liệu cho **thanh ghi** (register), sau đó **thanh ghi** mới chuyển dữ liệu đó vào **bộ xử lý trung tâm** để thực hiện việc tính toán.
- Điều này khiến cho chương trình mất rất nhiều thời gian vì phải truyền dữ liệu qua lại giữa: **RAM**, **thanh ghi (register)** và **ALU (bộ xử lý trung tâm)**.
- Vì vậy biến `register` được tạo ra với mục đích tối ưu tốc độ chương trình.
- Biến `register` được lưu trực tiếp trên thanh ghi, từ đó giảm đường truyền xuống chỉ còn truyền giữa: **thanh ghi (register)** và **ALU (bộ xử lý trung tâm)**.
- Vậy nên biến `register` có thể tối ưu tốc độ của chương trình.
- Ví dụ:
```c
register int a;
```
- Lưu ý:
  - Biến `register` không bị giới hạn khai báo số lượng biến tối đa. 
  - Nhưng thanh ghi là có hạn. Nếu khai báo quá nhiều thì biến `register` sẽ lưu tạm trên RAM. Sau đó sẽ nạp lần lượt các biến dư từ RAM vào thanh ghi từ đó làm giảm đi tốc của chương trình.
  - Biến `register` không có địa chỉ vì biến `register` không nằm trên RAM.
</details>

</details>
<!-- ----------------------------------Struct-------------------------------------------- -->
<details>
<summary><h2>Struct</h2></summary>

- Cú pháp:
```c
struct <tên struct>{
  //kiểu dữ liệu1    tên biến1
  //kiểu dữ liệu2    tên biến2...
};
```
- Struct là một kiểu dữ liệu do người dùng tự định nghĩa.
- Struct bao gồm nhiều biến có nhiều kiểu dữ liệu khác nhau.
- Kích thước của struct bằng bội số của kiểu dữ liệu lớn nhất.
- Một lần quét dữ liệu sẽ do kiến trúc của vi xử lý quyết định.
- Ví dụ:
  - Kiến trúc 32bit -> quét một lần 4byte
  - Kiến trúc 64bit -> quét một lần 8byte
- Chính vì cách quét dữ liệu như vậy nên sẽ có hiện tượng padding (ô nhớ trống).
- Để khắc phục hiện tượng này thì ta nên sắp xếp thứ tự các kiểu dữ liệu một cách hợp lý.
- Ví dụ:
```c
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
```
Output:
```c
Size sinhVien1: 32
Size sinhVien2: 24
```
</details>
<!-- ----------------------------------Union-------------------------------------------- -->
<details>
<summary><h2>Union</h2></summary>

- Cú pháp:
```c
union <tên union>{
  //kiểu dữ liệu1    tên biến1
  //kiểu dữ liệu2    tên biến2...
};
```
- Union cũng tương tự như Struct là kiểu dữ liệu do người dùng tự định danh.
- Union cũng bao gồm nhiều biến có nhiều kiểu dữ liệu khác nhau như Struct.
- Tuy nhiên Union khác Struct ở một điểm đó là tất cả các biến của Union đều có chung một địa chỉ.
- Kích thước của Union bằng bội số của biến thành viên có kích thước lớn nhất.
- Một lần quét dữ liệu của Union cũng sẽ do kiến trúc của vi xử lý quyết định.
- Ví dụ:
```c
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
```
Output:
`Size sinhVien: 8`
- Vì union sử dụng chung 1 địa chỉ và 1 vùng nhớ duy nhất cho tất cả các biến nên union chỉ được sử dụng khi những biến thành viên không đồng thời cùng tồn tại hoặc muốn ghi và kiểm soát từng giá trị khi truyền vào một vùng nhớ nào đó.
- Ví dụ:
```c
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
```
Output: `1 0 1 2 3 8`
- Chương trình trên để nhập dữ liệu vào frame dữ liệu để có thể truyền đi một cách dễ dàng.
- Những thành phần trong Struct của đoạn chương trình ở phía trên đó là những thành phần của data frame.
- Array chính là data frame đã được liên kết hoàn chỉnh.
</details>
<!-- ----------------------------------Compiler-------------------------------------------- -->
<details>
<summary><h2>Compiler</h2></summary>

- Compiler là quá trình biên dịch từ ngôn ngữ bậc cao sang mã máy.
- Compiler có 4 quá trình chính:
  - Tiền xử lý (Pre-processor)
  - Compiler.
  - Assembler.
  - Linker.
![Compiler](https://i0.wp.com/tapit.vn/wp-content/uploads/2017/07/GCC_CompilationProcess.png?zoom=2)

1. Giai đoạn tiền xử lý – Preprocessor
- Cú pháp để khởi chạy tiền xử lý là: `gcc -E main.c -o main.i`
- Nhận mã nguồn
- Xóa bỏ tất cả chú thích, comments của chương trình
- Chỉ thị tiền xử lý (bắt đầu bằng #) cũng được xử lý
- Ví dụ: chỉ thị #include cho phép ghép thêm mã chương trình của một tệp tiêu để vào mã nguồn cần dịch. Các hằng số được định nghĩa bằng #define sẽ được thay thế bằng giá trị cụ thể tại mỗi nơi sử dụng trong chương trình.
2. Cộng đoạn dịch Ngôn Ngữ Bậc Cao sang Assembly (Compiler)
- Cú pháp để khởi chạy Compiler là: `gcc main.i -S -o main.s`
- Phân tích cú pháp (syntax) của mã nguồn NNBC
-	Chuyển chúng sang dạng mã Assembly là một ngôn ngữ bậc thấp (hợp ngữ) gần với tập lệnh của bộ vi xử lý.
3. Công đoạn dịch Assembly
- Cú pháp để khởi chạy Assembler là: `gcc -c main.s -o main.o`
-	Dich chương trình => Sang mã máy 0 và 1
-	Một tệp mã máy (.obj) sinh ra trong hệ thống sau đó.
4. Giai đoạn Linker
-	Trong giai đoạn này mã máy của một chương trình dịch từ nhiều nguồn (file .c hoặc file thư viện .lib) được liên kết lại với nhau để tạo thành chương trình đích duy nhất
-	Mã máy của các hàm thư viện gọi trong chương trình cũng được đưa vào chương trình cuối trong giai đoạn này.
-	Chính vì vậy mà các lỗi liên quan đến việc gọi hàm hay sử dụng biến tổng thể mà không tồn tại sẽ bị phát hiện. Kể cả lỗi viết chương trình chính không có hàm main() cũng được phát hiện trong liên kết.
- Kết thúc quá trình tất cả các đối tượng được liên kết lại với nhau thành một chương trình có thể thực thi được (executable hay .exe) thống nhất.


</details>
<!-- ----------------------------------Macro-------------------------------------------- -->
<details>
<summary><h2>Marcro</h2></summary>

- Macro đơn giản là thay thế một tên nào đó thành một đoạn chương trình.
- Macro thường dùng để gán giá trị cho biến, macro if-else, macro hàm, định nghĩa cho thư viện.
- Macro được dùng để viết thư viện cho các dòng vi điều khiển để có thể chỉ sử dụng 1 chương trình mà vẫn có thể nạp cho nhiều dòng vi điều khiển khác nhau.
- Ví dụ sử dụng để định nghĩa cho biến:
```c
#include <stdio.h>

#define PI 3.14

int main()
{
    printf("So pi = %f", PI);
    return 0;
}
```
- Ví dụ sử dụng để định nghĩa cho if-else:
```c
#include <stdio.h>

#define SIZE 20

int main()
{
    #if SIZE > 20
    printf("size lon hon 20");

    #elif SIZE == 20
    printf("size bang 20");

    #else
    printf("size nho hon 20");
    #endif
    return 0;
}
```
- Ví dụ sử dụng để định nghĩa cho hàm:
```c
#include <stdio.h>
#include <stdint.h>

#define CREATE_FUNC(func_name, cmd) \
void func_name()                    \
{                                   \
    printf(cmd);                    \
}
//hoặc nếu muốn cho macro tự hiểu cmd là chuỗi thì ta dùng dấu '#'
//printf(#cmd);
CREATE_FUNC(Func1, "Func1: abc\n");
CREATE_FUNC(Func2, "Func2: xyz\n");

int main()
{
    Func1();
    Func2();
    return 0;
}
```
- Ví dụ sử dụng để định nghĩa cho thư viện:
```c
#include <stdio.h>

#ifndef STM32 //Kiểm tra xem đã có định nghĩa STM32 này chưa. nếu chưa định nghĩa STM32. nếu rồi thì sẽ bỏ qua.
#define STM32 //thì định nghĩa STM32

int a = 10;   //trong định nghĩa STM32 thì có biến int a = 10;

#endif        //kết thúc #ifndef
```
- Ví dụ sử dụng để định nghĩa cho nhiều vi điều khiển:
```c
#define MCU STM32

#if MCU == STM32
//Câu lệnh cho dòng STM32
#elif MCU == PIC
//Câu lệnh cho dòng PIC
#elif MCU == ESP32
//Câu lệnh cho dòng ESP32
#else
printf("không có dòng vi điều khiển phù hợp");
#endif
```
</details>

<!-- ----------------------------------Function------------------------------------------ -->
<details>
<summary><h2>Function</h2></summary>

- Khi mở nguồn sẽ vào địa chỉ 0x00 khởi tạo program counter -> stack pointer
- Program counter: bộ đếm (chỉ đếm và đọc giá trị) lấy giá trị hiện tại tăng 4 ô nhớ và đọc giá trị
- Stack pointer: bộ nhớ để lưu địa chỉ.
- Cách hoạt động:
  - Đầu tiên chương trình sẽ chạy các lệnh một cách tuần tự từ địa chỉ thấp đến địa chỉ cao.
  - Khi gặp phải hàm thì `Stack Pointer` sẽ lưu địa chỉ tiếp theo của dòng lệnh trước khi vào hàm.
  - Sau đó `Program Counter` sẽ chạy từ địa chỉ đầu tiên đến địa chỉ kết thúc của hàm.
  - Sau đó `Program Pointer` sẽ lấy địa chỉ đã lưu của `Stack Pointer` (địa chỉ tiếp theo của dòng lệnh trước khi chạy vào hàm) từ đó chạy tiếp chương trình.
  - Thực hiện lặp lại như vậy cho đến khi kết thúc chương trình.
</details>
</details>

<details>
<summary><h1>C++ Programming Language</h1></summary>

<details>
<summary><h2>Class</h2></summary>

Class bao gồm 2 thành phần là:
- Thuộc tính (Properties)
- Phương thức (Method)
Ví dụ:
```c++
#include <iostream>
#include <string>

using namespace std;

class SinhVien{
		private: 
				int MSSV; //properties
				string TEN;
				string LOP;
				int NAM_SINH;
		public:
				int tuoi(); //method
};

int SinhVien::tuoi(){
		return 2023-NAM_SINH;
}
```
- Hàm tạo (Constructor): Là hàm có tên trùng với tên Class và được gọi mỗi khi tạo Object bằng Class đó.
- Hàm hủy (Destructor): Là hàm có tên trùng với tên Class nhưng có dấu ‘~’ phía trước và được gọi mỗi khi thu hồi vùng nhớ Object của một Class.
```c++
#include <iostream>
#include <string>

using namespace std;

class SinhVien{
		private: 
				int MSSV;
				string TEN;
				string LOP;
				int NAM_SINH;
				int TUOI;
		public:
				SinhVien();
				~SinhVien();
};

SinhVien::SinhVien(){
		cout << "Ham tao duoc goi" << endl;
}

SinhVien::~SinhVien(){
		cout << "Ham huy duoc goi" << endl;
}

int main()
{
		cout << "Bat dau" << endl;
		if(1){
				SinhVien x;
		}
		cout << "ket thuc" << endl;
		return 0;
}
```
- Output:
```c++
Bat dau
Ham tao duoc goi
Ham huy duoc goi
ket thuc
```

<summary><h3>Static</h3></summary>

- Khi sử dụng Static trong Class thì tất cả Object trong Class đều sử dụng chung  một địa chỉ  Static Property đó.
- Ví dụ:
```c++
#include <iostream>
#include <string>

using namespace std;

class SinhVien{
	private: 
		static int MSSV;
		string TEN;
		string LOP;
	public:
		SinhVien(string, string);
		void display();
};

int SinhVien::MSSV = 0;

SinhVien::SinhVien(string TEN, string LOP){
	this->TEN = TEN;
	this->LOP = LOP;
}

void SinhVien::display(){
	this->MSSV++;
	cout << "MSSV: " << MSSV << endl;
	cout << "TEN: " << TEN << endl;
	cout << "LOP: " << LOP << endl;
}

int main()
{
	SinhVien a("Loc", "9A3");
	SinhVien b("Dat", "9A5");
	a.display();
	cout << "-----------" << endl;
	b.display();
	return 0;
}
```
- Output:
```c++
MSSV: 1
TEN: Loc
LOP: 9A3
-----------
MSSV: 2
TEN: Dat
LOP: 9A5
```
- Vì MSSV của 2 Object có chung địa chỉ nên khi gặp lệnh “this->MSSV++;” trong method “display()” thì giá trị của MSSV tăng lên dù 2 Object có khác nhau.

<summary><h3>Access Modifier: (Phạm vi truy cập)</h3></summary>

- **Public:** Cho phép Object truy cập bên ngoài và bên trong Class.
- **Private:** Không phép Object truy cập bên ngoài Class, chỉ có thể sử dụng bên trong Class. **Lưu ý:** Những Properties nằm trong private của Base Class (Class cha) sau khi được kế thừa thì không thể truy cập được ở Derived Class (Class con).
- **Protected:** Không cho phép truy cập bên ngoài Class như Private, nhưng cho phép truy cập ở Derived Class (Class con) sau khi kế thừa.

</details>

<details>
<summary><h2>Tính chất của hướng đối tượng</h2></summary>

<details>
<summary><h3>Tính đóng gói (Encapsulation)</h3></summary>

- Toàn bộ Properties của một Class phải ở chế độ Private.
- Không cho phép Object truy cập trực tiếp vào Properties.

</details>

<details>
<summary><h3>Tính trừu tượng (Abstraction)</h3></summary>

- Vì không được truy cập hoặc thay đổi giá trị trực tiếp của Properties (thuộc tính) trong Class vì vi phạm Tính đóng gói.
- Nên phải sử dụng các Method (phương thức) để truy cập hoặc thay đổi giá trị của Properties (thuộc tính) trong Class.
- Tính trừu tượng được sử dụng để hạn chế quyền của người sử dụng. Chỉ cho phép người sử dụng truy cập đến Properties thông qua một số Method mà người viết chương trình mong muốn.

</details>

<details>
<summary><h3>Tính kế thừa (inheritance)</h3></summary>

- Là tạo ra 1 Derived Class (Class con) có toàn bộ những đặc tính và phương thức của Base Class (Class cha).
- Kế thừa có 3 phương thức: **public**, **private**, **protected**.
    - **Public**:
        
        
        | Access Modifier
        Base Class | Access Modifier
        Derived Class |
        | --- | --- |
        | Public | Public |
        | Protected | Protected |
        | Private | Private |
    - **Protected:**
        
        
        | Access Modifier
        Base Class | Access Modifier
        Derived Class |
        | --- | --- |
        | Public | Protected |
        | Protected | Protected |
        | Private | Private |
    - **Private:**
        
        
        | Access Modifier
        Base Class | Access Modifier
        Derived Class |
        | --- | --- |
        | Public | Private |
        | Protected | Private |
        | Private | Private |
- Ghi đè Method (phương thức): có một Method cùng tên mà Base Class và Derived Class lại có tham số và lệnh trong Method đó là khác nhau → Ta cần ghi đè Method đó cho phù hợp với từng Derived Class (Lớp con).


</details>

<details>
<summary><h3>Tính đa hình (polymorphism)</h3></summary>

- Là một **Method** (phương thức) có thể có một tên nhưng định nghĩa nhiều lần với nhiều **Input Parameter** khác nhau.
- Lúc này chương trình sẽ tìm đến **Method** có **Input Parameter** phù hợp nhất để chạy chương trình.

</details>

</details>

</details>

<!-- ----------------------------------EMBEDDED------------------------------------------ -->
<details>
<summary><h1>Embedded</h1></summary>

<details>
<summary><h2>SPI</h2></summary>


</details>

</details>
