
class Parameter {
    string *name;
    
    float mMinIn , mMaxIn; // 0 - 96 for one encoder cycle
    float mMinOut , mMaxOut; // In will be scaled to these boundaries (re
}

---

---

// To kathe knob
class Encoder {
    mPin[2];
    mIncr;
}


class Looper {
    Channel channels[16];
    
    Encoder encoders[3];  // mporeis na to afiseis gia later
    
    Parameter EncMode;
    
    
    void read_knobs(); // anti gia to Encoders::read()
    
    // sto melon
    int get_current_channel();  // sou girnaei to index mesa sto channels[]
}

class Channel {
    Mode modes[5];
}

class Mode {
    string name;
    
    Parameter params[3];
}


----

Looper my_looper;

bool setup():
{
    for (i=0 ; i < sizeof(my_looper.channels) ; i++) {
        current_channel = my_looper.channels[i]
        
        my_looper.channels[i].mode[0].param[0].setup("volume", 0, 250, ..... );
        my_looper.channels[i].mode[0].param[1].setup("blabla", 0, 250, ..... );
        
        my_looper.channels[i].mode[1].param[1].setup("blabla", 0, 250, ..... );
        ...
    }
    
    void render(BelaContext *context, void *userData)
    {
        current_channel = my_looper.get_current_channel();
        
        
        ....
        
        
        Enc.read(); // Reads pins of encoders and determines whether they were turned (Increment)
        
        // Kathe 200, kanei update to
        if (gCount%200 == 0)
        {
            EncMode.update(Enc.getIncr(0));
            
            SelectedEncMode = (int)(EncMode.getParam() + 0.5);
            current_mode = my_looper.channels[current_channel].modes[SelectedEncMode];
            
            // Update parameters for Current/Selected Channel and Current Encoder Mode, for our 3 Encoders
            for (unsigned int i=0 ; i<sizeof(my_looper.encoders) ; i++)
            {
                
                current_param = current_mode.params[i]
                
                
                current_param.update(Enc.getIncr(i+1));
                
            }
        }
        
        if (gCount % 2000 == 0)
        {
            rt_printf("Enc Mode ------ Val1   ------  Val2   ------  Val3\n");
            rt_printf("   %d    ----  %f  ---  %f  ---  %f \n",SelectedEncMode,Param[SelectedCh][SelectedEncMode]    [0].getParam(),Param[SelectedCh][SelectedEncMode][1].getParam(),Param[SelectedCh][SelectedEncMode][2].getParam());
        }
        
        gCount++;
    }
    
    void cleanup(BelaContext *context, void *userData)
    {
        
    }
    
