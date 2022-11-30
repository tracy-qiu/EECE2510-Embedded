//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//DE1SoCfpga cpp file - DE1SoCfpga.cpp
//Functions for DE1SoCfpga class
//Tracy Qiu ID 001313852 10/19/20

#include "DE1SoCfpga.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <iostream>
#include <cmath>

DE1SoCfpga::DE1SoCfpga()
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

DE1SoCfpga::~DE1SoCfpga()
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

void DE1SoCfpga::RegisterWrite(unsigned int offset, int value)
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
int DE1SoCfpga::RegisterRead(unsigned int offset)
{
    return * (volatile unsigned int *)(pBase + offset);
}

