class Solution {
public:
    long long sumAndMultiply(int n) {
        if(n==0)
            return 0;
        string str=to_string(n);
        string x="";
        long long sum=0;
        for(char c:str){
            if(c>='1' && c<='9'){
                x+=c;
                long long i=c-'0';
                sum+=i;
            }
        }
        long long res=stoll(x);
        return res*sum;
    }
};