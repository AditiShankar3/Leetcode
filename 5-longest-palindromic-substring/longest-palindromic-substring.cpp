class Solution {
public:
    bool solve(vector<vector<bool>>& dp,int i,int j,string& s){
        if(i==j)
            return dp[i][j]=true; //single length character 
        if(j-i==1){
            if(s[i]==s[j])
                return dp[i][j]=true;
            else
                return dp[i][j]=false;
        }
        if(s[i]==s[j] && dp[i+1][j-1]==true)
            return dp[i][j]=true;
        else
            return dp[i][j]=false;
    }
    string longestPalindrome(string str){
        int n=str.size();
        vector<vector<bool>> dp(n,vector<bool>(n,false));
        int startIndex=0;
        int maxLen=0;
        for(int g=0;g<n;g++){
            for(int i=0,j=g;j<n;i++,j++){
                solve(dp,i,j,str);
                if(dp[i][j]==true){
                    if(j-i+1>maxLen){
                        startIndex=i;
                        maxLen=j-i+1;
                    }
                }
            }
        }
        return str.substr(startIndex,maxLen);
        
    }
};