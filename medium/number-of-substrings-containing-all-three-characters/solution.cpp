/*
[Description]
Number of Substrings Containing All Three Characters
https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/submissions/

Given a string s consisting only of characters a, b and c.

Return the number of substrings containing at least one occurrence of all these characters a, b and c.

 
Example 1:

Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again). 

Example 2:

Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one occurrence of the characters a, b and c are "aaacb", "aacb" and "acb". 

Example 3:

Input: s = "abc"
Output: 1

 
Constraints:

  3 <= s.length <= 5 x 10^4
  s only consists of a, b or c characters.

[Metadata]
- Difficulty: Medium
- Topics: Hash Table, String, Sliding Window
- Slug: number-of-substrings-containing-all-three-characters
*/

// [Solution]
class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen={-1,-1,-1};
        int count=0;
        for(int i=0; i<s.length();i++){
            last_seen[s[i]-'a']=i;
            if(last_seen[0]!=-1 && last_seen[1]!=-1 && last_seen[2]!=-1){
                auto min_it = min_element(last_seen.begin(), last_seen.end());
                count=count+(1+*min_it);
            }
        }
        return count;
    }
};