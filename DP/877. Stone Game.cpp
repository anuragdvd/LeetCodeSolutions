// 877. Stone Game :: https://leetcode.com/problems/stone-game/

class Solution {
public:
    int dp[501][501][2];
    int ans(vector<int>& piles, int i,int j , int k)
    {
        if(i>=piles.size()||j>=piles.size())    return 0;
        if(dp[i][j][k]!=-1)
            return dp[i][j][k];
        else if(k==0)
            dp[i][j][k]=max(ans(piles,i+1,j,!k)+piles[i],piles[j]+ans(piles,i,j-1,!k));
        else
            dp[i][j][k]=max(ans(piles,i+1,j,!k)-piles[i],-piles[j]+ans(piles,i,j-1,!k));
        return dp[i][j][k];
    }
    bool stoneGame(vector<int>& piles) {
        memset(dp,-1,sizeof(dp));
        dp[0][0][1]=piles[0];
        int val=ans(piles,0,piles.size()-1,0);
        
       
        if(val>0)
            return true;
        else
            return false;
    }
};