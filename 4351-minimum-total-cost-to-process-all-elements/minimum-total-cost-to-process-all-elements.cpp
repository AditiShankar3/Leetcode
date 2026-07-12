class Solution {
public:
    const long long MOD = 1e9 + 7;
    int minimumCost(vector<int>& nums, int k) {
        // oh u have to calculate the costs 
        long long sum1=accumulate(nums.begin(), nums.end(), (long long)0);
        if(sum1<=k)
            return 0;
        long long temp=sum1/k;
        if(sum1%k==0)
            temp--;
        long long a=temp%MOD;
        long long b=(temp+1)%MOD;
        long long cost=((a*b)/2)%MOD;
        return cost;
    }
};