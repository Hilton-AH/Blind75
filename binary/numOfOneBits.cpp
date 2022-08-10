#include <iostream>

using namespace std;

/*
Write a function that takes an unsigned integer and returns the number of '1' bits it has (also known as the Hamming weight).

Example:

Input: n = 00000000000000000000000000001011
Output: 3
Explanation: The input binary string 00000000000000000000000000001011 has a total of three '1' bits.

Constraints:

The input must be a binary string of length 32.

Difficulty: easy

Time: O(1)
Space: O(1)

*/

class Solution {
public:
    int hammingWeight(uint32_t n) { //create a function called hammingWeight that takes in a unsigned integer called n
        
        int count = 0; //create a variable called count and initialize it to 0
        
        while (n != 0) { //while n is not 0 because there is still a bit to check
            n &= (n - 1); //set n to n - 1 (& is the bitwise AND operator) which will remove the last bit of n and set it to 0 if it is 1 and 1 if it is 0
            count++; //increment count by 1 to keep track of the number of 1 bits
        }
        
        return count; //return count
    }
};

//test
int main() {
    Solution s;
    cout << "The number of 1 bits in the number is: " << s.hammingWeight(11) << endl;
    return 0;
}