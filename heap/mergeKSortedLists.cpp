#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*
You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.
Merge all the linked-lists into one sorted linked-list and return it.


Example 1:
Input: lists = [[1,4,5],[1,3,4],[2,6]]
Output: [1,1,2,3,4,4,5,6]
Explanation: The linked-lists are:
[
1->4->5,
1->3->4,
2->6
]
merging them into one sorted list:
1->1->2->3->4->4->5->6

Example 2:
Input: lists = []
Output: []

Example 3:
Input: lists = [[]]
Output: []


Constraints:

k == lists.length
0 <= k <= 104
0 <= lists[i].length <= 500
-104 <= lists[i][j] <= 104
lists[i] is sorted in ascending order.
The sum of lists[i].length will not exceed 104.

Difficulty: hard

Time: O(n)
Space: O(n)
*/


//Definition for singly-linked list.
struct ListNode { //struct for linked list
    int val; //value of the node
    ListNode *next; //pointer to the next node
    ListNode() : val(0), next(nullptr) {} //constructor for the node
    ListNode(int x) : val(x), next(nullptr) {} //constructor for the node with a value of x
    ListNode(int x, ListNode *next) : val(x), next(next) {} //constructor for the node with a value of x and a pointer to the next node
};

//DIVIDE AND CONQUER
class Solution {
public:
    ListNode* merge2Lists(ListNode* l1, ListNode* l2) { //parameters are the two linked lists to merge
        if (!l1) return l2; //if l1 is empty return l2
        if (!l2) return l1; //if l2 is empty return l1
        ListNode* head = l1->val <= l2->val? l1 : l2; //if l1 is less than l2 set head to l1 else set head to l2
        head->next = l1->val <= l2->val ? merge2Lists(l1->next, l2) : merge2Lists(l1, l2->next); //if l1 is less than l2 merge l1 with the next node of l2 else merge l2 with the next node of l1
        return head; //return the head of the merged linked list
    }
    
    ListNode* mergeKLists(vector<ListNode*>& lists) { //parameters are the vector of linked lists to merge
        if (lists.size() == 0) return NULL; //if the vector is empty return NULL
        
        ListNode* head = lists[0]; //set the head of the merged linked list to the first linked list in the vector
        
        for (int i = 1; i < lists.size(); i++) { //for each linked list in the vector
            head = merge2Lists(head, lists[i]); //merge the linked list with the head of the merged linked list
        }
        return head; //return the head of the merged linked list
    }
};

//test
int main() {
    Solution s;
    vector<ListNode*> lists; //vector of linked lists
    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6)));
    ListNode* head = s.mergeKLists(lists); //merge the linked lists
    while (head) { //while the head of the merged linked list is not empty
        cout << head->val << " "; //print the value of the head of the merged linked list
        head = head->next; //move to the next node of the merged linked list
    }
    cout << endl;
    return 0;
}







//RECURSION USING HEAP AND PRIORITY QUEUE
/*
Concept:

1.Heap is a kind of data structure. It is a name for a particular way of storing data that makes certain operations very efficient. We can use a tree or array to describe it.

   18
  /	\
 10	 16
/ \   / \
9  5  8  12

18, 10, 16, 9, 5, 8, 12
2.Priority queue is an abstract datatype. It is a shorthand way of describing a particular interface and behavior, and says nothing about the underlying implementation.

A heap is a very good data structure to implement a priority queue. The operations which are made efficient by the heap data structure are the operations that the priority queue interface needs.



// 1.priority_queue: we can only get the top element (from ChiangKaiShrek's solution)
class solution {
    public:
struct compare {
    bool operator()(const ListNode* l, const ListNode* r) {
        return l->val > r->val;
    }
};
ListNode *mergeKLists(vector<ListNode *> &lists) { //priority_queue
    priority_queue<ListNode *, vector<ListNode *>, compare> q;
    for(auto l : lists) {
        if(l)  q.push(l);
    }
    if(q.empty())  return NULL;

    ListNode* result = q.top();
    q.pop();
    if(result->next) q.push(result->next);
    ListNode* tail = result;            
    while(!q.empty()) {
        tail->next = q.top();
        q.pop();
        tail = tail->next;
        if(tail->next) q.push(tail->next);
    }
    return result;
}

//2.make_heap: we can access all the elements (from my answer for that solution)

static bool heapComp(ListNode* a, ListNode* b) {
        return a->val > b->val;
}
ListNode* mergeKLists(vector<ListNode*>& lists) { //make_heap
    ListNode head(0);
    ListNode *curNode = &head;
    vector<ListNode*> v;   
    for(int i =0; i<lists.size(); i++){
        if(lists[i]) v.push_back(lists[i]);
    }
    make_heap(v.begin(), v.end(), heapComp); //vector -> heap data strcture

    while(v.size()>0){
        curNode->next=v.front();
        pop_heap(v.begin(), v.end(), heapComp); 
        v.pop_back(); 
        curNode = curNode->next;
        if(curNode->next) {
            v.push_back(curNode->next); 
            push_heap(v.begin(), v.end(), heapComp);
        }
    }
    return head.next;
}
};

*/