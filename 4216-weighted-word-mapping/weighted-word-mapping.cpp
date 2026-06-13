class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        vector<char> reverseAlphabet = {'z','y','x','w','v','u','t','s','r','q','p','o','n','m','l','k','j','i','h','g','f','e','d','c','b','a'};
        string answer = "";
        for(int i=0;i<words.size();i++)
        {
            int sum=0;
            for(int j=0;j<words[i].size();j++)
            {
                int position1=words[i][j]-'a';
                int weight=weights[position1];
                sum+=weight;
            }
            int modulo=sum%26;
            char mp=reverseAlphabet[modulo];
            answer+=mp;
        }
        return answer;
    }
};