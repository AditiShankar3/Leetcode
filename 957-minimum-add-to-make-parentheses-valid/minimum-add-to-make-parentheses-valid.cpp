class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> myst;
        int count_open=0;
        int count_close=0;
        for(char c:s){
            if(c=='(')
                myst.push(c);
            else{
                if(c==')'){
                    if(!myst.empty() && myst.top()=='(')
                    {
                        myst.pop();
                    }
                    else
                        myst.push(c);
                }
            }
        }
        return myst.size();
    }
};