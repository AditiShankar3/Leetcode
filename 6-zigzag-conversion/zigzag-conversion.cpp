class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows==1 || numRows>=s.length())
            return s;
        string res="";
        vector<vector<char>> rows(numRows);
        int cr=0; //current direction
        int d=1; //direction 
        for(char c:s){
            rows[cr].push_back(c);
            if(cr==0)
                d=1;
            else if(cr==numRows-1)
                d=-1;
            cr+=d;
        }
        for(int i=0;i<numRows;i++){
            for(char c:rows[i])
                res+=c;
        }
        return res;



    }
};