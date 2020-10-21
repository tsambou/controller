/***** Looper.cpp *****/
#include "Looper.h"

Looper::Looper(){
}

void Looper::setup(){
	for (unsigned int i=0; i<NofChannels; i++){
		channel[i].setup();
	}
}