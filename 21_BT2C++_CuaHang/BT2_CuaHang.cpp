#include <iostream>
#include <string>
#include <vector>
#include <iomanip>

using namespace std;

typedef enum{MAIN, MANAGER, MANAGER_SET_TABLE, MANAGER_ADD, MANAGER_ADJUST, MANAGER_DELETE, MANAGER_MENU,
             STAFF, STAFF_TABLE, STAFF_ADD, STAFF_ADJUST, STAFF_DELETE, STAFF_ODERED, STAFF_PAYMENT} State;

//      MANAGER
//tạo menu - menu gồm nhiều món ăn
//món ăn gồm: ID, tên, giá
//món ăn -> class
//menu -> vector <món ăn>

//=====================================CLASS FOOD====================================
class Food{
    protected:
        int id;
        string name;
        long long price;
    public:
        Food();
        //---------SET--------
        void setName(string);
        void setPrice(long long);
        //---------GET--------
        int getId();
        string getName();
        long long getPrice();
};
//-----------------------CONSTRUCTOR--------------------
Food::Food(){
    static int ID = 100;
    ID++;
    id = ID;
}
//--------------------------SET-----------------------
void Food::setName(string name){
    this->name = name;
}
void Food::setPrice(long long price){
    this->price = price;
}
//--------------------------GET-----------------------
int Food::getId(){
    return this->id;
}
string Food::getName(){
    return this->name;
}
long long Food::getPrice(){
    return this->price;
}
//=====================================CLASS FOOD ON TABLE====================================
class FoodOnTable : public Food{
    private:
        int quantity;
    public:
        void pushValue(Food food);
        void setQuantity(int quantity);
        int getQuantity();
};
void FoodOnTable::pushValue(Food food){
    this->id = food.getId(); 
    this->name = food.getName();
    this->price = food.getPrice();
}
void FoodOnTable::setQuantity(int quantity){
    this->quantity = quantity;
}
int FoodOnTable::getQuantity(){
    return this->quantity;
}
//=====================================SUPPORT FUNCTION====================================
void displayHeaderFood(){
    cout << "--------------------------------------------------------" << endl;
    cout << "|" << setw(4) << " " << setw(8)  << left << "ID";
    cout << "|" << setw(4) << " " << setw(16) << left << "NAME";
    cout << "|" << setw(4) << " " << setw(16)  << left << "PRICE" << "|" << endl;
    cout << "--------------------------------------------------------" << endl;
}
void displayOneFood(Food food){
    cout << "|" << setw(4) << " " << setw(8)  << left << food.getId();
    cout << "|" << setw(4) << " " << setw(16) << left << food.getName();
    cout << "|" << setw(4) << " " << setw(16)  << left << food.getPrice() << "|" << endl;
    cout << "--------------------------------------------------------" << endl;
}
void displayMenu(vector <Food> menu){
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
    }
    else{
        cout << "\n====================================MENU===================================" << endl;
        displayHeaderFood();
        for(int i=0; i<menu.size(); i++){
            displayOneFood(menu[i]);
        }
    }
}

void displayHeaderFoodTable(){
    cout << "---------------------------------------------------------------------------" << endl;
    cout << "|" << setw(4) << " " << setw(8)  << left << "ID";
    cout << "|" << setw(4) << " " << setw(16) << left << "NAME";
    cout << "|" << setw(4) << " " << setw(14)  << left << "QUANTITY";
    cout << "|" << setw(4) << " " << setw(16)  << left << "PRICE" << "|" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}
void displayOneFoodTable(FoodOnTable foodOnTable){
    cout << "|" << setw(4) << " " << setw(8)  << left << foodOnTable.getId();
    cout << "|" << setw(4) << " " << setw(16) << left << foodOnTable.getName();
    cout << "|" << setw(4) << " " << setw(14)  << left << foodOnTable.getQuantity();
    cout << "|" << setw(4) << " " << setw(16)  << left << foodOnTable.getPrice() << "|" << endl;
    cout << "---------------------------------------------------------------------------" << endl;
}
void displayFoodTable(vector <FoodOnTable> table){
    if(table.empty())
        cout << "BAN CHUA GOI MON" << endl;
    else{
        displayHeaderFoodTable();
        for(int i=0; i<table.size(); i++)
            displayOneFoodTable(table[i]);
    }
}

void displayHeaderFoodPayment(){
    cout << "------------------------------------------------------------------------------------------------" << endl;
    cout << "|" << setw(4) << " " << setw(8)  << left << "ID";
    cout << "|" << setw(4) << " " << setw(16) << left << "NAME";
    cout << "|" << setw(4) << " " << setw(14)  << left << "QUANTITY";
    cout << "|" << setw(4) << " " << setw(16)  << left << "PRICE";
    cout << "|" << setw(4) << " " << setw(16)  << left << "SUM" << "|" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
}
void displayOneFoodPayment(FoodOnTable foodOnTable){
    cout << "|" << setw(4) << " " << setw(8)  << left << foodOnTable.getId();
    cout << "|" << setw(4) << " " << setw(16) << left << foodOnTable.getName();
    cout << "|" << setw(4) << " " << setw(14)  << left << foodOnTable.getQuantity();
    cout << "|" << setw(4) << " " << setw(16)  << left << foodOnTable.getPrice();
    cout << "|" << setw(4) << " " << setw(16)  << left << foodOnTable.getPrice()*foodOnTable.getQuantity() << "|" << endl;
    cout << "------------------------------------------------------------------------------------------------" << endl;
}
void displayPayment(vector <FoodOnTable> table){
    if(table.empty())
        cout << "BAN CHUA GOI MON" << endl;
    else{
        displayHeaderFoodPayment();
        for(int i=0; i<table.size(); i++)
            displayOneFoodPayment(table[i]);
    }
}
//========================================FUNCTION========================================
void displayMain(State& state){
    int keyInt;
    do{
        cout << "\n====================================MAIN====================================" << endl;
        cout << "Chon vai tro:\n\t1: Manager\n\t2: Staff" << endl;
        cout << "Nhap lua chon: ";
        cin >> keyInt;
        if(keyInt != 1 && keyInt != 2) 
            cout << "Khong co chuc nang nay!\nVui long nhap 1 hoac 2" << endl;
    }while(keyInt != 1 && keyInt != 2);
    if(keyInt == 1)    state = MANAGER;
    else            state = STAFF;
}

//==================MANAGER===================
void displayManager(State& state){
    int keyInt;
    do{
        cout << "\n===================================MANAGER=================================" << endl;
        cout << "Chon chuc nang:\n\t1: Set so ban\n\t2: Them mon vao Menu\n\t3: Sua mon\n\t4: Xoa mon\n\t5: Danh sach mon\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: ";
        cin >> keyInt;
        if(keyInt < 0 || keyInt > 5) 
            cout << "Khong co chuc nang nay!\nVui long nhap tu 0 den 5" << endl;
    }while(keyInt < 0 || keyInt > 5);
    switch (keyInt)
    {
    case 1:
        state = MANAGER_SET_TABLE;
        break;
    case 2:
        state = MANAGER_ADD;
        break;
    case 3:
        state = MANAGER_ADJUST;
        break;
    case 4:
        state = MANAGER_DELETE;
        break;
    case 5:
        state = MANAGER_MENU;
        break;
    case 0:
        state = MAIN;
        break;
    default:
        cout << "MANAGER khong co chuc nang nay" << endl;
        break;
    }
}

void displayManagerSetTable(State& state, int& numOfTable){   
    do{
        cout << "\n========================MANAGER CHOOSE NUMBER OF TABLE=====================" << endl;
        cout << "Nhap so luong ban: ";
        cin >> numOfTable;
        if(numOfTable < 0) 
            cout << "SO LUONG BAN KHONG THE LA SO AM" << endl;
        if(numOfTable > 40){
            cout << "SO LUONG BAN QUA LON" << endl;
            cout << "SO LUONG BAN PHAI NHO HON 40" << endl;
        }
    }while(numOfTable < 0 || numOfTable > 40);
    cout << "So luong ban da duoc cai dat la: " << numOfTable << endl;
    state = MANAGER;
}

void displayManagerAddFood(State& state, vector <Food>& menu){
    string name;
    long long price;
    cout << "\n==============================MANAGER ADD FOOD=============================" << endl;  
    cout << "Nhap ten: ";
    cin.ignore();
    getline(cin, name);
    cout << "Nhap gia: ";
    cin >> price;
    Food food;
    food.setName(name);
    food.setPrice(price);
    menu.push_back(food);

    char keyChar;
    cout << "\n=========================MANAGER ADD FOOD SUCCESSFUL=======================" << endl;
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MAIN;
    }
    else{
        int keyInt;
        displayMenu(menu);
        do{
            cout << "\n1: Tiep tuc them\n0: Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> keyInt;
            if(keyInt != 1 && keyInt != 0)
                cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
        }while(keyInt != 1 && keyInt != 0);
        if(keyInt == 0)
            state = MANAGER;
        else
            displayManagerAddFood(state, menu);
    }
}

void displayManagerAdjust(State& state, vector <Food>& menu){
    char keyChar;
    int found = 0;
    cout << "\n============================MANAGER ADJUST FOOD============================" << endl;
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MAIN;
    }
    else{
        displayMenu(menu);
        int currentId;
        cout << "\nNhap vao ID mon an can sua: ";
        cin >> currentId;
        for(int i=0; i<menu.size(); i++){
            if(menu[i].getId() == currentId){
                found = 1;
                int keyInt;
                do{
                    cout << "\t1: Sua ten" <<endl;
                    cout << "\t2: Sua gia" <<endl;
                    cout << "\t0: Quay lai" <<endl;
                    cout << "Nhap lua chon: ";
                    cin >> keyInt;
                    if(keyInt < 0 || keyInt > 2)
                        cout << "Khong co chuc nang nay!\nVui long chon 1,2 hoac 0" << endl;
                }while(keyInt < 0 || keyInt > 2);
                if(keyInt == 0){
                    state = MANAGER;
                    return;
                }
                else if (keyInt == 1){
                    string name;
                    cout << "Nhap ten moi: ";
                    cin.ignore();
                    getline(cin, name);
                    menu[i].setName(name);
                    cout << "***Cap nhat ten moi thanh cong***" << endl;
                }
                else{
                    long long price;
                    cout << "Nhap gia moi: ";
                    cin >> price;
                    menu[i].setPrice(price);
                    cout << "***Cap nhat gia moi thanh cong***" << endl;
                }
            }
        }
        if(found == 0){
            cout << "KHONG TIM THAY ID NAY" << endl;
            state = STAFF_TABLE;
        } 
        else{
            int keyInt;
            cout << "\n___Menu sau khi sua thong tin___" << endl;
            displayMenu(menu);
            do{
                cout << "\t1: Tiep tuc sua" <<endl;
                cout << "\t0: Quay lai" <<endl;
                cout << "Nhap lua chon: ";
                cin >> keyInt;
                if(keyInt < 0 || keyInt > 1)
                    cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
            }while(keyInt < 0 || keyInt > 1);
            if(keyInt == 0)
                state = MANAGER;
            else
                displayManagerAdjust(state, menu);
        }
    }
}

void displayManagerDelete(State& state, vector <Food>& menu){
    char keyChar;
    cout << "\n===============================MANAGER DELETE==============================" << endl;
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MAIN;
    }
    else{
        displayMenu(menu);
        int currentId;
        cout << "\nNhap vao ID mon an can xoa: ";
        cin >> currentId;
        for(int i=0; i<menu.size(); i++){
            if(menu[i].getId() == currentId){
                menu.erase(menu.begin()+i);
                break;
            }
        }
        cout << "XOA MON THANH CONG" << endl;
        displayMenu(menu);
        int keyInt;
        do{
            cout << "\t1: Tiep tuc xoa" <<endl;
            cout << "\t0: Quay lai" <<endl;
            cout << "Nhap lua chon: ";
            cin >> keyInt;
            if(keyInt < 0 || keyInt > 1)
                cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
        }while(keyInt < 0 || keyInt > 1);
        if(keyInt == 0)
            state = MANAGER;
        else
            displayManagerDelete(state, menu);
    }
}

void displayManagerMenu(State& state, vector <Food>& menu){
    char keyChar;
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MAIN;
    }
    else{
        displayMenu(menu);
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MANAGER;
    }
}

//==================STAFF===================
void displayStaff(State& state, vector <char>& status, int numOfTable, int& tableNumber){
    cout << "\n====================================STAFF==================================" << endl;
    if(numOfTable){
        cout << "________________________________DANH SACH BAN______________________________" << endl;
        cout << "So ban |";
        for(int i=1; i<=numOfTable; i++){
            cout << " " << setw(2) << left << i << " |";
        }
        cout << endl;
        for(int i=0; i<=numOfTable; i++){
            status.push_back('O');
        }
        cout << "Status |";
        for(int i=1; i<=numOfTable; i++){
            cout << " " << setw(2) << left << status[i] << " |";
        }
        cout << endl;
        do{
            cout << "\nNhap so ban (0: Quay lai): ";
            cin >> tableNumber;
            if(tableNumber < 0)
                cout << "So ban khong the am" <<endl;
            if(tableNumber > numOfTable)
                cout << "So ban khong the lon hon tong so ban" <<endl;
        }while(tableNumber < 0 || tableNumber > numOfTable);
        if(tableNumber == 0) state = MAIN;
        else{
            state = STAFF_TABLE;
        }
    }
    else{
        char keyChar;
        cout << "CHUA NHAP SO BAN" << endl;
        cout << "Nhap phim bat ky de tiep tuc...";
        cin >> keyChar;
        state = MAIN;
    }
}

void displayStaffTable(State& state, int tableNumber){
    int keyInt = 0;
    do{
        cout << "\n=============================STAFF CHOOSE FUNCTION=========================" << endl;
        cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
        cout << "Chon chuc nang:\n\t1: Goi mon\n\t2: Sua mon\n\t3: Xoa mon\n\t4: Danh sach mon da goi\n\t5: Thanh toan\n\t0: Quay lai" << endl;
        cout << "Nhap lua chon: ";
        cin.ignore();
        cin >> keyInt;
        if(keyInt < 0 || keyInt > 5) 
            cout << "Khong co chuc nang nay!\nVui long nhap tu 0 den 5" << endl;
    }while(keyInt < 0 || keyInt > 5);
    switch (keyInt)
    {
    case 1:
        state = STAFF_ADD;
        break;
    case 2:
        state = STAFF_ADJUST;
        break;
    case 3:
        state = STAFF_DELETE;
        break;
    case 4:
        state = STAFF_ODERED;
        break;
    case 5:
        state = STAFF_PAYMENT;
        break;
    case 0:
        state = STAFF;
        break;
    default:
        cout << "STAFF khong co chuc nang nay" << endl;
        break;
    }
}

void displayStaffAdd(State& state, vector <char>& status, vector <Food> menu, vector <vector <FoodOnTable>>& listTable, int tableNumber){
    char keyChar;
    if(menu.empty()){
        cout << "CHUA NHAP MENU" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = MAIN;
    }
    else{
        int currentId, totalQuantity, currentQuantity, found = 0;
        FoodOnTable foodOnTable;
        cout << "\n===============================STAFF ADD FOOD==============================" << endl;
        cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
        displayMenu(menu);
        cout << "Nhap ID mon an: ";
        cin >> currentId;
        cout << "Nhap so luong: "; 
        cin >> currentQuantity;
        //Buoc 1:
        for(int i=0; i<listTable[tableNumber].size(); i++){
            if(listTable[tableNumber][i].getId() == currentId){
                totalQuantity = listTable[tableNumber][i].getQuantity() + currentQuantity;
                listTable[tableNumber][i].setQuantity(totalQuantity);
                found = 1;
                break;
            }
        }
        if(found == 0){
            for(int i=0; i<menu.size(); i++){
                if(menu[i].getId() == currentId){
                    foodOnTable.setQuantity(currentQuantity);
                    foodOnTable.pushValue(menu[i]);
                    listTable[tableNumber].push_back(foodOnTable);
                    found = 1;
                    cout << "THEM MON THANH CONG" << endl;
                    break;
                }
            }   
        }
        if(found == 0){
            cout << "Khong tim thay ID nay" << endl;
            state = STAFF_TABLE;
            return;
        }
        //------------------------------------------------------------------------------------
        int keyInt;
        do{
            cout << "\n===========================STAFF ADD FOOD==============================" << endl;
            cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
            cout << "\n_____________MON DA THEM____________" << endl;
            displayFoodTable(listTable[tableNumber]);
            cout << "1: Tiep tuc goi mon\n2: Gui danh sach mon da goi\n0: Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> keyInt;
            if(keyInt < 0 || keyInt > 2) 
                cout << "Khong co chuc nang nay!\nVui long nhap tu 0 den 2" << endl;
        }while(keyInt < 0 || keyInt > 2);
        if(keyInt == 0)
            state = STAFF_TABLE;
        else if(keyInt == 1)
            displayStaffAdd(state, status, menu, listTable, tableNumber);
        else{
            char keyChar;
            status[tableNumber] = 'X';
            cout << "GUI DANH SACH MON THANH CONG" << endl;
            cout << "Nhan phim bat ky de tiep tuc:...";
            cin >> keyChar;
            state = STAFF_TABLE;
        }        
    }
}

void displayStaffAdjust(State& state, vector <vector <FoodOnTable>>& listTable, int tableNumber){
    int currentId, found = 0, quantity;
    char keyChar;
    if(listTable[tableNumber].empty()){
        cout << "BAN CHUA GOI MON" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = STAFF_TABLE;
    }
    else{
        cout << "\n============================STAFF ADJUST===============================" << endl;
        cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
        cout << "\n____________________________MON DA GOI________________________________" << endl;
        displayFoodTable(listTable[tableNumber]);
        cout << "Nhap ID mon can sua: ";
        cin >> currentId;
        for(int i=0; i<listTable[tableNumber].size(); i++){
            if(listTable[tableNumber][i].getId() == currentId){
                found = 1;
                cout << "Nhap so luong: "; 
                cin >> quantity;
                listTable[tableNumber][i].setQuantity(quantity);
                cout << "SUA MON THANH CONG" << endl;
                cout << "\n__________________________MON SAU KHI SUA_____________________________" << endl;
                displayFoodTable(listTable[tableNumber]);
                break;
            }
        }
        if(found == 0){
            cout << "Khong tim thay ID nay" << endl;
            cout << "Nhan phim bat ky de tiep tuc:...";
            cin >> keyChar;
            state = STAFF_TABLE;
            return;
        }
        int keyInt;
        do{
            cout << "1: Tiep tuc sua\n0: Quay lai" << endl;
            cin >> keyInt;
            if(keyInt < 0 || keyInt > 1)
                cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
        }while(keyInt < 0 || keyInt > 1);
        if(keyInt == 1)
            displayStaffAdjust(state, listTable, tableNumber);
        else
            state = STAFF_TABLE;
    }
}

void displayStaffDelete(State& state, vector <char>& status, vector <vector <FoodOnTable>>& listTable, int tableNumber){
    int currentId, found = 0;
    char keyChar;
    if(listTable[tableNumber].empty()){
        cout << "BAN CHUA GOI MON" << endl;
        cout << "Nhap phim bat ky de thoat:...";
        cin.ignore();
        cin >> keyChar;
        state = STAFF_TABLE;
    }
    else{
        cout << "\n=============================STAFF DELETE===============================" << endl;
        cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
        cout << "\n____________________________MON DA GOI________________________________" << endl;
        displayFoodTable(listTable[tableNumber]);
        cout << "Nhap ID mon can xoa: ";
        cin >> currentId;
        for(int i=0; i<listTable[tableNumber].size(); i++){
            if(listTable[tableNumber][i].getId() == currentId){
                found = 1;
                listTable[tableNumber].erase(listTable[tableNumber].begin()+i);
                cout << "XOA MON THANH CONG" << endl;
                cout << "\n__________________________MON SAU KHI XOA_____________________________" << endl;
                displayFoodTable(listTable[tableNumber]);
                break;
            }
        }
        if(found == 0){
            cout << "Khong tim thay ID nay" << endl;
            cout << "Nhan phim bat ky de tiep tuc:...";
            cin >> keyChar;
            state = STAFF_TABLE;
            return;
        }
        if(listTable[tableNumber].empty()){
            status[tableNumber] = 'O';
        }
        int keyInt;
        do{
            cout << "1: Tiep tuc xoa\n0: Quay lai" << endl;
            cin >> keyInt;
            if(keyInt < 0 || keyInt > 1)
                cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
        }while(keyInt < 0 || keyInt > 1);
        if(keyInt == 1)
            displayStaffDelete(state, status, listTable, tableNumber);
        else
            state = STAFF_TABLE;
    }
}

void displayStaffOrdered(State& state, vector <vector <FoodOnTable>> listTable, int tableNumber){
    char keyChar;
    if(listTable[tableNumber].empty()){
        cout << "BAN CHUA GOI MON" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        cin.ignore();
        state = STAFF_TABLE;
    }
    else{
        cout << "\n============================STAFF ORDERED===============================" << endl;
        cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
        cout << "\n____________________________MON DA GOI________________________________" << endl;
        displayFoodTable(listTable[tableNumber]);
        cout << "Nhap phim bat ky de thoat:...";
        cin >> keyChar;
        cin.ignore();
        state = STAFF_TABLE;
    }
}

void displayPayment(State& state, vector <char>& status, vector <vector <FoodOnTable>>& listTable, int tableNumber){
    char keyChar;
    long long total = 0;
    if(listTable[tableNumber].empty()){
        cout << "BAN CHUA GOI MON" << endl;
        cout << "Nhan phim bat ky de tiep tuc:...";
        cin >> keyChar;
        state = STAFF_TABLE;
    }
    else{
        int keyInt;
        do{
            cout << "\n=================================PAYMENT================================" << endl;
            cout << "__________________________________BAN SO " << tableNumber << "________________________________" << endl;
            cout << "\n____________________________MON DA GOI________________________________" << endl;
            displayPayment(listTable[tableNumber]);
            for(int i=0; i<listTable[tableNumber].size(); i++){
                total += listTable[tableNumber][i].getPrice() * listTable[tableNumber][i].getQuantity();
            }
            cout << "TOTAL:" << setw(20) << total << endl;
            cout << "1: Thanh toan\n0: Quay lai" << endl;
            cout << "Nhap lua chon: ";
            cin >> keyInt;
            state = STAFF_TABLE;
            if(keyInt < 0 || keyInt > 1)
                cout << "Khong co chuc nang nay!\nVui long chon 1 hoac 0" << endl;
        }while(keyInt < 0 || keyInt > 1);
        if(keyInt == 1){
            listTable[tableNumber].clear();
            if(listTable[tableNumber].empty())
                status[tableNumber] = 'O';
            cout << "THANH TOAN THANH CONG" << endl;
            cout << "Nhan phim bat ky de tiep tuc:...";
            cin >> keyChar;
            state = STAFF_TABLE;
        }
        else
            state = STAFF_TABLE;
    }
}
//==================MAIN===================
int main(){
    int numOfTable = 0;
    int tableNumber = 0;
    State state = MAIN;
    vector <char> status;
    vector <Food> menu;
    vector <FoodOnTable> table;
    vector <vector <FoodOnTable>> listTable(50);
    while(1){
        switch (state)
        {
        case MAIN:
            displayMain(state);
            break;
        case MANAGER:
            displayManager(state);
            break;
        case MANAGER_SET_TABLE:
            displayManagerSetTable(state, numOfTable);
            break;
        case MANAGER_ADD:
            displayManagerAddFood(state, menu);
            break;
        case MANAGER_ADJUST:
            displayManagerAdjust(state, menu);
            break;
        case MANAGER_DELETE:
            displayManagerDelete(state, menu);
            break;
        case MANAGER_MENU:
            displayManagerMenu(state, menu);
            break;
        case STAFF:
            displayStaff(state, status, numOfTable, tableNumber);
            break;
        case STAFF_TABLE:
            displayStaffTable(state, tableNumber);
            break;
        case STAFF_ADD:
            displayStaffAdd(state, status, menu, listTable, tableNumber);
            break;
        case STAFF_ADJUST:
            displayStaffAdjust(state, listTable, tableNumber);
            break;
        case STAFF_DELETE:
            displayStaffDelete(state, status, listTable, tableNumber);
            break;
        case STAFF_ODERED:
            displayStaffOrdered(state, listTable, tableNumber);
            break;
        case STAFF_PAYMENT:
            displayPayment(state, status, listTable, tableNumber);
            break;
        default:
            cout << "STATE nay khong co" << endl;
            break;
        }
    }
    return 0;
}
