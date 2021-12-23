#include "observer-subscriber.hpp"

struct newsreader : public subscriber{

    string name{};

    newsreader(string _name):name{_name}{}

    void update() override{
        cout << "I am " << name << endl;
    }

    string getName() override{
        return name;
    }
};
