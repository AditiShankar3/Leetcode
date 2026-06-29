/*
[Description]
Evaluate Reverse Polish Notation
https://leetcode.com/problems/evaluate-reverse-polish-notation/submissions/2050269479/

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

  The valid operators are '+', '-', '*', and '/'.
  Each operand may be an integer or another expression.
  The division between two integers always truncates toward zero.
  There will not be any division by zero.
  The input represents a valid arithmetic expression in a reverse polish notation.
  The answer and all the intermediate calculations can be represented in a 32-bit integer.

 
Example 1:

Input: tokens = ["2","1","+","3","*"]
Output: 9
Explanation: ((2 + 1) * 3) = 9

Example 2:

Input: tokens = ["4","13","5","/","+"]
Output: 6
Explanation: (4 + (13 / 5)) = 6

Example 3:

Input: tokens = ["10","6","9","3","+","-11","*","/","*","17","+","5","+"]
Output: 22
Explanation: ((10 * (6 / ((9 + 3) * -11))) + 17) + 5
= ((10 * (6 / (12 * -11))) + 17) + 5
= ((10 * (6 / -132)) + 17) + 5
= ((10 * 0) + 17) + 5
= (0 + 17) + 5
= 17 + 5
= 22

 
Constraints:

  1 <= tokens.length <= 104
  tokens[i] is either an operator: "+", "-", "*", or "/", or an integer in the range [-200, 200].

[Metadata]
- Difficulty: Medium
- Topics: Array, Math, Stack
- Slug: evaluate-reverse-polish-notation
*/

// [Solution]
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int result=0;
        stack<int> st;
        for(string c:tokens){
            if(c=="+"||c=="-"||c=="*"||c=="/"){
                if(c=="+")
                {
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int sum=a+b;
                    st.push(sum);
                }
                else if(c=="-"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int diff=b-a;
                    st.push(diff);
                }
                else if(c=="*"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int prod=a*b;
                    st.push(prod);
                }
                else if(c=="/"){
                    int a=st.top();
                    st.pop();
                    int b=st.top();
                    st.pop();
                    int div=b/a;
                    st.push(div);
                }
            }
            else{
                int num = stoi(c);
                st.push(num);
            }
        }
        return st.top();
    }
};