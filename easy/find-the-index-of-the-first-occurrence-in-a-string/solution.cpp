/*
[Description]
Find the Index of the First Occurrence in a String
https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/submissions/2079018739/

Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.

 
Example 1:

Input: haystack = "sadbutsad", needle = "sad"
Output: 0
Explanation: "sad" occurs at index 0 and 6.
The first occurrence is at index 0, so we return 0.

Example 2:

Input: haystack = "leetcode", needle = "leeto"
Output: -1
Explanation: "leeto" did not occur in "leetcode", so we return -1.

 
Constraints:

  1 <= haystack.length, needle.length <= 104
  haystack and needle consist of only lowercase English characters.

[Metadata]
- Difficulty: Easy
- Topics: Two Pointers, String, String Matching
- Slug: find-the-index-of-the-first-occurrence-in-a-string
*/

// [Solution]
class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t ind=haystack.find(needle);
        if(ind!=string::npos)
            return (int)ind;
        return -1;
    }
};