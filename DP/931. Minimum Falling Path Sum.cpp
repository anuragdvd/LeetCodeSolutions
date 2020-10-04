// 931. Minimum Falling Path Sum : https://leetcode.com/problems/minimum-falling-path-sum/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& a) {
        int n=a.size();
        int m=a[0].size();
        int dp[n][m];
        memset(dp,0,sizeof(dp));
       
        for(int i=0;i<m;i++)
            dp[n-1][i]=a[n-1][i];
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=a[i][j]+min(dp[i+1][max(0,j-1)],min(dp[i+1][j],dp[i+1][min(m-1,j+1)]));
            }
        }
        
        int mn=INT_MAX;
        for(int i=0;i<m;i++)
            mn=min(mn,dp[0][i]);
        return mn;
    }
};