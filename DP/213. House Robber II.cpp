// 213. House Robber II :: https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0)    return 0;
        if(n==1)    return nums[0];
        if(n==2)    return max(nums[1],nums[0]);
        int dp1[n+1];
        int ans=0;
        memset(dp1,0,sizeof(dp1));
       
        dp1[0]=nums[0];
        dp1[1]=nums[0];
        for(int i=2;i<n;i++)
        {
            if(i==n-1)    dp1[i]=dp1[i-1];
            else dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        ans=dp1[n-1];
        
        memset(dp1,0,sizeof(dp1));
        
        dp1[0]=0;
        dp1[1]=nums[1];
        for(int i=2;i<n;i++)
        {
            
             dp1[i]=max(dp1[i-1],dp1[i-2]+nums[i]);
        }
        
        ans=max(ans,dp1[n-1]);
        
        return ans;
        
    }
};