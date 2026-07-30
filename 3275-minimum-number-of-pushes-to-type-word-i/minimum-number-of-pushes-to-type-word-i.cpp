class Solution {
public:
    int minimumPushes(string word) {
        int n=word.length();
        if(n<=8)
            return n;
        int diff=n-8;
        int click=2;
        int res=8;
        if(diff<8){
            return n+diff;
        }
        while(diff>8)
        {
            res+=8*click;
            click++;
            diff=diff-8;
        }
        res+=diff*click;
        return res;
    }
};