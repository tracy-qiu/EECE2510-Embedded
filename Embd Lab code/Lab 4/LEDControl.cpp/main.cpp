//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//LEDControl cpp file - LEDControl.cpp
//Functions for LEDControl class
//Tracy Qiu ID 001313852 10/19/20

#include "LEDControl.h"
#include <iostream>
#include <cmath>

LEDControl::LEDControl(){
    leds_regValue = 0;
}

LEDControl::~LEDControl() {
    leds_regValue = 0;
    RegisterWrite(LEDR_BASE, leds_regValue);
    //write displays to match the leds
    Hex_WriteNumber(leds_regValue);
    cout << "Closing LEDs, Switches, & Buttons... " << endl;
}

//changes the state of one led to be  on or off
void LEDControl::Write1Led(int ledNum, int state) {
    //read all the switches and mask them
    int masked = RegisterRead(SW_BASE) & 1023;
    //if the state is 1, turn on specified led, leave everything else unchanged
    if (state) {
        //take the current state of switches OR with 2^ledNum
        int num = masked | int(pow(2, ledNum));
        //write leds with this new value
        leds_regValue = num;
        RegisterWrite(LEDR_BASE, leds_regValue);
        //write displays to match the leds
        Hex_WriteNumber(leds_regValue);
    }
        //if the state is 0, turn off specified switch, leave everything else unchanged
    else {
        //current state & operator the opposite of 2^ledNum
        int num = masked & ~int(pow(2, ledNum));
        //write leds with this new value
        leds_regValue = num;
        RegisterWrite(LEDR_BASE, leds_regValue);
        //write displays to match the leds
        Hex_WriteNumber(leds_regValue);
    }
}

/** Set the state of the LEDs with the given value.
*
* @param pBase Base address for general-purpose I/O
* @param value Value between 0 and 1023 written to the LEDs
*/
void LEDControl::WriteAllLeds(int value){
    leds_regValue = value;
    //call register write with parameter of led offset
    RegisterWrite(LEDR_BASE, leds_regValue);
    //write displays to match the leds
    Hex_WriteNumber(leds_regValue);

}

/** Reads the value of a switch
* @param pBase Base address of I/O
* @param switchNum Switch number (0 to 9)
* @return Switch value read
*/
int LEDControl::Read1Switch(int switchNum){
    //read in current state of switches
    int masked = RegisterRead(SW_BASE) & 1023;
    //create number for the binary value of given switch number
    int num = int(pow(2, switchNum));
    //& operator on masked and num to find the value
    int switch1 = masked & num;
    int on;
    //if switch is greater than zero, switch is on
    if (switch1)
        on = 1;
        //switch is zero, switch is off
    else
        on = 0;
    //return the state of the switch 1 or 0
    return on;
}

/** Reads all the switches and returns their value in a single integer.
 *
 * @param pBase Base address for general-purpose I/O
* @return A value that represents the value of the switches
*/
int LEDControl::ReadAllSwitches() {
    //read register & with 1023 to mask bits 10-31
    return RegisterRead(SW_BASE) & 1023;
}

void LEDControl::PushButtonGet(){
    //counter for leds, starts off matching the switches
    unsigned int counter = ReadAllSwitches();
    WriteAllLeds(counter);

    //reads in the buttons
    unsigned int key;

    //exit variable for while loop
    int x = 0;
    while(x == 0) {
        leds_regValue = counter;
        //read in the state of the buttons
        key = RegisterRead(KEY_BASE);
        //sleep to add one second delay
        sleep(1);
        switch (key) {
            //no buttons pushed
            case 0:
                cout << "-1" << endl;
                break;
                //button 0 pushed
            case 1:
                //increase the counter by one
                counter++;
                //changes the leds to match the counter
                WriteAllLeds(counter);
                //write displays to match the leds
                Hex_WriteNumber(counter);
                cout << "0" << endl;
                break;
                //button 1 pushed
            case 2:
                //decrease the counter by one
                counter--;
                //changes the leds to match the counter
                WriteAllLeds(counter);
                //write displays to match the leds
                Hex_WriteNumber(counter);
                cout << "1" << endl;
                break;
                //button 2 pushed
            case 4:
                //shift counter to the right one bit position
                counter = counter >> 1;
                //changes the leds to match the counter
                WriteAllLeds(counter);
                //write displays to match the leds
                Hex_WriteNumber(counter);
                cout << "2" << endl;
                break;
                //button 3 pushed
            case 8:
                //shift counter to the left one bit position
                counter = counter << 1;
                //changes the leds to match the counter
                WriteAllLeds(counter);
                //write displays to match the leds
                Hex_WriteNumber(counter);
                cout << "3" << endl;
                break;
                //multiple buttons pushed
            default:
                //write leds to match the switches
                WriteAllLeds(ReadAllSwitches());
                //write displays to match the leds
                Hex_WriteNumber(ReadAllSwitches());
                cout << "4" << endl;
                //set exit variable x to 1 to break out of switch
                x = 1;
                break;
        }
    }
}

