#include "de1sochps.h" 

using namespace std;

        //Constructor
        DE1SoChps::DE1SoChps()
        {
                int* f =&fd;
                // Open /dev/mem to give access to physical addresses
                *f = open("/dev/mem", (O_RDWR | O_SYNC));
                if (*f == -1) // check for errors in openning /dev/mem
                {
                        cout << "ERROR: could not open /dev/mem..." << endl;
                        exit(1);
                }

                // Get a mapping from physical addresses to virtual addresses
                char* virtual_base = (char*)mmap(NULL, HPS_BRIDGE_SPAN,
                        (PROT_READ | PROT_WRITE),
 MAP_SHARED, *f, HPS_BRIDGE_BASE); 
                if (virtual_base == MAP_FAILED) { // check for errors
                        cout << "ERROR: mmap() failed..." << endl;
                        close(*f); // close memory before exiting
                        exit(1); // Returns 1 to the operating system;
                }
                pBase = virtual_base;
        }
        //Destructor
        DE1SoChps::~DE1SoChps()
        { 
                if (munmap(pBase, HPS_BRIDGE_SPAN) != 0) {
                        cout << "ERROR: munmap() failed..." << endl;
                        exit(1);
                }
                close(fd); // close memory
        }
        void DE1SoChps::RegisterWrite(unsigned int offset, int value)
        {
                *(volatile unsigned int*)(pBase + offset) = value;
        } 
        int DE1SoChps::RegisterRead(unsigned int offset)
        {
                return *(volatile unsigned int*)(pBase + offset);
        }

