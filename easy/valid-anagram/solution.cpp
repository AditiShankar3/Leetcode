/*
[Description]
Valid Anagram
https://leetcode.com/problems/valid-anagram/submissions/2098756895/

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
class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> sfreq;
        unordered_map<char,int> tfreq;
        for(char c:s)
            sfreq[c]++;
        for(char c:t)
            tfreq[c]++;
        for(int i=0;i<s.size();i++)
        {
            if(sfreq[s[i]]!=tfreq[s[i]])
                return false;
        }
        return true;
    }
};