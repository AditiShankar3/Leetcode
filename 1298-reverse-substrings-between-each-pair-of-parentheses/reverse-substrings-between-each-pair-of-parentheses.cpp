class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> index;
        int i=0;
        while(i<s.size()){
            char c=s[i];
            if(c=='('){
                index.push(i);
                i++;
            }
            else if(c==')'){
                int x=index.top()+1;
                index.pop();
                int len=i-x;
                string temp=s.substr(x,len);
                reverse(temp.begin(),temp.end());
                s.replace(x-1, len+2, temp);
                i-=1;
            }
            else
                i++;
        }
        return s;
    }
};