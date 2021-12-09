#pragma once
#include <iostream>
#include <memory>
#include <random>

using namespace std;

class Rectangle {
private:
	int length{};
	int breadth{};

public:
    Rectangle() = delete; // can be default too

	Rectangle(int l, int b)
    :length{l},
    breadth{b}
	{ }

    int getLength() const
    { 
        return length; 
    }

    int getBreadth() const 
    {
        return breadth; 
    }

	int area()
	{
		return length * breadth;
	}

    bool operator() (const Rectangle& r){
        if( getLength() == r.getLength() )
        {
            if( getBreadth() == r.getBreadth() )
            {
                return true;
            }
            return false;
        }
        else
        {
            return false;
        }

    }

};
