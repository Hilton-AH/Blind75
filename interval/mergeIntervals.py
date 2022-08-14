from ast import List # Import List from ast module (ast is the module that contains the classes for the abstract syntax tree)

"""
Given an array of intervals where intervals[i] = [starti, endi], merge all overlapping intervals, and return an array of the non-overlapping intervals that cover all the intervals in the input.

Example 1:

Input: intervals = [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlap, merge them into [1,6].

Example 2:

Input: intervals = [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.

Constraints:

1 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 104
"""


"""
intervals [[1, 3], [2, 6], [8, 10], [15, 18]]
intervals.sort [[1, 3], [2, 6], [8, 10], [15, 18]]

interval = [1,3]
merged =[]
not merged:
	merged =[ [1,3] ]

interval =[2,6]
merged = [ [1,3] ]
merged[-1][-1] = 3 > interval[0] = 2:
	merged[-1][-1] = max(merged[-1][-1] = 3 ,interval[-1] = 6) =6
merged = [[1,6]]
"""
def merge(intervals):
    intervals.sort() # Sort the intervals by start time in ascending order (sort in Python uses the algoritm "merge sort") O(nlogn)
    merged = [] # Create an empty list to store the merged intervals
    for interval in intervals: # For each interval in the intervals list
        if not merged or merged[-1][1] < interval[0]: # If the merged list is empty or the last interval in the merged list ends before the current interval starts
            merged.append(interval) # Add the current interval to the merged list
        else:
            merged[-1][1] = max(merged[-1][1], interval[1]) # Else, update the end time of the last interval in the merged list to be the max of the end time of the last interval in the merged list and the end time of the current interval
    return merged

#test
print(merge([[1,3],[2,6],[8,10],[15,18]]))

"""
class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        if not intervals:
            return []
        intervals.sort()
        merged = [intervals[0]]
        for interval in intervals[1:]:
            if interval[0] <= merged[-1][1]:
                merged[-1][1] = max(merged[-1][1], interval[1])
            else:
                merged.append(interval)
        return merged


#test
if __name__ == "__main__":
    sol = Solution()
    print(sol.merge([[1,3],[2,6],[8,10],[15,18]])) # [[1,6],[8,10],[15,18]]

# intervals = [[1,3],[2,6],[8,10],[15,18]]
# print(Solution().merge(intervals)) 

"""