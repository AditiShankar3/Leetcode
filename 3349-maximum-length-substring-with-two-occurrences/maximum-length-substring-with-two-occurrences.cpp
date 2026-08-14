class Solution {
public:
    int maximumLengthSubstring(string s) {
        // at most two occurances 
        int i=0;
        int j=i+1;
        int max_len=0;
        vector<int> count(26,0);
        count[s[0]-'a']=1;
        while(j<s.size()){
            count[s[j]-'a']++;
            while (count[s[j] - 'a'] > 2) {
                count[s[i] - 'a']--;   // i leaves the window
                i++;
            }
            max_len=max(max_len,j-i+1);
            j++;
            
        }
        return max_len;
    }
};