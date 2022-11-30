//Embedded Design 2160 Lab 4 Controlling 7 Segment Displays
//MakefileB that compiles main.o DE1SoCfpga.o SevenSegment.o LEDControl.o
//Tracy Qiu ID 001313852 10/19/20

#main Makefile

makemain: main.o DE1SoCfpga.o SevenSegment.o LEDControl.o
        g++ main.o DE1SoCfpga.o SevenSegment.o LEDControl.o -o makemain

DE1SoCfpga.o: DE1SoCfpga.cpp DE1SoCfpga.h
        g++ -c DE1SoCfpga.cpp

SevenSegment.o: SevenSegment.cpp SevenSegment.h
        g++ -c SevenSegment.cpp

LEDControl.o: LEDControl.cpp LEDControl.h
        g++ -c LEDControl.cpp

main.o: main.cpp LEDControl.h
        g++ -c main.cpp

clean:
        rm main.o DE1SoCfpga.o SevenSegment.o LEDControl.o