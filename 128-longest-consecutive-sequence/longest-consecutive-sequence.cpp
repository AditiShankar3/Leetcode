class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> map{nums.begin(),nums.end()};
        for(int n:map){
            if(map.find(n-1)==map.end()){ //begining of the sequence
                int current=n;
                int count=1;
                while(map.find(current+1)!=map.end()){
                    current++;
                    count++;
                }
                longest=max(longest,count);
            }
        }
        return longest;
    }
};