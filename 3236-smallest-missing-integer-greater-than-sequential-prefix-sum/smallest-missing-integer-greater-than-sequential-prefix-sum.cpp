class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int maxi=nums[0];
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]+1)
                maxi+=nums[i];
            else
                break;
        }
        vector<bool> hash(1276,false);
        for(int i:nums)
            hash[i]=true;
        while(hash[maxi])
            maxi++;
        return maxi;
    }
};