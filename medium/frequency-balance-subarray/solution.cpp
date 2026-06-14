/*
[Description]
Frequency Balance Subarray
https://leetcode.com/problems/frequency-balance-subarray/submissions/2032903566/

You are given an integer array ​​​​​​​nums.

Define a frequency balance subarray as follows:

  If the subarray contains only one distinct value, it is frequency balanced.
  Otherwise, there must exist a positive integer f such that every distinct value in the subarray occurs either f or 2 * f times, and both frequencies occur among the distinct values.

Return an integer denoting the length of the longest frequency balance subarray.

 
Example 1:

Input: nums = [1,2,2,1,2,3,3,3]

Output: 5

Explanation:

  The longest frequency balance subarray is [2, 1, 2, 3, 3].
  The elements that appear most frequently are 2 and 3, both appearing twice.
  The remaining element 1 appears once, meeting the requirements.

Example 2:

Input: nums = [5,5,5,5]

Output: 4

Explanation:

  The longest frequency balance subarray is [5, 5, 5, 5].
  The element that appears most frequently is 5.
  There are no other elements meeting the requirements.

Example 3:

Input: nums = [1,2,3,4]

Output: 1

Explanation:

Since all elements appear only once, the length of the longest frequency balance subarray is 1.

 
Constraints:

  1 <= nums.length <= 10​​​​​​​3
  1 <= nums[i] <= 10​​​​​​​9

[Metadata]
- Difficulty: Medium
- Topics: 
- Slug: frequency-balance-subarray
*/

// [Solution]
class Solution {
public:
    int getLength(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        for(int i=0;i<n;i++){
            map<int,int> mp;
            vector<int> fq(n+1);
            int mx=0;
            int s=0;
            for(int j=i;j<n;j++){
                if(mp[nums[j]])
                    fq[mp[nums[j]]]--;
                mp[nums[j]]++;
                fq[mp[nums[j]]]++;
                if(mp[nums[j]]>mx){
                    mx=mp[nums[j]];
                    s=1;
                }
                else if(mp[nums[j]]==mx){
                    s++;
                }
                int distinct=mp.size();
                if(distinct==1)
                    ans=max(ans,j-i+1);
                else if(mx%2==0 && s<distinct && fq[mx/2]==distinct-s)
                    ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};