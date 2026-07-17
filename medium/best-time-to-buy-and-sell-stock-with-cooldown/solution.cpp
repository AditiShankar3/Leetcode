/*
[Description]
Best Time to Buy and Sell Stock with Cooldown
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-ii/submissions/2070977611/

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
        vector<long> ahead(2,0),curr(2,0);
        ahead[0]=ahead[1]=0;
        int n=prices.size();
        for(int ind=n-1;ind>=0;ind--){
            for(int buy=0;buy<=1;buy++)
            {
                long profit=0;
                if(buy)
                    profit=max(-prices[ind]+ahead[0],0+ahead[1]);
                else
                    profit=max(prices[ind]+ahead[1],0+ahead[0]);
                curr[buy]=profit;
            }
            ahead=curr;
        }
        return ahead[1];
    }
};