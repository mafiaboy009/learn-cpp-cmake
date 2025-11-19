#include <iostream>
#include <vector>
#include <queue>

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
    auto cmp = [](ListNode *a, ListNode *b) { return a->val > b->val; };
    std::priority_queue<ListNode *, vector<ListNode *>, decltype(cmp)> pq(cmp);

    // Initialize the priority queue with the head of each list
    for (ListNode * node: lists)
    {
        if(node)
          pq.push(node);
    }

    ListNode *returnList = new ListNode(0);
    ListNode *curr = returnList;

    // Process the priority queue
    while (!pq.empty())
    {
        ListNode *smallest = pq.top();
        pq.pop();
        curr->next = smallest;
        curr = smallest;
        
        if (smallest->next)
        {
            pq.push(smallest->next);
        }
    }

    return returnList->next;
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

    ListNode *list4 = nullptr;
    printList(list4);

    vector<ListNode *> lists = {list1, list2, list3, list4};

    ListNode *mergedList = mergeKLists(lists);
    printList(mergedList);

    return 0;
}