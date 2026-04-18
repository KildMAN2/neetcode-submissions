class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ;
        int minPay = INT_MAX;
        for(int num : prices)
        {
            minPay = min(num , minPay);
            maxProfit = max(maxProfit, num - minPay);
        }
        return maxProfit;
        
    }
};
