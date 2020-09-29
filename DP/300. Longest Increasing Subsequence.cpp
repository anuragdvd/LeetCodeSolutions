// 300. Longest Increasing Subsequence :: https://leetcode.com/problems/longest-increasing-subsequence/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

	/* trying basic solution first , dp[i] = LIS till index i. 
   	   dp[i] = 1 + dp[j] , j -> 0 to i && nums[j]<nums[i] /*
        int n=nums.size();
        if(n==0)    return 0;
        vector<int> dp(n+1,1);
        for(int i=1;i<n;i++)
        {
            for(int j=i-1;j>=0;j--)
            {
                if(nums[j]<nums[i])
                {
                dp[i]=max(dp[i],dp[j]+1);
                }
            }
        }
        int ans=INT_MIN;
        for(int i=0;i<=n;i++)
            ans=max(ans,dp[i]); 
        return ans;
        
    }
};