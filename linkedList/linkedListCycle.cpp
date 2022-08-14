#include <iostream>

using namespace std;

/*
Given head, the head of a linked list, determine if the linked list has a cycle in it.

There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to. Note that pos is not passed as a parameter.

Return true if there is a cycle in the linked list. Otherwise, return false.


Example 1:
Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 1st node (0-indexed).

Example 2:
Input: head = [1,2], pos = 0
Output: true
Explanation: There is a cycle in the linked list, where the tail connects to the 0th node.

Example 3:
Input: head = [1], pos = -1
Output: false
Explanation: There is no cycle in the linked list.


Constraints:
The number of the nodes in the list is in the range [0, 104].
-105 <= Node.val <= 105
pos is -1 or a valid index in the linked-list.

Difficulty: easy

Time: O(n)
Space: O(1)
*/


//Definition for singly-linked list.
struct ListNode {
    int val; // value of the node
    ListNode *next; // pointer to next node
    ListNode(int x) : val(x), next(NULL) {} // constructor for the node with value x and next pointer NULL to start
};

class Solution {
public:
    bool hasCycle(ListNode *head) { // function to check if there is a cycle in the linked list by using two pointers (slow and fast) and checking if they meet 
        
        if(head == NULL) // if the linked list is empty, there is no cycle
            return false;
        
        ListNode *slow = head; // slow pointer starts at the head of the linked list and moves one node at a time
        ListNode *fast = head; // fast pointer starts at the head of the linked list and moves two nodes at a time
        
        while(fast != NULL && fast->next != NULL) { // while the fast pointer is not at the end of the linked list and the next pointer of the fast pointer is not NULL
            slow = slow->next; // move the slow pointer one node at a time
            fast = fast->next->next; // move the fast pointer two nodes at a time
            if(slow == fast) // if the slow pointer and the fast pointer meet, there is a cycle in the linked list
                return true;
        }
        return false; // if the fast pointer is at the end of the linked list or the next pointer of the fast pointer is NULL, there is no cycle in the linked list
    }
};

//test
int main() {
    Solution s; // create a Solution object
    ListNode *head = new ListNode(1); // create a linked list with a cycle
    head->next = new ListNode(2); 
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    head->next->next->next->next->next->next = head->next->next; // make the last node point to the first node to create a cycle in the linked list by pointing the last node to the first node
    cout << s.hasCycle(head) << endl;
    return 0;
}