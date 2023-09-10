#include <iostream>

using namespace std;

typedef enum{CLOCKWISE, COUNTERCLOCKWISE} Direction;

//=======================================DCMotor=======================================
class DCMotor{
    private:
        float voltage;
        float current;
        float heat;
        float maxCurrent;
        bool isRunning;
        int speed;
        Direction direction;
    public:
        void setCurrent(float);
        float getCurrent();
        void setHeat(float);
        float getHeat();
        void setSpeed(int);
        int getSpeed();
        void setMaxCurrent(float);
        float getMaxCurrent();
        void setDirection(Direction);
        bool getIsRunning();
        Direction getDirection();
        void startMotor();
        void stopMotor();
};
void DCMotor::setCurrent(float current){
    this->current = current;
}
float DCMotor::getCurrent(){
    return current;
}
void DCMotor::setHeat(float heat){
    this->heat = heat;
}
float DCMotor::getHeat(){
    return heat;
}
void DCMotor::setSpeed(int speed){
    this->speed = speed;
}
int DCMotor::getSpeed(){
    return speed;
}
void DCMotor::setMaxCurrent(float maxCurrent){
    this->maxCurrent = maxCurrent;
}
float DCMotor::getMaxCurrent(){
    return maxCurrent;
}
void DCMotor::setDirection(Direction direction){
    this->direction = direction;
}
bool DCMotor::getIsRunning(){
    return isRunning;
}
Direction DCMotor::getDirection(){
    return direction;
}
void DCMotor::startMotor(){
    isRunning = true;
}
void DCMotor::stopMotor(){
    isRunning = false;
}

//====================================FeedbackSystem===================================
class FeedbackSystem{
    private:
        float maxVoltage;
        float maxHeat;
        DCMotor motor;
    public:
        void setMaxValue(float, float, float);
        bool overloadDetected(float);
        bool overheatDetected(float);
        DCMotor& getMotor();
};
void FeedbackSystem::setMaxValue(float maxVoltage, float maxCurrent, float maxHeat){
    this->maxVoltage = maxVoltage;
    this->maxHeat = maxHeat;
    motor.setMaxCurrent(maxCurrent);
}
bool FeedbackSystem::overloadDetected(float currentFeedback){
    if(currentFeedback > motor.getMaxCurrent()) return true;
    return false;
}
bool FeedbackSystem::overheatDetected(float heatFeedback){
    if(heatFeedback > maxHeat) return true;
    return false;
}
DCMotor& FeedbackSystem::getMotor(){
    return motor;
}

//==================================DCMotorController==================================
class DCMotorController{
    private:
        FeedbackSystem feedbackSystem;
    public:
        DCMotorController(float, float ,float);
        void controlMotor(float currentFeedback, float heatFeedback);
        void directionMotor(Direction);
        void speedMotor(int);
};
DCMotorController::DCMotorController(float maxVoltage, float maxCurrent, float maxHeat){
    feedbackSystem.setMaxValue(maxVoltage, maxCurrent, maxHeat);
}
void DCMotorController::controlMotor(float currentFeedback, float heatFeedback){
    if(feedbackSystem.overloadDetected(currentFeedback) || feedbackSystem.overheatDetected(heatFeedback)){
        feedbackSystem.getMotor().stopMotor();
        cout << "\nMotor is stopping" << endl;
        if(feedbackSystem.overloadDetected(currentFeedback))
            cout << "Motor is overloading" << endl;
        if(feedbackSystem.overheatDetected(heatFeedback))
            cout << "Motor is overheating" << endl;
        cout << endl;
    }
    else{
        feedbackSystem.getMotor().startMotor();
        cout << "\nMotor is running" << endl;
    }
}
void DCMotorController::directionMotor(Direction dicrection){
    if(feedbackSystem.getMotor().getIsRunning()){
        feedbackSystem.getMotor().setDirection(dicrection);
        cout << "Direction: " << ((feedbackSystem.getMotor().getDirection() == CLOCKWISE) ? "CLOCKWISE" : "COUNTERCLOCKWISE") << endl;
    }
}
void DCMotorController::speedMotor(int speed){
    if(feedbackSystem.getMotor().getIsRunning()){
        feedbackSystem.getMotor().setSpeed(speed);
        cout << "Speed: " << feedbackSystem.getMotor().getSpeed() << "rpm\n" << endl;
    }    
}

//========================================MAIN=========================================
int main(){
    //Cài đặt giá trị max: Voltage, Current, Heat cho Controller
    DCMotorController controller(24, 10, 60);

    //điều khiển động cơ
    controller.controlMotor(10, 20);
    controller.directionMotor(CLOCKWISE);
    controller.speedMotor(200);
    
    return 0;
}