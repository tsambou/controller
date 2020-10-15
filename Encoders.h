#include <Bela.h>
#include "global.h"

class Encoders
{
    
private:
    int mPin[10],mPin_prev[10];
    int mButtonPin[5], mButtonPin_prev[5];
    float mIncr[5],mIncr_prev[5];
    
    
public:
    Encoders();
    
    void read(BelaContext *context);

    float getIncr(int index);

};
