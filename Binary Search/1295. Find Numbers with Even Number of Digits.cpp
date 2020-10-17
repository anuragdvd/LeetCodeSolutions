// 1295. Find Numbers with Even Number of Digits :: https://leetcode.com/problems/find-numbers-with-even-number-of-digits/

class Solution {
public:
    int findNumbers(vector<int>& a) {
        // using math tricks of log 
        
        int c=0;
        
        for(auto i:a)
        {
            int digits=log10(i);
            
            if(digits%2) c++;
            
        }
        
        return c;
        
    }
};