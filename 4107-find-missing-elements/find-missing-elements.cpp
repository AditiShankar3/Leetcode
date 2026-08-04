class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        auto result = minmax_element(nums.begin(), nums.end());
        // Dereference the iterators to get the values
        int mini = *result.first;
        int maxi = *result.second;
        // Formula: Sum(1 to end) - Sum(1 to start - 1)
        vector<int> res;
        int indi=0;
        sort(nums.begin(),nums.end());
        for(int i=mini;i<=maxi;i++){
            if(i!=nums[indi])
                res.push_back(i);
            else
                indi++;
        }
        return res;

    }
};