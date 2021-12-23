#include "observer-publisher.hpp"

struct newspaper: public publisher{

    vector<subscriber*> subscribers;

    newspaper():subscribers{}{}

    virtual void subscribe( subscriber *sub ) override{
        subscribers.push_back( sub );
    }

    virtual void unsubscribe( subscriber *sub ) override{
        for( auto it = subscribers.begin(); it != subscribers.end(); ){
            if( (*it)->getName() == sub->getName() ){
                cout << "Unsubscribing " << sub->getName() << endl;
                subscribers.erase( it );
            }
            else{
                ++it;
            }
        }
    }

    virtual void notify() override{
        for( auto it : subscribers ){
            it->update();
        }
    }

};
