#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

/*
Given an integer array nums and an integer k, return the k most frequent elements. You may return the answer in any order.


Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]

Constraints:
1 <= nums.length <= 105
-104 <= nums[i] <= 104
k is in the range [1, the number of unique elements in the array].
It is guaranteed that the answer is unique.

Difficulty: medium

Time: O(nlogn) where N is the size of the priority queue
Space: O(n)
*/








//priority queue(implemented with heap) and unordered_map(hash table that does not need to be sorted)
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq; // map from number to frequency
        for(int num : nums) { // for each number in the array
            freq[num]++; // increment the frequency of the number in the map
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // priority queue to store the top k frequent numbers
        for(auto it : freq) { // for each number in the frequency map
            pq.push(make_pair(it.second, it.first)); // push the number and its frequency into the priority queue
            if(pq.size() > k) { // if the priority queue is larger than k
                pq.pop(); // pop the least frequent number
            }
        }
        vector<int> result; // vector to store the top k frequent numbers
        while(!pq.empty()) { // while the priority queue is not empty
            result.push_back(pq.top().second); // push the least frequent number into the vector
            pq.pop(); // pop the least frequent number
        }
        return result; // return the vector of the top k frequent numbers
    }
};

//test
int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = s.topKFrequent(nums, k);
    cout << "The most frequent numbers are: " << endl;
    for(int i = 0; i < result.size(); i++) {
        cout << result[i] << "  ";
    }
    cout << endl;
    return 0;
}



/***********************************************************************************************************************/


/*

//hash table and bucket sort
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> m; // map from number to frequency
        for (int num : nums) // for each number in the array
            ++m[num]; // increment the frequency of the number in the map
        
        vector<vector<int>> buckets(nums.size() + 1);  // create a vector of vectors of ints with size nums.size() + 1 (since we want to include 0 frequency)
        for (auto p : m) // for each element in the map (key, value)
            buckets[p.second].push_back(p.first); // add the key to the vector of the value frequency
        
        vector<int> result; // create a vector of ints to store the result
        for (int i = buckets.size() - 1; i >= 0 && result.size() < k; --i) {  // for each bucket in reverse order (from highest frequency to lowest frequency)
            for (int num : buckets[i]) { // for each number in the bucket
                result.push_back(num); // add the number to the result
                if (result.size() == k) // if the result has the correct size
                    break;
            }
        }
        return result; // return the result vector of ints 
    }
};

//test
int main() {
    Solution s;
    vector<int> nums = {1,1,1,2,2,3};
    int k = 2;
    vector<int> result = s.topKFrequent(nums, k);
    for (int num : result)
        cout << num << " ";
    cout << endl;
    return 0;
}

*/