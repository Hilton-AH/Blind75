#include <iostream>
#include <queue>
#include <vector>

using namespace std;

/*

There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.

For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
Return true if you can finish all courses. Otherwise, return false.


Example 1:

Input: numCourses = 2, prerequisites = [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0. So it is possible.

Example 2:

Input: numCourses = 2, prerequisites = [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take. 
To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.

Constraints:

1 <= numCourses <= 2000
0 <= prerequisites.length <= 5000
prerequisites[i].length == 2
0 <= ai, bi < numCourses
All the pairs prerequisites[i] are unique.

Difficulty: medium

Time: O(n)
Space: O(n)

*/

class Solution { //This is a topological sort problem
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        if (numCourses == 0) { //if numCourses is 0 return true because there are no courses to take
            return true;
        }
        
        if (prerequisites.size() == 0) { //if prerequisites is empty return true because there are no prerequisites
            return true;
        }
        
        vector<vector<int>> adjList(numCourses); //create a vector of vectors called adjList and initialize it to numCourses (adjacency list for the graph)
        vector<int> inDegree(numCourses, 0); //create a vector called inDegree and initialize it to numCourses (inDegree for the graph)
        
        for (int i = 0; i < prerequisites.size(); i++) { //for loop that starts at 0 and goes to prerequisites.size
            adjList[prerequisites[i][1]].push_back(prerequisites[i][0]); //set adjList[prerequisites[i][1]] to prerequisites[i][0] which will add the prerequisite to the adjacency list
            inDegree[prerequisites[i][0]]++; //set inDegree[prerequisites[i][0]] to inDegree[prerequisites[i][0]] + 1 which will add 1 to the inDegree of the prerequisite so that we know how many prerequisites a course has
        }
        
        queue<int> q; //create a queue called q (queue uses FIFO so we can use it to implement a topological sort
        
        for (int i = 0; i < inDegree.size(); i++) { //for loop that starts at 0 and goes to inDegree.size to check if there are any courses with 0 inDegree
            if (inDegree[i] == 0) { //if inDegree[i] is 0 (if a course has no prerequisites)
                q.push(i); //push i into q
            }
        }
        
        while (!q.empty()) { //while q is not empty
            int curr = q.front(); //set curr to q.front which will get the first element in q
            q.pop(); //pop q which will remove the first element in q in order to get the next element in q
            
            for (int i = 0; i < adjList[curr].size(); i++) { //for loop that starts at 0 and goes to adjList[curr].size to check if there are any courses that depend on the current course
                inDegree[adjList[curr][i]]--; //set inDegree[adjList[curr][i]] to inDegree[adjList[curr][i]] - 1 which will subtract 1 from the inDegree of the course that depends on the current course
                if (inDegree[adjList[curr][i]] == 0) { //if inDegree[adjList[curr][i]] is 0 (if a course has no prerequisites)
                    q.push(adjList[curr][i]); //push adjList[curr][i] into q which will add the course that depends on the current course to the queue
                }
            }
        }

        for (int i = 0; i < inDegree.size(); i++) { //for loop that starts at 0 and goes to inDegree.size to check if there are any courses with inDegree > 0
            if (inDegree[i] != 0) { //if inDegree[i] is not 0 (if a course has prerequisites)
                return false; //return false
            }
        }

        return true; //return true
    }
};

//test 
int main() {
    Solution s;
    vector<vector<int>> prerequisites = {{1,0},{0,1},{1,2},{2,3}};
    if (s.canFinish(4, prerequisites)) {
        cout << "You can finish all courses." << endl;
    } else {
        cout << "You can not finish all courses." << endl;
    }
    return 0;
}




/*

This problem is equivalent to detecting a cycle in the directed graph represented by prerequisites. Both BFS and DFS can be used to solve it using the idea of topological sort. Since pair<int, int> is inconvenient for implementing graph algorithms, we first transform it to the adjacency-list representation. If course u is a prerequisite of course v, then the adjacency list of u will contain v.



BFS

BFS uses the indegrees of each node. We will first try to find a node with 0 indegree. If we fail to do so, there must be a cycle in the graph and we return false. Otherwise we set its indegree to be -1 to prevent from visiting it again and reduce the indegrees of its neighbors by 1. This process will be repeated for n (number of nodes) times.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<int> degrees = computeIndegrees(g);
        for (int i = 0; i < numCourses; i++) {
            int j = 0;
            for (; j < numCourses; j++) {
                if (!degrees[j]) {
                    break;
                }
            }
            if (j == numCourses) {
                return false;
            }
            degrees[j]--;
            for (int v : g[j]) {
                degrees[v]--;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    vector<int> computeIndegrees(graph& g) {
        vector<int> degrees(g.size(), 0);
        for (auto adj : g) {
            for (int v : adj) {
                degrees[v]++;
            }
        }
        return degrees;
    }
};




DFS

For DFS, in each visit, we start from a node and keep visiting its neighbors, if at a time we return to a visited node, there is a cycle. Otherwise, start again from another unvisited node and repeat this process. We use todo and done for nodes to visit and visited nodes.

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g = buildGraph(numCourses, prerequisites);
        vector<bool> todo(numCourses, false), done(numCourses, false);
        for (int i = 0; i < numCourses; i++) {
            if (!done[i] && !acyclic(g, todo, done, i)) {
                return false;
            }
        }
        return true;
    }
private:
    typedef vector<vector<int>> graph;
    
    graph buildGraph(int numCourses, vector<pair<int, int>>& prerequisites) {
        graph g(numCourses);
        for (auto p : prerequisites) {
            g[p.second].push_back(p.first);
        }
        return g;
    }
    
    bool acyclic(graph& g, vector<bool>& todo, vector<bool>& done, int node) {
        if (todo[node]) {
            return false;
        }
        if (done[node]) {
            return true;
        }
        todo[node] = done[node] = true;
        for (int v : g[node]) {
            if (!acyclic(g, todo, done, v)) {
                return false;
            }
        }
        todo[node] = false;
        return true;
    }
};

*/

