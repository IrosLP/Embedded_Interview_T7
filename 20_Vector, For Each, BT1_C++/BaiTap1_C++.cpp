//                 ĐỀ BÀI:
// Tạo 1 vector studentList có KDL là class Student
//     class Student bao gồm:
//         ID
//         Tên
//         Tuổi
//         Giới tính
//         điểm toán lý hóa và điểm TB

//                 YÊU CẦU:
// 0: Thoát
// 1: thêm SV
// 2: Cập nhật tt sv bằng id
// 3: xóa sv bằng id
// 4: tìm kiếm sv theo ten
// 5: sắp xếp sv theo điểm tb
// 6: sắp xếp sv theo ten
// 7: hiển thị danh sách sv

//làm thêm HOC LUC

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cstring>

int decreaseId=0;

using namespace std;

typedef enum{NAM = 1, NU} TypeGender;

typedef enum{ADD = 1, UPDATE, DELETE, FIND, SORTBYSCORE, SORTBYNAME, DISPLAY} Function;

typedef enum{EXCELLENT = 1, GOOD, AVERAGE, WEAK} Capacity;

class Student{
    private:
        int         id;
        string      name;
        int         age;
        TypeGender  gender;
        double      mathScore;
        double      physicalScore;
        double      chemistryScore;
        double      averageScore;
        Capacity    capacity;
        //+++++++++++++++++++++++++++++++++++++++++++++++++HOCLUC+++++++++++++++++++++++++++++++++++++++++++
    public:
        //-------CONSTRUCTOR------
        Student(string name = "", int age = 0, TypeGender gender = NAM, double mathScore = 0.0, double physicalScore = 0.0, double chemistryScore = 0.0);
        //----------SET-----------
        void setName(string);
        void setAge(int);
        void setGender(int);
        void setGender(string);
        void setMathScore(float);
        void setPhysicalScore(float);
        void setChemistryScore(float);
        //----------GET-----------
        int     getId();
        string  getName();
        int     getAge();
        string  getGender();
        float   getMathScore();
        float   getPhysicalScore();
        float   getChemistryScore();
        float   getAverageScore();
        string getCapacity();
        //----------ORTHER METHOD-----------
};

//-----------------------------------------------CONSTRUCTOR--------------------------------------
Student::Student(string name, int age, TypeGender gender, double mathScore, double physicalScore, double chemistryScore){
    static int ID = 1000;    
    ID++;
    ID -= decreaseId;
    decreaseId = 0;
    this->id = ID;

    this->name = name;
    this->age = age;
    this->gender = gender;
    this->mathScore = mathScore;
    this->physicalScore = physicalScore;
    this->chemistryScore = chemistryScore;
    this->averageScore = (mathScore + physicalScore + chemistryScore) / 3;
}

//-----------------------------------------------SET--------------------------------------
void Student::setName(string name){
    this->name = name;
}
void Student::setAge(int age){
    this->age = age;
}
void Student::setGender(int gender){
    if(gender == 1) this->gender = NAM;
    else if(gender == 2) this->gender = NU;
    else cout << "Nhap sai gioi tinh" << endl;
}
void Student::setGender(string gender){
    if(gender == "NAM") this->gender = NAM;
    else if(gender == "NU") this->gender = NU;
    else cout << "NHAP SAI GIOI TINH" << endl;
}
void Student::setMathScore(float mathScore){
    this->mathScore = mathScore;
}
void Student::setPhysicalScore(float physicalScore){
    this->physicalScore = physicalScore;
}
void Student::setChemistryScore(float chemistryScore){
    this->chemistryScore = chemistryScore;
}

//-----------------------------------------------GET--------------------------------------
int Student::getId(){
    return this->id;
}
string Student::getName(){
    return this->name;
}
int Student::getAge(){
    return this->age;
}
string Student::getGender(){
    if(this->gender == 1) return "NAM";
    else if(this->gender == 2) return "NU";
    else return "ERROR";
}
float Student::getMathScore(){
    return this->mathScore;
}
float Student::getPhysicalScore(){
    return this->physicalScore;
}
float Student::getChemistryScore(){
    return this->chemistryScore;
}
float Student::getAverageScore(){
    this->averageScore = (mathScore + physicalScore + chemistryScore) / 3;
    return this->averageScore;
}
string Student::getCapacity(){
    if(averageScore >= 8){
        capacity = EXCELLENT;
        return "EXCELLENT";
    }
    else if((averageScore >= 6.5)){
        capacity = GOOD;
        return "GOOD";
    }
    else if((averageScore >= 5)){
        capacity = AVERAGE;
        return "AVERAGE";
    }
    else{
        capacity = WEAK;
        return "WEAK";
    }
}
//-----------------------------------------------FUNCTION--------------------------------------
void enterInfor(Student& a){
    string name;
    int age, gender;
    float mathScore, physicalScore, chemistryScore;
    //----------------------------------
    cout << "Nhap ten: ";
    cin >> name;   
    a.setName(name);
    //----------------------------------
    do{
        cout << "Nhap tuoi: ";
        cin >> age;
    }while((age < 0)||(age > 100));
    a.setAge(age);
    //----------------------------------
    do{
        cout << "Chon gioi tinh (1:Nam; 2:Nu): ";
        cin >> gender;
    }while((gender != 1)&&(gender != 2));
    a.setGender(gender);
    //----------------------------------
    do{
        cout << "Nhap diem Toan: ";
        cin >> mathScore;
    }while((mathScore < 0.0)||(mathScore > 10.0));
    a.setMathScore(mathScore);
    //----------------------------------
    do{
        cout << "Nhap diem Ly: ";
        cin >> physicalScore;
    }while((physicalScore < 0.0)||(physicalScore > 10.0));
    a.setPhysicalScore(physicalScore);
    //----------------------------------
    do{
        cout << "Nhap diem Hoa: ";
        cin >> chemistryScore;
    }while((chemistryScore < 0.0)||(chemistryScore > 10.0));
    a.setChemistryScore(chemistryScore);
}

void printHeaderOfTable(){
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(4) << " " << setw(8)  << left << "ID";
    cout << "|" << setw(4) << " " << setw(16) << left << "NAME";
    cout << "|" << setw(4) << " " << setw(7)  << left << "AGE";
    cout << "|" << setw(4) << " " << setw(10) << left << "GENDER";
    cout << "|" << setw(4) << " " << setw(8)  << left << "MATH";
    cout << "|" << setw(4) << " " << setw(13) << left << "PHYSICAL";
    cout << "|" << setw(4) << " " << setw(14) << left << "CHEMISTRY";
    cout << "|" << setw(4) << " " << setw(11) << left << "AVERAGE";
    cout << "|" << setw(4) << " " << setw(12) << left << "CAPACITY" << "|" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void printStudentInforOfTable(Student a){
    cout << "|" << setw(4) << " " << setw(8)  << left << a.getId();
    cout << "|" << setw(4) << " " << setw(16) << left << a.getName();
    cout << "|" << setw(4) << " " << setw(7)  << left << a.getAge();
    cout << "|" << setw(4) << " " << setw(10) << left << a.getGender();
    cout << "|" << setw(4) << " " << setw(8)  << left << a.getMathScore();
    cout << "|" << setw(4) << " " << setw(13) << left << a.getPhysicalScore();
    cout << "|" << setw(4) << " " << setw(14) << left << a.getChemistryScore();
    cout << "|" << setw(4) << " " << setw(11) << left << a.getAverageScore();
    cout << "|" << setw(4) << " " << setw(12) << left << a.getCapacity() << "|" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void addStudent(vector <Student>& studentList){
    int key;
    do{
        Student a;
        enterInfor(a);
        studentList.push_back(a);
        cout << "***NHAP THONG TIN THANH CONG***" << endl;
        cout << "Nhap them sinh vien khac (1:Co, 2:Khong): ";
        cin >> key;
    }while(key == 1);
}

void displayListStudent(vector <Student> studentList){
    printHeaderOfTable();
    for(int i=0; i < studentList.size(); i++){
        printStudentInforOfTable(studentList[i]);
    }
}

void updateInfor(vector <Student>& studentList){
    int currentId, found = 0;
    cout << "Nhap vao ID sinh vien: ";
    cin >> currentId;
    for(int i=0; i<studentList.size(); i++){
        if(currentId == studentList[i].getId()){
            enterInfor(studentList[i]);
            cout << "***CAP NHAT THONG TIN THANH CONG***" << endl;
            found = 1;
            break;
        }
    }
    if(found == 0) cout << "***KHONG TIM THAY ID NAY***" << endl;
}

void deleteInfor(vector <Student>& studentList){
    int currentId, found = 0;
    cout << "Nhap vao ID sinh vien: ";
    cin >> currentId;
    for(int i=0; i<studentList.size(); i++){
        if(currentId == studentList[i].getId()){
            for(int j=i; j<studentList.size(); j++){
                if(j != studentList.size() - 1){
                    studentList[j].setName(studentList[j+1].getName());
                    studentList[j].setAge(studentList[j+1].getAge());
                    studentList[j].setGender(studentList[j+1].getGender());
                    studentList[j].setMathScore(studentList[j+1].getMathScore());
                    studentList[j].setPhysicalScore(studentList[j+1].getPhysicalScore());
                    studentList[j].setChemistryScore(studentList[j+1].getChemistryScore());
                    found = 1;
                }
                else found = 1;
            }
            studentList.pop_back();
            decreaseId++;
            cout << "***XOA THONG TIN THANH CONG***" << endl;
            break;
        }
    }
    if(found == 0) cout << "***KHONG TIM THAY ID NAY***" << endl;
}

void findStudent(vector <Student> studentList){
    string currentName;
    int found = 0;
    cout << "Nhap vao TEN sinh vien: ";
    cin >> currentName;
    for(int i=0; i<studentList.size(); i++){    
        if(currentName == studentList[i].getName()){
            if(found == 0){
               printHeaderOfTable();
            }
            printStudentInforOfTable(studentList[i]);
            found = 1;
        }
    }
    if(found == 0) cout << "***KHONG TIM THAY TEN NAY***" << endl;
}

void sortByAverageScore(vector <Student>& studentList){
    Student temp;
    for(int i=0; i<studentList.size() - 1; i++){
        for(int j=i; j<studentList.size(); j++){
            if(studentList[i].getAverageScore() < studentList[j].getAverageScore()){
                temp = studentList[i];
                studentList[i] = studentList[j];
                studentList[j] = temp;
            }
        }
    }
    cout << "***SAP XEP THEO DIEM TRUNG BINH THANH CONG***";
}

void sortByName(vector <Student>& studentList){
    Student temp;
    for(int i=0; i<studentList.size() - 1; i++){
        for(int j=i; j<studentList.size(); j++){
            if(studentList[i].getName() > studentList[j].getName()){
                temp = studentList[i];
                studentList[i] = studentList[j];
                studentList[j] = temp;
            }
        }
    }
    cout << "***SAP XEP THEO TEN THANH CONG***";
}
//-----------------------------------------------MAIN--------------------------------------
int main(){
    vector <Student> studentList;
    int key;

    while (1){    
        cout << "\n*****************************************" << endl;
        cout << "Chon chuc nang:" << endl;
        cout << "\t1: Them sinh vien" << endl;
        cout << "\t2: Cap nhat thong tin sinh vien" << endl;
        cout << "\t3: Xoa sinh vien" << endl;
        cout << "\t4: Tim kiem sinh vien" << endl;
        cout << "\t5: Sap xep danh sach theo diem trung binh" << endl;
        cout << "\t6: Sap xep danh sach theo ten sinh vien" << endl;
        cout << "\t7: Hien thi danh sach sinh vien\t";
        cin >> key;

        switch (key){
            case ADD:
                addStudent(studentList);
                break;
            case UPDATE:
                updateInfor(studentList);
                break;
            case DELETE:
                deleteInfor(studentList);
                break;
            case FIND:
                findStudent(studentList);
                break;
            case SORTBYSCORE:
                sortByAverageScore(studentList);
                break;
            case SORTBYNAME:
                sortByName(studentList);
                break;
            case DISPLAY:
                displayListStudent(studentList);
                break;
            default:
                cout << "Khong co chuc nang nay" <<endl;
                break;
        }
    }
}
