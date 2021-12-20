#include "reverse-a-linked-list.hpp"

void LinkedList::reverse(){
    Node *nodePtr = head;
    Node *nextNodePtr = nullptr;
    if( head ){
        if( head->next ){
            nextNodePtr = nodePtr->next;
        }
    }
    while( nextNodePtr ){
        Node *tempNodePtr = nextNodePtr->next;
        nextNodePtr->next = nodePtr;
        nodePtr = nextNodePtr;
        nextNodePtr = tempNodePtr;
    }
    if( head ){
        if( head->next ){
            head->next = nullptr;
        }
    }
    head = nodePtr;
}

int main(){

    LinkedList linkedList;

    linkedList.push(2);
    linkedList.push(3);
    linkedList.push(8);
    linkedList.push(5);
    linkedList.push(10);
    linkedList.display();

    linkedList.reverse();
    linkedList.display();

    linkedList.reverse();
    linkedList.display();

    LinkedList linkedList1;
    linkedList1.reverse();
    linkedList1.display();

    return 0;
}
