#include <iostream>
#include <vector>

using namespace std;

/*
Given an m x n matrix, return all elements of the matrix in spiral order.

Example 1:
Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
Output: [1,2,3,6,9,8,7,4,5]

Example 2:
Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
Output: [1,2,3,4,8,12,11,10,9,5,6,7]

Constraints:
m == matrix.length
n == matrix[i].length
1 <= m, n <= 10
-100 <= matrix[i][j] <= 100

Difficulty: medium

Time: O(m*n)
Space: O(1)



When traversing the matrix in the spiral order, at any time we follow one out of the following four directions: RIGHT DOWN LEFT UP. Suppose we are working on a 5 x 3 matrix as such:

0 1 2 3 4 5
6 7 8 9 10
11 12 13 14 15

Imagine a cursor starts off at (0, -1), i.e. the position at '0', then we can achieve the spiral order by doing the following:

Go right 5 times
Go down 2 times
Go left 4 times
Go up 1 times.
Go right 3 times
Go down 0 times -> quit
Notice that the directions we choose always follow the order 'right->down->left->up', and for horizontal movements, the number of shifts follows:{5, 4, 3}, and vertical movements follows {2, 1, 0}.

Thus, we can make use of a direction matrix that records the offset for all directions, then an array of two elements that stores the number of shifts for horizontal and vertical movements, respectively. This way, we really just need one for loop instead of four.

Another good thing about this implementation is that: If later we decided to do spiral traversal on a different direction (e.g. Counterclockwise), then we only need to change the Direction matrix; the main loop does not need to be touched.
*/

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<vector<int> > dirs{{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; // direction matrix for traversing the matrix in spiral order
        vector<int> result; // result vector to store the spiral order
        int nr = matrix.size();     if (nr == 0) return result; // nr is the number of rows, if the matrix is empty, return an empty vector
        int nc = matrix[0].size();  if (nc == 0) return result; // nc is the number of columns, if the matrix is empty, return an empty vector
        
        vector<int> nSteps{nc, nr-1}; // nSteps is an array of two elements, the first element is the number of shifts for horizontal movements, the second element is the number of shifts for vertical movements (nr-1 because we need to go down one row at the end of the loop in order to quit)
        
        int iDir = 0;   // iDir is the index of the current direction in the direction matrix
        int ir = 0, ic = -1;    // ir is the row index, ic is the column index initalized to -1 because we need to go right one column at the beginning of the loop in order to start from the first column
        while (nSteps[iDir%2]) { // while the number of shifts for the current direction is not zero (i.e. the current direction is not quit)
            for (int i = 0; i < nSteps[iDir%2]; ++i) { // for each shift in the current direction 
                ir += dirs[iDir][0]; ic += dirs[iDir][1]; // update the row and column indices
                result.push_back(matrix[ir][ic]); // add the element in the current row and column to the result vector
            }
            nSteps[iDir%2]--; // update the number of shifts for the current direction by subtracting 1 in order to quit the current direction
            iDir = (iDir + 1) % 4; // update the current direction by adding 1 in order to go to the next direction (i.e. go to the next row or next column) 
            //%4 is used to make sure the index of the current direction is always between 0 and 3 inclusive in order to avoid going out of bounds
        }
        return result; // return the result vector
    }
};

//test
int main() {
    Solution s;
    vector<vector<int> > matrix{{1,2,3},{4,5,6},{7,8,9}};
    vector<int> answer = s.spiralOrder(matrix);
    cout <<  "The spiral matrix is: " << endl;
    for (int i = 0; i < answer.size(); ++i) {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}

