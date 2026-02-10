/*
[Description]
Valid Anagram
https://leetcode.com/problems/valid-anagram/

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

 
Example 1:

Input: s = "anagram", t = "nagaram"

Output: true

Example 2:

Input: s = "rat", t = "car"

Output: false

 
Constraints:

  1 <= s.length, t.length <= 5 * 104
  s and t consist of lowercase English letters.

 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

[Metadata]
- Difficulty: Easy
- Topics: Hash Table, String, Sorting
- Slug: valid-anagram
*/

// [Solution]
#include <stdio.h>
#include <string.h> 
bool isAnagram(char* s, char* t) {
    // s and t are the strings with all lower case characters 
    int n=strlen(s);
    int m=strlen(t);
    if(n!=m)
        return false;

    int a[26]={0};
    for(int i=0;i<n;i++)
    {
        char x=s[i];
        int y=x;
        y=y-'a';
        a[y]=a[y]+1;
    }
    for(int j=0;j<m;j++)
    {
        char x=t[j];
        int y=x;
        y=y-'a';
        if(a[y]==0)
            return false;
        else
            a[y]=a[y]-1;
    }
    for(int k=0;k!='\0';k++)
    {
        if(a[k]!=0)
            return false;
    }
    return true;
}