class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>> ans(m,vector<int>(n));
        k %= (m * n);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int old_index=i*n+j;
                int new_index=(old_index+k)%(m*n);
                ans[new_index/n][new_index%n]=grid[i][j];
            }
        }
        return ans;
    }
};