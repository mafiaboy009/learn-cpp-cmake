#include "stringClass.hpp"


stringClass::stringClass(char* chArr){
    if( chArr == nullptr){
        array = new char[1];
        array[0] = '\0';
    }
    else{
        int length = strlen( chArr );
        array = new char[length+1];
        for(int i = 0; i < length; i++ ){
            array[i] = chArr[i];
        }
        array[length] = '\0';
    }
}

stringClass::stringClass(){
    array = new char[1];
    array[0] = '\0';
}

stringClass::stringClass(const stringClass& str){
    int length = strlen( str.array )+1;
    array = new char[length];
    for(int i = 0; i < length; i++ ){
        array[i] = str[i];
    }
}

stringClass::stringClass(stringClass&& str){
    array = str.array;
    str.array = nullptr;
}

void stringClass::print(){
    cout << array << '\n';
}

stringClass& stringClass::operator=(stringClass&& rhs){
    delete[] array;
    array=rhs.array;
    rhs.array = nullptr;
    return *this;
}

stringClass& stringClass::operator=(const stringClass& rhs){
    if( this == &rhs){
        return *this;
    }
    stringClass str(rhs);
    *this = move(str);
    return *this;
}

char stringClass::operator[](int i) const {
    return array[i];
}

char& stringClass::operator[](int i){
    return array[i];
}

stringClass::operator char*() { return array;}

stringClass::~stringClass(){
    delete[] array;
}
