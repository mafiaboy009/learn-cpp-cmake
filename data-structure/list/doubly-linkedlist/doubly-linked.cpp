#include "doubly-linked.hpp"

template <typename T>
void doublyLinkedList<T>::push_front(T data)
{
    if (head == nullptr && tail == nullptr)
    {
        head = new doubly_node<T>(data);
        tail = head;
    }
    else if (head == nullptr)
    {
        throw runtime_error("Invariants inconsistent!");
    }
    else if (tail == nullptr)
    {
        throw runtime_error("Invariants inconsistent!");
    }
    else
    {
        head->setPrevNode( new doubly_node<T>(data) );
        head->getPrevNode()->setNextNode( head );
        head = head->getPrevNode();
    }
}

template <typename T>
void doublyLinkedList<T>::push_back(T data)
{

    if (head == nullptr && tail == nullptr)
    {
        head = new doubly_node<T>(data);
        tail = head;
    }
    else if (head == nullptr)
    {
        throw runtime_error("Invariants inconsistent!");
    }
    else if (tail == nullptr)
    {
        throw runtime_error("Invariants inconsistent!");
    }
    else
    {
        tail->setNextNode( new doubly_node<T>(data) );
        tail->getNextNode()->setPrevNode( tail );
        tail = tail->getNextNode();
    }
}

template <typename T>
void doublyLinkedList<T>::display()
{
    doubly_node<T> *nodePtr = head;
    while (nodePtr)
    {
        cout << nodePtr->getData() << " ";
        nodePtr = nodePtr->getNextNode();
    }
    cout << '\n';
}

template <typename T>
void doublyLinkedList<T>::reverseDisplay()
{
    doubly_node<T> *nodePtr = tail;
    while (nodePtr)
    {
        cout << nodePtr->data << " ";
        nodePtr = nodePtr->getPrevNode();
    }
    cout << '\n';
}

template <typename T>
void doublyLinkedList<T>::deleteNode(int position)
{
    int count{};
    doubly_node<T> *tmpNode = head;
    while (tmpNode)
    {
        ++count;
        if (count == position)
        {
            doubly_node<T> *tmpNodePrev = tmpNode->getPrevNode();
            doubly_node<T> *tmpNodeNext = tmpNode->getNextNode();
            delete tmpNode;
            if (tmpNode == head)
            {
                head = tmpNodeNext;
            }
            if (tmpNode == tail)
            {
                tail = tmpNodePrev;
            }
            if (tmpNodePrev)
            {
                tmpNodePrev->setNextNode( tmpNodeNext );
            }
            if (tmpNodeNext)
            {
                tmpNodeNext->setPrevNode( tmpNodePrev );
            }
            return;
        }
        tmpNode = tmpNode->getNextNode();
    }
    if (count < position)
    {
        cout << "Position exceeded the size of the list, " << count << endl;
    }
}

template <typename T>
void doublyLinkedList<T>::clear()
{
    doubly_node<T> *nodePtr = head;
    while (nodePtr)
    {
        doubly_node<T> *tempNodePtr = nodePtr->getNextNode();
        delete nodePtr;
        nodePtr = tempNodePtr;
    }
    head = nullptr;
    tail = nullptr;
}

template <typename T>
doublyLinkedList<T>::~doublyLinkedList()
{
    doubly_node<T> *nodePtr = head;
    while (nodePtr)
    {
        // cout << "destructing node " << nodePtr->data << '\n';
        doubly_node<T> *tempNodePtr = nodePtr->getNextNode();
        delete nodePtr;
        nodePtr = tempNodePtr;
    }
}