class Solution {
public:
    vector<int> generateRow(int row){
        long long ans=1;
        vector<int> rows;
        rows.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            rows.push_back(ans);
        }
        return rows;
    }
    vector<vector<int>> generate(int numRows) {
        if(numRows==1)
            return {{1}};
        vector<vector<int>> ans;
        for(int i=1;i<=numRows;i++){
            ans.push_back(generateRow(i));
        }
        return ans;
        
    }
};