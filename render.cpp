#include <Bela.h>
#include "chip_control.h"
#include "Buttons.h"

chip_control chipctrl;
Buttons button[3][8];

bool setup(BelaContext *context, void *userData)
{
	chipctrl.setup(context);
	for (int i=0; i<3; i++){
		for (int j=0; j<8; j++){
			button[i][j].setup(SerOut_buttons, i, 2*j);
		}
	}
	return true;
}

void render(BelaContext *context, void *userData)
{
	
	chipctrl.run(context);
	
	for (unsigned int i=0; i<3; i++){
		for (unsigned int j=0; j<8; j++){
			button[i][j].read(context);
			//if (button[i][j].bang() == 1) rt_printf("button pressed is : %d:%d\n",i,j);
		}
	}


	for (unsigned int i=0; i<3; i++){
		for (unsigned int j=0; j<8; j++){
			if (button[i][j].bang() == 1) rt_printf("button pressed is : %d:%d \t but value %d\n",i,j,button[i][i].but());
		}
	}

if (gCount%1500 == 100){	
	for (unsigned int i=0; i<3; i++){
		for (unsigned int j=0; j<8; j++){
			 if (button[i][j].press() == 1) rt_printf("button %d:%d is pressed!\n",i,j);
			 if (button[i][j].doublePress() == 1) rt_printf("button %d:%d is DOUBLE pressed!\n",i,j);
		}
	}
}



gCount++;
}

void cleanup(BelaContext *context, void *userData)
{

}