#include "newspaper.hpp"
#include "newsreader.hpp"

int main(){
    newspaper theGuardian;
    newsreader thePanda{"Po"};
    newsreader theTigri{"Grr"};
    theGuardian.subscribe( &thePanda );
    theGuardian.notify();
    theGuardian.subscribe( &theTigri );
    theGuardian.notify();
    theGuardian.unsubscribe( &theTigri );
    theGuardian.notify();
    return 0;
}
