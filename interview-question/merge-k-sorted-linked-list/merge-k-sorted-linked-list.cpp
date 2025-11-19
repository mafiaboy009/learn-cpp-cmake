#include <iostream>
#include <vector>

using namespace std;

// https://leetcode.com/problems/merge-k-sorted-lists/

// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

bool isAllListEmpty(const vector<ListNode *> &lists)
{
    bool listEmpty = true;
    for (int i = 0; i < lists.size(); ++i)
    {
        if (lists[i] != nullptr)
        {
            listEmpty &= false;
        }
    }
    return listEmpty;
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

ListNode *mergeKLists(vector<ListNode *> &lists)
{
    int numberOfLists = lists.size();

    if (numberOfLists == 0)
    {
        return nullptr;
    }

    bool allListEmpty = isAllListEmpty(lists);
    if (allListEmpty)
    {
        return nullptr;
    }

    if (numberOfLists == 1)
    {
        return lists[0];
    }

    vector<ListNode *> copyLists = lists;

    ListNode *returnList = nullptr;

    while (!isAllListEmpty(copyLists))
    {
        int smallest, idx;
        for(int i = 0; i < numberOfLists; i++)
        {
            if (copyLists[i] != nullptr)
            {
                smallest = copyLists[i]->val;
                idx = i;
                break;
            }
        }

        for (int i = 1; i < numberOfLists; i++)
        {
            if (copyLists[i] != nullptr && copyLists[i]->val < smallest )
            {
                smallest = copyLists[i]->val;
                idx = i;
            }
        }

        if( returnList == nullptr )
        {
            returnList = new ListNode(smallest);
        }
        else
        {
            ListNode *currentNode = returnList;
            while (currentNode->next != nullptr)
            {
                currentNode = currentNode->next;
            }
            currentNode->next = new ListNode(smallest);
        }

        copyLists[idx] = copyLists[idx]->next;
    }

    return returnList;
}

int main()
{
    std::cout << "-- Merge k sorted linked list --" << std::endl;

    ListNode *list1 = new ListNode(1);
    list1->next = new ListNode(4);
    list1->next->next = new ListNode(5);
    printList(list1);

    ListNode *list2 = new ListNode(1);
    list2->next = new ListNode(3);
    list2->next->next = new ListNode(4);
    printList(list2);

    ListNode *list3 = new ListNode(2);
    list3->next = new ListNode(6);
    printList(list3);

    vector<ListNode *> lists = {list1, list2, list3};

    ListNode *mergedList = mergeKLists(lists);
    printList(mergedList);

    return 0;
}