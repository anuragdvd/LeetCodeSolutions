// 647. Palindromic Substrings :: https://leetcode.com/problems/palindromic-substrings/

class Solution {
public:
    int countSubstrings(string s) {
        int n=s.length();
        int dp[n][n];
        memset(dp,0,sizeof(dp));
        int ans=n;
        // all substring of size 1 are palindrome 
        for(int i=0;i<n;i++)
        {
            dp[i][i]=1;
        }
        if(n==1)    return n;
        
        // checking all substring of size 2 
        
        for(int i=0;i<n-1;i++)
        {
            if(s[i]==s[i+1])
                dp[i][i+1]=1;
            if(dp[i][i+1])
                ans++;
        }
        
        
        // checking rest of the sustrings 
        // For any S[i...j] it will be palindrome if s[i]==s[j] and s[i+1...j-1] is also            a palindrome 
        // here curr is the length of the current substring 
        for(int curr=2;curr<n;curr++)
        {
            for(int start=0;start<n-curr+1;start++)
            {
                int end=curr+start;
                
                if(s[start]==s[end]&&dp[start+1][end-1]==1)
                {
                    dp[start][end]=1;
                    ans++;
                }                
            }
        }
        
        return ans;
    }
};