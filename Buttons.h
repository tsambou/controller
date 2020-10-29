/***** Buttons.h *****/

#include "Bela.h"
#include "global.h"
#include "math.h"

class Buttons{
    
private:

	int mChip;
	int mRow;
	int mFrame;
	
	int mButton = 1, mButton_last;
	int mPress_time = 0, mIsPressed = 0, mPressCounter = 0;
	int mDouble_press_time1 = 0, mDouble_press_time2 = 0, mDouble_press_status = 0, mIsDouble_pressed = 0;
	int mDebounce = 100; // debounce for 10 renders
	bool mBang;
	
	
    
public:
	Buttons();
	void setup(int chip, int row, int frame);
	
	void read(BelaContext *context);
	
	bool bang();

	bool press();
	
	bool doublePress();
	
	int but(){
		return mButton;
	}
};