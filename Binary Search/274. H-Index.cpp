// 274. H-Index :: https://leetcode.com/problems/h-index/

class Solution {
public:
    int hIndex(vector<int>& a) {
        sort(a.begin(),a.end());
        int ans=0;
        int n=a.size();
        for(int i=0;i<n;i++)
        {
            if(a[i]>=n-i)
            {
                ans=n-i;
                break;
            }
        }
        return ans;
    }
};