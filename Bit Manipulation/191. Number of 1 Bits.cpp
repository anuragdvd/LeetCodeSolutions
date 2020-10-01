// 191. Number of 1 Bits ;; https://leetcode.com/problems/number-of-1-bits/

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int ans=0;
        // Not using built in function for solving this problem

        // n=6 (110)
        // n = 6 ==> 6 & 5 ==> 110 & 101 => 100 => 4 
        // 4 => 4 & 3 ==> 100&011 => 000
        // n = n & (n-1) will drop the last bit nice 
        while(n>0)
        {
            n=n&(n-1);
            ans++;
        }
        return ans;
    }
};