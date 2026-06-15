class Solution {
public:
    typedef long long ll;
    long long maxRatings(vector<vector<int>>& units) {
        ll mini=INT_MAX;
        ll sum=0;
        ll mini2=INT_MAX;
        // sorting all the rows 
        if(units[0].size()==1)
        {
            for(auto x:units)
                sum+=x[0];
            return sum;
        }
        for(auto& row:units)
        {
            sort(row.begin(),row.end());
            auto min_it=min_element(row.begin(),row.end());
            mini=min(mini,(ll)*min_it);
            sum+=row[1];
            ll m=row[1];
            mini2=min(mini2,m);
        }
        return (sum+mini-mini2); 
        
    }
};