/*
[Description]
Maximum Number of Balloons
https://leetcode.com/problems/maximum-number-of-balloons/submissions/2042279612/

Given a string text, you want to use the characters of text to form as many instances of the word "balloon" as possible.

You can use each character in text at most once. Return the maximum number of instances that can be formed.

 
Example 1:

Input: text = "nlaebolko"
Output: 1

Example 2:

Input: text = "loonbalxballpoon"
Output: 2

Example 3:

Input: text = "leetcode"
Output: 0

 
Constraints:

  1 <= text.length <= 104
  text consists of lower case English letters only.

 
Note: This question is the same as  2287: Rearrange Characters to Make Target String.

[Metadata]
- Difficulty: Easy
- Topics: Hash Table, String, Counting
- Slug: maximum-number-of-balloons
*/

// [Solution]
class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> char_count;
        for(char c: text)
            char_count[c]++;
        int c_b=char_count['b'];
        int c_a=char_count['a'];
        int c_n=char_count['n'];
        int c_l=char_count['l']/2;
        int c_o=char_count['o']/2;
        return min({c_a, c_b, c_o, c_l, c_n});

    }
};