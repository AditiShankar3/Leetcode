/*
[Description]
Number Complement
https://leetcode.com/problems/number-complement/submissions/2031624890/

The complement of an integer is the integer you get when you flip all the 0's to 1's and all the 1's to 0's in its binary representation.

  For example, The integer 5 is "101" in binary and its complement is "010" which is the integer 2.

Given an integer num, return its complement.

 
Example 1:

Input: num = 5
Output: 2
Explanation: The binary representation of 5 is 101 (no leading zero bits), and its complement is 010. So you need to output 2.

Example 2:

Input: num = 1
Output: 0
Explanation: The binary representation of 1 is 1 (no leading zero bits), and its complement is 0. So you need to output 0.

 
Constraints:

  1 <= num < 231

 
Note: This question is the same as 1009: https://leetcode.com/problems/complement-of-base-10-integer/

[Metadata]
- Difficulty: Easy
- Topics: Bit Manipulation
- Slug: number-complement
*/

// [Solution]
class Solution {
public:
    string decimaltobinary(int num){
        if(num==0)
            return "0";
        string binarystr="";
        while(num>0){
            int remainder=num%2;
            binarystr=to_string(remainder)+binarystr;
            num=num/2;
        }
        return binarystr;
    }
    int findComplement(int num) {
        string s = decimaltobinary(num);
        for(char &bit:s){
            if(bit=='0')
                bit='1';
            else if(bit=='1')
                bit='0';
        }
        int decimal=stoi(s,NULL,2);
        return decimal;
    }
};