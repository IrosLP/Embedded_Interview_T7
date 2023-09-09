#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <stdint.h>

using namespace std;

typedef enum{MAIN, BOOKING, CUSTOMER, STAFF, SERVICE, PAYMENT, SECURITY, REPORT, INTERACT} State;
typedef enum{SECURITY_LOGIN, SECURITY_DONE} StateSecurity; 
typedef enum{STAFF_LOGIN, STAFF_DONE} StateStaff;
typedef enum{SERVICE_LOGIN, SERVICE_DONE} StateService;
typedef enum{ROLE_MANAGER, ROLE_STAFF} Role;

typedef struct{
    int second;
    int minute;
    int hour;
}TypeTime;
typedef struct{
    int day;
    int month;
    int year;
}TypeDate;
typedef struct{
    TypeTime time;
    TypeDate date;
}DetailBooking;
typedef struct{
    TypeTime time;
    int day;
}StayTime;
//=======================================CLASS ROOM=======================================
class Room{
    private:
        int roomNumber;
        bool isBooked;
    public:
        Room(int);
        int getRoomNumber();
        bool bookRoom();
        bool checkOut();
        bool getStatus();
};
Room::Room(int roomNumber){
    this->roomNumber = roomNumber;
    isBooked = false;
}
int Room::getRoomNumber(){
    return roomNumber;
}
bool Room::bookRoom(){
    isBooked = true;
}
bool Room::checkOut(){
    isBooked = false;
}
bool Room::getStatus(){
    return isBooked;
}
//=====================================CLASS CUSTOMER=====================================
class Customer{
    private:
        uint32_t idRoom;
        string name;
        string address;
        string phoneNumber;
        vector <DetailBooking> bookingHistory;
    public:
        void setIdRoom(int, vector <Room> &);
        void setName(string);
        void setAddress(string);
        void setPhoneNumber(string);
        void setBookingHistory(DetailBooking);
        uint32_t getIdRoom();
        string getName();
        string getAddress();
        string getPhoneNumber();
        vector <DetailBooking> getBookingHistory();
};
void Customer::setIdRoom(int roomNumber, vector <Room> &listRoom){
    idRoom = roomNumber;
    listRoom[idRoom].bookRoom();
}
void Customer::setName(string name){
    this->name = name;
}
void Customer::setAddress(string address){
    this->address = address;
}
void Customer::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}
void Customer::setBookingHistory(DetailBooking detailBooking){
    bookingHistory.push_back(detailBooking);
}
uint32_t Customer::getIdRoom(){
    return idRoom;
}
string Customer::getName(){
    return name;
}
string Customer::getAddress(){
    return address;
}
string Customer::getPhoneNumber(){
    return phoneNumber;
}
vector <DetailBooking> Customer::getBookingHistory(){
    return bookingHistory;
}
//======================================CLASS STAFF=======================================
class Staff{
    private:
        string name;
        string phoneNumber;
        Role role;
    public:
        void setName(string);
        void setPhoneNumber(string);
        void setRole(Role);
        string getName();
        string getPhoneNumber();
        Role getRole();
};
void Staff::setName(string name){
    this->name = name;
}
void Staff::setPhoneNumber(string phoneNumber){
    this->phoneNumber = phoneNumber;
}
void Staff::setRole(Role role){
    this->role = role;
}
string Staff::getName(){
    return name;
}
string Staff::getPhoneNumber(){
    return phoneNumber;
}
Role Staff::getRole(){
    return role;
}
//=====================================CLASS ACCOUNT======================================
class Account{
    private:
        string userName;
        string password;
        Role role;
    public:
        void setUserName(string);
        void setPassword(string);
        void setRole(Role);
        string getUserName();
        string getPassword();
        Role getRole();
};
void Account::setUserName(string userName){
    this->userName = userName;
}
void Account::setPassword(string password){
    this->password = password;
}
void Account::setRole(Role role){
    this->role = role;
}
string Account::getUserName(){
    return userName;
}
string Account::getPassword(){
    return password;
}
Role Account::getRole(){
    return role;
}
//=====================================CLASS SERVICE======================================
class Service{
    private:
        string nameService;
        long long price;
    public:
        void setNameService(string);
        void setPrice(long long);
        string getNameService();
        long long getPrice();
};
void Service::setNameService(string nameService){
    this->nameService = nameService;
}
void Service::setPrice(long long price){
    this->price = price;
}
string Service::getNameService(){
    return nameService;
}
long long Service::getPrice(){
    return price;
}
//====================================SUPPORT FUNCTION====================================
void inputDetailBooking(DetailBooking &detailBooking){
    cout << "Nhap gio, phut, giay: "; cin >> detailBooking.time.hour >> detailBooking.time.minute >> detailBooking.time.second;
    cout << "Nhap ngay, thang, nam: "; cin >> detailBooking.date.day >> detailBooking.date.month >> detailBooking.date.year;
}

void displayBookingHistory(vector <DetailBooking> bookingHistory){
    for(int i=0; i<bookingHistory.size(); i++){
        cout << "Ngay vao: " << bookingHistory[i].time.hour << "h" << bookingHistory[i].time.minute << "m" << bookingHistory[i].time.second << "s_" 
        << bookingHistory[i].date.day << "/" << bookingHistory[i].date.month << "/" << bookingHistory[i].date.year << endl;
    }
}

void setListRoom(vector <Room> &listRoom, uint32_t numberOfRoom){
    for(int i=0; i<=numberOfRoom; i++){
        Room room(i);
        listRoom.push_back(room);
    }
}

void displayListRoom(vector <Room> listRoom, uint32_t numberOfRoom){
    cout << " Room  |";
    for(int i=1; i<=numberOfRoom; i++){
        cout << " " << setw(2) << left << listRoom[i].getRoomNumber() << " |";
    }
    cout << endl;
    cout << "Status |";
    for(int i=1; i<=numberOfRoom; i++){
        cout << " " << setw(2) << left << ((listRoom[i].getStatus()==false)?'O':'X') << " |";
    }
    cout << endl;
}

void customerAdd(vector <Customer> &listCustomer, vector <Room> &listRoom, State &state){
    string currentName, currentAddress, currentPhoneNumber;
    uint32_t currentRoomNumber;
    Customer newCustomer;
    DetailBooking detailBooking;
    int keyInt;
    cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
    cout << "________________________________THEM KHACH HANG_______________________________" << endl;
    cout << "Nhap ten: ", cin >> currentName;
    newCustomer.setName(currentName);
    cout << "Nhap dia chi: ", cin >> currentAddress;
    newCustomer.setAddress(currentAddress);
    cout << "Nhap sdt: ", cin >> currentPhoneNumber;
    newCustomer.setPhoneNumber(currentPhoneNumber);
    do{
        cout << "Nhap phong: ", cin >> currentRoomNumber;
        if(listRoom[currentRoomNumber].getStatus() == true)
            cout << "Phong nay da co khach\nVui long chon phong khac" << endl;
    }while(listRoom[currentRoomNumber].getStatus() == true);
    newCustomer.setIdRoom(currentRoomNumber, listRoom);
    inputDetailBooking(detailBooking);
    newCustomer.setBookingHistory(detailBooking);
    listCustomer.push_back(newCustomer);
    cout << "**************************THEM KHACH HANG THANH CONG**************************" << endl;
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    } while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0)
        state = MAIN;
}

void customerAdjustName(vector <Customer> &listCustomer, int customerPosition){
    string currentName;
    cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
    cout << "____________________________________SUA TEN___________________________________" << endl;
    cout << "Nhap ten moi:";
    cin >> currentName;
    listCustomer[customerPosition].setName(currentName);
    cout << "*******************************SUA TEN THANH CONG*****************************" << endl;
}

void customerAdjustPhoneNumber(vector <Customer> &listCustomer, int customerPosition){
    string currentPhoneNumber;
    cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
    cout << "________________________________SUA SO DIEN THOAI_____________________________" << endl;
    cout << "Nhap so dien thoai moi:" << endl;
    cin >> currentPhoneNumber;
    listCustomer[customerPosition].setName(currentPhoneNumber);
    cout << "*************************SUA SO DIEN THOAI THANH CONG************************" << endl;
}

void customerAdjustAddress(vector <Customer> &listCustomer, int customerPosition){
    string currentAddress;
    cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
    cout << "__________________________________SUA DIA CHI_________________________________" << endl;
    cout << "Nhap so dien thoai moi:" << endl;
    cin >> currentAddress;
    listCustomer[customerPosition].setName(currentAddress);
    cout << "****************************SUA DIA CHI THANH CONG***************************" << endl;
}

void customerAdjustRoom(vector <Customer> &listCustomer, vector <Room> &listRoom, int customerPosition){
    uint32_t roomNumber;
    cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
    cout << "___________________________________SUA PHONG__________________________________" << endl;
    cout << "Nhap so phong moi:" << endl;
    cin >> roomNumber;
    listRoom[listCustomer[customerPosition].getIdRoom()].checkOut();
    listCustomer[customerPosition].setIdRoom(roomNumber, listRoom);
    cout << "*****************************SUA PHONG THANH CONG****************************" << endl;
}

void customerAdjust(vector <Customer> &listCustomer, vector <Room> &listRoom, State &state, uint32_t numOfRoom){
    int keyInt, found = 0;
    char keyChar;
    int customerPosition;
    string currentName, currentPhoneNum;
    if(listCustomer.empty()){
        cout << "****************************CHUA CO KHACH HANG NAO****************************" << endl;
    }
    else{
        cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
        cout << "_________________________________SUA THONG TIN________________________________" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(18) << left << "TEN KHACH HANG";
        cout << "|" << setw(4) << " " << setw(11) << left << "DIA CHI";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(12) << left << "SO PHONG";
        cout << "|" << setw(4) << " " << setw(32) << left << "THOI GIAN DAT/CHECK IN PHONG" << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        for(int i=0; i<listCustomer.size(); i++){
            cout << "|" << setw(4) << " " << setw(18) << left << listCustomer[i].getName();
            cout << "|" << setw(4) << " " << setw(11) << left << listCustomer[i].getAddress();
            cout << "|" << setw(4) << " " << setw(16) << left << listCustomer[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(12) << left << listCustomer[i].getIdRoom();
            cout << "|" << setw(4) << " "
            << "Time: " << (listCustomer[i].getBookingHistory())[0].time.hour << "h" << (listCustomer[i].getBookingHistory())[0].time.minute << "m" << (listCustomer[i].getBookingHistory())[0].time.second << "s" 
            << "; Date: " << (listCustomer[i].getBookingHistory())[0].date.day << "/" << (listCustomer[i].getBookingHistory())[0].date.month << "/" << (listCustomer[i].getBookingHistory())[0].date.year << setw(7) << " " << "|" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
        cout << "Nhap ten: "; cin >> currentName;
        cout << "Nhap sdt: "; cin >> currentPhoneNum;
        for(customerPosition = 0; customerPosition < numOfRoom; customerPosition++){
            if(listCustomer[customerPosition].getName()==currentName && listCustomer[customerPosition].getPhoneNumber()==currentPhoneNum){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "*************************KHONG TIM THAY KHACH HANG NAY************************" << endl;
            cout << "Nhan phim bat ky de quay lai:... ";
            cin >> keyChar;
            state = MAIN;
        }
        else{
            do{
                cout << "______________________________THONG TIN KHACH HANG____________________________" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "|" << setw(4) << " " << setw(18) << left << "TEN KHACH HANG";
                cout << "|" << setw(4) << " " << setw(11) << left << "DIA CHI";
                cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
                cout << "|" << setw(4) << " " << setw(12) << left << "SO PHONG";
                cout << "|" << setw(4) << " " << setw(32) << left << "THOI GIAN DAT/CHECK IN PHONG" << "|" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
                cout << "|" << setw(4) << " " << setw(18) << left << listCustomer[customerPosition].getName();
                cout << "|" << setw(4) << " " << setw(11) << left << listCustomer[customerPosition].getAddress();
                cout << "|" << setw(4) << " " << setw(16) << left << listCustomer[customerPosition].getPhoneNumber();
                cout << "|" << setw(4) << " " << setw(12) << left << listCustomer[customerPosition].getIdRoom();
                cout << "|" << setw(4) << " "
                << "Time: " << (listCustomer[customerPosition].getBookingHistory())[customerPosition].time.hour << "h" << (listCustomer[customerPosition].getBookingHistory())[0].time.minute << "m" << (listCustomer[customerPosition].getBookingHistory())[0].time.second << "s" 
                << "; Date: " << (listCustomer[customerPosition].getBookingHistory())[0].date.day << "/" << (listCustomer[customerPosition].getBookingHistory())[0].date.month << "/" << (listCustomer[customerPosition].getBookingHistory())[0].date.year << setw(7) << " " << "|" << endl;
                cout << "-------------------------------------------------------------------------------------------------------------------" << endl;

                cout << "Chon phan muon sua:" << endl;
                cout << "\t1: Sua ten\n\t2: Sua sdt\n\t3: Sua dia chi\n\t4: Sua phong\n\t0: Quay lai" << endl;
                cout << "Nhap lua chon:"; cin >> keyInt;
                if(keyInt < 0 || keyInt > 4)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            } while(keyInt < 0 || keyInt > 4);
            switch (keyInt)
            {
                case 0:
                    state = MAIN;
                    break;
                case 1:
                    customerAdjustName(listCustomer, customerPosition);
                    break;
                case 2:
                    customerAdjustPhoneNumber(listCustomer, customerPosition);
                    break;
                case 3:
                    customerAdjustAddress(listCustomer, customerPosition);
                    break;
                case 4:
                    customerAdjustRoom(listCustomer, listRoom, customerPosition);
                    break;
            }
        }
    }
    do{
        cout << "\t1: Tiep tuc cap nhat thong tin khach hang\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    } while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0)
        state = MAIN;
}

void customerErase(vector <Customer> &listCustomer, vector <Room> &listRoom, State &state, uint32_t numOfRoom){
    int keyInt, found = 0;
    char keyChar;
    string currentName, currentPhoneNum;
    if(listCustomer.empty()){
        cout << "*****************************CHUA CO KHACH HANG NAO***************************" << endl;
    }
    else{
        cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
        cout << "_________________________________XOA THONG TIN________________________________" << endl;cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(18) << left << "TEN KHACH HANG";
        cout << "|" << setw(4) << " " << setw(11) << left << "DIA CHI";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(12) << left << "SO PHONG";
        cout << "|" << setw(4) << " " << setw(32) << left << "THOI GIAN DAT/CHECK IN PHONG" << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        for(int i=0; i<listCustomer.size(); i++){
            cout << "|" << setw(4) << " " << setw(18) << left << listCustomer[i].getName();
            cout << "|" << setw(4) << " " << setw(11) << left << listCustomer[i].getAddress();
            cout << "|" << setw(4) << " " << setw(16) << left << listCustomer[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(12) << left << listCustomer[i].getIdRoom();
            cout << "|" << setw(4) << " "
            << "Time: " << (listCustomer[i].getBookingHistory())[0].time.hour << "h" << (listCustomer[i].getBookingHistory())[0].time.minute << "m" << (listCustomer[i].getBookingHistory())[0].time.second << "s" 
            << "; Date: " << (listCustomer[i].getBookingHistory())[0].date.day << "/" << (listCustomer[i].getBookingHistory())[0].date.month << "/" << (listCustomer[i].getBookingHistory())[0].date.year << setw(7) << " " << "|" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }

        cout << "Nhap ten: "; cin >> currentName;
        cout << "Nhap sdt: "; cin >> currentPhoneNum;
        for(int i=0; i<numOfRoom; i++){
            if(listCustomer[i].getName()==currentName && listCustomer[i].getPhoneNumber()==currentPhoneNum){
                listRoom[listCustomer[i].getIdRoom()].checkOut();
                listCustomer.erase(listCustomer.begin()+i);
                found = 1;
                cout << "***************************XOA THONG TIN THANH CONG***************************" << endl;
                break;
            }
        }
        if(found == 0) cout << "*************************KHONG TIM THAY KHACH HANG NAY************************" << endl;
    }
    do{
        cout << "\t1: Tiep tuc cap nhat thong tin khach hang\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    } while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0)
        state = MAIN;
}

void customerList(vector <Customer> &listCustomer, State &state, uint32_t numOfRoom){
    int keyInt;
    cout << "\n=============================QUAN LY KHACH HANG================================" << endl;
    cout << "____________________________DANH SACH KHACH HANG_______________________________" << endl;
    if(listCustomer.empty()){
        cout << "*****************************CHUA CO KHACH HANG NAO***************************" << endl;
    }
    else{
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(18) << left << "TEN KHACH HANG";
        cout << "|" << setw(4) << " " << setw(11) << left << "DIA CHI";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(12) << left << "SO PHONG";
        cout << "|" << setw(4) << " " << setw(32) << left << "THOI GIAN DAT/CHECK IN PHONG" << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        for(int i=0; i<listCustomer.size(); i++){
            cout << "|" << setw(4) << " " << setw(18) << left << listCustomer[i].getName();
            cout << "|" << setw(4) << " " << setw(11) << left << listCustomer[i].getAddress();
            cout << "|" << setw(4) << " " << setw(16) << left << listCustomer[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(12) << left << listCustomer[i].getIdRoom();
            cout << "|" << setw(4) << " "
            << "Time: " << (listCustomer[i].getBookingHistory())[0].time.hour << "h" << (listCustomer[i].getBookingHistory())[0].time.minute << "m" << (listCustomer[i].getBookingHistory())[0].time.second << "s" 
            << "; Date: " << (listCustomer[i].getBookingHistory())[0].date.day << "/" << (listCustomer[i].getBookingHistory())[0].date.month << "/" << (listCustomer[i].getBookingHistory())[0].date.year << setw(7) << " " << "|" << endl;
            cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) 
        state = MAIN;
}

void loginAccount(vector <Account> listAccount, int &found, int &accountPosition){
    string currentUserName, currentPassword;
    cout << "Ten dang nhap: "; cin >> currentUserName;
    cout << "Mat khau: "; cin >> currentPassword;
    for(accountPosition = 0; accountPosition < listAccount.size(); accountPosition++)
    {
        if(listAccount[accountPosition].getUserName() == currentUserName){
            if(listAccount[accountPosition].getPassword() == currentPassword) found = 2;
            else found = 1;
            break;
        }        
    }
    switch(found)
    {
        case 0:
            cout << "***************************TEN DANG NHAP KHONG DUNG***************************" << endl;
            break;
        case 1:
            cout << "******************************MAT KHAU KHONG DUNG*****************************" << endl;
            break;
        case 2:
            break;
    }
}

void securityAdd(vector <Account> &listAccount, State &state, StateSecurity &stateSecurity){
    Account newAccount;
    string currentUserName, currentPassword;
    int keyInt, found;
    cout << "\n===============================QUAN LY BAO MAT================================" << endl;
    cout << "________________________________THEM TAI KHOAN________________________________" << endl;
    do{
        found = 0;
        cout << "Nhap ten tai khoan: "; cin >> currentUserName;
        for(int i=0; i<listAccount.size(); i++){
            if(listAccount[i].getUserName() == currentUserName){
                found = 1;
                break;
            }
        }
        if(found == 1) 
            cout << "*************************TEN TAI KHOAN NAY DA TON TAI*************************" << endl;
    }while(found == 1);
    newAccount.setUserName(currentUserName);
    cout << "Nhap mat khau: "; cin >> currentPassword;
    newAccount.setPassword(currentPassword);
    do{
        cout << "Chuc vu:\n\t0: MANAGER\n\t1: STAFF\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc vu nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) newAccount.setRole(ROLE_MANAGER);
    else newAccount.setRole(ROLE_STAFF);
    listAccount.push_back(newAccount);
    cout << "**************************THEM TAI KHOAN THANH CONG**************************" << endl;
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateSecurity = SECURITY_LOGIN;
    }
}

void securityAdjustUserName(vector <Account> &listAccount, int accountPosition){
    string currentUserName;
    cout << "Nhap ten tai khoan moi: "; cin >> currentUserName;
    listAccount[accountPosition].setUserName(currentUserName);
    cout << "***********************THAY DOI TEN TAI KHOAN THANH CONG**********************" << endl;
}

void securityAdjustPassword(vector <Account> &listAccount, int accountPosition){
    string currentPassword;
    cout << "Nhap ten mat khau moi: "; cin >> currentPassword;
    listAccount[accountPosition].setUserName(currentPassword);
    cout << "*************************THAY DOI MAT KHAU THANH CONG*************************" << endl;
}

void securityAdjustRole(vector <Account> &listAccount, int accountPosition){
    int keyInt;
    do{
        cout << "Chon chuc vu:\n\t0: MANAGER\n\t1: STAFF\nNhap lua chon: ";
        cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc vu nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) listAccount[accountPosition].setRole(ROLE_MANAGER);
    else listAccount[accountPosition].setRole(ROLE_STAFF);
    cout << "**************************THAY DOI CHUC VU THANH CONG*************************" << endl;
}

void securityAdjust(vector <Account> &listAccount, State &state, StateSecurity &stateSecurity){
    string currentUserName, currentPassword;
    int keyInt, accountPosition, found = 0;
    cout << "\n===============================QUAN LY BAO MAT================================" << endl;
    cout << "______________________________CHINH SUA TAI KHOAN_____________________________" << endl;
    if(listAccount.empty()){
        cout << "*****************************CHUA CO TAI KHOAN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN TAI KHOAN";
        cout << "|" << setw(4) << " " << setw(16) << left << "MAT KHAU";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listAccount.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getUserName();
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getPassword();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listAccount[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << "Nhap ten tai khoan: "; cin >> currentUserName;
        for(accountPosition = 0; accountPosition < listAccount.size(); accountPosition++){
            if(listAccount[accountPosition].getUserName() == currentUserName){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "***************************KHONG TIM THAY TAI KHOAN***************************" << endl;
        }
        else{
            do{
                cout << "\t1: Sua ten tai khoan\n\t2: Sua mat khau\n\t3: Sua chuc vu\nNhap lua chon: ";
                cin >> keyInt;
                if(keyInt < 1 || keyInt > 3)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            }while(keyInt < 1 || keyInt > 3);
            switch (keyInt)
            {
            case 1:
                securityAdjustUserName(listAccount, accountPosition);
                break;
            case 2:
                securityAdjustPassword(listAccount, accountPosition);
                break;
            case 3:
                securityAdjustRole(listAccount, accountPosition);
                break;
            default:
                break;
            }
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateSecurity = SECURITY_LOGIN;
    }
}

void securityDelete(vector <Account> &listAccount, State &state, StateSecurity &stateSecurity){
    string currentUserName, currentPassword;
    int keyInt, accountPosition, found = 0;
    cout << "\n===============================QUAN LY BAO MAT================================" << endl;
    cout << "_________________________________XOA TAI KHOAN________________________________" << endl;
    if(listAccount.empty()){
        cout << "*****************************CHUA CO TAI KHOAN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN TAI KHOAN";
        cout << "|" << setw(4) << " " << setw(16) << left << "MAT KHAU";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listAccount.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getUserName();
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getPassword();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listAccount[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    cout << "Nhap ten tai khoan: "; cin >> currentUserName;
    for(accountPosition = 0; accountPosition < listAccount.size(); accountPosition++){
        if(listAccount[accountPosition].getUserName() == currentUserName){
            found = 1;
            break;
        }
    }
    if(found == 0){
        cout << "***************************KHONG TIM THAY TAI KHOAN***************************" << endl;
    }
    else{
        listAccount.erase(listAccount.begin()+accountPosition);
        cout << "***************************XOA TAI KHOAN THANH CONG***************************" << endl;
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateSecurity = SECURITY_LOGIN;
    }
}

void securityList(vector <Account> listAccount, State &state, StateSecurity &stateSecurity){
    int keyInt;
    cout << "\n===============================QUAN LY BAO MAT================================" << endl;
    cout << "______________________________DANH SACH TAI KHOAN_____________________________" << endl;
    if(listAccount.empty()){
        cout << "****************************KHONG CO TAI KHOAN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN TAI KHOAN";
        cout << "|" << setw(4) << " " << setw(16) << left << "MAT KHAU";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listAccount.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getUserName();
            cout << "|" << setw(4) << " " << setw(16) << left << listAccount[i].getPassword();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listAccount[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateSecurity = SECURITY_LOGIN;
    }
}

void staffAdd(vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    Staff newStaff;
    string currentName, currentPhoneNumber;
    int keyInt;
    
    cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
    cout << "________________________________THEM NHAN VIEN________________________________" << endl;
    cout << "Nhap ten nhan vien: "; cin >> currentName;
    newStaff.setName(currentName);
    cout << "Nhap so dien thoat: "; cin >> currentPhoneNumber;
    newStaff.setPhoneNumber(currentPhoneNumber);
    do{
        cout << "Chuc vu:\n\t0: MANAGER\n\t1: STAFF\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc vu nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) newStaff.setRole(ROLE_MANAGER);
    else newStaff.setRole(ROLE_STAFF);
    listStaff.push_back(newStaff);
    cout << "**************************THEM NHAN VIEN THANH CONG**************************" << endl;
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateStaff = STAFF_LOGIN;
    }
}

void staffAdjustName(vector <Staff> &listStaff, int accountPosition){
    string currentName;
    cout << "Nhap ten nhan vien: "; cin >> currentName;
    listStaff[accountPosition].setName(currentName);
    cout << "***********************THAY DOI TEN NHAN VIEN THANH CONG**********************" << endl;
}

void staffAdjustPhoneNumber(vector <Staff> &listStaff, int accountPosition){
    string currentPhoneNumber;
    cout << "Nhap so dien thoai: "; cin >> currentPhoneNumber;
    listStaff[accountPosition].setPhoneNumber(currentPhoneNumber);
    cout << "***********************THAY DOI SO DIEN THOAI THANH CONG**********************" << endl;
}

void staffAdjustRole(vector <Staff> &listStaff, int accountPosition){
    int keyInt;
    do{
        cout << "Chon chuc vu:\n\t0: MANAGER\n\t1: STAFF\nNhap lua chon: ";
        cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
            cout << "Khong co chuc vu nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) listStaff[accountPosition].setRole(ROLE_MANAGER);
    else listStaff[accountPosition].setRole(ROLE_STAFF);
    cout << "**************************THAY DOI CHUC VU THANH CONG*************************" << endl;

}

void staffAdjust(vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    string currentName, currentPhoneNumber;
    int keyInt, accountPosition, found = 0;
    cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
    cout << "______________________________CHINH SUA THONG TIN_____________________________" << endl;
    if(listStaff.empty()){
        cout << "*****************************CHUA CO NHAN VIEN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN NHAN VIEN";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listStaff.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getName();
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listStaff[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << "Nhap ten nhan vien: "; cin >> currentName;
        for(accountPosition = 0; accountPosition < listStaff.size(); accountPosition++){
            if(listStaff[accountPosition].getName() == currentName && listStaff[accountPosition].getPhoneNumber() == currentPhoneNumber){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "***************************KHONG TIM THAY TAI KHOAN***************************" << endl;
        }
        else{
            do{
                cout << "\t1: Sua ten tai khoan\n\t2: Sua mat khau\n\t3: Sua chuc vu\nNhap lua chon: ";
                cin >> keyInt;
                if(keyInt < 1 || keyInt > 3)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            }while(keyInt < 1 || keyInt > 3);
            switch (keyInt)
            {
            case 1:
                staffAdjustName(listStaff, accountPosition);
                break;
            case 2:
                staffAdjustPhoneNumber(listStaff, accountPosition);
                break;
            case 3:
                staffAdjustRole(listStaff, accountPosition);
                break;
            default:
                break;
            }
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateStaff = STAFF_LOGIN;
    }
}

void staffDelete(vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    string currentName, currentPhoneNumber;
    int keyInt, accountPosition, found = 0;
    cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
    cout << "_________________________________XOA NHAN VIEN________________________________" << endl;
    if(listStaff.empty()){
        cout << "*****************************CHUA CO TAI KHOAN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN NHAN VIEN";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listStaff.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getName();
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listStaff[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    cout << "Nhap ten tai khoan: "; cin >> currentName;
    for(accountPosition = 0; accountPosition < listStaff.size(); accountPosition++){
        if(listStaff[accountPosition].getName() == currentName && listStaff[accountPosition].getPhoneNumber() == currentPhoneNumber){
            found = 1;
            break;
        }
    }
    if(found == 0){
        cout << "***************************KHONG TIM THAY NHAN VIEN***************************" << endl;
    }
    else{
        listStaff.erase(listStaff.begin()+accountPosition);
        cout << "***************************XOA TAI KHOAN NHAN VIEN***************************" << endl;
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateStaff = STAFF_LOGIN;
    }
}

void staffList(vector <Staff> listStaff, State &state, StateStaff &stateStaff){
    int keyInt;
    cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
    cout << "______________________________DANH SACH NHAN VIEN_____________________________" << endl;
    if(listStaff.empty()){
        cout << "*****************************CHUA CO NHAN VIEN NAO****************************" << endl;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN NHAN VIEN";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listStaff.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getName();
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listStaff[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateStaff = STAFF_LOGIN;
    }
}

void staffManager(vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    int keyInt;
    do{
        cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
        cout << "____________________________________MANAGER___________________________________" << endl;
        cout << "\t1: Them nhan vien\n\t2: Sua thong tin nhan vien\n\t3: Xoa nhan vien\n\t4: Danh sach nhan vien\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 4)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 4);
    switch (keyInt)
    {
    case 0:
        state = MAIN;
        break;
    case 1:
        staffAdd(listStaff, state, stateStaff);
        break;
    case 2:
        staffAdjust(listStaff, state, stateStaff);
        break;
    case 3:
        staffDelete(listStaff, state, stateStaff);
        break;
    case 4:
        staffList(listStaff, state, stateStaff);
        break;
    default:
        break;
    }
}

void staffStaff(vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    string currentName, currentPhoneNumber;
    int found = 0, accountPosition;
    int keyInt;
    char keyChar;
    cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
    cout << "_____________________________________STAFF____________________________________" << endl;
    if(listStaff.empty()){
        cout << "*****************************CHUA CO NHAN VIEN NAO****************************" << endl;
        cout << "Nhan phim bat ky de thoat:..."; cin >> keyChar;
        state = MAIN;
    }
    else{
        cout << "----------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN NHAN VIEN";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(16) << left << "CHUC VU" << "|" << endl;
        cout << "----------------------------------------------------------------" << endl;
        for(int i=0; i<listStaff.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getName();
            cout << "|" << setw(4) << " " << setw(16) << left << listStaff[i].getPhoneNumber();
            cout << "|" << setw(4) << " " << setw(16) << left << ((listStaff[i].getRole()==0) ? "MANAGER" : "STAFF") << "|" << endl;
            cout << "----------------------------------------------------------------" << endl;
        }
        cout << "Nhap ten nhan vien: "; cin >> currentName;
        for(accountPosition = 0; accountPosition < listStaff.size(); accountPosition++){
            if(listStaff[accountPosition].getName() == currentName && listStaff[accountPosition].getPhoneNumber() == currentPhoneNumber){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "***************************KHONG TIM THAY TAI KHOAN***************************" << endl;
        }
        else{
            do{
                cout << "\t1: Sua ten\n\t2: Sua so dien thoai\n\t0: Quay lai" << endl;
                cout << "Nhap lua chon: "; cin >> keyInt;
                if(keyInt < 0 || keyInt > 2)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            }while(keyInt < 0 || keyInt > 2);
            switch (keyInt)
            {
            case 0:
                state = MAIN;
                break;
            case 1:
                staffAdjustName(listStaff, accountPosition);
                do{
                    cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
                    if(keyInt < 0 || keyInt > 1)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
                }while(keyInt < 0 || keyInt > 1);
                if(keyInt == 0) {
                    state = MAIN;
                    stateStaff = STAFF_LOGIN;
                }
                break;
            case 2:
                staffAdjustPhoneNumber(listStaff, accountPosition);
                do{
                    cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
                    if(keyInt < 0 || keyInt > 1)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
                }while(keyInt < 0 || keyInt > 1);
                if(keyInt == 0) {
                    state = MAIN;
                    stateStaff = STAFF_LOGIN;
                }
                break;
            }
        }
    }
}

void serviceAdd(vector <Service> &listService, State &state, StateService &stateService){
    Service newService;
    string currentServiceName;
    long long currentServicePrice;
    int keyInt, found;
    cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
    cout << "__________________________________THEM DICH VU_________________________________" << endl;
    
    do{
        found = 0;
        cout << "Nhap ten dich vu: "; cin >> currentServiceName;
        for(int i=0; i<listService.size(); i++){
            if(listService[i].getNameService() == currentServiceName){
                found = 1;
                break;
            }
        }
        if(found == 1) 
            cout << "**************************TEN DICH VU NAY DA TON TAI**************************" << endl;
    }while(found == 1);
    newService.setNameService(currentServiceName);
    cout << "Nhap so tien: "; cin >> currentServicePrice;
    newService.setPrice(currentServicePrice);
    listService.push_back(newService);
    cout << "***************************THEM DICH VU THANH CONG***************************" << endl;
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateService = SERVICE_LOGIN;
    }
}

void serviceAdjustName(vector <Service> &listService, int servicePosition){
    string currentServiceName;
    cout << "Nhap ten dich vu: "; cin >> currentServiceName;
    listService[servicePosition].setNameService(currentServiceName);
    cout << "************************THAY DOI TEN DICH VU THANH CONG***********************" << endl;
}

void serviceAdjustPrice(vector <Service> &listService, int servicePosition){
    long long currentPrice;
    cout << "Nhap gia dich vu: "; cin >> currentPrice;
    listService[servicePosition].setPrice(currentPrice);
    cout << "*************************THAY DOI GIA TIEN THANH CONG*************************" << endl;
}

void serviceAdjust(vector <Service> &listService, State &state, StateService &stateService){
    string currentServiceName;
    long long currentPrice;
    int keyInt, servicePosition, found = 0;
    cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
    cout << "________________________________CHINH SUA DICH VU______________________________" << endl;
    if(listService.empty()){
        cout << "******************************CHUA CO DICH VU NAO*****************************" << endl;
    }
    else{
        cout << "-------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN DICH VU";
        cout << "|" << setw(4) << " " << setw(16) << left << "GIA" << "|" << endl;
        cout << "-------------------------------------------" << endl;
        for(int i=0; i<listService.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getNameService();
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getPrice() << "|" << endl;
            cout << "-------------------------------------------" << endl;
        }
        cout << "Nhap ten dich vu: "; cin >> currentServiceName;
        for(servicePosition = 0; servicePosition < listService.size(); servicePosition++){
            if(listService[servicePosition].getNameService() == currentServiceName){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "****************************KHONG TIM THAY DICH VU****************************" << endl;
        }
        else{
            do{
                cout << "\t1: Sua ten dich vu\n\t2: Sua gia\nNhap lua chon: ";
                cin >> keyInt;
                if(keyInt < 1 || keyInt > 2)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            }while(keyInt < 1 || keyInt > 2);
            switch (keyInt)
            {
            case 1:
                serviceAdjustName(listService, servicePosition);
                break;
            case 2:
                serviceAdjustPrice(listService, servicePosition);
                break;
            default:
                break;
            }
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateService = SERVICE_LOGIN;
    }
}

void serviceDelete(vector <Service> &listService, State &state, StateService &stateService){
    string currentServiceName;
    long long currentPrice;
    int keyInt, servicePosition, found = 0;
    cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
    cout << "___________________________________XOA DICH VU___________________________________" << endl;
    if(listService.empty()){
        cout << "******************************CHUA CO DICH VU NAO*****************************" << endl;
    }
    else{
        cout << "-------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN DICH VU";
        cout << "|" << setw(4) << " " << setw(16) << left << "GIA" << "|" << endl;
        cout << "-------------------------------------------" << endl;
        for(int i=0; i<listService.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getNameService();
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getPrice() << "|" << endl;
            cout << "-------------------------------------------" << endl;
        }
        cout << "Nhap ten dich vu: "; cin >> currentServiceName;
        for(servicePosition = 0; servicePosition < listService.size(); servicePosition++){
            if(listService[servicePosition].getNameService() == currentServiceName){
                found = 1;
                break;
            }
        }
        if(found == 0){
            cout << "****************************KHONG TIM THAY DICH VU****************************" << endl;
        }
        else{
            listService.erase(listService.begin() + servicePosition);
            cout << "****************************XOA DICH VU THANH CONG****************************" << endl;
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateService = SERVICE_LOGIN;
    }
}

void serviceList(vector <Service> listService, State &state, StateService &stateService){
    int keyInt;
    cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
    cout << "________________________________DANH SACH DICH VU______________________________" << endl;
    if(listService.empty()){
        cout << "******************************CHUA CO DICH VU NAO*****************************" << endl;
    }
    else{
        cout << "-------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN DICH VU";
        cout << "|" << setw(4) << " " << setw(16) << left << "GIA" << "|" << endl;
        cout << "-------------------------------------------" << endl;
        for(int i=0; i<listService.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getNameService();
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getPrice() << "|" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    do{
        cout << "\t1: Tiep tuc\n\t0: Quay lai\nNhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 1)
        cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 1);
    if(keyInt == 0) {
        state = MAIN;
        stateService = SERVICE_LOGIN;
    }
}

void serviceManager(vector <Service> &listService, State &state, StateService &stateService){
    string currentName, currentPhoneNumber;
    int found = 0, accountPosition;
    int keyInt;
    char keyChar;
    cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
    if(listService.empty()){
        cout << "******************************CHUA CO DICH VU NAO******************************" << endl;
        cout << "Chon chuc nang: " << endl;
    }
    else{
        cout << "-------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(16) << left << "TEN DICH VU";
        cout << "|" << setw(4) << " " << setw(16) << left << "GIA" << "|" << endl;
        cout << "-------------------------------------------" << endl;
        for(int i=0; i<listService.size(); i++){
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getNameService();
            cout << "|" << setw(4) << " " << setw(16) << left << listService[i].getPrice() << "|" << endl;
            cout << "-------------------------------------------" << endl;
        }
    }
    do{
        cout << "\t1: Them dich vu\n\t2: Sua dich vu\n\t3: Xoa dich vu\n\t4: Danh sach dich vu\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 4)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    }while(keyInt < 0 || keyInt > 4);
    //---------------------------------------------------------
    switch (keyInt)
    {
    case 0:
        state = MAIN;
        stateService = SERVICE_LOGIN;
        break;
    case 1:
        serviceAdd(listService, state, stateService);
        break;
    case 2:
        serviceAdjust(listService, state, stateService);
        break;
    case 3:
        serviceDelete(listService, state, stateService);
        break;
    case 4:
        serviceList(listService, state, stateService);
        break;
    }
}

//========================================FUNCTION========================================
void mainScreen(State &state){
    uint32_t keyInt;
    do{
        cout << "\n====================================MAIN======================================" << endl;
        cout << "Chon che do:\n\t1: Quan ly dat phong\n\t2: Quan ly khach hang\n\t3: Quan ly nhan vien\n\t4: Quan ly dich vu va tien ich\n\t5: Quan ly thanh toan\n\t6: Bao mat va quyen truy cap\n\t7: Bao cao va thong ke\n\t8: Tuong tac khac hang" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 1 || keyInt > 8)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    } while(keyInt < 1 || keyInt > 8);
    switch (keyInt)
    {
    case 1:
        state = BOOKING;
        break;
    case 2:
        state = CUSTOMER;
        break;
    case 3:
        state = STAFF;
        break;
    case 4:
        state = SERVICE;
        break;
    case 5:
        state = PAYMENT;
        break;
    case 6:
        state = SECURITY;
        break;
    case 7:
        state = REPORT;
        break;
    case 8:
        state = INTERACT;
        break;
    default:
        cout << "KHONG CO CHUC NANG NAY (FUNCTION MAIN)" << endl;
        break;
    }
}

void bookingScreen(State &state, uint32_t numberOfRoom, vector <Room> &listRoom, vector <Customer> &listCustomer){
    char keyChar;
    uint32_t roomNumber;
    uint32_t keyInt;
    string keyString;
    Customer newCustomer;
    DetailBooking detailBooking;
    do{
        cout << "\n==============================QUAN LY DAT PHONG===============================" << endl;
        displayListRoom(listRoom, numberOfRoom);
        cout << "Chon so phong (0: Quay lai): "; cin >> keyInt;
        if(keyInt < 0 || keyInt > numberOfRoom)
            cout << "Khong co phong nay\nVui long nhap lai" << endl;
        if(listRoom[keyInt].getStatus() == true)
            cout << "Phong nay da duoc dat\nVui long chon phong khac" << endl;
    } while(keyInt < 0 || keyInt > numberOfRoom || listRoom[keyInt].getStatus() == true);
    roomNumber = keyInt;
    if(keyInt == 0) state = MAIN;
    else{
        //--------------------------------------------------------------------------------------------------
        cout << "\n==============================QUAN LY DAT PHONG===============================" << endl;
        cout << "Nhap ten: ", cin >> keyString;
        newCustomer.setName(keyString);
        cout << "Nhap dia chi: ", cin >> keyString;
        newCustomer.setAddress(keyString);
        cout << "Nhap sdt: ", cin >> keyString;
        newCustomer.setPhoneNumber(keyString);
        newCustomer.setIdRoom(roomNumber, listRoom);
        cout << "Nhap thoi gian check-in:" << endl;
        inputDetailBooking(detailBooking);
        newCustomer.setBookingHistory(detailBooking);
        listCustomer.push_back(newCustomer);
        //--------------------------------------------------------------------------------------------------
        cout << "*****************************DAT PHONG THANH CONG*****************************" << endl;
        state = MAIN;
        listRoom[roomNumber].bookRoom();
        cout << "Nhan phim bat ky de quay lai:... "; cin >> keyChar;
    }
}

void customerManager(vector <Customer> &listCustomer, vector <Room> &listRoom, State &state, uint32_t numberOfRoom){
    //dang nhap tk (Manager or Staff)
    int keyInt;
    char keyChar;
    do{
        cout << "\n==============================QUAN LY KHACH HANG==============================" << endl;
        //danh sach khach hang
        cout << "\t1: Them thong tin khach hang\n\t2: Sua thong tin khach hang\n\t3: Xoa thong tin khach hang\n\t4: Danh sach khach hang\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: "; cin >> keyInt;
        if(keyInt < 0 || keyInt > 4)
            cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
    } while(keyInt < 0 || keyInt > 4);
    switch (keyInt)
    {
        case 0:
            state = MAIN;
            break;
        case 1:
            customerAdd(listCustomer, listRoom, state);
            break;
        case 2:
            customerAdjust(listCustomer, listRoom, state, numberOfRoom);
            break;
        case 3:
            customerErase(listCustomer, listRoom, state, numberOfRoom);
            break;
        case 4:
            customerList(listCustomer, state, numberOfRoom);
            break;
    }
}

void staff(vector <Account> &listAccount, vector <Staff> &listStaff, State &state, StateStaff &stateStaff){
    string currentUserName, currentPassword;
    int found, accountPosition;
    char keyChar;
    switch (stateStaff)
    {
        case STAFF_LOGIN:
            cout << "\n==============================QUAN LY NHAN VIEN===============================" << endl;
            loginAccount(listAccount, found, accountPosition);
            if(found == 2)
                stateStaff = STAFF_DONE;
            else{
                cout << "Nhan phim bat ky de thoat:..."; cin >> keyChar;
                state = MAIN;
            }
            break;
        case STAFF_DONE:
            if(listAccount[accountPosition].getRole() == ROLE_MANAGER)
                staffManager(listStaff, state, stateStaff);
            else
                staffStaff(listStaff, state, stateStaff);
            break;
    }
}

void service(vector <Account> &listAccount, vector <Service> &listService, State &state, StateService &stateService){
    string currentUserName, currentPassword;
    int found, accountPosition;
    char keyChar;
    switch (stateService)
    {
        case SERVICE_LOGIN:
            cout << "\n==============================DICH VU VA TIEN ICH==============================" << endl;
            loginAccount(listAccount, found, accountPosition);
            if(found == 2){
                stateService = SERVICE_DONE;
            }
            else{
                cout << "Nhan phim bat ky de thoat:..."; cin >> keyChar;
                state = MAIN;
            }
            break;
        case SERVICE_DONE:
            if(listAccount[accountPosition].getRole() == ROLE_STAFF){
                cout << "*************************STAFF KHONG CO QUYEN TRUY CAP************************" << endl;
                state = MAIN;
                stateService = SERVICE_LOGIN;
                cout << "Nhan phim bat ky de tiep tuc:..."; 
                cin >> keyChar;
            }
            else{
                serviceManager(listService, state, stateService);
            }
            break;
    }
}

void security(vector <Account> &listAccount, State &state, StateSecurity &stateSecurity){
    string currentUserName, currentPassword;
    int found = 0, accountPosition;
    int keyInt;
    char keyChar;
    switch (stateSecurity)
    {
        case SECURITY_LOGIN:
            cout << "\n===============================QUAN LY BAO MAT================================" << endl;
            loginAccount(listAccount, found, accountPosition);
            if(found == 2){
                if(listAccount[accountPosition].getRole() == ROLE_STAFF){
                    cout << "*************************STAFF KHONG CO QUYEN TRUY CAP************************" << endl;
                    cout << "Nhan phim bat ky de tiep tuc:..."; cin >> keyChar;
                    state = MAIN;
                }
                else{
                    stateSecurity = SECURITY_DONE;
                }
            }
            else{
                cout << "Nhan phim bat ky de tiep tuc:..."; cin >> keyChar;
                state = MAIN;
            }
            break;
        case SECURITY_DONE:
            do{
                cout << "\n===============================QUAN LY BAO MAT================================" << endl;
                cout << "\t1: Them tai khoan\n\t2: Sua tai khoan\n\t3: Xoa tai khoan\n\t4: Danh sach tai khoan\n\t0: Quay lai" << endl;
                cout << "Nhap lua chon: "; cin >> keyInt;
                if(keyInt < 0 || keyInt > 4)
                    cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
            }while(keyInt < 0 || keyInt > 4);
            switch (keyInt)
            {
            case 0:
                state = MAIN;
                stateSecurity = SECURITY_LOGIN;
                break;
            case 1:
                securityAdd(listAccount, state, stateSecurity);
                break;
            case 2:
                securityAdjust(listAccount, state, stateSecurity);
                break;
            case 3:
                securityDelete(listAccount, state, stateSecurity);
                break;
            case 4:
                securityList(listAccount, state, stateSecurity);
                break;
            default:
                break;
            }
            break;
    }
}

void payment(vector <Customer> &listCustomer, vector <Room> &listRoom, State &state, int numberOfRoom, int priceDay, int priceHour){
    char keyChar;
    int roomNumber, customerPosition, keyInt;
    int hour, minute, second, day, month, year;
    int hour1, minute1, second1, day1, month1, year1;
    DetailBooking detailBooking;
    StayTime stayTime;
    stayTime.time.second = 1;
    stayTime.time.minute = stayTime.time.hour = stayTime.day = 0;

    if(listCustomer.empty()){
        cout << "****************************CHUA CO KHACH HANG NAO****************************" << endl;
        state = MAIN;
        cout << "Nhan phim bat ky de quai lai:..."; cin >> keyChar;
    }
    else{
        do{
            cout << "\n==============================QUAN LY THANH TOAN==============================" << endl;
            displayListRoom(listRoom, numberOfRoom);
            cout << "Nhap so phong: "; cin >> roomNumber;
            if(roomNumber < 0 || roomNumber > numberOfRoom)
                cout << "Khong co phong nay\nVui long nhap lai" << endl;
            if(listRoom[roomNumber].getStatus() == false)
                cout << "Phong nay khong co khach o\nVui long nhap lai" << endl;
        }while(roomNumber < 0 || roomNumber > numberOfRoom || listRoom[roomNumber].getStatus() == false);
        for(customerPosition=0; customerPosition<listCustomer.size(); customerPosition++){
            if(listCustomer[customerPosition].getIdRoom() == roomNumber)
                break;
        }
        cout << "Nhap thoi gian check-out:" << endl;
        inputDetailBooking(detailBooking);
        listCustomer[customerPosition].setBookingHistory(detailBooking);
        cout << "______________________________THONG TIN KHACH HANG____________________________" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(18) << left << "TEN KHACH HANG";
        cout << "|" << setw(4) << " " << setw(11) << left << "DIA CHI";
        cout << "|" << setw(4) << " " << setw(16) << left << "SO DIEN THOAI";
        cout << "|" << setw(4) << " " << setw(12) << left << "SO PHONG";
        cout << "|" << setw(4) << " " << setw(22) << left << "THOI GIAN CHECK IN";
        cout << "|" << setw(4) << " " << setw(22) << left << "THOI GIAN CHECK OUT" << "|" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        cout << "|" << setw(4) << " " << setw(18) << left << listCustomer[customerPosition].getName();
        cout << "|" << setw(4) << " " << setw(11) << left << listCustomer[customerPosition].getAddress();
        cout << "|" << setw(4) << " " << setw(16) << left << listCustomer[customerPosition].getPhoneNumber();
        cout << "|" << setw(4) << " " << setw(12) << left << listCustomer[customerPosition].getIdRoom();
        for(int i=0; i<(listCustomer[customerPosition].getBookingHistory()).size(); i++){
            cout << "|" << setw(4) << " " << setw(40) 
            << "Time: " << (listCustomer[customerPosition].getBookingHistory())[i].time.hour << "h" << (listCustomer[customerPosition].getBookingHistory())[i].time.minute << "m" << (listCustomer[customerPosition].getBookingHistory())[i].time.second << "s" 
            << "; Date: " << (listCustomer[customerPosition].getBookingHistory())[i].date.day << "/" << (listCustomer[customerPosition].getBookingHistory())[i].date.month << "/" << (listCustomer[customerPosition].getBookingHistory())[i].date.year << "|" << endl;
        }
        cout << "-------------------------------------------------------------------------------------------------------------------" << endl;
        
        hour = listCustomer[customerPosition].getBookingHistory()[0].time.hour;
        minute = (listCustomer[customerPosition].getBookingHistory())[0].time.minute;
        second = (listCustomer[customerPosition].getBookingHistory())[0].time.second;
        day = (listCustomer[customerPosition].getBookingHistory())[0].date.day;
        month = (listCustomer[customerPosition].getBookingHistory())[0].date.month;
        year = (listCustomer[customerPosition].getBookingHistory())[0].date.year;

        hour1 = listCustomer[customerPosition].getBookingHistory()[1].time.hour;
        minute1 = (listCustomer[customerPosition].getBookingHistory())[1].time.minute;
        second1 = (listCustomer[customerPosition].getBookingHistory())[1].time.second;
        day1 = (listCustomer[customerPosition].getBookingHistory())[1].date.day;
        month1 = (listCustomer[customerPosition].getBookingHistory())[1].date.month;
        year1 = (listCustomer[customerPosition].getBookingHistory())[1].date.year;

        while(1){
                    cout << second << endl;
            second++;
            if(second == 60){
                second = 0;
                minute++;
            }
            if(minute == 60){
                minute = 0;
                hour++;
            }
            if(hour == 24){
                hour = 0;
                day++;
            }
            if(day == 31){
                day = 1;
                month++;
            }
            if(month == 13){
                month = 1;
                year++;
            }
            //------------------------------
            stayTime.time.second++;
            if(stayTime.time.second == 60){
                stayTime.time.second = 0;
                stayTime.time.minute++;
            }
            if(stayTime.time.minute == 60){
                stayTime.time.minute = 0;
                stayTime.time.hour++;
            }
            if(stayTime.time.hour == 24){
                stayTime.time.hour = 0;
                stayTime.day++;

            if(second == second1 && minute == minute1 && hour == hour1 && day == day1 && month == month1 && year == year1)
                break;
            }
        }
        cout << "Thoi gian o: " << stayTime.day << " ngay, " << stayTime.time.hour << " tieng, " << stayTime.time.minute << " phut" << endl;
        cout << "Gia tien/ngay: " << priceDay <<endl;
        cout << "Gia tien/gio: " << priceHour <<endl;
        cout << "So tien can thanh toan: " << stayTime.day*priceDay + stayTime.time.hour*priceHour << endl;
        do{
            cout << "Chon phuong thuc thanh toan\n\t1: Tien mat\n\t2: The tin dung\n\t3: Vi dien tu\n\t4: Internet Banking\n\t0: Quay lai" << endl;
            cout << "Nhap lua chon: "; cin >> keyInt;
            if(keyInt < 0 || keyInt > 4)
                cout << "Khong co chuc nang nay\nVui long nhap lai" << endl;
        }while(keyInt < 0 || keyInt > 4);
        switch (keyInt)
        {
        case 0:
            state = MAIN;
            break;
        case 1:
            cout << "Thanh toan bang tien mat thanh cong" << endl;
            listRoom[listCustomer[customerPosition].getIdRoom()].checkOut();
            listCustomer.erase(listCustomer.begin()+customerPosition);
            state = MAIN;
            break;
        case 2:
            cout << "Thanh toan bang the tin dung thanh cong" << endl;
            listRoom[listCustomer[customerPosition].getIdRoom()].checkOut();
            listCustomer.erase(listCustomer.begin()+customerPosition);
            state = MAIN;
            break;
        case 3:
            cout << "Thanh toan bang vi dien tu thanh cong" << endl;
            listRoom[listCustomer[customerPosition].getIdRoom()].checkOut();
            listCustomer.erase(listCustomer.begin()+customerPosition);
            state = MAIN;
            break;
        case 4:
            cout << "Thanh toan bang Internet Banking thanh cong" << endl;
            listRoom[listCustomer[customerPosition].getIdRoom()].checkOut();
            listCustomer.erase(listCustomer.begin()+customerPosition);
            state = MAIN;
            break;
        }
    }
}

//==========================================MAIN==========================================
int main(){
    uint32_t numberOfRoom = 10;

    State state = MAIN;
    StateSecurity stateSecurity = SECURITY_LOGIN;
    StateStaff stateStaff = STAFF_LOGIN;
    StateService stateService = SERVICE_LOGIN;
    
    vector <Room> listRoom;

    vector <Customer> listCustomer;
    vector <Staff> listStaff;
    vector <Service> listService;

    vector <Account> listAccount;
    Account account;
    account.setUserName("123");
    account.setPassword("123");
    account.setRole(ROLE_MANAGER);
    listAccount.push_back(account);

    account.setUserName("111");
    account.setPassword("111");
    account.setRole(ROLE_STAFF);
    listAccount.push_back(account);

    int priceDay = 200, priceHour = 20;

    setListRoom(listRoom, numberOfRoom);

    while(1){
        switch (state)
        {
        case MAIN:
            mainScreen(state);
            break;
        case BOOKING:
            bookingScreen(state, numberOfRoom, listRoom, listCustomer);
            break;
        case CUSTOMER:
            customerManager(listCustomer, listRoom, state, numberOfRoom);
            break;
        case STAFF:
            staff(listAccount, listStaff, state, stateStaff);
            break;
        case SERVICE:
            service(listAccount, listService, state, stateService);
            break;
        case PAYMENT:
            payment(listCustomer, listRoom, state, numberOfRoom, priceDay, priceHour);
            break;
        case SECURITY:
            security(listAccount, state, stateSecurity);
            break;
        case REPORT:
            cout << "REPORT" << endl;
            state = MAIN;
            break;
        case INTERACT:
            cout << "INTERACT" << endl;
            state = MAIN;
            break;
        default:
            cout << "KHONG CO CHUC NANG NAY (MAIN)" << endl;
            break;
        }
    }
}