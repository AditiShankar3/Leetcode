class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        int count=0;
        vector<vector<int>> ans;
        if((m * n) != original.size()) return ans;
        for(int i=0;i<m;i++){
            vector<int> temp;
            for(int j=0;j<n;j++){
                temp.push_back(original[count]);
                count++;
            }
            ans.push_back(temp);

        }
        return ans;
    }
};