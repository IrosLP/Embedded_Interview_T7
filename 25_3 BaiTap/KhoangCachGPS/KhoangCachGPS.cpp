#include <iostream>
#include <cmath>

#define EARTH_RADIUS 6371
#define PI 3.141592654

using namespace std;

class GpsPoint{
    private:
        float latitude; //Vi do
        float longitude; //Kinh do
    public:
        void input();
        int isValid();
        float getLatitude();
        float getLongitude();
        float toRadians(float);
        float distanceTo(GpsPoint);
};
void GpsPoint::input(){
    do{
        cerr << "\tNhap vi do: "; cin >> latitude;
        cerr << "\tNhap kinh do: "; cin >> longitude;
    }while(isValid() < 0);
}
int GpsPoint::isValid(){
    if(latitude < -90 || latitude > 90){
        cerr << "***Vi do khong hop le***\n" << endl;
        return -1;
    }
    if(longitude < -180 || longitude > 180){
        cerr << "***Kinh do khong hop le***\n" << endl;
        return -2;
    }
    return 0;
}
float GpsPoint::getLatitude(){
    return latitude;
}
float GpsPoint::getLongitude(){
    return longitude;
}
float GpsPoint::toRadians(float degress){
    return degress*PI/180;
}
float GpsPoint::distanceTo(GpsPoint point){
    return EARTH_RADIUS*2*asin(sqrt(pow(sin(PI/180*(point.getLatitude()-latitude)/2),2)+cos(PI/180*latitude)*cos(PI/180*point.getLatitude())*pow(sin(PI/180*(point.getLongitude()-longitude)/2),2)));
}

int main(){
    GpsPoint point1, point2;
    cout << "\nDiem thu 1:" << endl;
    point1.input();
    cout << "\nDiem thu 2:" << endl;
    point2.input();
    cout << "\nKhoang cach giua 2 diem la: " << point1.distanceTo(point2) << "km" << endl;
    return 0;
}