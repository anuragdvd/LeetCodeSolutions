// 740. Delete and Earn :: https://leetcode.com/problems/delete-and-earn/

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        if(nums.size()==0)  return 0;
        map<int,int> freq;
        for(auto i:nums)    freq[i]++;
        sort(nums.begin(),nums.end());
        int mx=nums[nums.size()-1];
        int dp[mx+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;
        dp[1]=1*freq[1];
        for(int i=2;i<=mx;i++)
        {
            dp[i]=max(i*freq[i]+dp[i-2],dp[i]+dp[i-1]);
            cout<<dp[i]<<" ";
        }
        return dp[mx];
    }
};