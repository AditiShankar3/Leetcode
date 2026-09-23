class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adj(n); //creating adjency list
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> vis(n,0);
        stack<int> st;
        st.push(source);
        vis[source]=1;
        while(!st.empty()){
            int node=st.top();
            st.pop();
            if(node==destination)
                return true;
            for(int neighbour:adj[node]){
                if(!vis[neighbour])
                {
                    vis[neighbour]=1;
                    st.push(neighbour);
                }
            }
        }
        return false;
    }
};