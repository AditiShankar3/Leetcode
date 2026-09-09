class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)
            return 0;
        long long p=1000;
        long long count=0;
        while(p<=n){
            count+=n-p+1;
            p*=1000;
        }
        return count;
    }
};