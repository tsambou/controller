/***** chip_control.cpp *****/

#include "chip_control.h"

chip_control::chip_control(){
	
}

	
void chip_control::setup(BelaContext *context){
	pinMode(context,0,SerOut1,INPUT);
	pinMode(context,0,SerOut2,INPUT);
	pinMode(context,0,PL_pin,OUTPUT);
	pinMode(context,0,clock,OUTPUT);
}

void chip_control::write(BelaContext *context){
	
	for (unsigned int i=0; i<context->digitalFrames; i++)
	{
		if (i%2 == 0)
		{
			digitalWrite(context,i,clock,0);
		}
		else
		{
			digitalWrite(context,i,clock,1);
		}

		
		if (i==15) digitalWrite(context,i,PL_pin,0);
		else digitalWrite(context,i,PL_pin,1);
	}

}



