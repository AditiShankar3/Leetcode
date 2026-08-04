class Solution {
public:
    long long minOperations(vector<int>& nums) {
        long long sum=0;
        for(int i=nums.size()-2;i>=0;i--){
            if(nums[i+1]<nums[i]){
                long long diff=(long long)nums[i]-nums[i+1];
                sum+=diff;
            }
        }
        return sum;
    }
};