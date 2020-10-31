// 221. Maximal Square :: https://leetcode.com/problems/maximal-square/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        if(n==0)    return 0;
        int m=matrix[0].size();
        if(m==0)    return 0;
        int dp[n][m];
        memset(dp,0,sizeof(dp));
        int mx=0;
        for(int i=0;i<m;i++)
        {
            dp[0][i]=matrix[0][i]-'0';
            if(dp[0][i]==1) mx=1;
        }
        
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0]-'0';
            if(dp[i][0]==1) mx=1;
        }
        
         
       
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]-'0'==1)
                {    
                int firstcell=dp[i-1][j-1];
                int seccell=dp[i-1][j];
                int thirdcell=dp[i][j-1];
                dp[i][j]=min(min(firstcell,seccell),thirdcell)+1;
                mx=max(dp[i][j],mx);
                }
            }
           
        }
        
        return mx*mx;
        
        
    }
};