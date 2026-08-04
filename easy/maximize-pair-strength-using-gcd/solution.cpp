/*
[Description]
Maximize Pair Strength Using GCD
https://leetcode.com/problems/maximize-pair-strength-using-gcd/submissions/2093307877/

You are given an integer array nums.

Choose exactly one pair of distinct indices i and j. The strength of the pair is defined as (nums[i] * nums[j]) / gcd(nums[i], nums[j])2.

Return the maximum strength over all possible pairs.

 
Example 1:

Input: nums = [2,3,5]

Output: 15

Explanation:

Choosing i = 1 and j = 2 gives strength (3 * 5) / gcd(3, 5)2 = 15 / 1 = 15, which is the maximum over all pairs.

Example 2:

Input: nums = [4,6,8]

Output: 12

Explanation:

Choosing i = 1 and j = 2 gives strength (6 * 8) / gcd(6, 8)2 = 48 / 4 = 12, which is the maximum over all pairs.

Example 3:

Input: nums = [3,3]

Output: 1

Explanation:

Choosing i = 0 and j = 1 gives strength (3 * 3) / gcd(3, 3)2 = 9 / 9 = 1, the maximum over all pairs.

 
Constraints:

  2 <= nums.length <= 2000
  1 <= nums[i] <= 105

[Metadata]
- Difficulty: Easy
- Topics: 
- Slug: maximize-pair-strength-using-gcd
*/

// [Solution]
class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                long long nums1=nums[i];
                long long nums2=nums[j];
                long long g=gcd(nums1,nums2);
                long long res=(nums1*nums2)/(g*g);
                maxi=max(maxi,res);
            }
        }
        return maxi;

    }
};