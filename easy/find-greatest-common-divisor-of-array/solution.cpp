/*
[Description]
Find Greatest Common Divisor of Array
https://leetcode.com/problems/count-binary-substrings/submissions/2071931157/

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
    int countBinarySubstrings(string s) {
        if(s.length()==1)
            return 0;
        int res=0;
        int prev=0;
        int strk=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])
                strk++;
            else{
                prev=strk;
                strk=1;
            }
            if(strk<=prev)
                res++;
        }
        return res;
    }
};