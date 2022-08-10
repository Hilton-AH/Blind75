#include <iostream>

using namespace std;

/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Example 1:

Input: n = 2
Output: 2
Explanation: There are two ways to climb to the top.
1. 1 step + 1 step
2. 2 steps

Constraints:

1 <= n <= 45

Difficulty: easy

Time: O(n)
Space: O(1)

*/

class Solution {
public:
    int climbStairs(int n) {
        
        if (n == 1) { //if n is 1 return 1
            return 1;
        }
        
        if (n == 2) { //if n is 2 return 2
            return 2;
        }
        
        int oneStep = 1; //create a variable called oneStep and initialize it to 1
        int twoStep = 2; //create a variable called twoStep and initialize it to 2
        int count = 0; //create a variable called count and initialize it to 0
        
        for (int i = 3; i <= n; i++) { //for loop that starts at 3 and goes to n
            count = oneStep + twoStep; //set count to oneStep + twoStep which will add the two previous steps together
            oneStep = twoStep; //set oneStep to twoStep to keep track of the previous two steps and move on to the next iteration
            twoStep = count; //set twoStep to count so that the next iteration can use the previous two steps to calculate the next two steps
        }
        
        return count; //return count
    }
};

//test
int main() {
    Solution s;
    cout << "The number of ways to climb the stairs is: " << s.climbStairs(3) << endl;
    return 0;
}