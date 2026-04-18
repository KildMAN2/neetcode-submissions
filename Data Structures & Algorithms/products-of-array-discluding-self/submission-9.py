class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        zerocount = 0 
        tempall = 1
        for n in nums:
            if n != 0:
                tempall *= n
            else:
                zerocount += 1
        if zerocount>1 : 
            return [0] * len(nums)
        res = [0] * len(nums) 
        for i in range(len(nums)):
            if zerocount>0:
                if nums[i] == 0:
                    res[i] = tempall
                else:
                    res[i] = 0
            else:
                res[i] = tempall // nums[i]
        return res;


        