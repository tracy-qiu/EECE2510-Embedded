//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//SevenSegment cpp file - SevenSegment.cpp
//Functions for SevenSegment class
//Tracy Qiu ID 001313852 10/19/20

#include <iostream>
#include "SevenSegment.h"

//class constructor, displays all zeros
SevenSegment::SevenSegment() {
    //write the bit value of zero for each display | each other to combine them
    dataReg1 = bit_values[0] | bit_values[0] << 8 | bit_values[0] << 16 | bit_values[0] << 24;
    RegisterWrite(HEX3_HEX0_BASE, dataReg1);
    dataReg1 = bit_values[0] | bit_values[0] << 8;
    RegisterWrite(HEX5_HEX4_BASE, dataReg2);
}

//function clears all displays
void SevenSegment::Hex_ClearAll(){
    //set data registers to zeros to turn them all off
    dataReg1 = 0;
    RegisterWrite(HEX3_HEX0_BASE, dataReg1);
    dataReg2 = 0;
    RegisterWrite(HEX5_HEX4_BASE, dataReg2);
}

//class destructor that calls clear function
SevenSegment::~SevenSegment() {
    //DE1SoCfpga::~DE1SoCfpga();
    Hex_ClearAll();
}

//function clears a specific display
void SevenSegment::HEX_ClearSpecific(int index){
    //if the index is less than 4 then it is part of register 1
    if (index <= 3){
        dataReg1 = RegisterRead(HEX3_HEX0_BASE);
        //clear is equal to binary of 11111111, which is 255 in decimal
        int clear;
        //shifts however bits over to get to indicated display
        clear = 255 << index * 8;
        //the existing state & with clear to just clear the indicated index
        dataReg1 = dataReg1 & ~clear;
        RegisterWrite(HEX3_HEX0_BASE, dataReg1);
    }
    //if the index is less than 4 then it is part of register 1
    if (index >= 4 && index <= 5){
        dataReg2 = RegisterRead(HEX5_HEX4_BASE);
        int clear;
        //the index is subtracted four because HEX4 is in the first display of the second register
        clear = 255 << (index - 4)*8;
        dataReg2 = dataReg2 & ~clear;
        RegisterWrite(HEX5_HEX4_BASE, dataReg2);
    }
}

//write hexadecimal for a specific display
void SevenSegment::Hex_WriteSpecific(int display_id, int value){
    int write;
    //if the index is less than 4 then it is part of register 1
    if (display_id < 4) {
        //first clear that indicated display
        HEX_ClearSpecific(display_id);
        //index the bit value from the bit values array and shift it to match indicated index
        write = bit_values[value] << display_id * 8;
        //take the write bit value OR with current state of registers and write new display values
        dataReg1 = write | RegisterRead(HEX3_HEX0_BASE);
        RegisterWrite(HEX3_HEX0_BASE, dataReg1);
    }
    //if the index is greater than 3 then it is part of register 2
    else {
        HEX_ClearSpecific(display_id);
        //the index is subtracted four because HEX4 is in the first display of the second register
        write = bit_values[value] << (display_id-4) * 8;
        dataReg2 = write | RegisterRead(HEX5_HEX4_BASE);
        RegisterWrite(HEX5_HEX4_BASE, dataReg2);
    }
}

//function to write a number in hexadecimal on displays
void SevenSegment::Hex_WriteNumber(int number) {
    //loop to iterate through each display
    for (int i = 0; i < 6; i++) {
        //clear is to clear everything besides the current display we want to read
        int clear = 15 << (i * 4);
        //get that value and shift it the right most to get the value that would be in that display
        int value = (clear & number) >> (i * 4);
        Hex_WriteSpecific(i, value);
    }
}