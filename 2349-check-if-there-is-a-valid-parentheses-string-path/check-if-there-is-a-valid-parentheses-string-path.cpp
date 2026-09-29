class Solution {
public:
    bool hasValidPath(vector<vector<char>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        if((m+n-1)%2==1)
            return false;
        if(grid[0][0]==')' || grid[m-1][n-1]=='(')
            return false;
        vector<vector<unordered_set<int>>> dp(m+1,vector<unordered_set<int>>(n+1));
        dp[0][0].insert(0);
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                int change=(grid[i][j]=='(')?1:-1;
                for(int balance:dp[i][j]){
                    int nextBalance=balance+change;
                    if(nextBalance<0)
                        continue;
                    if (i == m - 1 && j == n - 1) {
                        if (nextBalance == 0)
                            return true;
                        continue;
                    }
                    if(i+1<m){
                        dp[i+1][j].insert(nextBalance);
                    }
                    if(j+1<n)
                        dp[i][j+1].insert(nextBalance);
                }
            }
        }
        return false;
    }
};