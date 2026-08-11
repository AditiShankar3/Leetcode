class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int maxi=0;
        int prev=nums[0];
        int sum=0;
        for(int i=1;i<nums.size();i++){
            int curr=nums[i];
            if(curr-prev==1)
            {
                sum+=prev;
            }
            else{
                sum+=prev;
                maxi=max(sum,maxi);
                break;
            }
            prev=curr;
        }
        if(prev==nums[nums.size()-1] && maxi==0){
            //entire array is a sequence; 
            sum+=prev;
            maxi=sum;
        }
        while(find(nums.begin(),nums.end(),maxi)!=nums.end()){
            maxi++;
        }
        return maxi;
    }
};