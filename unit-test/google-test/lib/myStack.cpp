#include "myStack.hpp"

MyStack::MyStack():_sp{-1}{
}

void MyStack::push(int elem){
    _stack.push_back(elem);
    ++_sp;
}

void MyStack::pop(){
    if( _sp == -1 ){
        throw runtime_error("stack empty!");
    }
    else{
        --_sp;
    }
}

int MyStack::top(){
    if( _sp == -1 ){
        throw runtime_error("stack empty!");
    }
    else{
        return _stack[_sp];
    }
}

string MyStack::toString(){
    string str;
    int i = _sp;
    while(i!=-1){
        str+= to_string(_stack[i]);
        str+=" ";
        --i;
    }
    str+="\n";
    return str;
}
