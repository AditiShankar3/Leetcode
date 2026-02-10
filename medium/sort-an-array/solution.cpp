/*
[Description]
Sort an Array
https://leetcode.com/problems/sort-an-array/

Given an array of integers nums, sort the array in ascending order and return it.

You must solve the problem without using any built-in functions in O(nlog(n)) time complexity and with the smallest space complexity possible.

 
Example 1:

Input: nums = [5,2,3,1]
Output: [1,2,3,5]
Explanation: After sorting the array, the positions of some numbers are not changed (for example, 2 and 3), while the positions of other numbers are changed (for example, 1 and 5).

Example 2:

Input: nums = [5,1,1,2,0,0]
Output: [0,0,1,1,2,5]
Explanation: Note that the values of nums are not necessarily unique.

 
Constraints:

  1 <= nums.length <= 5 * 104
  -5 * 104 <= nums[i] <= 5 * 104

[Metadata]
- Difficulty: Medium
- Topics: Array, Divide and Conquer, Sorting, Heap (Priority Queue), Merge Sort, Bucket Sort, Radix Sort, Counting Sort
- Slug: sort-an-array
*/

// [Solution]
class Solution {
public:
    void merge(vector<int>& nums,int lb,int mid,int ub)
    {
        int n1 = mid - lb + 1;
        int n2 = ub - mid;

        // Create temp vectors
        vector<int> L(n1), R(n2);

        // Copy data to temp vectors L[] and R[]
        for (int i = 0; i < n1; i++)
            L[i] = nums[lb + i];
        for (int j = 0; j < n2; j++)
            R[j] = nums[mid + 1 + j];

        int i = 0, j = 0;
        int k = lb;

        // Merge the temp vectors back 
        // into arr[left..right]
        while (i < n1 && j < n2) {
            if (L[i] <= R[j]) {
                nums[k] = L[i];
                i++;
            }
            else {
                nums[k] = R[j];
                j++;
            }
            k++;
        }

        // Copy the remaining elements of L[], 
        // if there are any
        while (i < n1) {
            nums[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], 
        // if there are any
        while (j < n2) {
            nums[k] = R[j];
            j++;
            k++;
        }
    }
    void mergesort(vector<int>& nums,int lb,int ub){
        if(lb<ub)
        {
            int mid=(lb+ub)/2;
            mergesort(nums,lb,mid);
            mergesort(nums,mid+1,ub);
            merge(nums,lb,mid,ub);
        }
    }
    vector<int> sortArray(vector<int>& nums) {
        int ub=nums.size()-1;
        int lb=0;
        mergesort(nums,lb,ub);
        return nums;

    }
};