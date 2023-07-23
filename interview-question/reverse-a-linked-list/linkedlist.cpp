#include "linkedlist.hpp"

template <class T>
void linkedList<T>::insert(T inData)
{
    if (_head)
    {
        node<T> *currNode = _head;
        node<T> *temp = nullptr;
        while (currNode)
        {
            temp = currNode->getNextNode();
            if (temp)
            {
                currNode = temp;
            }
            else
            {
                break;
            }
        }
        currNode->setNextNode(new node<T>(inData));
        ++_length;
    }
    else
    {
        _head = new node<T>(inData);
        ++_length;
    }
}

template <class T>
void linkedList<T>::reverse()
{
    if (_head)
    {
        node<T> *currNode = _head;
        node<T> *nextNode = _head->getNextNode();
        while (nextNode)
        {
            node<T> *temp = nextNode->getNextNode();
            nextNode->setNextNode(currNode);
            currNode = nextNode;
            nextNode = temp;
        }
        _head->setNextNode(nullptr);
        _head = currNode;
    }
    return;
}

template <class T>
void linkedList<T>::print()
{
    if (_head)
    {
        node<T> *currNode = _head;
        while (currNode)
        {
            cout << currNode->getData();
            currNode = currNode->getNextNode();
            if (currNode)
            {
                cout << " -> ";
            }
        }
        cout << "\n";
    }
    else
    {
        cout << "Empty List !!\n";
    }
    return;
}

template <class T>
void linkedList<T>::remove(unsigned nodeNum)
{
    if (_head)
    {
        if (nodeNum == 1)
        {
            node<T> *nextNode = _head->getNextNode();
            delete _head;
            --_length;
            _head = nextNode;
        }
        else if (nodeNum > 1 && nodeNum <= _length)
        {
            unsigned i = 1;
            node<T> *currNode = _head;
            node<T> *nextNode = _head->getNextNode();
            node<T> *prevNode = nullptr;
            while (nextNode)
            {
                node<T> *temp = nextNode->getNextNode();
                prevNode = currNode;
                currNode = nextNode;
                nextNode = temp;
                ++i;
                if (nodeNum == i)
                {
                    break;
                }
            }
            prevNode->setNextNode(nextNode);
            delete currNode;
            --_length;
        }
        else
        {
            cout << "node does not exist!\n";
        }
    }
}

template <class T>
void linkedList<T>::findData(T inData, vector<unsigned> &index)
{
    if (_head)
    {
        unsigned i{1};
        node<T> *currNode = _head;
        while (currNode)
        {
            if (currNode->getData() == inData)
            {
                index.push_back(i);
            }
            currNode = currNode->getNextNode();
            ++i;
        }
        sort(index.begin(), index.end(), greater<unsigned>());
    }
    else
    {
        cout << "None found!\n";
    }
}

/* remove all */
template <class T>
void linkedList<T>::removeData(T inData)
{
    vector<unsigned> index;
    findData(inData, index);
    for (auto v : index)
    {
        remove(v);
    }
}

/* remove all but one */
template <class T>
void linkedList<T>::removeDuplicates(T inData)
{
    vector<unsigned> index;
    findData(inData, index);
    int indexSize = index.size();
    for (int i{0}; i < indexSize - 1; ++i)
    {
        remove(index[i]);
    }
}