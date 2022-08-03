#include <iostream>
#include <vector>

using namespace std;

/*

Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

You must do it in place.

Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]


Constraints:
m == matrix.length
n == matrix[0].length
1 <= m, n <= 200
-231 <= matrix[i][j] <= 231 - 1


Follow up:
A straightforward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.

difficulty: medium

time: O(m + n)
space: O(m + n)

*/

class Solution {
public:
    void setZeroes(vector<vector<int> >& matrix) {
        
        //create a vector called row and set it to the size of the matrix
        vector<int> row(matrix.size()); //create a vector called row to store the row numbers
        //create a vector called col and set it to the size of the first row of the matrix
        vector<int> col(matrix[0].size()); //create a vector called col to store the column numbers
        
        //loop through the matrix and set the row and column numbers to 1 if the element is 0
        for (int i = 0; i < matrix.size(); ++i) { //loop through the matrix
            for (int j = 0; j < matrix[0].size(); ++j) { //loop through the first row of the matrix
                if (matrix[i][j] == 0) { //if the element is 0
                    row[i] = 1; //set the row number to 1
                    col[j] = 1; //set the column number to 1
                }
            }
        }
        
        //loop through the matrix and set the elements to 0 if the row or column number is 1
        for (int i = 0; i < matrix.size(); ++i) { //loop through the matrix
            for (int j = 0; j < matrix[0].size(); ++j) { //loop through the first row of the matrix
                if (row[i] == 1 || col[j] == 1) { //if the row or column number is 1
                    matrix[i][j] = 0; //set the element to 0
                }
            }
        }
    }
};

//test
int main() {
    Solution s;
    vector<vector<int> > matrix = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    s.setZeroes(matrix);
    for (int i = 0; i < matrix.size(); ++i) {
        for (int j = 0; j < matrix[0].size(); ++j) {
            cout << matrix[i][j] << " "; 
        }
        cout << endl;
    }
    return 0;
}

