class SegmentTree{
    vector<int> segmentTree;
    bool isMinTree;
    int n;

public:
    SegmentTree(vector<int>& nums,bool flag){
        n = nums.size();
        isMinTree = flag;
        segmentTree.resize(4 * n);
        buildSegmentTree(0,0,n-1,nums);
    }

    void buildSegmentTree(int i,int l,int r,vector<int>& nums){
        if(l==r){
            segmentTree[i]=nums[l];
            return;
        }

        int mid=l+(r-l)/2;

        buildSegmentTree(2*i+1,l,mid,nums);
        buildSegmentTree(2*i+2,mid+1,r,nums);

        if(isMinTree){
            segmentTree[i]=min(segmentTree[2*i+1],segmentTree[2*i+2]);
        }
        else{
            segmentTree[i]=max(segmentTree[2*i+1],segmentTree[2*i+2]);
        }
    }

    int querySegmentTree(int start,int end,int i,int l,int r){
        // no overlap
        if(l>end || r<start)
            return isMinTree ? INT_MAX : INT_MIN;

        // complete overlap
        if(l>=start && r<=end){
            return segmentTree[i];
        }

        int mid=l+(r-l)/2;

        int a=querySegmentTree(start,end,2*i+1,l,mid);
        int b=querySegmentTree(start,end,2*i+2,mid+1,r);

        if(isMinTree)
            return min(a,b);
        else
            return max(a,b);
    }

    int query(int l,int r){
        return querySegmentTree(l,r,0,0,n-1);
    }
};

class Solution {
public:
    typedef long long ll;

    ll getValue(int l,int r,SegmentTree& minST, SegmentTree& maxST){
        int minEL=minST.query(l,r);
        int maxEL=maxST.query(l,r);
        return (ll)maxEL-minEL;
    }

    long long maxTotalValue(vector<int>& nums, int k) {
        int n=nums.size();

        SegmentTree minST(nums,true);
        SegmentTree maxST(nums,false);

        priority_queue<tuple<ll,int,int>> pq;

        for(int l=0;l<n;l++){
            ll value=getValue(l,n-1,minST,maxST);
            pq.push({value,l,n-1});
        }

        ll result=0;

        while(k-- && !pq.empty()){
            auto [value,l,r]=pq.top();
            pq.pop();

            result+=value;

            if(r > l){
                ll nextBestValue=getValue(l,r-1,minST,maxST);
                pq.push({nextBestValue,l,r-1});
            }
        }

        return result;
    }
};