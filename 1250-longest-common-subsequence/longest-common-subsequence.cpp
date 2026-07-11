class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m=text2.size();
        vector<vector<int>> s(n+1, vector<int>(m+1, -1));
        for(int i=0;i<=n;i++)
            s[i][0]=0;
        for(int j=0;j<=m;j++)
            s[0][j]=0;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(text1[i-1]==text2[j-1])
                {
                    s[i][j]=1+s[i-1][j-1];
                }
                else
                    s[i][j]=max(s[i-1][j],s[i][j-1]);
            }
        }
        return s[n][m];
    }
};