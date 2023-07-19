#pragma once

#include <iostream>
#include <cstring>

using namespace std;

class stringClass{

    private:

    protected:

    public:
        char *array;

	// default ctor
        stringClass();

	//ctor
        stringClass(char* chArr);

	//copy ctor
        stringClass(const stringClass& str);

	//move ctor
        stringClass(stringClass&& str);

	//dtor
        ~stringClass();

        stringClass& operator=(const stringClass& rhs);
        stringClass& operator=(stringClass&& rhs);

        char operator[](int i) const;
        char& operator[](int i);

        operator char*();

        void print();
};
