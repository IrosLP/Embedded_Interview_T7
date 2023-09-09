#include <iostream>

using namespace std;

//======================================CLASS WHEEL======================================
class Wheel{
    private:
        float speed; //vong/phut
    public:
        void setSpeed(float speed);
        float getSpeed();
};
void Wheel::setSpeed(float speed){
    this->speed = speed;
}
float Wheel::getSpeed(){
    return speed;
}

//=======================================CLASS CAR=======================================
class Car{
    private:
        float carWeight;
        float passengerWeight;
        float lowerBound;
        Wheel wheel;
    public:
        Car();
        void setCarWeight(float weight);
        float getCarWeight();
        void setLowerBound(float);
        float getLowerBound();
        void addPassenger(float);
        float getTotalWeight();
        void setWheelSpeed(float);
        float getWheelSpeed();
};
Car::Car(){
    carWeight = 1000.0;
    lowerBound = 10.0;
    passengerWeight = 0.0;
}
void Car::setCarWeight(float carWeight){
    this->carWeight = carWeight;
}
float Car::getCarWeight(){
    return carWeight;
}
void Car::setLowerBound(float lowerBound){
    this->lowerBound = lowerBound;
}
float Car::getLowerBound(){
    return lowerBound;
}
void Car::addPassenger(float passengerWeight){
    this->passengerWeight += passengerWeight;
}
float Car::getTotalWeight(){
    return carWeight + passengerWeight;
}
void Car::setWheelSpeed(float speed){
    wheel.setSpeed(speed);
}
float Car::getWheelSpeed(){
    return wheel.getSpeed();
}

//=======================================CLASS ABS========================================
class ABS{
    private:
        Car* car;
    public:
        ABS(Car&);
        void brake();
};
ABS::ABS(Car &car){
    this->car = &car;
}
void ABS::brake(){
    if((*car).getWheelSpeed() < (*car).getLowerBound()){
        cerr << "Warning: Wheel is locking up! Current total weight: " << (*car).getTotalWeight() << "kg." << endl;
    }
    else
        cerr << "Brakes applied normally." << endl;
}

//==========================================MAIN===========================================
int main(){
    Car car;
    ABS abs(car);

    car.setWheelSpeed(20.0);
    abs.brake();

    car.addPassenger(80.0);
    car.setWheelSpeed(9.0);
    abs.brake();

    return 0;
}