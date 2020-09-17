// Unique paths - 2 :: https://leetcode.com/problems/unique-paths-ii 

class Solution {
public:
    long long int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        if(grid.size()==0)  return 0;

        vector<vector<long long int>> dp(grid.size(),vector<long long int>(grid[0].size(),0));
        
        int n=grid.size();
        int m=grid[0].size();
        
        
        dp[n-1][m-1]=1;
        
        if(grid[n-1][m-1])  dp[n-1][m-1]=0;
        
        // filling last row 
        bool flag=true;
        if(grid[n-1][m-1])  flag=!flag;
        for(int i=m-2;i>=0;i--)
        {
            if(grid[n-1][i])
            {
                flag=false;
            }
            if(flag)
            {
            dp[n-1][i]=1;
            }
            else{
                dp[n-1][i]=0;
            }
        }
        
        flag=true;
        
        if(grid[n-1][m-1])  flag=!flag;
        
        // filling last column
        
        for(int i=n-2;i>=0;i--)
        {
            if(grid[i][m-1])
                flag=false;
            if(flag)
                dp[i][m-1]=1;
            else
                dp[i][m-1]=0;
        }
        
        
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(grid[i][j])
                    dp[i][j]=0;
                else
                    dp[i][j]=dp[i+1][j]+dp[i][j+1];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<dp[i][j]<<" ";
            cout<<endl;
        }
        
        return dp[0][0];     
    }
};