#include "node.hpp"

template <typename T>
node<T>* node<T>::getNextNode()
{
    return _nextNode;
}

template <typename T>
void node<T>::setNextNode(node<T>* nextNode)
{
    _nextNode = nextNode;
}

template <typename T>
T node<T>::getData()
{
    return _data;
}