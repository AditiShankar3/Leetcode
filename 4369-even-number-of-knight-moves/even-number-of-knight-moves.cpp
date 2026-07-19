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