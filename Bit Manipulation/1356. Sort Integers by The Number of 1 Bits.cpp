 // 1356. Sort Integers by The Number of 1 Bits :: https://leetcode.com/problems/sort-integers-by-the-number-of-1-bits/

bool comp(int a,int b)
{
        if(__builtin_popcount(a)==__builtin_popcount(b)) 
            return a<b;
        else 
            return __builtin_popcount(a)<__builtin_popcount(b);
}
class Solution {
public:
   
    vector<int> sortByBits(vector<int>& arr) {
      
        sort(arr.begin(),arr.end(),comp);
        
        return arr;
    }
};