class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<
            pair<int,vector<int>>,
            vector<pair<int,vector<int>>>
        > min_heap; //max_heap
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int dis = x*x + y*y;
            min_heap.push({dis,{points[i][0],points[i][1]}});
            if(min_heap.size()>k)
                min_heap.pop();
        }
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};