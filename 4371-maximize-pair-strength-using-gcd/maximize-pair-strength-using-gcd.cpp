class Solution {
public:
    long long maxPairStrength(vector<int>& nums) {
        int n=nums.size();
        long long maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)
                    continue;
                long long nums1=nums[i];
                long long nums2=nums[j];
                long long g=gcd(nums1,nums2);
                long long res=(nums1*nums2)/(g*g);
                maxi=max(maxi,res);
            }
        }
        return maxi;

    }
};