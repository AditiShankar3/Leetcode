class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> last_seen={-1,-1,-1};
        int count=0;
        for(int i=0; i<s.length();i++){
            last_seen[s[i]-'a']=i;
            if(last_seen[0]!=-1 && last_seen[1]!=-1 && last_seen[2]!=-1){
                auto min_it = min_element(last_seen.begin(), last_seen.end());
                count=count+(1+*min_it);
            }
        }
        return count;
    }
};