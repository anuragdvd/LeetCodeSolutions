// 1289. Minimum Falling Path Sum II :: https://leetcode.com/problems/minimum-falling-path-sum-ii/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int dp[n][m];
        memset(dp,1000001,sizeof(dp));
       
        for(int i=0;i<m;i++)
            dp[n-1][i]=a[n-1][i];
        
       
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                for(int k=0;k<m;k++)
                {   
                    if(k!=j)
                        dp[i][j]=min(a[i][j]+dp[i+1][k],dp[i][j]);   
                }
            }
        }
        
        int mn=INT_MAX;
        for(int i=0;i<m;i++)
            mn=min(mn,dp[0][i]);
        return mn;
    }
};