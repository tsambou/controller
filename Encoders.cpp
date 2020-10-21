#include "Encoders.h"
#include <Bela.h>
#include "global.h"

Encoders::Encoders(){
	mIncr = 0;
	mIncr_prev = 0;
}

void Encoders::setup(int index, int FrameA, int FrameB){
	EncNumber = index;
	mFrameA = FrameA;
	mFrameB = FrameB;

}

void Encoders::read(BelaContext *context)
{
		mPinA_prev = mPinA;
		mPinB_prev = mPinB;
		
		mPinA = digitalRead(context,mFrameA,SerOut2);
		mPinB = digitalRead(context,mFrameB,SerOut2);
		
		if (gCount == 0){
			mPinA_prev = mPinA;
			mPinB_prev = mPinB;		
		}
        
        if (mPinA != mPinA_prev || mPinB != mPinB_prev )
        {
            if (mPinB == 1)
            {
                if (mPinA > mPinA_prev) mIncr++;
                if (mPinA < mPinA_prev) mIncr--;
            }
            if (mPinB == 0)
            {
                if (mPinA > mPinA_prev) mIncr--;
                if (mPinA < mPinA_prev) mIncr++;
            }
            if (mPinA == 0)
            {
                if (mPinB > mPinB_prev) mIncr++;
                if (mPinB < mPinB_prev) mIncr--;
            }
            if (mPinA == 1)
            {
                if (mPinB > mPinB_prev) mIncr--;
                if (mPinB < mPinB_prev) mIncr++;
            }
        }
    
}


float Encoders::getIncr()
{
    mIncr_prev = mIncr;
    mIncr = 0;
    return mIncr_prev;
    //return mIncr[index];
}

void Encoders::update(Looper Loop, int ChSel, int ModeSel){
	Loop.channel[ChSel].mode[ModeSel].param[EncNumber].update(mIncr);
	mIncr = 0;
}























