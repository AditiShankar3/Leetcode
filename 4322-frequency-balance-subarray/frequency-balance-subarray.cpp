class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            map<int,int> mp;
            vector<int> fq(n+1);
            int mx=0;
            int s=0;
            for(int j=i;j<n;j++){
                if(mp[nums[j]])
                    fq[mp[nums[j]]]--;
                mp[nums[j]]++;
                fq[mp[nums[j]]]++;
                if(mp[nums[j]]>mx){
                    mx=mp[nums[j]];
                    s=1;
                }
                else if(mp[nums[j]]==mx){
                    s++;
                }
                int distinct=mp.size();
                if(distinct==1)
                    ans=max(ans,j-i+1);
                else if(mx%2==0 && s<distinct && fq[mx/2]==distinct-s)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};