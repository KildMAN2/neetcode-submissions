class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        box = {}
        length = 0 
        l = 0
        for r in range(len(s)):
            if s[r] in box:
                l = max(l , box[s[r]] + 1)
            box[s[r]] = r
            length = max(length , r - l + 1)
        return length

        