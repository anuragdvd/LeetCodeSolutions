64. Minimum Path Sum

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int dp[n+1][m+1];
       
        
        // filling the extra row and column 
        
        for(int i=0;i<=n;i++)
        {
            dp[i][m]=10000001;
        }
        
        for(int i=0;i<=m;i++)
        {
            dp[n][i]=10000001;
        }
        
        dp[n-1][m]=0;
        dp[n][m-1]=0;
        
        
        // dp(i,j) == minimum path cell to reach cell (i,j)
        // there are two directions in this case 
        // thus, dp(i,j) = min(dp(i+1,j), dp(i,j+1)) + cost[i][j] 
        // where dp[i+1][j] is the bottom cell and dp[i][j+1] is the right cell
        
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                dp[i][j]=min(dp[i+1][j],dp[i][j+1]) + grid[i][j];
            }
        }
       
        
        return dp[0][0];
        
    }
};