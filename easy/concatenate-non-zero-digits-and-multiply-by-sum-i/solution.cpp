/*
[Description]
Concatenate Non-Zero Digits and Multiply by Sum I
https://leetcode.com/problems/concatenate-non-zero-digits-and-multiply-by-sum-i/submissions/2059534545/

You are given an integer n.

Form a new integer x by concatenating all the non-zero digits of n in their original order. If there are no non-zero digits, x = 0.

Let sum be the sum of digits in x.

Return an integer representing the value of x * sum.

 
Example 1:

Input: n = 10203004

Output: 12340

Explanation:

  The non-zero digits are 1, 2, 3, and 4. Thus, x = 1234.
  The sum of digits is sum = 1 + 2 + 3 + 4 = 10.
  Therefore, the answer is x * sum = 1234 * 10 = 12340.

Example 2:

Input: n = 1000

Output: 1

Explanation:

  The non-zero digit is 1, so x = 1 and sum = 1.
  Therefore, the answer is x * sum = 1 * 1 = 1.

 
Constraints:

  0 <= n <= 109

[Metadata]
- Difficulty: Easy
- Topics: Math
- Slug: concatenate-non-zero-digits-and-multiply-by-sum-i
*/

// [Solution]
class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
            return 0;
        string str=to_string(n);
        string x="";
        long long sum=0;
        for(char c:str){
            if(c>='1' && c<='9'){
                x+=c;
                long long i=c-'0';
                sum+=i;
            }
        }
        long long res=stoll(x);
        return res*sum;
    }
};