class Solution {
public:
    bool sumGame(string num) {
        int n=num.size();
        int left=0;
        int right=0;
        int sum1=0;
        int sum2=0;
        string first_half=num.substr(0,n/2);
        string last_half=num.substr(n/2);
        for(char c:first_half){
            if(c=='?')
                left++;
            else{
                int i=c-'0';
                sum1+=i;
            }
        }
        for(char c:last_half){
            if(c=='?')
                right++;
            else{
                int i=c-'0';
                sum2+=i;
            }
        }
        if((left+right)%2!=0)
            return true;
        int diff=sum1-sum2;
        int extra=9*(right-left)/2;
        if(extra==diff)
            return false;
        return true;
        
    }
};