"""
Given a string s, return the longest palindromic substring in s.

time: O(n^2)
space: O(1)
"""

class Solution:
    def longestPalindrome(self, s: str) -> str: # self, s: str -> str is the return type of the function
        if len(s) == 0: # if the length of s is 0, return an empty string
            return ""
        if len(s) == 1: # if the length of s is 1, return s
            return s
        max_len = 1 # initialize the max_len to 1
        start = 0 # initialize the start to 0
        for i in range(len(s)):
            if i - max_len >= 1 and s[i - max_len - 1:i + 1] == s[i - max_len - 1:i + 1][::-1]: # if the length of the substring is max_len + 2 and the substring is a palindrome
                start = i - max_len - 1 # set the start to the index of the first letter of the substring
                max_len += 2 # increase the max_len by 2 since the substring is a palindrome
                continue # continue to the next iteration of the for loop
            if i - max_len >= 0 and s[i - max_len:i + 1] == s[i - max_len:i + 1][::-1]: # if the length of the substring is max_len + 1 and the substring is a palindrome
                start = i - max_len # set the start to the index of the first letter of the substring
                max_len += 1 # increase the max_len by 1 since the substring is a palindrome
        return s[start:start + max_len] # return the substring of the start index and the length of the max_len

# Test
s = Solution() # create a Solution object
print(s.longestPalindrome("babad"))
print(s.longestPalindrome("cbbd"))

        