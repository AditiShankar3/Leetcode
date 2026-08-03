/*
[Description]
Stone Game III
https://leetcode.com/problems/stone-game/submissions/2092176985/

Alice and Bob continue their games with piles of stones. There are several stones arranged in a row, and each stone has an associated value which is an integer given in the array stoneValue.

Alice and Bob take turns, with Alice starting first. On each player's turn, that player can take 1, 2, or 3 stones from the first remaining stones in the row.

The score of each player is the sum of the values of the stones taken. The score of each player is 0 initially.

The objective of the game is to end with the highest score, and the winner is the player with the highest score and there could be a tie. The game continues until all the stones have been taken.

Assume Alice and Bob play optimally.

Return "Alice" if Alice will win, "Bob" if Bob will win, or "Tie" if they will end the game with the same score.

 
Example 1:

Input: stoneValue = [1,2,3,7]
Output: "Bob"
Explanation: Alice will always lose. Her best move will be to take three piles and the score become 6. Now the score of Bob is 7 and Bob wins.

Example 2:

Input: stoneValue = [1,2,3,-9]
Output: "Alice"
Explanation: Alice must choose all the three piles at the first move to win and leave Bob with negative score.
If Alice chooses one pile her score will be 1 and the next move Bob's score becomes 5. In the next move, Alice will take the pile with value = -9 and lose.
If Alice chooses two piles her score will be 3 and the next move Bob's score becomes 3. In the next move, Alice will take the pile with value = -9 and also lose.
Remember that both play optimally so here Alice will choose the scenario that makes her win.

Example 3:

Input: stoneValue = [1,2,3,6]
Output: "Tie"
Explanation: Alice cannot win this game. She can end the game in a draw if she decided to choose all the first three piles, otherwise she will lose.

 
Constraints:

  1 <= stoneValue.length <= 5 * 104
  -1000 <= stoneValue[i] <= 1000

[Metadata]
- Difficulty: Hard
- Topics: Array, Math, Dynamic Programming, Game Theory
- Slug: stone-game-iii
*/

// [Solution]
class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int alice=0;
        int bob=0;
        int ta=0;
        int tb=1;
        while(!piles.empty())
        {
            int n=piles.size();
            if(ta==0) //alice's turn
            {
                
                if(n==1)
                {
                    alice+=piles[0];
                    piles.pop_back(); 
                }
                else{
                    int first=alice+piles[0];
                    int last=alice+piles[n-1];
                    if(first>last){
                        alice=first;
                        piles.erase(piles.begin()+0);
                    }
                    else{
                        alice=last;
                        piles.pop_back();
                    }
                }
                ta=1;
                tb=0;
            }
            else //bob's turn
            {
                if(n==1)
                {
                    bob+=piles[0];
                    piles.pop_back(); 
                }
                else{
                    int first=bob+piles[0];
                    int last=bob+piles[n-1];
                    if(first<last){
                        bob=first;
                        piles.erase(piles.begin()+0);
                    }
                    else{
                        bob=last;
                        piles.pop_back();
                    }
                }
                ta=0;
                tb=1;
            }
        }
        if(bob>alice)
            return false;
        return true;
    }
};