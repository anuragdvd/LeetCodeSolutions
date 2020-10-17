// 33. Search in Rotated Sorted Array :: https://leetcode.com/problems/search-in-rotated-sorted-array/

class Solution {
public:
    int search(vector<int>& a, int target) {
        int l=0;
        int r=a.size()-1;
        int n=a.size()-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(a[mid]==target)
            {
                return mid;
            }
            if(a[mid]>a[n]&&(target<=a[n]||target>a[mid]))
            {
                l=mid+1;
            }
            else if(a[mid]>a[n]&&target>a[n]) 
            {
                r=mid-1;
            }
            else if(a[mid]<=a[n]&&a[mid]<target&&target<=a[n])
            {
                l=mid+1;

            }
            else 
            {
                r=mid-1;
            }
        }
        return -1;
    }
};