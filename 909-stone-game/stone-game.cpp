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