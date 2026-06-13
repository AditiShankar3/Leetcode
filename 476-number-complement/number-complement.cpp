class Solution {
public:
    string decimaltobinary(int num){
        if(num==0)
            return "0";
        string binarystr="";
        while(num>0){
            int remainder=num%2;
            binarystr=to_string(remainder)+binarystr;
            num=num/2;
        }
        return binarystr;
    }
    int findComplement(int num) {
        string s = decimaltobinary(num);
        for(char &bit:s){
            if(bit=='0')
                bit='1';
            else if(bit=='1')
                bit='0';
        }
        int decimal=stoi(s,NULL,2);
        return decimal;
    }
};