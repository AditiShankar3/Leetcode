class Solution {
public:
    void dfs(int city,vector<vector<int>>& isConnected,vector<int>& vis){
        int n=isConnected.size();
        vis[city]=1;
        for(int i=0;i<n;i++){
            if(isConnected[city][i]==1 && !vis[i]){
                dfs(i,isConnected,vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        vector<int> vis(n,0);
        int provinces=0;
        for(int i=0;i<n;i++){
            if(!vis[i]){
                provinces++;
                dfs(i,isConnected,vis);
            }
        }
        return provinces;
    }
};