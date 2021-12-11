#pragma once

#include <iostream>

using namespace std;

struct Node{
    int data;
    Node* next;

    Node(int data):data{data},next{nullptr}{}
};

struct LinkedList{
    Node *head;

    LinkedList():head{nullptr}{}

    void push(int data){
        if( head == nullptr ){
            head = new Node( data );
        }
        else{
            Node *nodePtr = head;
            Node *nextNodePtr = nodePtr->next;
            while( nextNodePtr ){
                nodePtr = nextNodePtr;
                nextNodePtr = nextNodePtr->next;
            }
            nodePtr->next = new Node( data );
        }
    }

    void display(){
        Node *nodePtr = head;
        while( nodePtr ){
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->next;
        }
        cout << '\n';
    }

    void reverse();

    ~LinkedList(){
        Node *nodePtr = head;
        while( nodePtr ){
            //cout << "destructing node " << nodePtr->data << '\n';
            Node* tempNodePtr = nodePtr->next;
            delete nodePtr;
            nodePtr = tempNodePtr;
        }
    }
};

