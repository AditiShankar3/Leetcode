/*
[Description]
Kth Largest Element in an Array
https://leetcode.com/problems/k-closest-points-to-origin/submissions/2077504688/

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?

 
Example 1:
Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:
Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4

 
Constraints:

  1 <= k <= nums.length <= 105
  -104 <= nums[i] <= 104

[Metadata]
- Difficulty: Medium
- Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Quickselect
- Slug: kth-largest-element-in-an-array
*/

// [Solution]
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<vector<int>> ans;
        priority_queue<
            pair<int,vector<int>>,
            vector<pair<int,vector<int>>>
        > min_heap; //max_heap
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];

            int dis = x*x + y*y;
            min_heap.push({dis,{points[i][0],points[i][1]}});
            if(min_heap.size()>k)
                min_heap.pop();
        }
        while(!min_heap.empty()){
            ans.push_back(min_heap.top().second);
            min_heap.pop();
        }
        return ans;
    }
};