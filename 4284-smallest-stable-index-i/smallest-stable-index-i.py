class Solution:
    def firstStableIndex(self, nums: list[int], k: int) -> int:
        for i in range(0,len(nums)):
            maxi=max(nums[0:i+1])
            mini=min(nums[i:])
            stable= maxi-mini
            if(stable<=k):
                return i
        return -1

        