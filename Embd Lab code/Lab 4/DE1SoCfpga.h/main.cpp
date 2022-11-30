//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//DE1SoCfpga header file - DE1SoCfpga.h
//Declares all the global variables and function prototypes
//Tracy Qiu ID 001313852 10/19/20

#ifndef DE1SoCfpga_h //preventing a header file from being
#define DE1SoCfpga_h //included multiple times and hence avoid the error of variables redefinitions

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

class DE1SoCfpga {
//private attributes of pBase and fd
private:
    char *pBase;
    int fd;

public:
    //function definitions
    DE1SoCfpga();

    ~DE1SoCfpga();

    void RegisterWrite(unsigned int offset, int value);

    int RegisterRead(unsigned int offset);

};

#endif