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

**Cách hoạt động của Function:**
- Giả sử MCU có kiến trúc 32 bit
- Bước 1: Chạy từ địa chỉ 0x00 (Top of Stack) đến 0x04 (Reset Handler) Reset Handler sẽ khởi tạo:
  - Program Counter: Bộ đếm + đọc giá trị.
  - Stack Pointer: Bộ nhớ (lưu địa chỉ tiếp theo của Program Counter)
- Bước 2: Chương trình cứ tiếp tục thực thi các câu lệnh từ địa chỉ thấp đến địa chỉ cao. Đến khi gặp hàm.
- Bước 3: Khi gặp hàm, Program Counter sẽ lưu địa chỉ hàm và nhảy đến địa chỉ đó để thực hiện lệnh. Lúc đó Stack Pointer sẽ lưu địa chỉ tiếp theo của Program Counter trước khi Program Counter nhảy đến hàm.
- Bước 4: Sau khi thực hiện xong tất cả các lệnh trong hàm. Program Counter sẽ lấy địa chỉ mà Stack Pointer đang giữ và cho vào chương trình. Chương trình sẽ chạy tiếp các lệnh tiếp theo, lệnh trước khi Program Counter nhảy đến hàm.

**So sánh Function và Marco Function:**
|             | Function      | Macro Function   |
|---|---|---|
| Ưu điểm     | Ít tốn bộ nhớ | Tốc độ nhanh     |
| Khuyết điểm | Tốc độ chậm   | Tốn nhiều bộ nhớ |

**Inline Function**
- Chương trình sẽ build Inline Function ra thành mã Assembly. Sau đó dán mã Assembly đó vào đoạn chương trình.
- Vậy nên kích thước chương trình sẽ lớn nhưng tốc độ nhanh hơn.

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
    ```cpp
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
    ```cpp
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
    ```cpp
    Bat dau
    Ham tao duoc goi
    Ham huy duoc goi
    ket thuc
    ```

  <summary><h3>Static</h3></summary>

  - Khi sử dụng Static trong Class thì tất cả Object trong Class đều sử dụng chung  một địa chỉ  Static Property đó.
  - Ví dụ:
    ```cpp
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
    ```cpp
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
          
          
          | Access Modifier Base Class | Access Modifier Derived Class |
          | --- | --- |
          | Public | Public |
          | Protected | Protected |
          | Private | Private |
      - **Protected:**
          
          
          | Access Modifier Base Class | Access Modifier Derived Class |
          | --- | --- |
          | Public | Protected |
          | Protected | Protected |
          | Private | Private |
      - **Private:**
          
          
          | Access Modifier Base Class | Access Modifier Derived Class |
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

  <details>
  <summary><h2>Vector</h2></summary>

  - Là một mảng chứa những phần tử có cùng một kiểu dữ liệu.
  - Thư viện: #include <vector>
  - Cú pháp: vector <Kiểu dữ liệu> Tên vector;
  - Ví dụ:
  ```c++
  #include <iostream>
  #include <string>
  #include <vector>

  using namespace std;

  int main(){
    vector <int> mangSoThuc;
    vector <char> mangKyTu;
    vector <string> mangChuoi;

    vector <vector <int>> mangHaiChieuSoThuc;
  }
  ```

  </details>

  <details>
  <summary><h2>For Each</h2></summary>

  - Là một vòng for được thu gọn
  - Cú pháp:
    ```cpp
    for (data_type  variable_name : container_name) {
        operations using variable_name
    }
    ```
  - Sử dụng:
    ```cpp
    #include <iostream>
    using namespace std;
    int main()
    {
      int arr[] = { 10, 20, 30, 40 };
      for (int x : arr)
          cout << x << " ";
    } 
    ```
  - Output:
      ```cpp
      10 20 30 40
      ```
  </details>

  <details>
  <summary><h2>Template</h2></summary>

  - Là 1 tính chất của tính đa hình. Template được sử dụng để hạn chế viết lại cùng 1 method cho những trường hợp khác KDL.
  - Cú pháp: 
    ```cpp
    template <typename <Tên KDL>>
    ```
  - Ví dụ 1:
    ```cpp
      #include <iostream>

    template <typename var1, typename var2>

    var1 tong(var1 a, var2 b){
      return var1(a+b);
    }

    int main(){
      std::cout << "Tong a va b: " << tong(4.3,5) << std::endl;
      return 0;
    }
    ```
  - Output:
    ```cpp
    Tong a va b: 9.3
    ```
  </details>

  <details>
  <summary><h2>Namespace</h2></summary>

  - Là 1 vùng nhớ chứa nhiều member. Member có thể là biến, class, function,… 
  - Ví dụ:
    ```cpp
    #include <iostream>

    using namespace std;

    namespace ConOngA{
      int Teo = 10;
    }
    namespace ConOngB{
      int Teo = 20;
    }
    int main(){
      cout << ConOngA::Teo << endl;
      cout << ConOngB::Teo << endl;
      return 0;
    }
    ```
  - Output:
    ```cpp
    10
    20
    ```
  - **Lưu ý:** Nếu thư viện tự tạo có namespace trùng tên với namespace trong file main thì 2 namespace này là một.
  - **Using namespace:**
    - là sử dụng namespace mà không cần khai báo toán tử phạm vi (”: :”) cho biến nằm trong namespace đó.
    - Ví dụ:
      ```cpp
      #include <iostream>

      using namespace std;

      namespace ConOngA{
        int Teo = 10;
      }
      namespace ConOngB{
        int Teo = 20;
      }

      using namespace ConOngA;

      int main(){
        cout << Teo << endl;
        cout << ConOngB::Teo << endl;
        return 0;
      }
      ```
    - Output:
      ```cpp
      10
      20
      ```
    - **Lưu ý:**  Không thể sử dụng **using namespace** cho 2 namespace trở lên có biến thành viên cùng tên với nhau (ví dụ: 2 namespace đề có tên biến: int Teo).
  </details>

<details>
  <summary><h2>Virtual Function</h2></summary>

  - Được sử dụng khi có class con kế thừa method của class cha. Nhưng method của class con cần được load lại (overload) method được ghi đè (override) mới nhất cho phù hợp với những tính chất của class con.
  - Ví dụ:
    ```cpp
    #include <iostream>

    using namespace std;

    class DoiTuong{
        public:
            virtual char* cmd(){
                return (char*)"Doi tuong";
            }
            void display(){
                cout << cmd() << endl;
            }
    };

    class SinhVien : public DoiTuong{
        char *cmd(){
            return (char*)"Sinh Vien";
        }
    };

    int main(){
        DoiTuong dt;
        dt.display();
        
        SinhVien sv;
        sv.display();
        
      return 0;
    }
    ```
  - Output:
    ```cpp
    Doi tuong
    Sinh Vien
    ```
  ⇒ Nếu không có từ khóa “virtual” phía trước method cmd() của class DoiTuong thì kết quá sẽ là:
    ```cpp
    Doi tuong
    Doi tuong
    ```
  - Khi gọi đến virtual function, chương trình sẽ kiểm tra virtual function này có được ghi đè (override) ở đâu không.
  - Nếu có thì chương trình sẽ load lại (overload) virtual function được *định nghĩa mới nhất*.
  
  </details>

  <details>
  <summary><h2>List</h2></summary>

  - Thư viện : `#include <list>`
  - Linked list lưu dữ liệu theo từng node.
  - Mỗi Node bao gồm 2 giá trị:
    - Dữ liệu (data)
    - Con trỏ trỏ sang node kế tiếp.
  - Ví dụ 2 cách in list:
    ```cpp
    #include <iostream>
    #include <list>
    using namespace std;

    int main(){
        list <int> arr = {1, 4, 6, 3, 9};
        
        for(int i : arr)
            cout << i << endl;
        
      return 0;
    }
    ```
    ```cpp
    #include <iostream>
    #include <list>
    using namespace std;

    int main(){
        list <int> arr = {1, 4, 6, 3, 9};
        
        for(list<int>::iterator it = arr.begin(); it != arr.end(); it++)
            cout << *it << endl;
        
      return 0;
    }
    ```
  </details>

  <details>
  <summary><h2>Map</h2></summary>

  - Thư viện: `#include <map>`
  - Map sẽ đi theo 1 cặp: key & value
  - Cú pháp: map <<key>, <value>> <tên biến>
  - Ví dụ:
    ```cpp
    #include <iostream>
    #include <map>
    #include <string>

    using namespace std;

    typedef struct{
        string ten;
        int tuoi;
    }ThongTin;

    int main()
    {
        map<int, ThongTin> SinhVien;
        
        SinhVien[101] = {"Hoang", 20};
        SinhVien[102] = {"Tuan", 18};
        SinhVien[103] = {"Quan", 21};

        for(auto item : SinhVien){
            cout << "ID = " << item.first << ", Ten: " << item.second.ten << ", Tuoi: " << item.second.tuoi << endl;
        }

        return 0;
    }
    ```
  </details>

  <details>
  <summary><h2>Lamda</h2></summary>

  - Là 1 function cục bộ
  - Cú pháp: `[<tham số biến cục bộ>](<biến tham số>)→<KDL trả về> {//code}`
  - Ví dụ:
    ```cpp
    #include <iostream>

    using namespace std;

    int main()
    {
        int x = 20;
        float y = 2.6;
        
        auto tong = [=](int a, int b)->void{
            cout << "x = " << x << endl;
            cout << "y = " << y << endl;
            cout << "Tong " << a << " va " << b << ": " << a+b << endl;
        };
        tong(7, 9);

        return 0;
    }
    ```
  </details>

</details>

<!-- ----------------------------------EMBEDDED------------------------------------------ -->
<details>
<summary><h1>Embedded</h1></summary>

  <details>
  <summary><h2>SPI</h2></summary>

  - ***Khái niệm:***
    
    SPI (Serial Peripheral Interface) là một chuẩn truyền thông nối tiếp tốc độ cao do Motorola đề xuất.
    
    - Các bit dữ liệu được truyền nối tiếp nhau và có xung clock đồng bộ.
    - Giao tiếp song công, có thể truyền và nhận cùng một thời điểm.
    - Khoảng cách truyền ngắn, được sử dụng để trao đổi dữ liệu với nhau giữa các chip trên cùng một bo mạch.
    - Tốc độ truyền khoảng vài Mb/s.
    - Các dòng vi điều khiển thường được tích hợp module giao tiếp SPI dùng để giao tiếp truyền dữ liệu với các vi điều khiển khác, hoặc giao tiếp với các ngoại vi bên ngoài như cảm biến, EEPROM, ADC, LCD, SD Card,…
        
- ***Cấu tạo:***
    
    Bus SPI gồm có 4 đường tín hiệu:
    
    - **SCK**: Serial Clock
    - **MOSI**: Master Out, Slave In
    - **MISO**: Master In, Slave Out
    - **SS**: Slave Select
- ***Cách truyền và nhận dữ liệu:***
    - Mỗi chip Master hay Slave sẽ có một thanh ghi dữ liệu 8 bit chứa dữ liệu cần gửi đi hoặc dữ liệu nhận về.
    - Cứ mỗi xung nhịp do Master tạo ra trên chân SCK, một bit trong thanh ghi dữ liệu của Master được truyền qua Slave trên đường MOSI, đồng thời một bit trong thanh ghi dữ liệu của Slave cũng được truyền qua cho Master trên đường MISO.
    
- ***Chế độ truyền:***
    - SPI có 4 chế độ hoạt động phụ thuộc vào cực của xung giữ (Clock Polarity – CPOL) và pha (Phase - CPHA).
    - CPOL dùng để chỉ trạng thái của chân SCK ở trạng thái nghỉ. Chân SCK giữ ở mức cao khi CPOL=1 hoặc mức thấp khi CPOL=0.
    - CPHA dùng để chỉ cách mà dữ liệu được lấy mẫu theo xung. Dữ liệu sẽ được lấy ở cạnh lên của SCK khi CPHA=0 hoặc cạnh xuống khi CPHA=1.
    
    | Mode | CPOL | CPHA |
    | --- | --- | --- |
    | 1 | 0 | 0 |
    | 2 | 0 | 1 |
    | 3 | 1 | 0 |
    | 4 | 1 | 1 |
    
    
    - Mode 0 (mặc định) – xung nhịp của đồng hồ ở mức thấp (CPOL = 0) và dữ liệu được lấy mẫu khi chuyển từ thấp sang cao (cạnh lên) (CPHA = 0).
    - Mode 1 - xung nhịp của đồng hồ ở mức thấp (CPOL = 0) và dữ liệu được lấy mẫu khi chuyển từ cao sang thấp (cạnh xuống) (CPHA = 1).
    - Mode 2 - xung nhịp của đồng hồ ở mức cao (CPOL = 1) và dữ liệu được lấy mẫu khi chuyển từ cao sang thấp (cạnh lên) (CPHA = 0).
    - Mode 3 - xung nhịp của đồng hồ ở mức cao (CPOL = 1) và dữ liệu được lấy mẫu khi chuyển từ thấp sang cao (cạnh xuông) (CPHA = 1).
    
    **Lưu ý:** Khi giao tiếp SPI giữa vi điều khiển và các thiết bị ngoại vi khác như IC, cảm biến thì 2 bên bắt buộc hoạt động cùng Mode, nếu không dữ liệu truyền nhận có thể bị đọc sai.
    
- ***Các sơ đồ kết nối giao tiếp SPI:***
    - 1 thiết bị Master và 1 thiết bị Slave
        
    - 1 thiết bị Master và nhiều thiết bị Slave ( chế độ độc lập - Independent):
    
    Ở chế độ này, mỗi thiết bị Slave kết nối với Master được quy định riêng bởi những chân SS khác nhau. Khi thiết bị Master muốn giao tiếp với Slave nào thì kéo chân SS tương ứng xuống mức 0, những chân SS còn lại giữ ở mức 1.
    
    
    - 1 thiết bị Master và nhiều thiết bị Slave ( chế độ dây chuyền - Daisy):
    
    Thử tưởng tượng có bạn cần kết nối SPI với nhiều thiết bị, nếu dùng cách trên thì sẽ tốn nhiều chân SS của vi điều khiển. Thay vào đó chúng ta có thể kết nối các thiết bị Slave theo kiểu dây chuyển như bên dưới mà chỉ cần 1 chân SS từ vi điều khiển. Chân MOSI của Slave này sẽ nối với MISO của Slave tiếp theo.
    
    Dữ liệu gửi từ vi điều khiển ( hay thiết bị Master), đi vào Slave 1 bằng đường MOSI. Sau đó lại đi ra từ chân MISO của Slave 1, gửi tới chân MOSI của Slave 2, và cứ tiếp tục như vậy,.... Các bạn có thể thấy cách hoạt động này khác giống với các IC dịch.
    
  </details>

  <details>
  <summary><h2>I2C</h2></summary>

  - ***Khái niệm:***
    - I2C ( Inter – Integrated Circuit) là 1 giao thức giao tiếp nối tiếp đồng bộ được phát triển bởi Philips Semiconductors.
    - I2C chỉ sử dụng hai dây để truyền dữ liệu giữa các thiết bị:
        - SDA (Serial Data) - đường truyền cho master và slave để gửi và nhận dữ liệu.
        - SCL (Serial Clock) - đường mang tín hiệu xung nhịp.
    - I2C là một giao thức truyền thông nối tiếp, vì vậy dữ liệu được truyền từng bit dọc theo một đường duy nhất (đường SDA).
    - I2C là đồng bộ, do đó đầu ra của các bit được đồng bộ hóa với việc lấy mẫu các bit bởi một tín hiệu xung nhịp được chia sẻ giữa master và slave. Tín hiệu xung nhịp luôn được điều khiển bởi master.
- ***Cấu tạo:***
    
    I2C sử dụng 2 đường truyền tín hiệu:
    
    - **SCL** -  Serial Clock Line : Tạo xung nhịp đồng hồ do Master phát đi
    - **SDA** - Serial Data Line : Đường truyền nhận dữ liệu.
    - Và 2 điện trờ ( từ 1 – 4,7 kΩ) để nối lên nguồn để giữ 2 dây ở mức cao
    
    
- ***Khung truyền I2C:***
    
    Với I2C, dữ liệu được truyền trong các tin nhắn. Tin nhắn được chia thành các khung dữ liệu. Mỗi tin nhắn có một khung địa chỉ chứa địa chỉ nhị phân của địa chỉ slave và một hoặc nhiều khung dữ liệu chứa dữ liệu đang được truyền. Thông điệp cũng bao gồm điều kiện khởi động và điều kiện dừng, các bit đọc / ghi và các bit ACK / NACK giữa mỗi khung dữ liệu:
    
    
    **Start Condition:** Đường SDA chuyển từ mức điện áp cao xuống mức điện áp thấp trước khi đường SCL chuyển từ mức cao xuống mức thấp.
    
    **Stop Condition:** Đường SDA chuyển từ mức điện áp thấp sang mức điện áp cao sau khi đường SCL chuyển từ mức thấp lên mức cao.
    
    **Address Frame:** Một chuỗi 7 hoặc 10 bit duy nhất cho mỗi slave để xác định slave khi master muốn giao tiếp với nó. 
    
    - Nếu địa chỉ phù hợp, Slave sẽ gửi lại một bit ACK điện áp thấp cho master.
    - Nếu địa chỉ không khớp, slave không làm gì cả và đường SDA vẫn ở mức cao.
    
    **Read/Write bit:** Một bit duy nhất ở cuối tin nhắn cho slave biết master đang 
    
    **gửi** dữ liệu đến slave (mức điện áp **thấp**)
    
    **yêu cầu** dữ liệu từ nó (mức điện áp **cao**).
    
    **Bit ACK / NACK:** Mỗi khung trong một tin nhắn được theo sau bởi một bit xác nhận / không xác nhận. Nếu một khung địa chỉ hoặc khung dữ liệu được nhận thành công, một bit ACK sẽ được trả lại cho thiết bị gửi từ thiết bị nhận.
    
    **Data:**
    
    Sau khi master phát hiện bit ACK từ slave, data đã sẵn sàng được gửi.
    
    Khung dữ liệu luôn có độ dài 8 bit và được gửi với bit quan trọng nhất trước. Mỗi khung dữ liệu ngay sau đó là một bit ACK / NACK để xác minh rằng khung đã được nhận thành công. Bit ACK phải được nhận bởi master hoặc slave (tùy thuộc vào cái nào đang gửi dữ liệu) trước khi khung dữ liệu tiếp theo có thể được gửi.
    
    Sau khi tất cả các khung dữ liệu đã được gửi, master có thể gửi một điều kiện dừng cho slave để tạm dừng quá trình truyền. Điều kiện dừng là sự chuyển đổi điện áp từ thấp lên cao trên đường SDA sau khi chuyển tiếp từ thấp lên cao trên đường SCL , với đường SCL vẫn ở mức cao.
    
- ***Quá trình truyền nhận dữ liệu:***
    1. Master gửi điều kiện khởi động đến mọi slave được kết nối bằng cách chuyển đường SDA từ mức điện áp cao sang mức điện áp thấp trước khi chuyển đường SCL từ mức cao xuống mức thấp.
    2. Master gửi cho mỗi slave địa chỉ 7 hoặc 10 bit của slave mà nó muốn giao tiếp, cùng với bit đọc / ghi.
    3. Mỗi slave sẽ so sánh địa chỉ được gửi từ master với địa chỉ của chính nó. Nếu địa chỉ trùng khớp, slave sẽ trả về một bit ACK bằng cách kéo dòng SDA xuống thấp cho một bit. Nếu địa chỉ từ master không khớp với địa chỉ của slave, slave rời khỏi đường SDA cao.
    4. Master gửi hoặc nhận khung dữ liệu.
    5. Sau khi mỗi khung dữ liệu được chuyển, thiết bị nhận trả về một bit ACK khác cho thiết bị gửi để xác nhận đã nhận thành công khung.
    6. Để dừng truyền dữ liệu, master gửi điều kiện dừng đến slave bằng cách chuyển đổi mức cao SCL trước khi chuyển mức cao SDA.
- ***Các chế độ hoạt động của I2C:***
    - Chế độ chuẩn (standard mode) với tốc độ 100 kBit/s.
    - Chế độ tốc độ thấp (low speed mode) với tốc độ 10 kBit/s.
    
    Ngoài ra, khác với giao tiếp SPI chỉ có thể có 1 Master, giao tiếp I2C cho phép chế độ truyền nhận dữ liệu giữa nhiều thiết bị Master khác nhau với thiết bị Slave. Tuy nhiên quá trình này có hơi phức tạp vì thiết bị Slave có thể nhận 1 lúc nhiều khung dữ liệu từ các thiết bị Master khác nhau, điều đó đôi khi dẫn đến xung đột hoặc sai sót dữ liệu nhận được.
    
    Để tránh điều đó, khi làm việc ở chế độ này, mỗi thiết bị Master cần phát hiện xem đường SDA đang ở trạng thái nào.
    
    Nếu SDA ở mức 0, nghĩa là đang có 1 thiết bị Master khác đang có quyền điều khiển và phải chờ đến khi truyền xong.
    
    Ngược lại nếu SDA ở mức 1, nghĩa là đường truyền SDA đã an toàn và có sử dụng .
  </details>

  <details>
  <summary><h2>UART</h2></summary>

  - ***Khái niệm:***
    
    UART hay bộ thu-phát không đồng bộ đa năng là một trong những hình thức giao tiếp kỹ thuật số giữa thiết bị với thiết bị đơn giản và lâu đời nhất. Bạn có thể tìm thấy các thiết bị UART trong một phần của mạch tích hợp (IC) hoặc dưới dạng các thành phần riêng lẻ. Các UART giao tiếp giữa hai nút riêng biệt bằng cách sử dụng một cặp dẫn và một nối đất chung.
    
    
- ***Hướng dẫn giao tiếp UART***
    
    Vì nó là thiết lập phổ quát nên chúng ta có thể định cấu hình UART để hoạt động với nhiều loại giao thức nối tiếp khác nhau. UART đã được điều chỉnh thành các đơn vị chip đơn vào đầu những năm 1970, bắt đầu với Western Digital’s WD1402A.
    
    Trong một sơ đồ giao tiếp UART:
    
    1. Chân Tx (truyền) của một chip kết nối trực tiếp với chân Rx (nhận) của chip kia và ngược lại. Thông thường, quá trình truyền sẽ diễn ra ở 3.3V hoặc 5V. UART là một giao thức một master, một slave, trong đó một thiết bị được thiết lập để giao tiếp với duy nhất một thiết bị khác.
    2. Dữ liệu truyền đến và đi từ UART song song với thiết bị điều khiển (ví dụ: CPU).
    3. Khi gửi trên chân Tx, UART đầu tiên sẽ dịch thông tin song song này thành nối tiếp và truyền đến thiết bị nhận.
    4. UART thứ hai nhận dữ liệu này trên chân Rx của nó và biến đổi nó trở lại thành song song để giao tiếp với thiết bị điều khiển của nó.
- ***Chế độ truyền:***
    
    UART truyền dữ liệu nối tiếp, theo một trong ba chế độ:
    
    - Full duplex: Giao tiếp đồng thời đến và đi từ mỗi master và slave
    - Half duplex: Dữ liệu đi theo một hướng tại một thời điểm
    - Simplex: Chỉ giao tiếp một chiều
- ***UART Frame:***
    
    Dữ liệu truyền qua UART được tổ chức thành các gói. Mỗi gói chứa 1 bit bắt đầu, 5 đến 9 bit dữ liệu (tùy thuộc vào UART), một bit chẵn lẻ tùy chọn và 1 hoặc 2 bit dừng.
    
    
    ***Bit bắt đầu***
    
    Đường truyền dữ liệu UART thường được giữ ở mức điện áp cao khi không truyền dữ liệu. Để bắt đầu truyền dữ liệu, UART truyền sẽ kéo đường truyền từ mức cao xuống mức thấp trong một chu kỳ clock. Khi UART nhận phát hiện sự chuyển đổi điện áp cao xuống thấp, nó bắt đầu đọc các bit trong khung dữ liệu ở tần số của tốc độ truyền.
    
    ***Khung dữ liệu***
    
    Khung dữ liệu chứa dữ liệu thực tế được chuyển. Nó có thể dài từ 5 bit đến 8 bit nếu sử dụng bit chẵn lẻ. Nếu không sử dụng bit chẵn lẻ, khung dữ liệu có thể dài 9 bit. Trong hầu hết các trường hợp, dữ liệu được gửi với bit ít quan trọng nhất trước tiên.
    
    ***Bit chẵn lẻ***
    
    Bit chẵn lẻ là một cách để UART nhận cho biết liệu có bất kỳ dữ liệu nào đã thay đổi trong quá trình truyền hay không. Bit có thể bị thay đổi bởi bức xạ điện từ, tốc độ truyền không khớp hoặc truyền dữ liệu khoảng cách xa. Sau khi UART nhận đọc khung dữ liệu, nó sẽ đếm số bit có giá trị là 1 và kiểm tra xem tổng số là số chẵn hay lẻ. Nếu bit chẵn lẻ là 0 (tính chẵn), thì tổng các bit 1 trong khung dữ liệu phải là một số chẵn. Nếu bit chẵn lẻ là 1 (tính lẻ), các bit 1 trong khung dữ liệu sẽ tổng thành một số lẻ. Khi bit chẵn lẻ khớp với dữ liệu, UART sẽ biết rằng quá trình truyền không có lỗi. Nhưng nếu bit chẵn lẻ là 0 và tổng là số lẻ; hoặc bit chẵn lẻ là 1 và tổng số là chẵn, UART sẽ biết rằng các bit trong khung dữ liệu đã thay đổi.
    
    ***Bit dừng***
    
    Để báo hiệu sự kết thúc của gói dữ liệu, UART gửi sẽ điều khiển đường truyền dữ liệu từ điện áp thấp đến điện áp cao trong ít nhất khoảng 2 bit.
    
    ***Tóm tắt:***
    
    Quá trình truyền dữ liệu diễn ra dưới dạng các gói dữ liệu, bắt đầu bằng một bit bắt đầu, đường mức cao được kéo xuống đất. Sau bit bắt đầu, năm đến chín bit dữ liệu truyền trong khung dữ liệu của gói, theo sau là bit chẵn lẻ tùy chọn để xác minh việc truyền dữ liệu thích hợp. Cuối cùng, một hoặc nhiều bit dừng được truyền ở nơi đường đặt ở mức cao. Như vậy là kết thúc một gói.
    

  UART là giao thức không đồng bộ, do đó không có đường clock nào điều chỉnh tốc độ truyền dữ liệu. Người dùng phải đặt cả hai thiết bị để giao tiếp ở cùng tốc độ. Tốc độ này được gọi là tốc độ truyền, được biểu thị bằng bit trên giây hoặc bps. Tốc độ truyền thay đổi đáng kể, từ 9600 baud đến 115200 và hơn nữa. Tốc độ truyền giữa UART truyền và nhận chỉ có thể chênh lệch khoảng 10% trước khi thời gian của các bit bị lệch quá xa.

  Mặc dù UART là giao thức cũ và chỉ có thể giao tiếp giữa một master và slave duy nhất, nhưng nó dễ thiết lập và cực kỳ linh hoạt. Do đó, bạn có thể gặp nó khi làm việc với các dự án vi điều khiển. UART có thể là một phần của hệ thống mà bạn sử dụng hàng ngày, mà có thể bạn không nhận ra.

- ***Ưu điểm***
    - Chỉ sử dụng hai dây
    - Không cần tín hiệu clock
    - Có một bit chẵn lẻ để cho phép kiểm tra lỗi
    - Cấu trúc của gói dữ liệu có thể được thay đổi miễn là cả hai bên đều được thiết lập cho nó
    - Phương pháp có nhiều tài liệu và được sử dụng rộng rãi
- ***Nhược điểm***
    - Kích thước của khung dữ liệu được giới hạn tối đa là 9 bit
    - Không hỗ trợ nhiều hệ thống slave hoặc nhiều hệ thống master
    - Tốc độ truyền của mỗi UART phải nằm trong khoảng 10% của nhau
- **Lưu ý:**
    - UART là giao thức không đồng bộ, do đó không có đường clock nào điều chỉnh tốc độ truyền dữ liệu.
    - Người dùng phải đặt cả hai thiết bị để giao tiếp ở cùng tốc độ. Tốc độ này được gọi là tốc độ truyền, được biểu thị bằng bit trên giây hoặc bps.
    - Tốc độ truyền giữa UART truyền và nhận chỉ có thể chênh lệch khoảng 10% trước khi thời gian của các bit bị lệch quá xa.
    
   </details>

  <details>
  <summary><h2>INTERRUPT</h2></summary>

- là một số sự kiện khẩn cấp bên trong hoặc bên ngoài bộ vi điều khiển xảy ra, buộc vi điều khiển tạm dừng thực hiện chương trình hiện tại, phục vụ ngay lập tức nhiệm vụ mà ngắt yêu cầu – nhiệm vụ này gọi là trình phục vụ ngắt (**ISR:** Interrupt Service Routine).

Trình phục vụ ngắt:

- Đối với mỗi ngắt thì phải có một **trình phục vụ ngắt** (**ISR**) hay trình quản lý ngắt để đưa ra nhiệm vụ cho bộ vi điều khiển khi được gọi ngắt.
- Khi một ngắt timer xảy ra, MCU sẽ tạm dừng thực hiện chương trình hiện tại và nhảy đến **Trình phục vụ ngắt** của ngắt đó. Và thực hiện lệnh trong **Trình phục vụ ngắt**
- Đối với mỗi ngắt thì có một vị trí cố định trong bộ nhớ để giữ địa chỉ **ISR** của nó.
- Số thứ tự ngắt càng thấp thì độ ưu tiên càng cao
- Ngắt có 4 loại:
    - reset: Ngắt reset là một loại ngắt nội xảy ra khi MCU nhận được một tín hiệu reset. Ngắt reset thường được sử dụng để khởi động lại MCU hoặc khôi phục MCU về trạng thái ban đầu.
    - ngoài: Ngắt ngoài là một loại ngắt xảy ra khi một sự kiện bên ngoài MCU xảy ra, chẳng hạn như nhấn nút, đọc cảm biến, v.v. Ngắt ngoài thường được sử dụng để phản ứng với các sự kiện từ thế giới thực.
    - timer: Ngắt timer là một loại ngắt nội xảy ra khi một bộ đếm thời gian đếm đến giá trị đã định. Ngắt timer thường được sử dụng để tạo ra các khoảng thời gian định kỳ, chẳng hạn như để điều khiển các thiết bị ngoại vi hoặc thực hiện các tác vụ lặp đi lặp lại.
    - Ngắt truyền thông là một loại ngắt xảy ra khi có một sự kiện liên quan đến giao tiếp xảy ra, chẳng hạn như nhận được một byte dữ liệu hoặc hoàn thành một giao tiếp. Ngắt truyền thông thường được sử dụng để xử lý các sự kiện truyền thông một cách kịp thời và hiệu quả.

Cấu hình Config 1 timer: (4 bước)

- **Timer base config:** Chọn bộ chia (nếu tốc độ cần đếm không quá nhỏ thì nên sử dụng bộ chia)
- **Xóa cờ tràn** (xóa trước khi dùng cho chắc chắn vì nếu cờ tràn sẽ xảy ra ngắt)
- **Đăng ký timer ngắt** (đăng ký timer nào thì timer đó mới bật ngắt)
- **Enable interrupt:** cho phép ngắt hoạt động (ngắt nào đã đc đăng ký thì bật cái này lên mới hoạt động)
- **Enable timer:** là cho phép tim4 bắt đầu đếm
   </details>

  <details>
  <summary><h2>CAN</h2></summary>

- **Khái niệm**
    
    Controller Area Network (CAN hoặc CAN Bus) là công nghệ mạng nối tiếp, tốc độ cao, bán song công, hai dây.
    
- **Ưu điểm:**
    - **Đơn giản, chi phí thấp:** bus CAN chỉ có 2 dây giúp kết nối các module điều khiển với nhau dễ dàng hơn khi so sánh với cách làm truyền thống. Kèm theo đó là nhiều lợi ích về việc dễ lắp đặt và dễ sửa chữa, bảo trì khi có sự cố.
    - **Là 1 một giao thức chung** để nhiều nhà cung cấp khác nhau có thể phát triển các module điều khiển tương thích với nhau
    - **Tính ưu tiên của thông điệp (Prioritization of messages):** mỗi thông điệp được truyền ra từ một nút (node) hay trạm (station) trên bus CAN đều có mức ưu tiên. Khi nhiều thông điệp được truyền ra bus cùng lúc thì thông điệp có mức ưu tiên cao nhất sẽ được truyền. Cá thông điệp có mức ưu tiên thấp hơn sẽ tạm dừng và được truyền lại khi bus rảnh. Việc xác định mức ưu tiên của thông điệp dựa trên cấu tạo (cấu trúc) thông điệp và cơ chế phân xử quy định trong chuẩn chuẩn CAN.
    - **Cấu hình linh hoạt:** cho phép thiết lập cấu hình thời gian bit, thời gian đồng bộ, độ dài dữ liệu truyền, dữ liệu nhận, …
    - **Nhận dữ liệu đa điểm với sự đồng bộ thời gian:** một thông điệp có thể được nhận bởi nhiều node khác nhau trong bus cùng lúc. Tất cả các node trên bus đều có thể thấy thông điệp đang truyền trên bus, tùy vào cấu hình ở mỗi node mà node sẽ quyết định có chấp nhận thông điệp này hay không.
    Nhiều master (multimaster)
    - **Phát hiện và báo hiệu lỗi:** Mỗi thông điệp có kèm theo mã CRC (Cyclic Redundancy Code) để thực hiện kiểm tra lỗi. Nếu lỗi xuất hiện, node nhận sẽ bỏ qua thông điệp lỗi và truyền khung báo lỗi (error frame) lên bus CAN. Mỗi node trong bus có bộ đếm quản lý lỗi truyền nhận riêng để xác định trạng thái lỗi của chính nó. Nếu lỗi xuất hiện quá nhiều, một node có thể tự động ngắt khỏi bus. Ngoài ra còn một số dạng lỗi khác có thể được phát hiện với chuẩn CAN.
    - **Tự động truyền lại các thông điệp bị lỗi khi bus rảnh:** Một thông điệp được truyền ra bus nếu bị lỗi thì sẽ không mất đi mà node truyền thông điệp này sẽ giữ nó lại và tự động phát lại thông điệp này khi bus CAN rảnh cho đến khi thành công. Điều này giúp đảm bảo tính toàn vẹn dữ liệu trong bus
- **CAN hoạt động như thế nào?**
    - Trước khi gửi thông điệp, nút CAN sẽ kiểm tra xem bus có bận không.
    - Nó cũng sử dụng để phát hiện khả năng trùng lặp.
    - Sau đó sử dụng xác định quyền ưu tiên để xác định Node nào được truyền
    
- **Trạng thái “dominant (0)” và “recessive (1)”**
    - Ở lớp vật lý, Bus CAN định nghĩa hai trạng thái là “dominant” và “recessive”, tương ứng với hai trạng thái là 0 và 1.
    - Trạng thái “dominant” chiếm ưu thế so với trạng thái “recessive”.
    - Bus chỉ ở trạng thái “reccessive” khi không có node nào phát đi trạng thái “dominant”.
    - Điều này tạo ra khả năng giải quyết chanh chấp khi nhiều hơn một Master cùng muốn chiếm quyền sử dụng bus.
    - Bởi tính chất vật lý của bus, cần thiết phải phân biệt 2 dạng truyền:
    
    | Thông số | CAN low speed | CAN high speed |
    | --- | --- | --- |
    | Tốc độ | 125kb/s | 125kb/s → 1Mb/s |
    | Số nút trên Bus | 2 → 20 | 2 → 30 |
    | Trạng thái dominant | CANH = 4v ; CANL = 1V | CANH = 3.25v ; CANL = 1.5V |
    | Trạng thái recessive | CANH = 1.75v ; CANL = 3.25V | CANH = 2.5v ; CANL = 2.5V |
    | Tính chất của cap | 30pF giữa cáp và dây | 2*120 ohm |
    | Điện áp cung cấp | 5V | 5V |
    
- **Các loại CAN Frame (4 loại)**
    
    Dữ liệu CAN được truyền dưới dạng các Frame (khung). Có 4 loại Frame khác
    nhau, đó là:
    
    1. **Data Frame** **(khung dữ liệu):** là khung mang dữ liệu từ một bộ truyền dữ
    liệu đến các bộ nhận dữ liệu. Khung này có vùng để mang các byte dữ
    liệu.
    2. **Remote Frame** **(khung yêu cầu hay điều khiển):** là khung được truyền từ
    một Node bất kỳ để yêu cầu dữ liệu từ Node khác. Khi Node khác đó nhận
    được yêu cầu sẽ truyền lại dữ liệu có ID (Identifier) trùng với ID được gửi
    trong Remote Frame.
    3. **Error Frame (khung lỗi):** là khung được truyền bởi bất kỳ Node nào khi
    Node đó phát hiện lỗi từ Bus.
    4. **Overflow Frame** **(khung báo tràn):** mỗi Node trong CAN Bus có thể truyền
    bất kỳ khi nào nếu phát hiện Bus rảnh. Hoặc nếu một Node nhận quá
    nhiều dữ liệu và không xử lý kịp, nó sẽ gửi Frame này để các Node khác
    không gửi thêm dữ liệu cho nó.
    
    Data Frame và Remote Frame làm việc theo cơ chế phân xử quyền ưu tiên của tín
    hiệu vì thế cấu trúc của chúng có vùng phân xử quyền ưu tiên, nơi chứa ID của
    khung.
    
- **Data frame:**
    
    ***Có 7 trường trong 1 data frame:***
    
    - **Trường bắt đầu khung (Start Of Frame Field – SOF)**
        - Trường này chiếm 1 bit dữ liệu.
        - Bit đầu tiên này là một Dominant Bit (mức logic 0) đánh dấu sự bắt đầu của một Data Frame.
    - **Trường xác định quyền ưu tiên (Arbitration Field)**
        
        Bao gồm: 
        
        Định dạng vùng xác định quyền ưu tiên là khác nhau đối với dạng khung chuẩn và khung mở rộng:
        
        - Định dạng chuẩn: vùng xác định quyền ưu tiên có độ dài 12 bit, bao gồm 11 bit ID và 1 bit RTR.
        - Định dạng mở rộng: trường xác định quyền ưu tiên có độ dài 32 bit, bao gồm có 29 bit ID, 1 bit SRR, 1 bit IDE và 1 bit RTR
        
        **Trong đó:**
        
        **Bit RTR (Remote Transmission Request)**
        
        - Là bit dùng để phân biệt khung là Data Frame hay Remote Frame.
        - Nếu là Data Frame, bit này luôn bằng 0 (Dominant Bit).
        - Nếu là Remote Frame, bit này luôn bằng 1 (Recessive Bit).
        - Vị trí bit này luôn nằm sau bit ID.
        - Trường hợp nếu Data Frame và Remote Frame có cùng ID được gửi đi đồng thời thì Data Frame sẽ được ưu tiên hơn.
        
        **Bit SRR (Substitute Remote Request)**
        
        - Bit này chỉ có ở khung mở rộng.
        - Bit này có giá trị là 1 (Recessive Bit).
        - So với vị trí tương ứng trong khung chuẩn thì bit này trùng với vị trí của bit
        
        **RTR nên còn được gọi là bit thay thế (Substitute).**
        
        - Giả sử có hai Node cùng truyền, một Node truyền Data Frame chuẩn, một Node
        truyền Data Frame mở rộng có ID giống nhau thì Node truyền khung chuẩn sẽ thắng phân xử quyền ưu tiên vì đến vị trí sau ID, khung chuẩn là bit RTR = 0, còn khung mở rộng là bit SRR = 1. Như vậy, khung chuẩn chiếm ưu thế hơn so với khung mở rộng khi có ID như nhau.
        
        **Bit IDE (Identifier Extension)**
        
        - Đây là bit phân biệt giữa loại khung chuẩn và khung mở rộng: IDE = 0 quy
        định khung chuẩn, IDE = 1 quy định khung mở rộng.
        - Bit này nằm ở trường xác định quyền ưu tiên với khung mở rộng và ở
        trường điều khiển với khung chuẩn.
    - **Trường điều khiển (Control Field)**
        
        Khung chuẩn và khung mở rộng có định dạng khác nhau ở trường này:
        
        Khung chuẩn gồm IDE, r0 và DLC (Data Length Code).
        
        Khung mở rộng gồm r1, r0 và DLC.
        
        **Trong đó:**
        
        **Bit IDE**
        
        Dùng phân biệt loại khung (đã được trình bày ở trên).
        
        **Bit r0, r1 (hai bit dự trữ)**
        
        Tuy hai bit này phải được truyền là Recessive Bit bởi bộ truyền nhưng bộ nhận
        không quan tâm đến giá trị 2 bit này. Bộ nhận có thể nhận được các tổ hợp 00, 01,
        10 hoặc 11 của r1 và r0 nhưng không coi đó là lỗi mà bỏ qua và nhận thông điệp
        bình thường.
        
        **DLC (Data Length Code)**
        
        - Có độ dài 4 bit quy định số byte của trường dữ liệu của Data Frame
        - Chỉ được mang giá trị từ 0 đến 8 tương ứng với trường dữ liệu có từ 0 đến
        8 byte dữ liệu. Data Frame có thể không có byte dữ liệu nào khi DLC = 0.
        - Giá trị lớn hơn 8 không được phép sử dụng. Hình dưới mô tả các loại mã
        bit mà DLC có thể chứa để quy định số byte của trường dữ liệu.
    - **Trường dữ liệu (Data Field)**
        
        Trường này có độ dài từ 0 đến 8 byte tùy vào giá trị của DLC ở trường điều khiển.
        
    - **Trường kiểm tra (Cyclic Redundancy Check Field – CRC)**
        
        Trường kiểm tra hay trường CRC gồm 16 bit và được chia làm hai phần là:
        
        - **CRC Sequence:** gồm 15 bit CRC tuần tự
        - **CRC Delimiter:** là một Recessive Bit làm nhiệm vụ phân cách trường CRC
        với trường ACK
        
        Mã kiểm tra CRC phù hợp nhất cho các khung mà chuỗi bit được kiểm tra
        có chiều dài dưới 127 bit, mã này thích hợp cho việc phát hiện các trường
        hợp sai nhóm (Bus Error). Ở đây, tổng bit từ trường bắt đầu (SOF) đến
        trường dữ liệu (Data Field) tối đa là 83 bit (khung định dạng chuẩn) và 103
        bit (khung định dạng mở rộng).
        
        => Trường CRC bảo vệ thông tin trong Data Frame và Remote Frame bằng cách
        thêm các bit kiểm tra dự phòng ở đầu khung truyền. Ở đầu khung nhận, cũng sẽ tính
        toán CRC như bộ truyền khi đã nhận dữ liệu và so sánh kết quả đó với CRC
        Sequence mà nó đã nhận được, nếu khác nhau tức là đã có lỗi, nếu giống nhau tức
        là đã nhận đúng từ trường SOF đến trường dữ liệu.
        
    - **Trường báo nhận (Acknowledge Field – ACK)**
        
        Trường báo nhận hay trường ACK có độ dài 2 bit và bao gồm hai phần là ACK Slot
        và ACK Delimiter.
        
        - **ACK Slot:** có độ dài 1 bit, một Node truyền dữ liệu sẽ thiết lập bit này là
        Recessive. Khi một hoặc nhiều Node nhận chính xác giá trị thông điệp
        (không có lỗi và đã so sánh CRC Sequence trùng khớp) thì nó sẽ báo lại
        cho bộ truyền bằng cách truyền ra một Dominant Bit ngay vị trí ACK Slot
        để ghi đè lên Recessive Bit của bộ truyền.
        - **ACK Delimiter:** có độ dài 1 bit, nó luôn là một Recessive Bit. Như vậy, ta
        thấy rằng ACK Slot luôn được đặt giữa hai Recessive Bit là CRC Delimiter
        và ACK Delimiter.
    - **Trường kết thúc (End Of Frame Field – EOF)**
        
        Trường EOF là trường thông báo kết thúc một Data Frame hay Remote Frame.
        
        - Trường này gồm 7 Recessive Bit
    
- **Cách xét ưu tiên trong CAN khi có nhiều NODE gửi cùng 1 lúc:**
    
    CAN sẽ ưu tiên nhận NODE có ID nhỏ nhất (Nhiều bit 0 liên tiếp ở đầu nhất)
    
- **Chế độ hoạt động:**
    
    1. Configuration mode
    2. Listen mode:
    3. Loop back mode
    4. Disabled mode
    5. Normal mode
    6. Error recognition mode
    
- **Các loại lỗi:**
    
    Bit Error:
    Lỗi Stuffing( Stuff Error)
    Lỗi Cyclic Redundancy(CRC Error)
    Lỗi ACK Delimiter
    Lỗi Slot ACK (ACK Error)
    
- **Quy trình xử lý lỗi trong CAN**
    1. Lỗi được phát hiện bởi bộ điều khiển CAN (bộ phát hoặc bộ thu).
    2. Một Error Frame được truyền ngay lập tức.
    3. Thông điệp bị hủy ở tất cả các nút (tồn tại ngoại lệ).
    4. Trạng thái của bộ điều khiển CAN được cập nhật.
    5. Thông điệp được truyền lại. Nếu một số bộ điều khiển cùng gửi thông điệp, trường xác định quyền ưu tiên sẽ được sử dụng như bình thường.
   </details>

</details>
