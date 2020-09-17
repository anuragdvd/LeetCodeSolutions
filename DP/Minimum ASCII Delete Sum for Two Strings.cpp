/* Minimum ASCII Delete Sum for Two Strings :: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings 


dp(i,j) = min ( dp[i-1][j] + s1[i-1] ( if we remove character from first string ) , 
		dp[i][j-1] + s2[j-1] ( if we remove character from second string ) ,
		dp[i-1][j-1] + s1[i-1] + s2[j-1] (if we remove character from both strings ) ) 


*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n=s1.length();
        int m=s2.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        for(int i=1;i<=m;i++)
        {    
            dp[0][i]=s2[i-1]+dp[0][i-1];
        }
        for(int i=1;i<=n;i++)
        {
            dp[i][0]=s1[i-1]+dp[i-1][0];
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s1[i-1]==s2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else
                {
                    dp[i][j]=min(dp[i-1][j]+s1[i-1],dp[i][j-1]+s2[j-1]);
                    dp[i][j]=min(dp[i-1][j-1]+s1[i-1]+s2[j-1],dp[i][j]);
                }
            }
                
        }
        
       
        
               
        return dp[n][m];
        
    }
};