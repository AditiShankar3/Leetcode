class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1)
            return true;
        if(n==0)
            return false;
        long long temp=abs((long long)n);
        if(n%2==0)
            return isPowerOfTwo(n/2);
        else 
            return false;
    }
};