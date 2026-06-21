/*
[Description]
Maximum Manhattan Distance After All Moves
https://leetcode.com/problems/maximum-manhattan-distance-after-all-moves/description/

You are given a string moves consisting of the characters 'U', 'D', 'L', 'R', and '_'.

Starting from the origin (0, 0), each character represents one move on a 2D plane:

  'U': Move up by 1 unit.
  'D': Move down by 1 unit.
  'L': Move left by 1 unit.
  'R': Move right by 1 unit.
  '_': Can be independently replaced with any one of 'U', 'D', 'L', or 'R'.

Return the maximum Manhattan distance from the origin that can be achieved after all moves have been performed.

 
Example 1:

Input: moves = "L_D_"

Output: 4

Explanation:

One optimal choice is:

  'L': (0, 0) -> (-1, 0)
  '_' treated as 'D': (-1, 0) -> (-1, -1)
  'D': (-1, -1) -> (-1, -2)
  '_' treated as 'L': (-1, -2) -> (-2, -2)

The final Manhattan distance from the origin is |0 - (-2)| + |0 - (-2)| = 4.

Example 2:

Input: moves = "U_R"

Output: 3

Explanation:

One optimal choice is:

  'U': (0, 0) -> (0, 1)
  '_' treated as 'U': (0, 1) -> (0, 2)
  'R': (0, 2) -> (1, 2)

The final Manhattan distance from the origin is |0 - 1| + |0 - 2| = 3.

 
Constraints:

  1 <= moves.length <= 105
  moves consists of only 'U', 'D', 'L', 'R', and '_'.

[Metadata]
- Difficulty: Medium
- Topics: 
- Slug: maximum-manhattan-distance-after-all-moves
*/

// [Solution]
class Solution {
public:
    int maxDistance(string moves) {
        int x=0;
        int y=0;
        int count=0;
        for(auto ch:moves)
        {
            if(ch=='L')
                x+=-1;
            else if(ch=='R')
                x+=1;
            else if(ch=='D')
                y-=1;
            else if(ch=='U')
                y+=1;
            else 
                count++;
        }
        int ans=(abs(x)+abs(y))+count;
        return ans;
    }
};