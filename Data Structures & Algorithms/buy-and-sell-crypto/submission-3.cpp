class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minProfit = INT_MAX ;
        int maxProfit = 0  ;
        for(int num : prices)
        {
            minProfit = min(minProfit , num);
            maxProfit = max(maxProfit , num - minProfit);

        }
        
        return maxProfit;
    }
};
