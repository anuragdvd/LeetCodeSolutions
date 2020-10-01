// 476. Number Complement :: https://leetcode.com/problems/number-complement/

class Solution {
public:
    int findComplement(int num) {
        
        
        // n = (n|(2^log2(n)-1))^n 
        
        
        int val=log2(num);
        return num^(num|((1<<val)-1));
    }
};