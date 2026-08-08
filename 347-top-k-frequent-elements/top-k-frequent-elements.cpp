class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freq;
        for(int i=0;i<nums.size();i++)
            freq[nums[i]]++;
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > mh;
        for(auto &entry:freq){
            mh.push({entry.second,entry.first});
            if(mh.size()>k)
                mh.pop();
        }
        vector<int> ans;
        while(!mh.empty()){
            ans.push_back(mh.top().second);
            mh.pop();
        }
        return ans;
    }
};