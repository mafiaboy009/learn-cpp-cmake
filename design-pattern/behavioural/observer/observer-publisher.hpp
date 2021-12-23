#pragma once

#include <vector>
#include "observer-subscriber.hpp"

using namespace std;

struct publisher{
    virtual void subscribe( subscriber *sub ) = 0;
    virtual void unsubscribe( subscriber *sub ) = 0;
    virtual void notify() = 0;
};
