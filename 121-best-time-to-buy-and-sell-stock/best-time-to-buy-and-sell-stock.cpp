class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxi=0;
        int buy=prices[0];
        int prof=0;
        for(int i=1;i<=prices.size()-1;i++){
            if(buy>prices[i])
                buy=prices[i];
            int p=prices[i]-buy;
            prof=max(prof,p);
        }
        return prof;
    }
};