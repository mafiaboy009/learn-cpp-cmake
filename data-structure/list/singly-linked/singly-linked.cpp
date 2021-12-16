#include "singly-linked.hpp"

int main(){

    SinglyLinkedList linkedList;

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
