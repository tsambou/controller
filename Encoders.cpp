#include "Encoders.h"
#include <Bela.h>
#include "global.h"

Encoders::Encoders(){}

void Encoders::read(BelaContext *context)
{
	
	for (unsigned int i=0 ; i<10 ; i++)
	{
		mPin_prev[i] = mPin[i];
	}
    
    for (unsigned int i=0 ; i<8 ; i++)
    {
        if (i==2 || i==3) 
        {
        	mPin[i-2] = digitalRead(context,i*2,SerOut2);
        	mPin[i+6] = digitalRead(context,i*2,SerOut1);
        }
        if (i==0 || i==1) mPin[i+2] = digitalRead(context,i*2,SerOut2);
		if (i==4 || i==6) mPin[i+1] = digitalRead(context,i*2,SerOut2);
		if (i==5 || i==7) mPin[i-1] = digitalRead(context,i*2,SerOut2);
    }
    
       // mPin[i] = digitalRead(context,i*2,SerOut1);
     
    if (gCount < 4) for (unsigned int i=0; i<10; i++) mPin_prev[i] = mPin[i];

    for (unsigned int i=0; i<5; i++)
    {
        
        if (mPin[i*2] != mPin_prev[i*2] || mPin[i*2+1] != mPin_prev[i*2+1] )
        {
            if (mPin[i*2+1] == 1)
            {
                if (mPin[i*2] > mPin_prev[i*2]) mIncr[i]++;
                if (mPin[i*2] < mPin_prev[i*2]) mIncr[i]--;
            }
            if (mPin[i*2+1] == 0)
            {
                if (mPin[i*2] > mPin_prev[i*2]) mIncr[i]--;
                if (mPin[i*2] < mPin_prev[i*2]) mIncr[i]++;
            }
            if (mPin[i*2] == 0)
            {
                if (mPin[i*2+1] > mPin_prev[i*2+1]) mIncr[i]++;
                if (mPin[i*2+1] < mPin_prev[i*2+1]) mIncr[i]--;
            }
            if (mPin[i*2] == 1)
            {
                if (mPin[i*2+1] > mPin_prev[i*2+1]) mIncr[i]--;
                if (mPin[i*2+1] < mPin_prev[i*2+1]) mIncr[i]++;
            }
        }
    }
}


float Encoders::getIncr(int index)
{
    mIncr_prev[index] = mIncr[index];
    //mIncr[index] = 0;
    //return mIncr_prev[index];
    return mIncr[index];
}























