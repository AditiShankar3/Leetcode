/*
[Description]
Minimum Path Sum
https://leetcode.com/problems/minimum-path-sum/submissions/2068754909/

Given a m x n grid filled with non-negative numbers, find a path from top left to bottom right, which minimizes the sum of all numbers along its path.

Note: You can only move either down or right at any point in time.

 
Example 1:

Input: grid = [[1,3,1],[1,5,1],[4,2,1]]
Output: 7
Explanation: Because the path 1 → 3 → 1 → 1 → 1 minimizes the sum.

Example 2:

Input: grid = [[1,2,3],[4,5,6]]
Output: 12

 
Constraints:

  m == grid.length
  n == grid[i].length
  1 <= m, n <= 200
  0 <= grid[i][j] <= 200

[Metadata]
- Difficulty: Medium
- Topics: Array, Dynamic Programming, Matrix
- Slug: minimum-path-sum
*/

// [Solution]
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid.empty() ? 0 : grid[0].size();
        vector<int> prev(n,0);
        for(int i=0;i<n;i++)
        {
            if(i>0)
                prev[i]=prev[i-1]+grid[0][i];
            else
                prev[i]=grid[0][i];
        }
        for(int i=1;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)
                    curr[j]=grid[i][j];
                else{
                    int up=0;
                    int left=0;
                    if(i>0)
                        up=prev[j]+grid[i][j];
                    if(j>0)
                        left=curr[j-1]+grid[i][j];
                    if(up==0)
                        curr[j]=left;
                    else if(left==0)
                        curr[j]=up;
                    else
                        curr[j]=min(up,left);
                }
            }
            prev=curr;
        }
        return prev[n-1];

    }
};