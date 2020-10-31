// 1218. Longest Arithmetic Subsequence of Given Difference :: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int,int> freq;
        int n=arr.size();
        if(n<=1)    return n;
        vector<int> dp(n,1);
        freq[arr[0]]=0;
        int mx=INT_MIN;
        for(int i=1;i<n;i++)
        {
            if(freq.find(arr[i]-diff)!=freq.end())
            {
                dp[i]=dp[freq[arr[i]-diff]]+1;
                 cout<<arr[i]<<" ";
            }
            freq[arr[i]]=i;
            mx=max(mx,dp[i]);
        }
        return mx;
    }
};