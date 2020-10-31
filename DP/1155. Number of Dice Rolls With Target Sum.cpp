// 1155. Number of Dice Rolls With Target Sum :: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int dp[d][target+1];
        memset(dp,0,sizeof(dp));
        
        for(int i=1;i<=min(f,target);i++)
        {
            dp[0][i]=1;
        }
        
        for(int i=1;i<d;i++)
        {
            for(int j=target;j>=1;j--)
            {
                for(int k=1;k<=f;k++)
                {
                    if(j-k>0)
                        dp[i][j]=(dp[i][j]%1000000007+dp[i-1][j-k]%1000000007)%1000000007;
                }
            }
        }
        
        
        
        return dp[d-1][target];
        
    }
};