class Solution {
public:
    string findSymbol(int d,int i,unordered_map<int, char> symbol){
        string res="";
        if(d==4){
            if(i==1)
                res="IV";
            else{
                int t=i+i*4;
                res += symbol[i];
                res += symbol[t];
            }
        }
        else if(d==9){
            if(i==1)
            {
                res="IX";
            }
            else
            {
                res += symbol[i];
                res += symbol[i*10];
            }
        }
        else{
            if(d<5){
                for(int j = 0; j < d; j++) {
                    res += symbol[i];
                }
            }
            else if(d>5){
                int diff=d-5;
                char ci=symbol[i*5];
                string in="";
                for(int j = 0; j < diff; j++) {
                    in += symbol[i];
                }
                res+=ci;
                res+=in;
            }
            else{
                res+=symbol[i*5];
            }
        }
        return res;
    }
    string intToRoman(int num) {
        string res="";
        int temp=num;
        int i=1;
        unordered_map<int, char> symbols = {
            {1, 'I'},
            {5, 'V'},
            {10, 'X'},
            {50, 'L'},
            {100, 'C'},
            {500, 'D'},
            {1000, 'M'}
        };
        while(temp>0){
            int d=temp%10;
            string c=findSymbol(d,i,symbols);
            res=c+res;
            i*=10;
            temp=temp/10;
        }
        
        return res;
    }
};