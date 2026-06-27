class Solution {
public:
    int maximumLength(vector<int>& nums) {
        unordered_map<long long,int> mp;
        int maxi=1;
        for(int i:nums)
            mp[i]++;
        if(mp.count(1)){
            int ones=mp[1];
            if(ones%2==0)
                maxi=max(maxi,ones-1);
            else
                maxi=max(maxi,ones);
        }
        for(auto& [key,val]:mp){
            if(key==1)
                continue;
            long long curr=key;
            int len=0;
            while(true){
                auto it=mp.find(curr);
                if(it==mp.end())
                {
                    len--;
                    break;
                }
                int cnt=it->second;
                if(cnt>=2)
                    len+=2;
                else{
                    len+=1;
                    break;
                }
                if(curr==1)
                    break;
                curr=curr*curr;
            }
            maxi=max(maxi,len);
        }
        return maxi; 
    }
};