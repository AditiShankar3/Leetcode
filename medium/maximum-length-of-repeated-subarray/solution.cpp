/*
[Description]
Maximum Length of Repeated Subarray
https://leetcode.com/problems/maximum-length-of-repeated-subarray/submissions/2063853274/

Given two integer arrays nums1 and nums2, return the maximum length of a subarray that appears in both arrays.

 
Example 1:

Input: nums1 = [1,2,3,2,1], nums2 = [3,2,1,4,7]
Output: 3
Explanation: The repeated subarray with maximum length is [3,2,1].

Example 2:

Input: nums1 = [0,0,0,0,0], nums2 = [0,0,0,0,0]
Output: 5
Explanation: The repeated subarray with maximum length is [0,0,0,0,0].

 
Constraints:

  1 <= nums1.length, nums2.length <= 1000
  0 <= nums1[i], nums2[i] <= 100

[Metadata]
- Difficulty: Medium
- Topics: Array, Binary Search, Dynamic Programming, Sliding Window, Rolling Hash, Hash Function
- Slug: maximum-length-of-repeated-subarray
*/

// [Solution]
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i=0;i<=n;i++)
            dp[i][0]=0;
        for(int j=0;j<=m;j++)
            dp[0][j]=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(nums1[i-1]==nums2[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                    ans=max(ans,dp[i][j]);
                }
                else
                    dp[i][j]=0;
            }
        }
        return ans;

    }
};