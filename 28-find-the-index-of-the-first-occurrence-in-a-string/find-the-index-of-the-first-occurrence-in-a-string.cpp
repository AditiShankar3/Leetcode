class Solution {
public:
    int strStr(string haystack, string needle) {
        size_t ind=haystack.find(needle);
        if(ind!=string::npos)
            return (int)ind;
        return -1;
    }
};