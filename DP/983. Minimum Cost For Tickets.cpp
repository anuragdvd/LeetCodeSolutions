// 983. Minimum Cost For Tickets :: https://leetcode.com/problems/minimum-cost-for-tickets/

class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        int dp[365+1];
        memset(dp,0,sizeof(dp));
        map<int,int> mp;
        for(auto i:days)    mp[i]++;
        for(int i=1;i<=365;i++)
        {
           
            if(mp[i])
            {
                dp[i]=dp[i-1]+costs[0];
        
                dp[i]=min(dp[i],dp[max(0,i-7)]+costs[1]);
                
                
                dp[i]=min(dp[max(0,i-30)]+costs[2],dp[i]);
                
               
            }
            else
            {
                 dp[i]=dp[i-1];
            }
        }
     
        
        return dp[365];
    }
};