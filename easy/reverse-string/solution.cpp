/*
[Description]
Reverse String
https://leetcode.com/problems/reverse-string/

Write a function that reverses a string. The input string is given as an array of characters s.

You must do this by modifying the input array in-place with O(1) extra memory.

 
Example 1:
Input: s = ["h","e","l","l","o"]
Output: ["o","l","l","e","h"]
Example 2:
Input: s = ["H","a","n","n","a","h"]
Output: ["h","a","n","n","a","H"]

 
Constraints:

  1 <= s.length <= 105
  s[i] is a printable ascii character.

[Metadata]
- Difficulty: Easy
- Topics: Two Pointers, String
- Slug: reverse-string
*/

// [Solution]
class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
        while(l<r)
        {
            swap(s[l],s[r]);
            l++;
            r--;
        }
        cout<<"[";
        for(int i=0;i<s.size();i++)
        {
            cout<<s[i];
            if(i!=s.size()-1)
                cout<<",";
        }
        cout<<"]";
    }
};