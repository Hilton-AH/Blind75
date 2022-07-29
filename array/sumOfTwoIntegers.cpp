#include <iostream>

using namespace std;

/*

Given two integers a and b, return the sum of the two integers without using the operators + and -.

difficulty: easy

time: O(1)
space: O(1)

*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum_1 = a ^ b; // sum of two integers without using the operators + and - (^ is XOR)
        int sum_2 = (a & b & 0xffffffff) << 1; // there is a problem about negative number shifting, use 8 f( unsigned int ) to solve it , 7 f is int 
        return sum_1 + sum_2; // if sum_2 is negative, it will be overflow, so we need to use unsigned int to solve it
    }
};

//test 
int main() {
    Solution s;
    cout << s.getSum(1, 2) << endl;
    return 0;
}


