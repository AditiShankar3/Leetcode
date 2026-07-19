/*
[Description]
Even Number of Knight Moves
https://leetcode.com/problems/even-number-of-knight-moves/solutions/8406526/simple-one-liner-c-beast-100-no-bfs-by-d-8ay8/

You are given two integer arrays start and target, where each array is of the form [x, y] representing a cell on a standard 8 x 8 chessboard.

Return true if a knight can move from start to target in an even number of moves. Otherwise, return false.

Note: A valid knight move consists of moving two squares in one direction and one square perpendicular to it. The figure below illustrates all eight possible moves from a cell.

 
Example 1:

Input: start = [1,1], target = [2,2]

Output: true

Explanation:

One possible sequence of moves is (1, 1) -> (3, 2) -> (2, 4) -> (4, 3) -> (2, 2).

The knight reaches the target in 4 moves, which is even. Thus, the answer is true.

Example 2:

Input: start = [4,5], target = [6,6]

Output: false

Explanation:​​​​​​​

It is impossible to reach target = [6, 6] from start = [4, 5] in an even number of moves. Thus, the answer is false.

 
Constraints:

  start.length == target.length == 2
  0 <= start[i], target[i] <= 7

[Metadata]
- Difficulty: Easy
- Topics: 
- Slug: even-number-of-knight-moves
*/

// [Solution]
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        // basically we can see a pattern of chess colour changes every move so from that we determine wether its true or not 
        // even sum - > white block
        // odd sum -> black block 
        // we can see a pattern where after one move - lands on white 
        // 2 moves black 
        // 3 moves white 
        // from this we can infer that any colour to black will be even 
        // and any colour to white will be odd 
        int s=start[0]+start[1];
        int t=target[0]+target[1];
        if(t%2==0) //white block 
        {
            if(s%2==0) // white to white - even
                return true;
            else 
                return false; // white to black - odd
        }
        else{ // black block
            if(s%2!=0) //black to black even
                return true;
            else
                return false; // black to white odd
        }
    }
};