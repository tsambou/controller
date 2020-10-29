/***** chip_control.cpp *****/

#include "chip_control.h"

chip_control::chip_control(){
	
}

// button latch (dark oil color) : pin 5
	
void chip_control::setup(BelaContext *context){
    pinMode(context,0,clock,OUTPUT); //yellow
	pinMode(context,0,latch_buttons,OUTPUT); //orange
	pinMode(context,0,PL_pin,OUTPUT); //gray
	pinMode(context,0,SerOut_buttons,INPUT); //blue
	pinMode(context,0,data_buttons,OUTPUT); //white
}

void chip_control::run(BelaContext *context){
	
	for (unsigned int i=0; i<context->digitalFrames; i++)
	{
		if (i%2 == 0)
		{
			if (i >=8 && i<=12)	
			{
				if (i/2 == gButtonRows+4) digitalWrite(context,i,data_buttons,0);
				else digitalWrite(context,i,data_buttons,1);
			}
			else digitalWrite(context,i,data_buttons,0);
			
			
			
			
			digitalWrite(context,i,clock,0);
		}
		else
		{
			digitalWrite(context,i,clock,1);
		}
		if (i==0) digitalWrite(context,i,latch_buttons,1); 
		else digitalWrite(context,i,latch_buttons,0);
		
		if (i==15) digitalWrite(context,i,PL_pin,0);
		else digitalWrite(context,i,PL_pin,1);
	}
	
	if (gCount > 0) gButtonRows++;
	if (gButtonRows == 3) gButtonRows = 0;

}


