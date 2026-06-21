class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int count=0;
        for(auto ch:moves)
        {
            if(ch=='L')
                x+=-1;
            else if(ch=='R')
                x+=1;
            else if(ch=='D')
                y-=1;
            else if(ch=='U')
                y+=1;
            else 
                count++;
        }
        int ans=(abs(x)+abs(y))+count;
        return ans;
    }
};