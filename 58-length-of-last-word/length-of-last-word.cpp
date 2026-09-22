class Solution {
public:
    int lengthOfLastWord(string s) {
        istringstream ss(s);
        int count=0;
        string word;
        while(ss>>word){
            if((ss>>std::ws).eof()){
                count=word.size();
            }
        }
        return count;
    }
};