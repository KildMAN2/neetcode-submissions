class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ;
        int minSell = prices[0];
        for(int num : prices)
        {
            maxProfit = max(maxProfit, num - minSell);
            minSell = min (minSell, num);
        }
        return maxProfit;
    }
};
