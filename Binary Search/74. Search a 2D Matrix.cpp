// 74. Search a 2D Matrix :: https://leetcode.com/problems/search-a-2d-matrix/

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& a, int target) {
        int row=-1;
        int n=a.size();
        if(n==0)    return 0;
        int m=a[0].size();
        if(m==0)    return 0;
        int l=0; 
        int r=n-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid][0]<=target&&target<=a[mid][m-1])
            {
                row=mid;  break;
            }
            else{
                if(a[mid][0]>target)
                {
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
        }
        //cout<<row<<endl;
        if(row==-1) return false;
        
        l=0; r=m-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[row][mid]==target)
                return true;
            else if(a[row][mid]>target)
                r=mid-1;
            else
                l=mid+1;
        }
        return false;
        
    }
};