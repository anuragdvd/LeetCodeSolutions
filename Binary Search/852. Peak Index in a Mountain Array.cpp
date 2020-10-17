// 852. Peak Index in a Mountain Array :: https://leetcode.com/problems/peak-index-in-a-mountain-array/

class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int l=0;
        int r=arr.size()-1;
        int ans=0;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(mid==0||arr[mid]>arr[mid-1])
            {
                ans=mid;
                l=mid+1;
            }
            else{
                r=mid-1;
            }
        }
        return ans;
    }
};