#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>



using namespace std;

/*

Given a reference of a node in a connected undirected graph.

Return a deep copy (clone) of the graph.

Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.



Test case format:

For simplicity, each node's value is the same as the node's index (1-indexed). For example, the first node with val == 1, the second node with val == 2, and so on. The graph is represented in the test case using an adjacency list.

An adjacency list is a collection of unordered lists used to represent a finite graph. Each list describes the set of neighbors of a node in the graph.

The given node will always be the first node with val = 1. You must return the copy of the given node as a reference to the cloned graph.

difficulty: medium

time: O(n)
space: O(n)
*/



//Node class
class Node {
public:
    int val; //value of the node
    vector<Node*> neighbors; //list of neighbors of the node
    Node() { //constructor for the node class
        val = 0; //set the value of the node to 0
        neighbors = vector<Node*>(); //set the neighbors of the node to an empty vector
    }
    Node(int _val) { //constructor with parameter _val to set the value of the node
        val = _val; //set the value of the node to the given value
        neighbors = vector<Node*>(); //set the neighbors of the node to an empty vector
    }
    Node(int _val, vector<Node*> _neighbors) { //constructor with given value and neighbors
        val = _val; //set the value of the node to the given value 
        neighbors = _neighbors; //set the neighbors of the node to the given neighbors
    }
};


class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp) //dfs function with parameter cur and mp to return a reference to a node
    {
        vector<Node*> neighbor; //create a vector called neighbor to store the neighbors of the current node
        Node* clone=new Node(cur->val); //create a new node called clone with the value of the current node 
        mp[cur]=clone;
            for(auto it:cur->neighbors) //loop through neighbors of current node (c++11 or above)
            {
                if(mp.find(it)!=mp.end()) //if current neighbor is already in map
                {
                    neighbor.push_back(mp[it]); //push back the neighbor into the neighbor vector
                }
                else
                    neighbor.push_back(dfs(it,mp)); //else call dfs function to get the neighbor and push back the neighbor into the neighbor vector
            }
            clone->neighbors=neighbor; //set the neighbors of the clone to the neighbor vector
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp; //create a map called mp to store the clone of the node
        if(node==NULL) 
            return NULL; 
        if(node->neighbors.size()==0) //if neighbors of node are empty
        {
            Node* clone= new Node(node->val); //create a new node called clone with the value of the node
            return clone; 
        }
        return dfs(node,mp); //else call dfs function to get the clone of the node and return the clone
    }
};


//test
int main() {
    Solution s;
    vector<vector<int>> adjList = {{2,4},{1,3},{2,4},{1,3}};
    Node* node = new Node(1);
    node->neighbors.push_back(new Node(2));
    node->neighbors.push_back(new Node(4));
    node->neighbors.push_back(new Node(3));
    Node* clone = s.cloneGraph(node); //call cloneGraph function to get the clone of the node
    return 0;
}