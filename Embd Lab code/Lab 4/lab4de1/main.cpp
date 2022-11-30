//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//This file combines everything: DE1SoCfpga.h, DE1SoCfpga.cpp, SevenSegment.h, SevenSegment.cpp,
// LEDControl.h, LEDControl.cpp, main.cpp
//This program has classes for DE1SoCfpga SevenSegment and LEDControl
//The program displays hexadecimal values onto the displays
//and can also be controlled by the switches and buttons
//Tracy Qiu ID 001313852 10/19/20

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <cmath>

using namespace std;

// Physical base address of FPGA Devices
const unsigned int LW_BRIDGE_BASE 	= 0xFF200000;  // Base offset

// Length of memory-mapped IO window
const unsigned int LW_BRIDGE_SPAN 	= 0x00005000;  // Address map size

// Cyclone V FPGA device addresses
const unsigned int LEDR_BASE 		= 0x00000000;  // Leds offset
const unsigned int SW_BASE 			= 0x00000040;  // Switches offset
const unsigned int KEY_BASE 		= 0x00000050;  // Push buttons offset

const unsigned int HEX3_HEX0_BASE = 0x00000020; // Data Reg1 offset
const unsigned int HEX5_HEX4_BASE = 0x00000030; // Data Reg2 offset

const unsigned int bit_values[16] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

class DE1SoCfpga
{
//private attributes of pBase and fd
private:
    char *pBase;
    int fd;

public:
    //default constructor - initialize function
    DE1SoCfpga()
    {
        int *f = &fd;
        // Open /dev/mem to give access to physical addresses
        *f = open("/dev/mem", (O_RDWR | O_SYNC));
        if (*f == -1)            //  check for errors in openning /dev/mem
        {
            cout << "ERROR: could not open /dev/mem..." << endl;
            exit(1);
        }

        // Get a mapping from physical addresses to virtual addresses
        char *virtual_base = (char *) mmap(NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, *f,
                                           LW_BRIDGE_BASE);
        if (virtual_base == MAP_FAILED)        // check for errors
        {
            cout << "ERROR: mmap() failed..." << endl;
            close(*f);        // close memory before exiting
            exit(1);        // Returns 1 to the operating system;
        }
        pBase = virtual_base;
    }

    //destructor - finalize function
    ~DE1SoCfpga()
    {
        if (munmap(pBase, LW_BRIDGE_SPAN) != 0) {
            cout << "ERROR: munmap() failed..." << endl;
            exit(1);
        }
        close(fd);    // close memory
    }

    /**
    * Write a 4-byte value at the specified general-purpose I/O location.
    *
    * @param pBase		Base address returned by 'mmap'.
     * @parem offset	Offset where device is mapped.
    * @param value	Value to be written.
    */

    virtual void RegisterWrite(unsigned int offset, int value)
    {
        * (volatile unsigned int *)(pBase + offset) = value;
    }

    /**
    * Read a 4-byte value from the specified general-purpose I/O location.
    *
    * @param pBase		Base address returned by 'mmap'.
    * @param offset	Offset where device is mapped.
    * @return		Value read.
    */
    virtual int RegisterRead(unsigned int offset)
    {
        return * (volatile unsigned int *)(pBase + offset);
    }
};

class SevenSegment : public DE1SoCfpga{
private:
    unsigned int dataReg1;
    unsigned int dataReg2;
public:
    SevenSegment() {
        dataReg1 = bit_values[0] | bit_values[0] << 8 | bit_values[0] << 16 | bit_values[0] << 24;
        RegisterWrite(HEX3_HEX0_BASE, dataReg1);
        dataReg1 = bit_values[0] | bit_values[0] << 8;
        RegisterWrite(HEX5_HEX4_BASE, dataReg2);
    }


    void Hex_ClearAll(){
        dataReg1 = 0;
        RegisterWrite(HEX3_HEX0_BASE, dataReg1);
        dataReg2 = 0;
        RegisterWrite(HEX5_HEX4_BASE, dataReg2);
    }

    ~SevenSegment() {
        //DE1SoCfpga::~DE1SoCfpga();
        Hex_ClearAll();
    }

    void HEX_ClearSpecific(int index){
        if (index <= 3){
            dataReg1 = RegisterRead(HEX3_HEX0_BASE);
            int clear;
            clear = 255 << index * 8;
            dataReg1 = dataReg1 & ~clear;
            RegisterWrite(HEX3_HEX0_BASE, dataReg1);
        }
        if (index >= 4 && index <= 5){
            dataReg2 = RegisterRead(HEX5_HEX4_BASE);
            int clear;
            clear = 255 << (index - 4)*8;
            dataReg2 = dataReg2 & ~clear;
            RegisterWrite(HEX5_HEX4_BASE, dataReg2);
        }
    }


    void Hex_WriteSpecific(int display_id, int value){
        int write;
        if (display_id < 4) {
            HEX_ClearSpecific(display_id);
            write = bit_values[value] << display_id * 8;
            dataReg1 = write | RegisterRead(HEX3_HEX0_BASE);
            RegisterWrite(HEX3_HEX0_BASE, dataReg1);
        }
        else {
            HEX_ClearSpecific(display_id);
            write = bit_values[value] << (display_id-4) * 8;
            dataReg2 = write | RegisterRead(HEX5_HEX4_BASE);
            RegisterWrite(HEX5_HEX4_BASE, dataReg2);
        }
    }

    void Hex_WriteNumber(int number){

        for (int i = 0; i < 6; i++){
            int clear = 15 << (i * 4);
            int value = (clear & number) >> (i * 4);
            Hex_WriteSpecific(i, value);
        }

    }


};



//LEDControl class inherits from DE1SoCfpga class
class LEDControl : public SevenSegment {
private:
    unsigned int leds_regValue;

public:
    //default constructor - inherit from DE1SoCfpga constructor
    LEDControl() {
        leds_regValue = 0;
    }

    //destructor
    //~LEDControl() = default;
    //destructor that inherits from DE1SoCfpga
    //{ DE1SoCfpga::~DE1SoCfpga();}

    ~LEDControl() {
        leds_regValue = 0;
        RegisterWrite(LEDR_BASE, leds_regValue);
        Hex_WriteNumber(leds_regValue);
        cout << "Closing LEDs, Switches, & Buttons... " << endl;
    }

    //changes the state of one led to be  on or off
    void Write1Led(int ledNum, int state) {
        //read all the switches and mask them
        int masked = RegisterRead(SW_BASE) & 1023;
        //if the state is 1, turn on specified led, leave everything else unchanged
        if (state) {
            //take the current state of switches OR with 2^ledNum
            int num = masked | int(pow(2, ledNum));
            //write leds with this new value
            leds_regValue = num;
            RegisterWrite(LEDR_BASE, leds_regValue);
            Hex_WriteNumber(leds_regValue);
        }
            //if the state is 0, turn off specified switch, leave everything else unchanged
        else {
            //current state & operator the opposite of 2^ledNum
            int num = masked & ~int(pow(2, ledNum));
            //write leds with this new value
            leds_regValue = num;
            RegisterWrite(LEDR_BASE, leds_regValue);
            Hex_WriteNumber(leds_regValue);
        }
    }

    /** Set the state of the LEDs with the given value.
    *
    * @param pBase Base address for general-purpose I/O
    * @param value Value between 0 and 1023 written to the LEDs
    */
    void WriteAllLeds(int value){
        leds_regValue = value;
        //call register write with parameter of led offset
        RegisterWrite(LEDR_BASE, leds_regValue);
        Hex_WriteNumber(leds_regValue);
    }

    /** Reads the value of a switch
    * @param pBase Base address of I/O
    * @param switchNum Switch number (0 to 9)
    * @return Switch value read
    */
    int Read1Switch(int switchNum){
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
    int ReadAllSwitches() {
        //read register & with 1023 to mask bits 10-31
        return RegisterRead(SW_BASE) & 1023;
    }

    void PushButtonGet(){
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
                    Hex_WriteNumber(counter);
                    cout << "0" << endl;
                    break;
                    //button 1 pushed
                case 2:
                    //decrease the counter by one
                    counter--;
                    //changes the leds to match the counter
                    WriteAllLeds(counter);
                    Hex_WriteNumber(counter);
                    cout << "1" << endl;
                    break;
                    //button 2 pushed
                case 4:
                    //shift counter to the right one bit position
                    counter = counter >> 1;
                    //changes the leds to match the counter
                    WriteAllLeds(counter);
                    Hex_WriteNumber(counter);
                    cout << "2" << endl;
                    break;
                    //button 3 pushed
                case 8:
                    //shift counter to the left one bit position
                    counter = counter << 1;
                    //changes the leds to match the counter
                    WriteAllLeds(counter);
                    Hex_WriteNumber(counter);
                    cout << "3" << endl;
                    break;
                    //multiple buttons pushed
                default:
                    //write leds to match the switches
                    WriteAllLeds(ReadAllSwitches());
                    Hex_WriteNumber(ReadAllSwitches());
                    cout << "4" << endl;
                    //set exit variable x to 1 to break out of switch
                    x = 1;
                    break;
            }
        }
    }

};


int main()
{
    SevenSegment *display = new SevenSegment;
    //write 0 in HEX0
    //display->RegisterWrite(HEX3_HEX0_BASE, 63);
    //cout << display->RegisterRead(HEX3_HEX0_BASE) << endl;
    //clears all displays
    //display->Hex_ClearAll();
    //clear the first display
    //display->HEX_ClearSpecific(1);
    //cout << display->RegisterRead(HEX3_HEX0_BASE) << endl;
    //write 0 in HEX4
    //display->RegisterWrite(HEX5_HEX4_BASE, 63);
    //cout << display->RegisterRead(HEX5_HEX4_BASE) << endl;

    display->Hex_WriteSpecific(0, 1);
    //displays FFFFFF on the registers
    display->Hex_WriteNumber(16777215);
/*
    //testing DE1 class make the leds match the switches
    DE1SoCfpga b;
    int masked = bRegisterRead(SW_BASE) & 1023;
    b.RegisterWrite(LEDR_BASE, masked);
    //call destructor to free memory
    b.~DE1SoCfpga();
*/

    //testing LEDControl class
    LEDControl *l = new LEDControl;
    //LEDControl l(&fd);

    //return the state of all switches
    int switches = l->ReadAllSwitches();
    display->Hex_WriteNumber(switches);
    l->WriteAllLeds(switches);

    //turn on led 2
    l->Write1Led(2,1);

    //make leds display 8, leds 3 and 0 on
    l->WriteAllLeds(9);

    //return the state of switch 5
    cout << l->Read1Switch(5) << endl;

    //run button method
    l->PushButtonGet();

    //call destructor to free memory
    l->~LEDControl();

    // Done
}
*/

/**
* Main operates the DE1-SoC 7-Segment Displays
* This program writes an integer number on the 7-Segment Displays
*/
int main(void)
{
    int count = -25;
    // Create a pointer object of the SevenSegment class
    SevenSegment *display = new SevenSegment;
    cout << "Program Starting...!" << endl;

    // Update the display every second
    while( count <= 25 ) {
        int value = count*count*count; // Value to display
        cout << "Count: " << count << ", Value = " << value << endl;
        display->Hex_WriteNumber(value); // display value
        sleep(1); // wait for 1 second
        count++; // increment count
    }
    cout << "Press any key to terminate..."; //wait before clearing the displays
    getchar(); getchar();
    delete display; // delete class object
    cout << "Terminating...!" << endl;
    return 0;
}
