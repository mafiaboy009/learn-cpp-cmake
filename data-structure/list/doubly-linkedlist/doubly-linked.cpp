#include "doubly-linked.hpp"

int main(){

    DoublyLinkedList linkedList;

    linkedList.push_front(2);
    linkedList.push_front(3);
    linkedList.push_front(8);
    linkedList.push_front(5);
    linkedList.push_front(10);
    linkedList.display();

    linkedList.push_back(12);
    linkedList.display();

    linkedList.deleteNode(1);
    linkedList.display();

    linkedList.deleteNode(10);
    linkedList.display();

    linkedList.deleteNode(5);
    linkedList.display();

    linkedList.clear();
    linkedList.display();

    return 0;
}
