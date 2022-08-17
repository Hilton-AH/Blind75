#include <iostream>

using namespace std;

/*
You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.

Return the length of the longest substring containing the same letter you can get after performing the above operations.

Example 1:
Input: s = "ABAB", k = 2
Output: 4
Explanation: Replace the two 'A's with two 'B's or vice versa.

Example 2:
Input: s = "AABABBA", k = 1
Output: 4
Explanation: Replace the one 'A' in the middle with 'B' and form "AABBBBA".
The substring "BBBB" has the longest repeating letters, which is 4.

Constraints:
1 <= s.length <= 105
s consists of only uppercase English letters.
0 <= k <= s.length

Difficulty: medium

Time: O(n)
Space: O(1)
*/

class Solution {
public:
    int characterReplacement(string s, int k) { // s is the string, k is the number of allowed replacements
        
        int n = s.length(); // n is the length of the string
        int left = 0, right = 0; // left and right are the indices of the left and right boundaries of the substring
        int maxLen = 0; // maxLen is the length of the longest substring with the same letter
        int count[40] = {0}; // count is an array that stores the number of times each letter appears in the substring
        int maxCount = 0; // maxCount is the maximum number of times any letter appears in the substring
        int maxIndex = 0; // maxIndex is the index of the letter with the maximum number of times it appears in the substring
        
        while (right < n) { // while the right boundary is not reached
            count[s[right] - 'A']++; // increase the number of times the letter at the right boundary appears in the substring by 1 in the count array in order to keep track of the number of times each letter appears in the substring
            maxCount = max(maxCount, count[s[right] - 'A']); // update the maximum number of times any letter appears in the substring
            maxIndex = right; // update the index of the letter with the maximum number of times it appears in the substring
            right++; // move the right boundary one step to the right
            
            while (right - left > maxCount + k) { // while the length of the substring is greater than the maximum length of the substring with the same letter plus the number of allowed replacements
                count[s[left] - 'A']--; // decrease the number of times the letter at the left boundary appears in the substring by 1 in the count array in order to keep track of the number of times each letter appears in the substring
                left++; // move the left boundary one step to the right
            }
            
            maxLen = max(maxLen, right - left); // update the length of the longest substring with the same letter
        }
        
        return maxLen; 
    }
};

//test
int main() {
    Solution s;
    cout << s.characterReplacement("ABAB", 2) << endl;
    cout << s.characterReplacement("AABABBA", 1) << endl;
    return 0;
}