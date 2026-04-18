class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if not prices: return 0 
        maxProfit = 0
        minBuy = prices[0]
        for num in prices :
            maxProfit = max(maxProfit , num - minBuy)
            minBuy = min(minBuy , num)
        return maxProfit
        