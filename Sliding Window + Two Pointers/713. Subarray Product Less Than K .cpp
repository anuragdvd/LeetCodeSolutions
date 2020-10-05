// 713. Subarray Product Less Than K : https://leetcode.com/problems/subarray-product-less-than-k/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int start=0;
        int end=0;
        int ans=0;
        int prod=1;
        if(k==0)    return 0;
        for(;end<n;end++)
        {
            prod*=nums[end];
            while(prod>=k&&start<=end)
            {
                prod/=nums[start];
                start++;
            }
            int sz=end-start+1;
            ans+=sz;
            

        }
        
        return ans;
    }
};