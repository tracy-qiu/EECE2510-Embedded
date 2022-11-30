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

/**
 * Write a 4-byte value at the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @parem offset	Offset where device is mapped.
 * @param value	Value to be written.
 */
void RegisterWrite(char *pBase, unsigned int reg_offset, int value)
{
    * (volatile unsigned int *)(pBase + reg_offset) = value;
    //volatile prevents the compiler from optimizing code
}

/**
 * Read a 4-byte value from the specified general-purpose I/O location.
 *
 * @param pBase		Base address returned by 'mmap'.
 * @param offset	Offset where device is mapped.
 * @return		Value read.
 */
int RegisterRead(char *pBase, unsigned int reg_offset)
{
    return * (volatile unsigned int *)(pBase + reg_offset);
}

/**
 * Initialize general-purpose I/O
 *  - Opens access to physical memory /dev/mem
 *  - Maps memory into virtual address space
 *
 * @param fd	File descriptor passed by reference, where the result
 *			of function 'open' will be stored.
 * @return	Address to virtual memory which is mapped to physical, or MAP_FAILED on error.
  */
char *Initialize(int *fd)
{
    // Open /dev/mem to give access to physical addresses
    *fd = open( "/dev/mem", (O_RDWR | O_SYNC));
    if (*fd == -1)			//  check for errors in openning /dev/mem
    {
        cout << "ERROR: could not open /dev/mem..." << endl;
        exit(1);
    }

    // Get a mapping from physical addresses to virtual addresses
    char *virtual_base = (char *)mmap (NULL, LW_BRIDGE_SPAN, (PROT_READ | PROT_WRITE), MAP_SHARED, *fd, LW_BRIDGE_BASE);
    if (virtual_base == MAP_FAILED)		// check for errors
    {
        cout << "ERROR: mmap() failed..." << endl;
        close (*fd);		// close memory before exiting
        exit(1);        // Returns 1 to the operating system;
    }
    return virtual_base;
}

/**
 * Close general-purpose I/O.
 *
 * @param pBase	Virtual address where I/O was mapped.
 * @param fd	File descriptor previously returned by 'open'.
 */
void Finalize(char *pBase, int fd)
{
    if (munmap (pBase, LW_BRIDGE_SPAN) != 0)
    {
        cout << "ERROR: munmap() failed..." << endl;
        exit(1);
    }
    close (fd); 	// close memory
}

/** Reads all the switches and returns their value in a single integer.
     *
     * @param pBase Base address for general-purpose I/O
    * @return A value that represents the value of the switches
    */
int ReadAllSwitches(char *pBase) {

    /*
    for (int i = 0; i < 10; i++) {
        int offset;
        offset = LEDR_BASE + i * 4;
    }
        */



    int x = 1023;
    int masked = RegisterRead(pBase, SW_BASE) & x;
    cout << masked;
    return masked;
    //int switches = read & 1023;
    //return switches;

        /*
        int b;
        int currents;
        for (int j = 0; j < 9; j++){
            b = 2^j;
            currents = read | b;
            switches += currents;
        }
         */

}

/** Set the state of the LEDs with the given value.
 *
 * @param pBase Base address for general-purpose I/O
 * @param value Value between 0 and 1023 written to the LEDs
 */
void WriteAllLeds(char *pBase, int value){
    for (int i = 0 ; i < 10; i ++)
        RegisterWrite(pBase, LW_BRIDGE_BASE, value);


}


int main()
{
    // Initialize
    int fd;
    char *pBase = Initialize(&fd);

    // ************** Put your code here **********************









    // Done
    Finalize(pBase, fd);
}
