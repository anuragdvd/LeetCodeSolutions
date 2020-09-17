class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        
        else if(n==1)    return nums[0];
        else if(n==2)   return max(nums[0],nums[1]);
        else
        {
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        int mx=max(dp[0],dp[1]);
        for(int i=2;i<nums.size();i++)
        {
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        for(auto i:dp)  cout<<i<<" ";
        return dp[n-1];
        }
    }
};