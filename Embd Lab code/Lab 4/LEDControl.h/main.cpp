//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//LEDControl header file - LEDControl.h
//Declares all the global variables and function prototypes
//includes SevenSegment header file
//Tracy Qiu ID 001313852 10/19/20

#ifndef LEDControl_h
#define LEDControl_h

#include "SevenSegment.h"

//LEDControl class inherits from DE1SoCfpga class
class LEDControl : public SevenSegment {
//private attribute for led_regValues
private:
    unsigned int leds_regValue; //stores value of LEDS

public:
    //default constructor - inherit from DE1SoCfpga constructor
    LEDControl();

    ~LEDControl();

    void Write1Led(int ledNum, int state);

    void WriteAllLeds(int value);

    int Read1Switch(int switchNum);

    int ReadAllSwitches();

    void PushButtonGet();

};

#endif