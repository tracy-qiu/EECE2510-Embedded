//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//main.cpp that tests the DE1SoCfpga, SevenSegment, LEDControl classes
//The program displays hexadecimal values onto the displays
//and can also be controlled by the switches and buttons
//Tracy Qiu ID 001313852 10/19/20

//includes the LEDControl header file
#include "LEDControl.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    //create new pointer to SevenSegment object
    SevenSegment *display = new SevenSegment;

    //testing LEDControl class
    LEDControl *l = new LEDControl;

    //return the state of all switches and makes display and leds match the switches
    int switches = l->ReadAllSwitches();
    display->Hex_WriteNumber(switches);
    l->WriteAllLeds(switches);

    //run button method
    l->PushButtonGet();

    /*
    //turn on led 2
    l->Write1Led(2,1);

    //make leds display 8, leds 3 and 0 on
    l->WriteAllLeds(9);

    //return the state of switch 5
    cout << l->Read1Switch(5) << endl;
*/
    //call destructor to free memory
    l->~LEDControl();

    // Done
}
