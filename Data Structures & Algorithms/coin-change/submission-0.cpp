class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        vector<unsigned int> dp(amount+ 1 , 0);
        for(int i = 1; i <= amount ; i++)
        {
            dp[i] = INT_MAX;
            for(int j = 0 ; j < coins.size() ; j++)
            {
                if(coins[j] <= i && dp[i - coins[j]] + 1 < dp[i])
                {
                    dp[i] = dp[i - coins[j]] + 1;
                    cout<< "dp[i] " << dp[i] << endl;
                }
            }
        }
        int i = 0 ;
        for(unsigned int num : dp)
        {
            cout << "dp is " << num << "i is"  <<i << endl;
            i++;
        }
        return dp[amount] == INT_MAX ? -1 : dp[amount];
        
    }
};
