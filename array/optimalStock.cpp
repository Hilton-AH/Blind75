#include <iostream>
#include <vector>

using namespace std;

/*

You are given an array prices where prices[i] is the price of a given stock on the ith day.

You want to maximize your profit by choosing a single day to buy one stock and choosing a different day in the future to sell that stock.

Return the maximum profit you can achieve from this transaction. If you cannot achieve any profit, return 0.


Example 1:

Input: prices = [7,1,5,3,6,4]
Output: 5
Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
Note that buying on day 2 and selling on day 1 is not allowed because you must buy before you sell.

Constraints:

1 <= prices.length <= 105
0 <= prices[i] <= 104

difficulty: easy

time: O(n)
space: O(1)

*/  

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int max_profit = 0; //create a variable called max_profit and initialize it to 0
        int min_price = INT_MAX; //create a variable called min_price and initialize it to INT_MAX
        for (int i = 0; i < prices.size(); i++) { //for each element in the prices array
            if (prices[i] < min_price) { //if the price of the ith element is less than the min_price
                min_price = prices[i]; //set the min_price to the price of the ith element
            }
            if (prices[i] - min_price > max_profit) { //if the price of the ith element minus the min_price is greater than the max_profit
                max_profit = prices[i] - min_price; //set the max_profit to the price of the ith element minus the min_price
            }
        }
        return max_profit; //return the max_profit
    }
};

//test
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "The max profit of the stock is: " << s.maxProfit(prices) << endl;
    return 0;
}