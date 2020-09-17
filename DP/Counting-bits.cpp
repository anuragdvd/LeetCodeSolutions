/* Problem Link:: https://leetcode.com/problems/counting-bits
dp[i] = number of 1's in ith number
dp[i] = 1 + dp[i-(1<<log2(i))
 */


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n+1);
        ans[0]=0;
        if(n==0)    return ans;
        ans[1]=1;
        if(n==1)    return ans;
        for(int i=2;i<=n;i++)
        {
            int j=log2(i);
            j=(1<<j);
            ans[i]=1+ans[i-j];
        }
        return ans;
    }
};