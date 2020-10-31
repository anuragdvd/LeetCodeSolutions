// 416. Partition Equal Subset Sum :: https://leetcode.com/problems/partition-equal-subset-sum/
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums)    sum+=i;
        if(sum%2!=0)    return false;
        sum/=2;
        int dp[n+1][sum+1];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=n;i++)
            dp[i][0]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=sum;j++)
            {
                
                dp[i][j]=dp[i-1][j];
                if(j-nums[i-1]>=0)
                {
                    dp[i][j]=max(dp[i][j],dp[i-1][j-nums[i-1]]);
                }
            }
        }
        
        int flag=0;
        for(int i=0;i<=n;i++)
        {
            
            if(dp[i][sum])   flag++;
        }
        
        return flag>=2?true:false;
        
    }
};