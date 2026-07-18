/*
[Description]
Find Greatest Common Divisor of Array
https://leetcode.com/problems/find-greatest-common-divisor-of-array/submissions/2071776325/

Given an integer array nums, return the greatest common divisor of the smallest number and largest number in nums.

The greatest common divisor of two numbers is the largest positive integer that evenly divides both numbers.

 
Example 1:

Input: nums = [2,5,6,9,10]
Output: 2
Explanation:
The smallest number in nums is 2.
The largest number in nums is 10.
The greatest common divisor of 2 and 10 is 2.

Example 2:

Input: nums = [7,5,6,8,3]
Output: 1
Explanation:
The smallest number in nums is 3.
The largest number in nums is 8.
The greatest common divisor of 3 and 8 is 1.

Example 3:

Input: nums = [3,3]
Output: 3
Explanation:
The smallest number in nums is 3.
The largest number in nums is 3.
The greatest common divisor of 3 and 3 is 3.

 
Constraints:

  2 <= nums.length <= 1000
  1 <= nums[i] <= 1000

[Metadata]
- Difficulty: Easy
- Topics: Array, Math, Number Theory
- Slug: find-greatest-common-divisor-of-array
*/

// [Solution]
class Solution {
public:
    int gcd(int a,int b){
        if(a==0 || b==0)
            return max(a,b);
        int result=min(a,b);
        while(result>0){
            if(a%result==0 && b%result==0)
                break;
            result--;
        }
        return result;
    }
    int findGCD(vector<int>& nums) {
        auto min_it=min_element(nums.begin(),nums.end());
        auto max_it=max_element(nums.begin(),nums.end());
        return gcd(*min_it,*max_it);
    }
};