struct compare{
        bool operator()(const pair<int,string> &a,const pair<int,string> &b){
            if(a.first==b.first){
                return a.second<b.second;
            }
            else{
                return a.first>b.first;
            }
        }
    };
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(string a:words){
            freq[a]++;
        }
        priority_queue<
            pair<int,string>,
            vector<pair<int,string>>,
            compare
        > min_heap;
        for(auto &entry:freq){
            min_heap.push({entry.second,entry.first});
            if(min_heap.size()>k)
                min_heap.pop();
        }
        vector<string> ans;
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};