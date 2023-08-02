#include "doubly-linked.cpp"

int main()
{
    {
        doublyLinkedList<int> linkedList;

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
    }
    {
        doublyLinkedList<char> linkedList;

        linkedList.push_front('h');
        linkedList.push_front('t');
        linkedList.push_front('r');
        linkedList.push_front('a');
        linkedList.push_front('e');
        linkedList.display();
    }

    return 0;
}