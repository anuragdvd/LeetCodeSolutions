// 240. Search a 2D Matrix II :: https://leetcode.com/problems/search-a-2d-matrix-ii/


/* nlogm solution */ 

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int n=a.size();
        if(n==0)    return false;
        int m=a[0].size();
        if(m==0)    return false;
        
        for(int i=0;i<n;i++)
        {
            int l=0; int r=m-1;
            if(a[i][0]>target||a[i][m-1]<target)   continue;
            else{
                while(l<=r)
                {
                    int mid=l+(r-l)/2;
                    if(a[i][mid]==target)   return true;
                    else if(a[i][mid]>target)    r=mid-1;
                    else    l=mid+1;
                }
            }
        }
        
        return false;
        
    }
};