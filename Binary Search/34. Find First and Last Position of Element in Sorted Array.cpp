// 34. Find First and Last Position of Element in Sorted Array :: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/

class Solution {
public:
    vector<int> searchRange(vector<int>& a, int target) {
        int first=-1;
        int last=-1;
        int l=0;
        vector<int> ans; 
        int r=a.size()-1;
        
        
        
        if(r==-1)
        {
            ans.push_back(first);
            ans.push_back(last);
            return ans;
        }
        
        while(l<=r)
        {
            if(r<0) break;
            int mid=l+(r-l)/2;
           
            if(a[mid]==target)
            {
                first=mid;
                r=mid-1;
            }
            else if(a[mid]>target)
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        l=0;
        r=a.size();
        
        while(l<=r)
        {
            if(l>=a.size())    break;
            int mid=l+(r-l)/2;
            if(a[mid]==target)
            {
                last=mid;
                l=mid+1;
            }
            else if(a[mid]>target)
            {
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        
        
        ans.push_back(first);
        ans.push_back(last);
        
        return ans;
        
    }
};