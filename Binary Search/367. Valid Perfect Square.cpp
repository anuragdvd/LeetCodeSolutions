class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int r=num;
        
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if((long long int)mid*mid==num)
            {
                return true;
            }
            else if((long long int)mid*mid<num)
            {
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return false;
    }
};