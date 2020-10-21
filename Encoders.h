#include <Bela.h>
#include "global.h"
#include "Looper.h"

class Encoders
{
    
private:
	int EncNumber;
	int mFrameA, mFrameB;
	int mPinA, mPinB, mPinA_prev, mPinB_prev;
	float mIncr, mIncr_prev;
    
public:
    Encoders();
    
    void setup(int index, int FrameA, int FrameB);
    
    void read(BelaContext *context);

    float getIncr();
    
    void update(Looper Loop, int ChSel, int ModeSel);

};
