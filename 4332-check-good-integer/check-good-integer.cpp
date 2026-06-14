class Solution {
public:
    typedef long long ll;
    bool checkGoodInteger(int n) {
        ll digitSum=0;
        ll squareSum=0;
        while(n>0){
            int digit=n%10;
            digitSum+=digit;
            squareSum+=(digit*digit);
            n=n/10;
        }
        if((squareSum-digitSum)>=50)
            return true;
        else
            return false;
    }
};