/*
[Description]
Maximum Length Substring With Two Occurrences
https://leetcode.com/problems/maximum-length-substring-with-two-occurrences/

Given a string s, return the maximum length of a substring such that it contains at most two occurrences of each character.
 
Example 1:

Input: s = "bcbbbcba"

Output: 4

Explanation:
The following substring has a length of 4 and contains at most two occurrences of each character: "bcbbbcba".

Example 2:

Input: s = "aaaa"

Output: 2

Explanation:
The following substring has a length of 2 and contains at most two occurrences of each character: "aaaa".

 
Constraints:

  2 <= s.length <= 100
  s consists only of lowercase English letters.

[Metadata]
- Difficulty: Easy
- Topics: Hash Table, String, Sliding Window
- Slug: maximum-length-substring-with-two-occurrences
*/

// [Solution]
class Solution {
public:
    int maximumLengthSubstring(string s) {
        // at most two occurances 
        int i=0;
        int j=i+1;
        int max_len=0;
        vector<int> count(26,0);
        count[s[0]-'a']=1;
        while(j<s.size()){
            count[s[j]-'a']++;
            while (count[s[j] - 'a'] > 2) {
                count[s[i] - 'a']--;   
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
            
        }
        return max_len;
    }
};