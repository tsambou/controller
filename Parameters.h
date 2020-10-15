#include <Bela.h>
#include "global.h"

// Η κλάση Parameters ουσιαστικά δέχεται το Increment του αντίστοιχου encoder και κάνει scale την RAW τιμή του encoder (πχ 0-96 για μία περιστροφή) σε μία πραγματική παράμετρο (πχ volume, frequency κλπ). Έτσι μπορώ να φτιάξω ένα object αυτής της κλάσης "EncMode" που παίρνει την τιμή του πρώτου encoder και την κάνει "scale" στον αριθμό των Encoder Modes (πχ 3 στο παρόν παράδειγμα).
// Για τις πραγματικές παραμέτρους φτιάχνουμε τόσα objects όσα είναι τα NofCh * NofModes * NofEncoders σε μορφή array: Parameters myParams[NofCh][NofModes][NofEncoders].

class Parameters{
    
private:
    float mMinIn , mMaxIn; // 0 - 96 for one encoder cycle
    float mMinOut , mMaxOut; // In will be scaled to these boundaries (real parameter values)
    bool mScale; // 0 for linear, 1 for logarithmic
    float mEncVal; // encoder value to be bounded by MinIn and MaxIn
    float mParamVal; // real parameter value to be bounded by MinOut and MaxOut
    
    float a,b; // needed to calculate the logarithmic change
    
public:

	Parameters();
    
    void setup(float min_in, float max_in, float min_out, float max_out, bool scale, float InitialVal);
    
    // Η συνάρτηση setup αρχικοποιεί τα objects της κλάσης. Επέλεξα να χρησιμοποιήσω διαφορετική συνάρτηση αντί του constructor για να φτιάνω τα object σε μορφή κλάσης και μέσα στη συνάρτηση setup (του Bela) να κάνω τις αρχικοποιήσεις μέσω αυτής της συνάρτησης.
    
    void update(float Increment);
    
    // Η συνάρτηση update παίρνει το Increment του αντίστοιχου Encoder, ανανεώνει την mEncVal (μέσα στα όριά της), και την κάνει scale γραμμικά ή λογαριθμικά στις τιμές της πραγματικής παραμέτρου (πχ volume panning κλπ). Το update δεν γίνεται σε κάθε render για να μην ζορίζεται το πρόγραμμα. Το κάθε συχνά πρέπει να γίνεται update είναι θέμα προς συζήτηση. Αν πχ ήθελα να παίξω με ένα φίλτρο σαν live automation, ποιο θα έπρεπε να είναι το update rate για να μην ακούγονται αυτά τα διακριτά update??
    
    float getParam();
};
