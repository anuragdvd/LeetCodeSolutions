// 42. Trapping Rain Water :: https://leetcode.com/problems/trapping-rain-water/

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n==0)    return 0;
        if(n==1)    return 0;
        int leftmx[n];
        int rightmx[n];
        leftmx[0]=0;
        rightmx[n-1]=0;
        for(int i=1;i<n;i++)
        {
            leftmx[i]=max(leftmx[i-1],height[i-1]);
        }
        for(int i=n-2;i>=0;i--)
        {
            rightmx[i]=max(rightmx[i+1],height[i+1]);
        }
        int ans=0;
        
        for(int i=0;i<n;i++)
        {
            int mn=min(leftmx[i],rightmx[i]);
            if(height[i]<mn)
            {
                ans+=mn-height[i];
            }
            
        }
        
        return ans;
    }
};