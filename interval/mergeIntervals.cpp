#include <iostream>
#include <vector>

using namespace std;

/*
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

Difficulty: medium

Time: O(n)
Space: O(n)
*/

/*

1. Firstly, the base case : if there are no intervals return [] .
2. Sort the intervals .
3. While traversing the intervals vector we will come accross two coditions
- First condition : if there is a overlapping between the intervals then just take out the max element from the ending point and thus we merged them
eg:- [1,4],[2,8] =Mergerd intervals will be> [1,8]
- Second condition : if there is no overlapping then simply push those interval to our resultant vector .

*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        if(intervals.size()<=1) //base case
            return intervals;
        //resultan vector
        vector<vector<int>> result;
        sort(intervals.begin(), intervals.end()); //sort the intervals in ascending order takes O(nlogn) time c++ sort uses merge sort algorithm
        result.push_back(intervals[0]); //insert the the the first interval in the result
        for(int i=1; i<intervals.size(); i++) { //traverse the intervals vector
            //if intevals are overlapping
            if(result.back()[1] >= intervals[i][0]) result.back()[1] = max(result.back()[1] , intervals[i][1]);
            //else they are not overlapping
            else result.push_back(intervals[i]); 
        }
        return result;
    }
};

//test
int main() {
    Solution s;
    vector<vector<int>> intervals;
    intervals.push_back({1,3});
    intervals.push_back({2,6});
    intervals.push_back({8,10});
    intervals.push_back({15,18});
    cout<<"The merged intervals are : ";
    for(int i=0; i<s.merge(intervals).size(); i++) {
        cout<<"["<<s.merge(intervals)[i][0]<<","<<s.merge(intervals)[i][1]<<"] "; //s.merge(intervals)[i][0] is the starting point and s.merge(intervals)[i][1] is the ending point
    }
    return 0;
}