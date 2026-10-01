class Solution {
public:
    bool isValid(string s) {
        if(s.size()<2)
            return false;
        stack<char> myst;
        for(char c:s){
            if(c=='('|| c=='{'||c=='[')
                myst.push(c);
            else{
                if(myst.empty())
                    return false;
                char x=myst.top();
                myst.pop();
                if(c==')' && x!='(')
                    return false;
                else if(c=='}' && x!='{')
                    return false;
                else if(c==']' && x!='[')
                    return false;
            }
        }
        if(!myst.empty())
            return false;
        return true;
    }
};