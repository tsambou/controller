/***** Looper.h *****/

#pragma once

#include "Bela.h"
#include "global.h"
#include "Channels.h"

class Looper{
	
private:

public:
	Looper();
    Channels channel[NofChannels];
    void setup();
};
