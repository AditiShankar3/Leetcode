/*
[Description]
Palindrome Number
https://leetcode.com/problems/palindrome-number/

Given an integer x, return true if x is a palindrome, and false otherwise.

 
Example 1:

Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.

Example 2:

Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.

Example 3:

Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.

 
Constraints:

  -231 <= x <= 231 - 1

 
Follow up: Could you solve it without converting the integer to a string?

[Metadata]
- Difficulty: Easy
- Topics: Math
- Slug: palindrome-number
*/

// [Solution]
bool isPalindrome(int x) {
    long rev=0;
    long ori=x;
    if(x<0)
        return false;
    while(x!=0)
    {
        int d=x%10;
        rev=rev*10+d;
        x/=10;
    }

    return rev==ori;
    
}