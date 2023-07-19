#include <iostream>
using namespace std;

class Colour{
    public:
    virtual Colour* clone(){
        return (new Colour(*this));
    }

};

class YellowColour: public Colour{
    public:
    virtual YellowColour* clone(){
        return (new YellowColour(*this));
    }

};

void fun(Colour *colour){
    //Colour* nColour = new Colour(*colour); // a colour is created and stored in nColour but we wanted YellowColour
    Colour* nColour = colour->clone(); // nColour is an YellowColour
    YellowColour* yColour = dynamic_cast<YellowColour*>(nColour);
    if( yColour ){
        cout << "Yay! I am yellow in colour" << endl;
    }
    else{
        cout << "Nah! I am some colour" << endl;
    }
    //....

}

int main(){
    YellowColour yColour = YellowColour();

    fun( &yColour );

    return EXIT_SUCCESS;
}