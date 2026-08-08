class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;
        unordered_map<char,int> sfreq;
        unordered_map<char,int> tfreq;
        for(char c:s)
            sfreq[c]++;
        for(char c:t)
            tfreq[c]++;
        for(int i=0;i<s.size();i++)
        {
            if(sfreq[s[i]]!=tfreq[s[i]])
                return false;
        }
        return true;
    }
};