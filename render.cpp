#include <Bela.h>
#include "global.h"
#include "chip_control.h"
#include "Encoders.h"
#include "Looper.h"

Looper loop;
chip_control Chip_Control;
Encoders Enc[4];

bool setup(BelaContext *context, void *userData)
{
	Enc[0].setup(0,4,6);
	Enc[1].setup(1,0,2);
	Enc[2].setup(2,10,8);
	Enc[3].setup(3,14,12);
	Chip_Control.setup(context);
	loop.setup();
	return true;
}

void render(BelaContext *context, void *userData)
{
	static int val[4] = {0},SelCh = 0, SelMode = 0;

	
	Chip_Control.run(context);
	
	for (unsigned int i=0; i<NofEncoders; i++) {
		Enc[i].read(context);
	}
	
	if (gCount%100 == 0)
	{
		for (unsigned int i=0; i<NofEncoders; i++){
			loop.channel[SelCh].mode[SelMode].param[i].update(Enc[i].getIncr());
			//Enc[i].update(loop,SelCh,SelMode);
		}
	}
	if (gCount%1500 == 0){
		for (unsigned int i=0; i<NofEncoders; i++){
			rt_printf("Enc %d: %f\t",i,loop.channel[SelCh].mode[SelMode].param[i].getParam());
		}
		rt_printf("\n");	
	}

	gCount++;
}

void cleanup(BelaContext *context, void *userData)
{

}
