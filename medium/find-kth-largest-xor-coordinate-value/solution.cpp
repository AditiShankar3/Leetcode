/*
[Description]
Find Kth Largest XOR Coordinate Value
https://leetcode.com/problems/widest-possible-fence/submissions/2117916187/

You are given a 2D matrix of size m x n, consisting of non-negative integers. You are also given an integer k.

The value of coordinate (a, b) of the matrix is the XOR of all matrix[i][j] where 0 <= i <= a < m and 0 <= j <= b < n (0-indexed).

Find the kth largest value (1-indexed) of all the coordinates of matrix.

 
Example 1:

Input: matrix = [[5,2],[1,6]], k = 1
Output: 7
Explanation: The value of coordinate (0,1) is 5 XOR 2 = 7, which is the largest value.

Example 2:

Input: matrix = [[5,2],[1,6]], k = 2
Output: 5
Explanation: The value of coordinate (0,0) is 5 = 5, which is the 2nd largest value.

Example 3:

Input: matrix = [[5,2],[1,6]], k = 3
Output: 4
Explanation: The value of coordinate (1,0) is 5 XOR 1 = 4, which is the 3rd largest value.

 
Constraints:

  m == matrix.length
  n == matrix[i].length
  1 <= m, n <= 1000
  0 <= matrix[i][j] <= 106
  1 <= k <= m * n

[Metadata]
- Difficulty: Medium
- Topics: Array, Divide and Conquer, Bit Manipulation, Sorting, Heap (Priority Queue), Matrix, Prefix Sum, Quickselect
- Slug: find-kth-largest-xor-coordinate-value
*/

// [Solution]
class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        typedef long long ll;
        unordered_map<ll,int> freq,mpp;
        for(auto it:planks)
            freq[it]++;
        vector<pair<ll,int>> vec(freq.begin(),freq.end());
        for(auto it:vec)
            mpp[it.first]=it.second;
        int n=vec.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++){
                ll value=vec[i].first+vec[j].first;
                if(i==j)
                    mpp[value]+=vec[i].second/2;
                else
                    mpp[value]+=min(vec[i].second,vec[j].second);
            }
        }
        int res=1;
        for(auto it:mpp)
            res=max(res,it.second);
        return res;
    }
};