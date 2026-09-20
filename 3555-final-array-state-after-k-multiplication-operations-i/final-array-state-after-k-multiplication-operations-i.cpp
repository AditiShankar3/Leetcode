class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int multiplier) {
        priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        for(int i=0;i<nums.size();i++){
            minHeap.push({nums[i],i});
        }
        for(int i=0;i<k;i++){
            pair<int,int> min=minHeap.top();
            minHeap.pop();
            int m=min.first;
            int idx=min.second;
            minHeap.push({m*multiplier,idx});
        }
        vector<int> res(nums.size(),0);
        while (!minHeap.empty()){
            pair<int,int> x=minHeap.top();
            minHeap.pop();
            res[x.second]=x.first;
        }
        return res;
    }
};