#include "linkedlist.hpp"

int main()
{
    linkedList<int> aLinkedList;
    aLinkedList.print();
    aLinkedList.insert(5);
    aLinkedList.insert(1);
    aLinkedList.insert(5);
    aLinkedList.insert(3);
    aLinkedList.insert(5);
    aLinkedList.insert(7);
    aLinkedList.insert(5);
    aLinkedList.insert(9);
    aLinkedList.insert(5);
    aLinkedList.print();
    aLinkedList.reverse();
    aLinkedList.print();
    aLinkedList.reverse();
    aLinkedList.removeDuplicates(5);
    aLinkedList.print();
    aLinkedList.remove(10);
    aLinkedList.reverse();
    aLinkedList.print();
    aLinkedList.remove(1);
    aLinkedList.remove(6);
    aLinkedList.print();
    aLinkedList.removeData(5);
    aLinkedList.print();
    return EXIT_SUCCESS;
}