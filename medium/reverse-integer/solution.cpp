/*
[Description]
Reverse Integer
https://leetcode.com/problems/reverse-integer/submissions/2105259567/

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 
Example 1:

Input: x = 123
Output: 321

Example 2:

Input: x = -123
Output: -321

Example 3:

Input: x = 120
Output: 21

 
Constraints:

  -231 <= x <= 231 - 1

[Metadata]
- Difficulty: Medium
- Topics: Math
- Slug: reverse-integer
*/

// [Solution]
class Solution {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) { 
            int d = x % 10;
            x /= 10;
            
            // Check for positive overflow BEFORE multiplying
            if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && d > 7)) {
                return 0;
            }
            
            // Check for negative overflow BEFORE multiplying
            if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && d < -8)) {
                return 0;
            }
            
            rev = rev * 10 + d;
        }
        
        return rev;
    }
};