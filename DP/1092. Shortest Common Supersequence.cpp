// 1092. Shortest Common Supersequence ::  https://leetcode.com/problems/shortest-common-supersequence/

class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.length();
        int m=t.length();
        int dp[n+1][m+1];
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                if(s[i-1]==t[j-1])
                {
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
       /* for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=m;j++)
            {
                cout<<dp[i][j]<<" ";
            }
            cout<<endl;
        }  */ 
        string lcs="";
        int x=n,y=m;
        while(x>0&&y>0)
        {
            if(s[x-1]==t[y-1])
            {
                   lcs=t[y-1]+lcs;
                   x--;
                   y--;
            }
            else if(dp[x-1][y]<=dp[x][y-1])
            {
                   y--;
            }
            else
            {
                   x--;
            }
        }  
      
        
        
        string ans="";
        int i=0; int j=0;
        for(auto c:lcs)
        {
            while(s[i]!=c) 
            {
                 ans+=s[i]; i++;
            }
            while(t[j]!=c)
            {
                 ans+=t[j]; j++;
            }
            ans+=c; i++; j++;
        }
        while(i!=n)
        {
            ans+=s[i++];
        }
        while(j!=m)
        {
            ans+=t[j++];
        }
        return ans;
    }
};