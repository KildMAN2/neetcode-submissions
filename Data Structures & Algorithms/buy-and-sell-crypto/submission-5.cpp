class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minBuy = prices[0] ; 
        int maxProfit = 0 ; 
        for(int num : prices)
        {
            minBuy = min(minBuy, num);
            maxProfit = max(maxProfit , num - minBuy);
        }
        return maxProfit;
        
    }
};
