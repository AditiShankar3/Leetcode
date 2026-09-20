class Solution {
public:
    string customSortString(string order, string s) {
        unordered_map<char,int> pos;
        for(int i=0;i<s.size();i++)
            pos[s[i]]++;
        string res="";
        for(char c:order){
            while(pos[c]>0)
            {
                res.push_back(c);
                pos[c]--;
            } 
        }
        for(auto& pair:pos){
            while(pair.second>0){
                res.push_back(pair.first);
                pair.second--;
            }
        }
        return res;
    }
};