#pragma once
#include <iostream>
using namespace std;

class node final{
    private:
    int _data{};
    node* _nextNode{nullptr};
    public:
    node():_data{-1},_nextNode{}{}
    node(int inData):_data{inData},_nextNode{nullptr}{}
    node* getNextNode();
    void setNextNode(node* nextNode);
    int getData();
};

node* node::getNextNode(){
    return _nextNode;
}

void node::setNextNode(node* nextNode){
    _nextNode = nextNode;
}

int node::getData(){
    return _data;
}

class linkedList final{
    private:
    node* _head{nullptr};
    unsigned _length{};
    public:
    linkedList():_head{nullptr},_length{0}{}
    void insert(int inData);
    void reverse();
    void print();
};

void linkedList::insert(int inData){
    if( _head )
    {
        node* currNode = _head;
        node* temp = nullptr;
        while( currNode )
        {
            temp = currNode->getNextNode();
            if( temp )
            {
                currNode = temp;
            }
            else
            {
                break;
            }
        }
        currNode->setNextNode(new node( inData ) );
        ++_length;
    }
    else{
        _head = new node( inData );
        ++_length;
    }
}

void linkedList::reverse(){
    if( _head )
    {
        node* currNode = _head;
        node* nextNode = _head->getNextNode();
        while( nextNode )
        {
            node* temp = nextNode->getNextNode();
            nextNode->setNextNode( currNode );
            currNode = nextNode;
            nextNode = temp;
        }
        _head->setNextNode(nullptr);
        _head = currNode;
    }
    return;
}

void linkedList::print(){
    if( _head )
    {
        node* currNode = _head;
        while( currNode )
        {
            cout << currNode->getData();
            currNode = currNode->getNextNode();
            if ( currNode ){
                cout << " -> ";
            }
        }
        cout << "\n";
    }
    return;
}