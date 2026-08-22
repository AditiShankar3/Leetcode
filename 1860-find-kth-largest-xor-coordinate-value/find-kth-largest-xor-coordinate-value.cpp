class Solution {
public:
    int kthLargestValue(vector<vector<int>>& matrix, int k) {
        int m=matrix.size();
        int n=matrix[0].size();
        if(m==1 && n==1)
            return matrix[0][0];
        priority_queue<
            int,
            vector<int>,
            greater<int>>pq;
        vector<int> prev(n);
        prev[0]=matrix[0][0];
        pq.push(prev[0]);
        for(int i=1;i<n;i++)
        {
            prev[i]=prev[i-1]^matrix[0][i];
            pq.push(prev[i]);
            if(pq.size()>k)
                pq.pop();
        }
        for(int i=1;i<m;i++){
            vector<int> curr(n);
            for(int j=0;j<n;j++){
                if(j==0){
                    curr[j]=prev[j]^matrix[i][j];
                }
                else{
                    curr[j]=prev[j]^curr[j-1]^prev[j-1]^matrix[i][j];
                }
                pq.push(curr[j]);
                if(pq.size()>k)
                    pq.pop();
            }
            prev=curr;
        }
        return pq.top();
    }
};