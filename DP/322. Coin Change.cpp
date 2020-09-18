// 322. Coin Change :: https://leetcode.com/problems/coin-change/

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,1000000001);
        dp[0]=0;       
        
        int n=coins.size();
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=coins[i];j<amount+1;j++)
            {
                if(j-coins[i]!=1000000001)
                    dp[j]=min(dp[j],dp[j-coins[i]]+1);                
            }
        }
        
        
        if(dp[amount]==1000000001)  dp[amount]=-1;
        return dp[amount];        
        
    }
};