class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini=prices[0];
        int maxProfit1=0;
        int maxProfit2=0;
        int n=prices.size();
        
        for(int i=1;i<n;i++){
            int cost=prices[i]-prices[i-1];
            if(cost>0)
            {
                maxProfit1+=cost;
            }
        }
        for(int i=1;i<n;i++){
            int cost=prices[i]-mini;
            maxProfit2=max(maxProfit2,cost);
            mini=min(mini,prices[i]);
        }
        return max(maxProfit1,maxProfit2);
    }
};