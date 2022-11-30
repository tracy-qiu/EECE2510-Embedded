#main Makefile 

runcode:: main.o de1sochps.o GPIOControl.o
	g++ main.o de1sochps.o GPIOControl.o -o runcode

de1sochps.o: de1sochps.cpp de1sochps.h
	g++ -c de1sochps.cpp

GPIOControl.o: GPIOControl.cpp GPIOControl.h
	g++ -c GPIOControl.cpp

main.o: main.cpp de1sochps.h GPIOControl.h
	g++ -c main.cpp

clean:
	rm main.o de1sochps.o GPIOControl.o


