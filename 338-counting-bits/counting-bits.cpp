class Solution {
public:
    vector<int> toBinary(vector<int>& ans,int n)
    {
        if(n==0)
        {
            ans[0]=0;
            return ans;
        }
        string bin=bitset<32>(n).to_string();
        ans[n]=count(bin.begin(),bin.end(),'1');
        return toBinary(ans,n-1);
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        return toBinary(ans,n);
    }
};