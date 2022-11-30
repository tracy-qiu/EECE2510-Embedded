//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//SevenSegment header file - SevenSegment.h
//Declares all the global variables and function prototypes
//includes DE1SoCfpga header file
//Tracy Qiu ID 001313852 10/19/20

#ifndef SevenSegment_h
#define SevenSegment_h

#include "DE1SoCfpga.h"

//global array constant of bit values for hexadecimal 0-F
const unsigned int bit_values[16] = {63, 6, 91, 79, 102, 109, 125, 7, 127, 103, 119, 124, 57, 94, 121, 113};

//class declaration, inherits from DE1SoCfpga
class SevenSegment : public DE1SoCfpga {
//two private attributes that store the values of the data registers
private:
    unsigned int dataReg1;
    unsigned int dataReg2;

//function prototypes
public:
    SevenSegment();

    void Hex_ClearAll();

    ~SevenSegment();

    void HEX_ClearSpecific(int index);

    void Hex_WriteSpecific(int display_id, int value);

    void Hex_WriteNumber(int number);

};

#endif

