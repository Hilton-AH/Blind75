#include <iostream>
#include <vector>

using namespace std;

/*

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

difficulty: medium

time: O(n^2)
space: O(n)

*/

class Solution {
public:
    int coinChange(vector<int> &coins, int amount) {
        vector<int> dynamic(amount + 1, amount + 1); //create a vector of size amount + 1 and fill it with amount + 1
        dynamic[0] = 0; //set the first element of the vector to 0
        for (int i = 1; i <= amount; i++) { //loop through the vector
            for (int j = 0; j < coins.size(); j++) { //loop through the coins vector
                if (coins[j] <= i) { //if the current coin is less than or equal to the current amount
                    dynamic[i] = min(dynamic[i], dynamic[i - coins[j]] + 1); //set the current element to the minimum of the current element and the current element minus the current coin
                }
            }
        }
        return dynamic[amount] > amount ? -1 : dynamic[amount]; //if the current element is greater than the current amount, return -1, otherwise return the current element
    }
};

//test
int main() {
    Solution sol; //create a Solution object called sol to call the coinChange function
    vector<int> coins; //create a vector called coins to store the coins
    coins.push_back(1); //push back 1 into the vector
    coins.push_back(2); //push back 2 into the vector
    coins.push_back(5); //push back 5 into the vector
    cout << sol.coinChange(coins, 11) << endl; //print the result of the coinChange function
    return 0;
}