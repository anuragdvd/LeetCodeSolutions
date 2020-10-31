// 50. Pow(x, n) :: https://leetcode.com/problems/powx-n
class Solution {
public:
    double myPow(double x, int n) {
        double res=1.00;
        // x ^ -y == 1/x^y  == 1/x * x ^ (y+1)  
        
        while(n!=0)
        {
        
            if(n%2==1&&n>0)  res*=x;
            if(n%2==-1&&n<0) res/=x; 
            x*=x;
            n/=2;
        }
        return res;
    }
};