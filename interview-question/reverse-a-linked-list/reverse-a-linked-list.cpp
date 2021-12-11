#include "reverse-a-linked-list.hpp"

void LinkedList::reverse(){
    Node *nodePtr = head;
    Node *nextNodePtr = nodePtr->next;

    while( nextNodePtr ){
        Node *tempNodePtr = nextNodePtr->next;
        nextNodePtr->next = nodePtr;
        nodePtr = nextNodePtr;
        nextNodePtr = tempNodePtr;
    }

    head->next = nullptr;
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

    return 0;
}
