class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        box = {}
        res = 0 
        l = 0 
        maxK = 0 
        for r in range(len(s)):
            maxK = max(maxK, box.get(s[r],0) + 1)
            while(r - l + 1 - maxK > k):
                box[s[l]] -= 1
                l += 1
            box[s[r]] = 1 + box.get(s[r], 0)
            res  = max(r - l + 1 , res)
            
        return res



        