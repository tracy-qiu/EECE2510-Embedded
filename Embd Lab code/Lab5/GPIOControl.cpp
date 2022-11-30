#include "GPIOControl.h" 
using namespace std;

//GPIOControl class constructor
GPIOControl::GPIOControl(){
    cout << "Initializing GPIOs...!" << endl;
    //read current state of data direction register
    unsigned int current = RegisterRead(gpio1_ddr_offset);
    //set bit 24 data direction register to output(1)
    RegisterWrite(gpio1_ddr_offset, current | 1 << 24);
    //set bit 25 data direction register to input(0)
    RegisterWrite(gpio1_ddr_offset, current & ~(1 << 25));
}

//Destructor
GPIOControl::~GPIOControl(){
//Display message
cout<<"Done using GPIOs...!"<<endl;
}

void GPIOControl:: LEDOnOff(int state){
//if 0 is passed, the led turns off
unsigned int ledstate=RegisterRead(gpio1_dr_offset); 
if (state==0){
RegisterWrite(gpio1_dr_offset, ledstate & ~(1<<24));
}
//if 1 is passed the led turns on
else if (state==1){
RegisterWrite(gpio1_dr_offset,ledstate | (1<<24));
}

}
//checks whether the button is pressed or not 
bool GPIOControl:: ButtonRead(){
unsigned int keystate = RegisterRead(gpio1_ext_port_offset);
int buttonstate= keystate & (1<<25);
//returns true if button is not pressed
return !buttonstate;
}


void GPIOControl::Timer0Setup(int s){ 
//bit0 is set to disable timer void Timer0Setup(int s){ unsigned int
int currentvalue=RegisterRead(timer0_control_reg);
int val = currentvalue & ~(1);
RegisterWrite(timer0_control_reg, val);
//bit1 is set so the mode is changed to user defined count mode
val = val|(1<<1);
 //bit2 is set to unmask the interrupt
val = val & ~(1 << 2);
RegisterWrite(timer0_control_reg, val);
 // load the timer counter with a value so that an interrupt is activated every
 //s seconds
RegisterWrite(timer0_load_reg, s*100000000);
 //enable timer 
val = val | 1 ;
RegisterWrite(timer0_control_reg, val);
}

int GPIOControl::Timer0Int(){ 
int interrupt;
interrupt=RegisterRead(timer0_int_stat_reg);

return interrupt;
}


