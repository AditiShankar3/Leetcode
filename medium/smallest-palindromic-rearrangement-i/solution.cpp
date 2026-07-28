/*
[Description]
Smallest Palindromic Rearrangement I
https://leetcode.com/problems/smallest-palindromic-rearrangement-i/submissions/2084505809/

You are given a palindromic string s.

Return the lexicographically smallest palindromic permutation of s.

 
Example 1:

Input: s = "z"

Output: "z"

Explanation:

A string of only one character is already the lexicographically smallest palindrome.

Example 2:

Input: s = "babab"

Output: "abbba"

Explanation:

Rearranging "babab" → "abbba" gives the smallest lexicographic palindrome.

Example 3:

Input: s = "daccad"

Output: "acddca"

Explanation:

Rearranging "daccad" → "acddca" gives the smallest lexicographic palindrome.

 
Constraints:

  1 <= s.length <= 105
  s consists of lowercase English letters.
  s is guaranteed to be palindromic.

[Metadata]
- Difficulty: Medium
- Topics: String, Sorting, Counting Sort
- Slug: smallest-palindromic-rearrangement-i
*/

// [Solution]
class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1||s.size()==3)
            return s;
        long long n=s.size();
        string first;
        string second;
        if(n%2==0)
        {
            long long half=ceil((n+1)/2);
            first=s.substr(0, half);
            second=s.substr(half,n-half);
            sort(first.begin(),first.end());
            sort(second.begin(),second.end(),greater<char>());
        }
        else
        {
            long long half=ceil(n/2);
            first=s.substr(0, half);
            second=s.substr(half+1,n-half-1);
            sort(first.begin(),first.end());
            first+=s[half];
            sort(second.begin(),second.end(),greater<char>());
        }
        return first+second;
    }
};