class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<int> array1d;
        vector<vector<int>> ans;
        for (auto &row : grid)
        {
            for (int x : row)
                array1d.push_back(x);
        }
        k %= (m * n);
        rotate(array1d.begin(),array1d.begin()+((m*n)-k),array1d.end());
        int count=0;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(array1d[count]);
                count++;
            }
            ans.push_back(temp);
        }
        return ans;
    }
};