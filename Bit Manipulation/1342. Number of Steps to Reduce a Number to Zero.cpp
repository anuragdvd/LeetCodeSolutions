// 1342. Number of Steps to Reduce a Number to Zero :: https://leetcode.com/problems/number-of-steps-to-reduce-a-number-to-zero/

class Solution {
public:
    int numberOfSteps (int num) {
        if(num==0)  return 0;
        int lim=log2(num);
        if((num|(1<<lim))==num)   lim++;
        int ans=1;
        for(int i=0;i<lim-1;i++)
        {
            if((num&(1<<i))==0)   ans++;
            else    ans+=2;
            cout<<(1<<i)<<" "<<ans<<endl;
        }
        return ans;
    }
};