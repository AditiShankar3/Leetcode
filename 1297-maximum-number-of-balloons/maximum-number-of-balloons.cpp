class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> char_count;
        for(char c: text)
            char_count[c]++;
        int c_b=char_count['b'];
        int c_a=char_count['a'];
        int c_n=char_count['n'];
        int c_l=char_count['l']/2;
        int c_o=char_count['o']/2;
        return min({c_a, c_b, c_o, c_l, c_n});

    }
};