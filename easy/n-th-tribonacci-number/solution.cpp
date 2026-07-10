/*
[Description]
N-th Tribonacci Number
https://leetcode.com/problems/n-th-tribonacci-number/submissions/2062665883/

The Tribonacci sequence Tn is defined as follows: 

T0 = 0, T1 = 1, T2 = 1, and Tn+3 = Tn + Tn+1 + Tn+2 for n >= 0.

Given n, return the value of Tn.

 
Example 1:

Input: n = 4
Output: 4
Explanation:
T_3 = 0 + 1 + 1 = 2
T_4 = 1 + 1 + 2 = 4

Example 2:

Input: n = 25
Output: 1389537

 
Constraints:

  0 <= n <= 37
  The answer is guaranteed to fit within a 32-bit integer, ie. answer <= 2^31 - 1.

[Metadata]
- Difficulty: Easy
- Topics: Math, Dynamic Programming, Memoization
- Slug: n-th-tribonacci-number
*/

// [Solution]
class Solution {
public:
    int tribonacci(int n) {
        if(n==0)
            return 0;
        if(n==1 || n==2)
            return 1;
        int prev3=0;
        int prev2=1;
        int prev=1;
        for(int i=3;i<=n;i++){
            int curr=prev+prev2+prev3;
            prev3=prev2;
            prev2=prev;
            prev=curr;
        }
        return prev;
    }
};