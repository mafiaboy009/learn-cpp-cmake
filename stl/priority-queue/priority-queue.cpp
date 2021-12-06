#include <iostream>
#include <queue>

using namespace std;

/*
 * priority_queue
 * -- functions
 *  -- empty()
 *  -- size()
 *  -- top()
 *  -- push()
 *  -- pop()
 *  -- swap()
 *  -- emplace() : unlike push(), the object is constructed in-place and saves an unnecessary copy
 *  -- value_type
 *
 * priority_queue<int> lpq1;
 * -- a max heap
 *
 * priority_queue<int, vector<int>, greater<int>> lpq2;
 * -- a min heap
 *
 */

template <typename T>
void showPriorityQueue(const T& pq) {
    cout << "priority_queue size " << pq.size() << '\n';
    T lpq{pq};
    cout << "The priority_queue is ";
    while(! lpq.empty() ){
        cout << lpq.top() << " ";
        lpq.pop();
    }
    cout << "\n\n";
}

int main(){

    //--- MAX HEAP ---//
    // we can create min heap from max heap by multiplying -1 to every entry; when top() multiply by -1
    priority_queue<int> lpq1;
    lpq1.push(10);
    lpq1.push(30);
    lpq1.push(30);
    lpq1.push(20);
    lpq1.push(5);
    lpq1.push(5);
    lpq1.emplace(4);
    showPriorityQueue( lpq1 );
    lpq1.pop();
    showPriorityQueue( lpq1 );

    //--- MIN HEAP ---//
    priority_queue<int, vector<int>, greater<int>> lpq2;
    lpq2.push(10);
    lpq2.push(30);
    lpq2.push(30);
    lpq2.push(20);
    lpq2.push(5);
    lpq2.push(5);
    showPriorityQueue( lpq2 );
    lpq2.pop();
    showPriorityQueue( lpq2 );

    return 0;
}
