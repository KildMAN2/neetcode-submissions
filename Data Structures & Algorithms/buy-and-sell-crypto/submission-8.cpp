class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ; 
        int minBuy = prices[0] ; 
        for(int p : prices )
        {
            minBuy = min(minBuy , p);
            maxProfit = max(maxProfit, p - minBuy);
        }
        return maxProfit;
        
    }
};
