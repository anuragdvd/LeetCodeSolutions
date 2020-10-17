// 1351. Count Negative Numbers in a Sorted Matrix :: https://leetcode.com/problems/count-negative-numbers-in-a-sorted-matrix/

class Solution {
public:
    int countNegatives(vector<vector<int>>& a) {
        int n=a.size();
        if(n==0)    return 0;
        int m=a[0].size();
        if(m==0)    return 0;
        int c=0;
        // we are looking for the last positive number in every row nlogm
        for(int i=0;i<n;i++)
        {
            int l=0;
            int r=m-1;
            
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(a[i][mid]<0)
                {
                    // search for last positive in left 
                    r=mid-1;
                }
                else if(a[i][mid]>=0)
                {
                    // search for last positive in rigt
                    l=mid+1;
                }
            }
            c=c+m-l;
        }
        
        return c;
        
    }
};