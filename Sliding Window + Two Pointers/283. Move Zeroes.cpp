// 283. Move Zeroes :: https://leetcode.com/problems/move-zeroes/

class Solution {
public:
    void moveZeroes(vector<int>& a) {
        int n=a.size();
        int k=0;
        // shift all non zero element in the end
        for(int i=0;i<n;i++)
        {
            if(a[i]!=0)
                a[k++]=a[i];
        }
        
        for(int i=k;i<n;i++)
            a[i]=0;
    }
};