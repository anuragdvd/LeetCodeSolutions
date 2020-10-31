// 413. Arithmetic Slices :: https://leetcode.com/problems/arithmetic-slices/

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& a) {
        int n=a.size();
        if(n<3)    return 0;
        int dp[n];
        memset(dp,0,sizeof(dp));
        if(a[2]-a[1]==a[1]-a[0])
        {
            dp[2]=1;
        }
        int curr=a[2]-a[1];
        for(int i=3;i<n;i++)
        {
            if(a[i]-a[i-1]==curr)
            {
                dp[i]=dp[i-1]+1;
            }
            else{
                curr=a[i]-a[i-1];
            }
        }
        int sum=0;
        for(auto i:dp)  sum+=i;
        return sum;
    }
};