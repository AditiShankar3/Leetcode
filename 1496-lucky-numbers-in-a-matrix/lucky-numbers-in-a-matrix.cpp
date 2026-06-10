class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> lucky;
        vector<int> maxi;
        vector<int> mini;
        int minimum=INT_MAX;
        int maximum=0;
        for(int l=0;l<rows;l++)
        {
            for(int k=0;k<cols;k++){
                minimum=min(minimum,matrix[l][k]);
            }
            mini.push_back(minimum);
            minimum=INT_MAX;
        }
        for(int i=0;i<cols;i++)
        {
            for(int j=0;j<rows;j++)
            {
                maximum=max(maximum,matrix[j][i]);
            }
            maxi.push_back(maximum);
            maximum=0;
        }
        sort(maxi.begin(), maxi.end());
        sort(mini.begin(), mini.end());
        set_intersection(maxi.begin(), maxi.end(),
                          mini.begin(), mini.end(),
                          back_inserter(lucky));



        return lucky;
        

    }
};