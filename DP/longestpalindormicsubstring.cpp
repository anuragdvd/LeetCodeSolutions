// Longest Palindromic Substring :: https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.length();
        int dp[n+1][n+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n+1;i++)
            dp[i][i]=1;
        int mx=1;
        int start=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]==s[i+1])
            {
                dp[i][i+1]=1;
                mx=2;
                start=i;
            }
        }
        
        for(int k=3;k<=n;k++)
        {
            for(int i=0;i<n-k+1;i++)
            {
                int j=i+k-1;
                if(s[i]==s[j]&&dp[i+1][j-1])
                    dp[i][j]=1;
                if(k>mx&&dp[i][j])
                {
                    mx=k;
                    start=i;
                
                }
            }
        }
        
        return(s.substr(start,mx));
    }
};