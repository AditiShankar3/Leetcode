class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest=0;
        unordered_set<int> map(nums.begin(),nums.end());
        for(int i:map){
            if(map.find(i-1)==map.end()){
                int count=1;
                int x=i;
                while(map.find(x+1)!=map.end()){
                    count++;
                    x++;
                }
                longest=max(count,longest);
            }
        }
        return longest;
    }
};