// 231. Power of Two :: https://leetcode.com/problems/power-of-two/

class Solution {
public:
    bool isPowerOfTwo(int n) {
        return __builtin_popcount(n)==1&&n>=0?true:false;
    }
};
