/***** Buttons.cpp *****/

#include "Buttons.h"

Buttons::Buttons(){
}

void Buttons::setup(int chip, int row, int frame){
	mChip = chip;
	mRow = row;
	mFrame = frame;
}

void Buttons::read(BelaContext *context){	
	mButton_last = mButton;
	if (mRow == gButtonRows) mButton = digitalRead(context,mFrame,mChip);
	
	if (mIsPressed == 1 || mButton == 0){
		if (gCount > mPress_time + mDebounce) mIsPressed = 0;	
		mPressCounter++;
	}
	if (mButton == 0 && mButton_last == 1){ 
		if (mIsPressed == 0) {
			mBang = 1;
			if (mDouble_press_status == 0) mDouble_press_time1 = gCount;
			else mDouble_press_time2 = gCount;
			mDouble_press_status = !mDouble_press_status;
			mIsDouble_pressed = 1;
		}
		mPress_time = gCount;
		//mBang = 1;
		mIsPressed = 1;

	}
}

bool Buttons::bang(){
	if (mBang == 1){
		mBang = 0;
		return 1;
	}
	else return 0;
}

bool Buttons::press(){
	if (mPressCounter > 0.8*(gCount-mPress_time)){ // if button is being pressed for 80% of the time
		if (gCount > mPress_time + 1000) return 1; // and after the button is being pressed for at least 
		else return 0;							   // 1500 renders: button press = 1
	}
	else {
		mPressCounter = 0;
		mPress_time = 0;
		return 0;
	}
}

bool Buttons::doublePress(){
//	if (mPress_time > 0 && (mDouble_press_time - mPress_time) <= 1000 && (mDouble_press_time - mPress_time) > 0) {
	if (mIsDouble_pressed == 1){
		if (abs(mDouble_press_time1 - mDouble_press_time2) < 1000 && abs(mDouble_press_time1 - mDouble_press_time2) > 100){
			mIsDouble_pressed = 0;
			return 1;
		}
		else return 0;
	}	
	else return 0;
}