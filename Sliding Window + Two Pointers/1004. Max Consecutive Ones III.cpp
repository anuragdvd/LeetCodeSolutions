// 1004. Max Consecutive Ones III :: https://leetcode.com/problems/max-consecutive-ones-iii/

class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int n=A.size();
        int start=0;
        int end=0;
        int curr=0;
        int ans=INT_MIN;
        for(;start<n;start++)
        {
            if(A[start]==0)
            {
                curr++;
            }
            if(curr>k)
            {
                while(curr>k&&end<=start)
                {
                    if(A[end]==0)    curr--; end++; 
                }
            }
            ans=max(ans,start-end+1);
        }
        return ans;
    }
};