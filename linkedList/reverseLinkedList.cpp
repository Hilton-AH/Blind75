#include <iostream>
#include <vector>

using namespace std;

/*

Given the head of a singly linked list, reverse the list, and return the reversed list.

difficulty: easy

time: O(n)
space: O(1)

*/


//Definition for singly-linked list.
struct ListNode {
    int val; //value of the node
    ListNode *next; //pointer to the next node
    ListNode() : val(0), next(nullptr) {} //constructor for the node that sets the value to 0 and the pointer to nullptr 
    ListNode(int x) : val(x), next(nullptr) {} //constructor for the node that sets the value to x and the pointer to nullptr
    ListNode(int x, ListNode *next) : val(x), next(next) {} //constructor for the node that sets the value to x and the pointer to the next node and sets the next node to the next node in order to create a linked list
};

class Solution {
public:
    ListNode* reverseList(ListNode* head) { //ListNode* is a pointer to a ListNode object that points to the next node in the list.... ListNode* head is a pointer to the head of the list
        ListNode* prev = nullptr; //set previous node to nullptr because we are starting at the head of the list
        ListNode* curr = head; //set current node to the head of the list in order to start the loop
        ListNode* next = nullptr; //set next node to nullptr because we are starting at the head of the list
        
        while (curr != nullptr) { //while the current node is not nullptr or the end of the list
            next = curr->next; //set next node to the next node in the list in order to move to the next node
            curr->next = prev; //set the next node to the previous node in the list to reverse the list (set the next node to the previous node)
            prev = curr; //set the previous node to the current node in order to move to the next node in the list
            curr = next; //set the current node to the next node in the list so we can loop through the list
        }
        
        return prev; //return the previous node because it is the head of the reversed list
    }
};

//test
int main() {
    Solution s;
    ListNode* head = new ListNode(1); //create a new ListNode object called head with a value of 1
    head->next = new ListNode(2); //set the next node of the head to a new ListNode object with a value of 2 and continue to set the next node to the next node in the list
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    //print the list
    ListNode* curr = head; //set curr to the head of the list
    vector<int> result; //create a vector called result to store the values of the list
    while (curr != nullptr) { //while the current node is not nullptr or the end of the list
        result.push_back(curr->val); //add the value of the current node to the vector
        curr = curr->next; //move to the next node in the list
    }
    cout << "original list: " << "[";
    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }
    cout << "]" << endl;

    ListNode* reversed = s.reverseList(head); //set reversed to the reversed list of the head to reverse the list
    vector<int> reversedVector;
    while (reversed != nullptr) {
        reversedVector.push_back(reversed->val);
        reversed = reversed->next;
    }
    cout << "reversed: " << "[";
    for (int i = 0; i < reversedVector.size(); i++) {
        cout << reversedVector[i] << " ";
    }
    cout << "]" << endl;
    return 0;
}

//recursive solution
/*
class Solution {
public:
    ListNode* reverseList(ListNode *head, ListNode *nextNode = NULL, ListNode *prevNode = NULL) {
        return head ? reverseList(head->next, (head->next = prevNode, nextNode), head) : prevNode;
    }
};
*/