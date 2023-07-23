#include "linkedlist.hpp"

int main()
{
    linkedList aLinkedList;
    aLinkedList.insert(1);
    aLinkedList.insert(3);
    aLinkedList.insert(5);
    aLinkedList.insert(7);
    aLinkedList.insert(9);
    aLinkedList.print();
    aLinkedList.reverse();
    aLinkedList.print();
    return EXIT_SUCCESS;
}