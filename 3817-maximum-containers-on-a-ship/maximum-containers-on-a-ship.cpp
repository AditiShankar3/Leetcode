class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int total=n*n;
        int i=1;
        while(i<=total){
            int weight=i*w;
            if(weight==maxWeight)
                return i;
            else if(weight>maxWeight)
                return i-1;
            else
                i++;
        }
        return i-1;
    }
};