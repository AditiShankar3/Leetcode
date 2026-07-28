class Solution {
public:
    string smallestPalindrome(string s) {
        if(s.size()==1||s.size()==3)
            return s;
        long long n=s.size();
        string first;
        string second;
        if(n%2==0)
        {
            long long half=ceil((n+1)/2);
            first=s.substr(0, half);
            second=s.substr(half,n-half);
            sort(first.begin(),first.end());
            sort(second.begin(),second.end(),greater<char>());
        }
        else
        {
            long long half=ceil(n/2);
            first=s.substr(0, half);
            second=s.substr(half+1,n-half-1);
            sort(first.begin(),first.end());
            first+=s[half];
            sort(second.begin(),second.end(),greater<char>());
        }
        return first+second;
    }
};