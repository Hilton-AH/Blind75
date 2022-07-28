"""
Given a string s, find the length of the longest substring without repeating characters.

difficulty: medium

time: O(n)
space: O(n)
"""


class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if len(s) == 0:
            return 0
        max_length = 0
        start = 0
        end = 0
        d = {}
        while end < len(s):
            if s[end] in d:
                start = max(start, d[s[end]] + 1)
            d[s[end]] = end
            max_length = max(max_length, end - start + 1)
            end += 1
        return max_length
        

#test
s = Solution()
print(s.lengthOfLongestSubstring("abcabcbb"))
print(s.lengthOfLongestSubstring("zzzzzzzzzz"))