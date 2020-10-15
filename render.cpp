#include <Bela.h>
#include "global.h"
#include "chip_control.h"
#include "Encoders.h"
//#include "Looper.h"

chip_control Chip_Control;
Encoders Enc;

bool setup(BelaContext *context, void *userData)
{
	Chip_Control.setup(context);
	return true;
}

void render(BelaContext *context, void *userData)
{
	static int val[5] = {0};

	
	Chip_Control.write(context);
	
	Enc.read(context);
	
	for (unsigned int i=0; i<5; i++)
	{
		val[i] = Enc.getIncr(i);
	}
	
	
	
	if (gCount%3000 == 0)
	{
		for (unsigned int i=0; i<5; i++)
		{
			rt_printf("%d\t",val[i]);
		}
		rt_printf("\n");
	}
	
	gCount++;
}

void cleanup(BelaContext *context, void *userData)
{

}
