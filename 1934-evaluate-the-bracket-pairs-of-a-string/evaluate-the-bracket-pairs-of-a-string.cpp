class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int i=0;
        unordered_map<string,string> myknow;
        for(int k=0;k<knowledge.size();k++){
            myknow[knowledge[k][0]]=knowledge[k][1];
        }
        int n=s.size();
        string res="";
        while(i<n){
            if(s[i]=='('){
                int j=i+1;
                i++;
                while(s[j]!=')'){
                    j++;
                }
                string temp=s.substr(i,j-i);
                i=j+1;
                if(myknow.find(temp)==myknow.end()){
                    res+='?';
                }
                else{
                    string temp_res=myknow[temp];
                    res+=temp_res;
                }
            }
            else{
                res+=s[i];
                i++;
            }
        }
        return res;
    }
};