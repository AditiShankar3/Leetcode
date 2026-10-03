class Solution {
public:
    long long maximumMedianSum(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        long long i=0;
        long long j=nums.size()-1;
        long long res=0;
        while(i+1<j){
            res+=nums[i+1];
            i+=2;
            j--;
        }
        return res;

    }
};