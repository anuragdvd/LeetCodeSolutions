// Longest Palindromic Subsequence :: https://leetcode.com/problems/longest-palindromic-subsequence

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n=s.size();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        
        // all subsequence of size are palindromes 
        
        for(int i=0;i<n;i++)
            dp[i][i]=1;
        
        
        // finding all the subsequence of size 2
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                dp[i][i+1]=2;
        }
        
        // filling the rest of the dp table
        
        for(int len=2;len<=n;len++)
        {
            for(int i=0;i<n-len+1;i++)
            {
                int j=i+len-1;
                
                if(s[i]==s[j])
                    dp[i][j]=2+dp[i+1][j-1];
                else
                    dp[i][j]=max(dp[i+1][j],dp[i][j-1]);
            }
        }
        
       
        return dp[0][n-1];
        
    }
};