/*
[Description]
Smallest Divisible Digit Product I
https://leetcode.com/problems/smallest-divisible-digit-product-i/submissions/2096406343/

You are given two integers n and t. Return the smallest number greater than or equal to n such that the product of its digits is divisible by t.

 
Example 1:

Input: n = 10, t = 2

Output: 10

Explanation:

The digit product of 10 is 0, which is divisible by 2, making it the smallest number greater than or equal to 10 that satisfies the condition.

Example 2:

Input: n = 15, t = 3

Output: 16

Explanation:

The digit product of 16 is 6, which is divisible by 3, making it the smallest number greater than or equal to 15 that satisfies the condition.

 
Constraints:

  1 <= n <= 100
  1 <= t <= 10

[Metadata]
- Difficulty: Easy
- Topics: Math, Enumeration
- Slug: smallest-divisible-digit-product-i
*/

// [Solution]
class Solution {
public:
    int smallestNumber(int n, int t) {
        auto[q,r]=div(n,10);
        int req=t/gcd(q+(10-q)/10,t);
        int nxt=((r+req-1)/req*req);
        int x=nxt-(nxt-10)*(nxt/10);
        return q*10+x;
    }
};