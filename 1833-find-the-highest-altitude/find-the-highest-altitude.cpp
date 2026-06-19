class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int start=0;
        vector<int> altitude;
        int diff=0;
        altitude.push_back(diff);
        for(int i=0;i<gain.size();i++){
            if(i==0)
            {
                diff=diff+gain[i];
            }
            else
                diff=diff+gain[i];
            altitude.push_back(diff);
        }
        auto max_it = max_element(altitude.begin(), altitude.end());
        int max_value = *max_it;
        return max_value;
    }
};