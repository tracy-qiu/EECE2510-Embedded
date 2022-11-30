#ifndef DE1SOCHPS_H 
#define DE1SOCHPS_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
const unsigned int HPS_BRIDGE_BASE = 0xFF700000; // base
const unsigned int HPS_BRIDGE_SPAN = 0x006FFFFF; // span
const unsigned int gpio1_dr_offset = 0x00009000; // Data Register to output data
const unsigned int gpio1_ddr_offset = 0x00009004; // Data Direction Register for
 //each corresponding data bit, 0 for input and 1 for output
const unsigned int gpio1_ext_port_offset = 0x00009050;

const unsigned int timer0_load_reg = 0x508000 ; // Value to be loaded into timer0. This is 
//the value from which counting commences and reloaded when count reaches zero.
const unsigned int timer0_curr_val_reg = 0x508004 ; // Provides current value o$ 
const unsigned int timer0_control_reg = 0x508008 ; // Register to enable or dis$
 //control its mode of operation.
 //bit0 = 0 Timer disables, 1 enabled
 //bit1 = 0 Timer in free-running mode (counts from max value the maximum value$
 // = 1 Timer in user-defined count mode (using the value in the load count reg$

const unsigned int timer0_eoi_reg = 0x0050800C ; // Reading from this register $ 
 //from timer0 and returns 0
const unsigned int timer0_int_stat_reg = 508010 ; // Provides the interrupt sta$
 // bit0 = 0 timer interrupt is not active and 1 if it is active.
//Reading from this register does not clear any active interrupts

class DE1SoChps 
{
        char* pBase;
        int fd;
public:
        //Constructor
        DE1SoChps();
        //Destructor
        ~DE1SoChps();
        //Writes value to specified offset
        void RegisterWrite(unsigned int offset, int value);
        //Reads value of specified offset
int RegisterRead(unsigned int offset); 


};

#endif

