#include <iostream>

using namespace std;

/*

Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

Input: root = [3,9,20,null,null,15,7]
Output: 3

Constraints:

The number of nodes in the tree is in the range [0, 104].
-100 <= Node.val <= 100

difficulty: easy

time: O(n)
space: O(n)

*/


//Definition for a binary tree node.
struct TreeNode { //create a struct called TreeNode to store the values of the nodes
    int val; //the value of the node
    TreeNode *left; //the left child of the node
    TreeNode *right; //the right child of the node
    TreeNode() : val(0), left(nullptr), right(nullptr) {} //constructor to initialize the values of the node
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {} //constructor to initialize the values of the node with a value of x
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {} //constructor to initialize the values of the node with a value of x and left and right children
};

class Solution {
public:
    int maxDepth(TreeNode* root) { //create a function called maxDepth that takes in a TreeNode called root
        if (root == nullptr) { //if the root is null or empty because the tree is empty
            return 0; //return 0
        }
        return max(maxDepth(root->left), maxDepth(root->right)) + 1; //return the maximum depth of the left and right children of the root plus 1 because the root is one level down
    }
};

//test
int main() {
    Solution s;
    TreeNode *root = new TreeNode(3); //create a TreeNode called root with a value of 3
    root->left = new TreeNode(9); //create a TreeNode called left with a value of 9
    root->right = new TreeNode(20); //create a TreeNode called right with a value of 20
    root->right->left = new TreeNode(15); //create a TreeNode called left with a value of 15
    root->right->right = new TreeNode(7); //create a TreeNode called right with a value of 7
    cout << "The max depth of binary tree is: " << s.maxDepth(root) << endl;
    return 0;
}