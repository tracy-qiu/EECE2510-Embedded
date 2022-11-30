#ifndef GPIOCONTROL_H 
#define GPIOCONTROL_H
#include "de1sochps.h"
using namespace std;

class GPIOControl : public DE1SoChps{
public:
//Constructor
GPIOControl();
//Destructor
~GPIOControl();
//Function to turn LED on or off
void LEDOnOff(int state);
//Function to read state of user button
bool ButtonRead();
//Funtion to set up timer 
void Timer0Setup(int s); 
//Funtion that returns interrupt 
int Timer0Int();
};
#endif

