// 72. Edit Distance :: https://leetcode.com/problems/edit-distance/


class Solution {
public:
    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        
        // filling the first row 
        // i.e we need to make a string of size i from a empty string 
        // thus, the cost will be simply 1 
        
        dp[0][0]=0;
        for(int i=1;i<m+1;i++)
        {
            dp[0][i]=i;
        }
        
        // filling the first column 
        // i.e we need to make a string of size j from a empty string 
        
        for(int i=1;i<n+1;i++)
        {
            dp[i][0]=i;
        }
        
        
        // filling the rest of the dp table 
        // there are two cases in this proble
        
        // Case 1: if (word[i]==word[j]) then we can ignore this word 
        // and find answer of dp[i-1][j-1]
        
        // Case 2 : if (word[i]!=word[j]) then we will have three options 
        // if we are deleting a letter from word1 then answer will be dp[i-1][j]
        // if we are replacing a letter then answer will be dp[i-1][j-1] as we will simply add the same character in the end
        // if we are inserting a letter then answer will be dp[i][j-1] as we will add the same charcter 
        // the answer will be minimum of these three operations 
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(word1[i-1]==word2[j-1])
                    dp[i][j]=dp[i-1][j-1];
                else{
                    dp[i][j]=min(dp[i-1][j]+1,dp[i-1][j-1]+1);
                    dp[i][j]=min(dp[i][j],dp[i][j-1]+1);
                }
            }
            
        }
        
        return dp[n][m];
        
    
        
    }
};