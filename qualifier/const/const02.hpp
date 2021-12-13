#pragma once
#include <iostream>
using namespace std;

class Dog{

    int age{};
    string name{};

    public:

    Dog():age{3}, name{"Tommy"}{}

    void setAge( const int& newAge){
        cout << "const setAge" << endl;
        age = newAge;
        //++newAge;
    }

    void setAge( int& newAge){
        cout << "non-const setAge" << endl;
        age = newAge;
    }

    int getAge(){
        return age;
    }

    /* following two functions are similar, except for const
    void setAge( int newAge){
    void setAge( const int newAge){
    */

    // const return value
    const string& getName() {
        return name;
    }
    //const string getName(); // completely useless

    // const function -- this function will be invoked when dog is a const
    void printDogName() const { // const here ensures that none of the member variables are changed
        cout << "const " << name << " " << age << endl;
        //++newAge; // compile err
        //cout << getName() << endl; // compile err since getName() is non-const function
    }

    // non-const function -- this function will be invoked when dog is a non-const
    void printDogName() { 
        cout << "non-const " << name << " " << age << endl;
    }

};
