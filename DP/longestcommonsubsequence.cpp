// LCS :: https://leetcode.com/problems/longest-common-subsequence

class Solution {
public:
    int longestCommonSubsequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n+1;i++)
        {
        for(int j=0;j<m+1;j++)
        {
            if(i==0||j==0)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j]=1+dp[i-1][j-1];
            }
            else
            {
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        }
        return dp[n][m];
    }
};