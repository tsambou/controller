/***** Channels.cpp *****/
#include "Channels.h" 

Channels::Channels(){
}

void Channels::setup(){
	for (unsigned int x=0; x<NofModes; x++){
		for (unsigned int y=0; y<NofEncoders; y++){
			mode[x].param[y].setup(0,100, 0,1, 0, 50); //volume
		}
	}
}


