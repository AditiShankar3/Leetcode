class Solution {
public:
    void dfs(int row,int col,vector<vector<int>>& grid,int& count){
        int n=grid.size();
        int m=grid[0].size();
        if(row<0||row>=n||col<0||col>=m)
            return;
        if(grid[row][col]==0)
            return;
        grid[row][col]=0;
        count++;
        dfs(row-1,col,grid,count);
        dfs(row+1,col,grid,count);
        dfs(row,col-1,grid,count);
        dfs(row,col+1,grid,count);
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int maxi=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1)
                {
                    int count=0;
                    dfs(i,j,grid,count);
                    maxi=max(count,maxi);
                }
            }
        }
        return maxi;
    }
};