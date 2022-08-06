#include <iostream>
#include <vector>
#include <limits.h>

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
        int optimalProfit = 0; //create a variable called optimalProfit and initialize it to 0
        int minPrice = INT_MAX; //create a variable called minPrice and initialize it to INT_MAX (macro that specifies the maximum value of an int)
        //32-bit = 2,147,483,647 (2^31 - 1)
        //64-bit = 9,223,372,036,854,775,807 (2^63 - 1)
        for (int i = 0; i < prices.size(); i++) { //for each element in the prices array
            if (prices[i] < minPrice) { //if the price of the ith element is less than the minPrice
                minPrice = prices[i]; //set the minPrice to the price of the ith element
            }
            if (prices[i] - minPrice > optimalProfit) { //if the price of the ith element minus the min_price is greater than the optimalProfit
                optimalProfit = prices[i] - minPrice; //set the optimalProfit to the price of the ith element minus the minPrice
            }
        }
        return optimalProfit; //return the optimalProfit
    }
};

//test
int main() {
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    //vector<int> prices = {7,6,4,3,1};
    cout << "The max profit of the stock is: $" << s.maxProfit(prices) << endl;
    return 0;
}