// 209. Minimum Size Subarray Sum :: https://leetcode.com/problems/minimum-size-subarray-sum/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& a) {
        int n=a.size();
        int start=0;
        int end=0;
        int curr_sum=0;
        int ans=INT_MAX;
        while(end<n)
        {
            curr_sum+=a[end++];
            if(curr_sum>=s)
            {
                while(curr_sum>=s)
                {
                    ans=min(ans,end-start);
                    curr_sum-=a[start++];
                }
            }
        }
        return ans==INT_MAX?0:ans;
    }
};