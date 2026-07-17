/*
[Description]
Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown/submissions/2071337474/

You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

  After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).

Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).

 
Example 1:

Input: prices = [1,2,3,0,2]
Output: 3
Explanation: transactions = [buy, sell, cooldown, buy, sell]

Example 2:

Input: prices = [1]
Output: 0

 
Constraints:

  1 <= prices.length <= 5000
  0 <= prices[i] <= 1000

[Metadata]
- Difficulty: Medium
- Topics: Array, Dynamic Programming
- Slug: best-time-to-buy-and-sell-stock-with-cooldown
*/

// [Solution]
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<vector<int>> dp(n+2,vector<int>(2,0));
        dp[n][0]=dp[n][1]=0;
        for(int i=n-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                int profit=0;
                if(buy)
                    profit=max(-prices[i]+dp[i+1][0],dp[i+1][1]);
                else
                    profit=max(prices[i]+dp[i+2][1],dp[i+1][0]);
                dp[i][buy]=profit;
            }
        }
        return dp[0][1];
    }
};