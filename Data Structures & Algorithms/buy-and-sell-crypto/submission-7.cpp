class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int minPay = prices[0] ; 
        int maxProfit = 0 ; 
        for(int price : prices)
        {
            minPay = min(price, minPay);
            maxProfit = max(maxProfit, price - minPay);
        }
        return maxProfit;
        
    }
};
