// 69. Sqrt(x) :: https://leetcode.com/problems/sqrtx/

class Solution {
public:
    int mySqrt(int x) {
        int l=0;
        int ans=0;
        int r=x; 
        while(l<=r)
        {
            long long int mid=l+(r-l)/2;
            if(mid*mid==x)
            {
                return mid;
            }
            else if((mid*mid)>x)
            {
                ans=mid-1; r=mid-1;
            }
            else{
                l=mid+1;
            }        
        }
        return ans;
    }
};