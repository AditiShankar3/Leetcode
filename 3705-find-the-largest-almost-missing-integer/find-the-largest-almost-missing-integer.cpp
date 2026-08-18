class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        int n=nums.size();
        if(n==k){
            auto max_it = max_element(nums.begin(), nums.end());
            int max_val = *max_it;
            return max_val;
        }
        for(int i=0;i<n;i++)
            freq[nums[i]]++;
        if(k==1){
            sort(nums.begin(),nums.end());
            for(int i=n-1;i>=0;i--){
                if(freq[nums[i]]==1)
                    return nums[i];
            }
            return -1;
        }
        int res = -1;
        if (freq[nums[0]] == 1) {
            res = max(res, nums[0]);
        }
        if (freq[nums.back()] == 1) {
            res = max(res, nums.back());
        }
        return res;
    }
};