/***** Channels.cpp *****/
#include "Channels.h" 

Channels::Channels()
{
	Modes mode[NofModes];
	
	mode[0].param[0].setup(0,100, 0,2, 0,50); //volume
}


