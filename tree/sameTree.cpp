#include <iostream>

using namespace std;

/*
Given the roots of two binary trees p and q, write a function to check if they are the same or not.

Two binary trees are considered the same if they are structurally identical, and the nodes have the same value.


Example 1:
          1         1
         / \       / \
        2   3     2   3   

Input: p = [1,2,3], q = [1,2,3]
Output: true

Example 2:
              1         1
             /           \
            2             2

Input: p = [1,2], q = [1,null,2]
Output: false

Example 3:
                  1         1
                 / \       / \
                2   1     1   2

Input: p = [1,2,1], q = [1,1,2]
Output: false

Constraints:
The number of nodes in both trees is in the range [0, 100].
-104 <= Node.val <= 104

Difficulty: easy

Time: O(n)
Space: O(n)
*/


//Definition for a binary tree node.
struct TreeNode {
    int val; // the value of the node
    TreeNode *left; // the left child of the node
    TreeNode *right; // the right child of the node
    TreeNode() : val(0), left(nullptr), right(nullptr) {} // constructor for the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} // constructor with value as parameter
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} // constructor with value and children as parameters
};


class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) { // p is the root of the first tree, q is the root of the second tree
        if(p == NULL &&  q== NULL) return true; // if both trees are empty, return true
        if(p == NULL ||  q== NULL) return false; // if one of the trees is empty, return false
        if(p->val != q->val) return false; // if the values of the two trees are not equal, return false
        return isSameTree(p->right, q->right) && isSameTree(p->left, q->left) ; // if the values of the two trees are equal, check if the children of the two trees are equal
    }
};

//test
int main() {
    Solution s; //s is the solution class
    TreeNode *p = new TreeNode(1); // p is the root of the first tree
    TreeNode *q = new TreeNode(1); // q is the root of the second tree
    cout << "The two trees are " << (s.isSameTree(p, q) ? "equal" : "not equal") << endl;

    p = new TreeNode(1); // p is the root of the first tree 
    q = new TreeNode(1, NULL, new TreeNode(2));
    cout << "The two trees are " << (s.isSameTree(p, q) ? "equal" : "not equal") << endl;

    p = new TreeNode(1); //create a tree with one node
    p->right = new TreeNode(2); //add a right child to p
    p->right->left = new TreeNode(3); //add a left child to p->right


    q = new TreeNode(1);
    q->right = new TreeNode(2);
    q->right->left = new TreeNode(3);
    cout << "The two trees are " << (s.isSameTree(p, q) ? "equal" : "not equal") << endl;
    
    return 0;
}

