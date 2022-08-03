#include <iostream>
#include <vector>

using namespace std;

/*

You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval newInterval = [start, end] that represents the start and end of another interval.

Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals still does not have any overlapping intervals (merge overlapping intervals if necessary).

Return intervals after the insertion.

Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
Output: [[1,2],[3,10],[12,16]]
Explanation: Because the new interval [4,8] overlaps with [3,5],[6,7],[8,10].

Constraints:

0 <= intervals.length <= 104
intervals[i].length == 2
0 <= starti <= endi <= 105
intervals is sorted by starti in ascending order.
newInterval.length == 2
0 <= start <= end <= 105

difficulty: medium

time: O(n)
space: O(n)

*/

class Solution {
public:
    vector<vector<int> > insert(vector<vector<int> >& intervals, vector<int>& newInterval) { 
        //& is used to pass the address of the object to the function
        vector<vector<int> > answer; //create a vector called answer to store the intervals
        /*
        vector<vector<int> > is a vector of vectors of ints
        Vector of Vectors is a two-dimensional vector with a variable number of rows where each row is vector. Each index of vector stores a vector which can be traversed and accessed using iterators. It is similar to an Array of Vectors but with dynamic properties.
        */
        size_t i = 0; //set i to 0 so we can loop through the intervals 
        //size_t is an unsigned int that is used to store the size of the vector
        
        // Left part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) { //while the current index is less than the size of the vector and the end of the current interval is less than the start of the new interval
            answer.push_back(intervals[i]); //add the current interval to the answer vector
            ++i; //increment i to move to the next interval using pre-increment operator inside the loop 
        }
        
        // newInterval part (with or without merge)
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) { //while the current index is less than the size of the vector and the start of the current interval is less than or equal to the end of the new interval
            newInterval[0] = min(newInterval[0], intervals[i][0]); //set the start of the new interval to the minimum of the start of the new interval and the start of the current interval
            newInterval[1] = max(newInterval[1], intervals[i][1]); //set the end of the new interval to the maximum of the end of the new interval and the end of the current interval
            ++i; //increment i to move to the next interval using pre-increment operator
        }
        answer.push_back(newInterval); //add the new interval to the answer vector outside of the while loop so that it is added to the end of the vector
        
        // Right part (no intersection with newInterval)
        while (i < intervals.size() && intervals[i][0] > newInterval[1]) { //while the current index is less than the size of the vector and the start of the current interval is greater than the end of the new interval
            answer.push_back(intervals[i]); //add the current interval to the answer vector
            ++i; //increment i to move to the next interval using pre-increment operator inside the loop
        }
        return answer; //return the answer vector
    }
};

//test
int main() {
    Solution s;
    vector<vector<int> > intervals = {{1,2},{3,5},{6,7},{8,10},{12,16}}; 
    vector<int> newInterval = {4,8};
    vector<vector<int> > answer = s.insert(intervals, newInterval); 
    for (int i = 0; i < answer.size(); i++) {
        cout << "[" << answer[i][0] << "," << answer[i][1] << "]" << endl; 
    }
    return 0;
}