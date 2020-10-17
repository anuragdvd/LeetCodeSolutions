// 153. Find Minimum in Rotated Sorted Array :: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/

class Solution {
public:
    int findMin(vector<int>& a) {
        // compare with the last element 
        
        int l=0;
        int r=a.size()-1;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]>a[a.size()-1])
            {
                l=mid+1;
            }
            else{
                ans=a[mid];
                r=mid-1;
            }
        }
        return ans;
    }
};