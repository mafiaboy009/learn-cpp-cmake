/*
Reverse Nodes in k-Group

Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

You may not alter the values in the list's nodes, only nodes themselves may be changed.

https://leetcode.com/problems/reverse-nodes-in-k-group

*/

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// utility function to reverse k nodes in the linked list
void printList(ListNode *list);

ListNode *reverseKGroup(ListNode *head, int k)
{
    ListNode *start = head;
    ListNode *temp = nullptr;
    bool firstIteration = true;

    if (start == nullptr || k <= 1)
    {
        return head;
    }

    while (true)
    {
        std::stack<ListNode *> nodeStack;
        
        for (int i = 0; i < k; ++i)
        {
            if (start)
            {
                nodeStack.push(start);
                start = start->next;
            }
            else
            {
                break;
            }
        }

        if (nodeStack.size() == k)
        {
            for (int i = 0; i < k; ++i)
            {
                ListNode *node = nodeStack.top();
                nodeStack.pop();
                if (firstIteration)
                {
                    head = node;
                    firstIteration = false;
                }
                else
                {
                    if (temp)
                    {
                        temp->next = node;
                    }
                    if (node)
                    {
                        node->next = temp;
                    }
                }
                temp = node;
            }
        }
        else
        {
            if (!nodeStack.empty())
            {
                if (temp)
                {
                    if (nodeStack.size() == 1)
                    {
                        temp->next = nodeStack.top();
                    }
                    else
                    {
                        while( nodeStack.size() > 1 )
                        {
                            nodeStack.pop();
                            temp->next = nodeStack.top();
                        }
                    }
                }
            }
            else{
                if (temp)
                {
                    temp->next = nullptr;
                }
            }
            break;
        }
    }
    return head;
}

int main()
{
    std::cout << "-- Reverse k-Group in a Linked List --" << std::endl;

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(2);
    list1->next->next = new ListNode(3);
    list1->next->next->next = new ListNode(4);
    list1->next->next->next->next = new ListNode(5);

    printList(list1);

    for (int k = 0; k < 6; ++k)
    {
        cout << "Reversing nodes in groups of " << k << ":" << endl;
        list1 = reverseKGroup(list1, k);
        printList(list1);
    }

    return 0;
}

void printList(ListNode *list)
{
    ListNode *currentNode = list;
    while (currentNode != nullptr)
    {
        cout << currentNode->val << " -> ";
        currentNode = currentNode->next;
    }
    cout << "nullptr" << endl;
}