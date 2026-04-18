class Solution:
    def trap(self, height: List[int]) -> int:
        if len(height) == 0 :
            return 0 
        left = 0 
        right = len(height) - 1 
        res = 0 
        maxL = height[left] 
        maxR = height[right] 
        while left < right:
            if maxL < maxR:
                left += 1 
                maxL = max(maxL , height[left])
                res += maxL - height[left]
            else :
                right -= 1 
                maxR = max(maxR , height[right])
                res += maxR - height[right]
        return res

