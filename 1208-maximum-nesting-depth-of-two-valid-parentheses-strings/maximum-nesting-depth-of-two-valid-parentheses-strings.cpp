class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int count=0;
        vector<int> res(seq.size(),0);
        int i=0;
        for(char c:seq){
            if(c=='('){
                count+=1;
                res[i]=count%2;
            }
            else{
                // c==)
                res[i]=count%2;
                count--;
            }
            i++;
        }
        return res;
    }
};