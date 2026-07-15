class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.empty() ? 0 : grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>0)
                prev[i]=prev[i-1]+grid[0][i];
            else
                prev[i]=grid[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    curr[j]=grid[i][j];
                else{
                    int up=0;
                    int left=0;
                    if(i>0)
                        up=prev[j]+grid[i][j];
                    if(j>0)
                        left=curr[j-1]+grid[i][j];
                    if(up==0)
                        curr[j]=left;
                    else if(left==0)
                        curr[j]=up;
                    else
                        curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];

    }
};