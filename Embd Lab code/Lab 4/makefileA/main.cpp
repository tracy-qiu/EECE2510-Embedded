//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//MakefileA that compiles main.o DE1SoCfpga.o SevenSegment.o
//Tracy Qiu ID 001313852 10/19/20

#main Makefile

makemain: main.o DE1SoCfpga.o SevenSegment.o
        g++ main.o DE1SoCfpga.o SevenSegment.o -o makemain

DE1SoCfpga.o: DE1SoCfpga.cpp DE1SoCfpga.h
        g++ -c DE1SoCfpga.cpp

SevenSegment.o: SevenSegment.cpp SevenSegment.h
        g++ -c SevenSegment.cpp

main.o: main.cpp SevenSegment.h
        g++ -c main.cpp

clean:
        rm main.o DE1SoCfpga.o SevenSegment.o