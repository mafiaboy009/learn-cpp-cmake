#pragma once

#include <iostream>
#include <stdexcept>

using namespace std;

struct Node{
    int data;
    Node* next;
    Node* prev;

    Node(int data):data{data},next{nullptr},prev{nullptr}{}
};

struct DoublyLinkedList{
    Node *head;
    Node *tail;

    DoublyLinkedList():head{nullptr},tail{nullptr}{}

    void push_front(int data){

        if( head == nullptr && tail == nullptr ){
            head = new Node( data );
            tail = head;
        }
        else if( head == nullptr ){
            throw runtime_error("Invariants inconsistent!");
        }
        else if( tail == nullptr ){
            throw runtime_error("Invariants inconsistent!");
        }
        else{
            head->prev = new Node( data );
            head->prev->next = head;
            head = head->prev;
        }

    }

    void push_back(int data){

        if( head == nullptr && tail == nullptr ){
            head = new Node( data );
            tail = head;
        }
        else if( head == nullptr ){
            throw runtime_error("Invariants inconsistent!");
        }
        else if( tail == nullptr ){
            throw runtime_error("Invariants inconsistent!");
        }
        else{
            tail->next = new Node( data );
            tail->next->prev = tail;
            tail = tail->next;
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

    void reverseDisplay(){
        Node *nodePtr = tail;
        while( nodePtr ){
            cout << nodePtr->data << " ";
            nodePtr = nodePtr->prev;
        }
        cout << '\n';
    }

    void deleteNode( int position ){
        int count{};
        Node *tmpNode = head;
        while( tmpNode ){
            ++count;
            if( count == position ){
                Node *tmpNodePrev = tmpNode->prev;
                Node *tmpNodeNext = tmpNode->next;
                delete tmpNode;
                if( tmpNode == head ){
                    head = tmpNodeNext;
                }
                if( tmpNode == tail ){
                    tail = tmpNodePrev;
                }
                if( tmpNodePrev ){
                    tmpNodePrev->next = tmpNodeNext;
                }
                if( tmpNodeNext ){
                    tmpNodeNext->prev = tmpNodePrev;
                }
                return;
            }
            tmpNode = tmpNode->next;
        }
        if( count < position ){
            cout << "Position exceeded the size of the list, " << count << endl; 
        }
    }

    void clear( ){
        Node *nodePtr = head;
        while( nodePtr ){
            Node* tempNodePtr = nodePtr->next;
            delete nodePtr;
            nodePtr = tempNodePtr;
        }
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList(){
        Node *nodePtr = head;
        while( nodePtr ){
            //cout << "destructing node " << nodePtr->data << '\n';
            Node* tempNodePtr = nodePtr->next;
            delete nodePtr;
            nodePtr = tempNodePtr;
        }
    }

};

