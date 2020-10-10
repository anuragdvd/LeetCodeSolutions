// 377. Combination Sum IV :: https://leetcode.com/problems/combination-sum-iv/

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        int n=nums.size();
        vector<long long int> dp(target+1,0);
        

        /*  
        dp(i) = number of ways to make sum i 
        dp(i) = summation of dp(i-nums[j]) where i -nums[j]>=0
        base case : dp(0) = 1
        
        Example case: 
        dp[1] = 1 (1) = 1
        dp[2] = (1,1) 1 + (2) 1  = 2
        dp[3] = {(1,1,1) , (2,1)} 2 + {(1,2)} 1 + {3} + 1 = 4
        dp[4] = {(1,1,1,1) , (2,1,1) , (1,2,1) , (3,1) 4 + {(1,1,2),(2,2)} 2 + {1,3} + 1          */ 
        
        dp[0]=1;
        for(int i=1;i<=target;i++)
        {
            for(int j=0;j<n;++j)
            {
                if(i-nums[j]>=0&&(dp[i]<INT_MAX)&&dp[i-nums[j]]<INT_MAX)
                   dp[i]=dp[i-nums[j]]+dp[i];
            }
        }
        
        
        
        return dp[target];
    }
};