class Solution {
public:
    int smallestNumber(int n, int t) {
        int prev=n;
        while(true){
            int prod=1;
            int temp=prev;
            while(temp>0){
                int dig=temp%10;
                prod*=dig;
                temp=temp/10;
            }
            if(prod%t==0)
                break;
            prev++;
        }
        return prev;
    }
};