class Solution {
public:
    string processStr(string s) {
        string result="";
        for(auto& c:s){
            if(c=='*'){
                if(result.length()==0)
                    continue;
                result.pop_back();
            }
            else if(c=='%'){
                reverse(result.begin(), result.end());
            }
            else if(c=='#'){
                string dup=result;
                result=result+dup;
            }
            else if(c>= 'a' && c<= 'z')
            {
                result+=c;
            }
        }
        return result;
    }
};