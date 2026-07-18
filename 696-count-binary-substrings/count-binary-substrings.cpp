class Solution {
public:
    int countBinarySubstrings(string s) {
        if(s.length()==1)
            return 0;
        int res=0;
        int prev=0;
        int strk=1;
        for(int i=1;i<s.length();i++){
            if(s[i]==s[i-1])
                strk++;
            else{
                prev=strk;
                strk=1;
            }
            if(strk<=prev)
                res++;
        }
        return res;
    }
};