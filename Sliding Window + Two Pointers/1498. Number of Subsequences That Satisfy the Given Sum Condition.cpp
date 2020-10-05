// 1498. Number of Subsequences That Satisfy the Given Sum Condition :: https://leetcode.com/problems/number-of-subsequences-that-satisfy-the-given-sum-condition/

class Solution {
public:
    int numSubseq(vector<int>& a, int k) {
        int n=a.size();
        int ans=0;
        sort(a.begin(),a.end());
        int start=0,end=n-1;
        int p[n]; p[0]=1;
        for(int i=1;i<n;i++)
        {
            p[i]=(p[i-1]*2)%1000000007;
        }
        
           
        while(start<=end)
        {
            if(a[start]+a[end]>k)
            {
                end--;
            }
            else 
            {
                
                ans=(ans+p[end-start])%1000000007;
                start++;
            }
        }
        return ans%1000000007;
    }
};