//Parth Patel NUID 001317107
//Tracy Qiu NUID 001313852

#include "de1sochps.h" 
#include "GPIOControl.h"
using namespace std;

int main(){
 //Constructor is used to initialize variable of GPIOControl class
GPIOControl control;

/*
//Part A 
//turn off led on/off
control.LEDOnOff(1);
//return state of button and makes button match its state
cout << control.ButtonRead() << endl;
*/

//Part B 
//Timer is set up and enabled
control.Timer0Setup(2);
 int y=1;
 int led;
 //infinte loop
 while(y>0){

//checks if user button is pressed
if (control.ButtonRead()==0){
      control.LEDOnOff(0);
        //breaks out of loop
      y=-1;
}

else{ 

if(control.Timer0Int() == 1) {
//toggle the first bit of led variable and change led state
led = led ^ 1;
//change led state
control.LEDOnOff(led);
//reset timer
control.RegisterRead(timer0_eoi_reg);
}
}
}

return 0;
}


