// 1318. Minimum Flips to Make a OR b Equal to c :: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        // cases :
        // 1. 0 | 0 = 1 (need to set one bit)
        // 2. 1 | 1 = 0 (need to unset both bit)
        // 3. 0 | 1 = 0 (need to unset one bit)
        
        bitset<32> b1=a;
        bitset<32> b2=b;
        bitset<32> b3=c;
        
        int ans=0;
        
        for (int i = 0; i < b1.size(); ++i) {
         //   cout<<(b1[i]|b2[i])<<" "<<b3[i]<<endl;
            if((b1[i]|b2[i])==b3[i])
            {
                continue;
            }
            else if(b3[i]==1&&(b1[i]|b2[i])==0&&(b1[i]^b2[i])==0)
                ans++;
            else if(b3[i]==0&&(b1[i]&b2[i])==1)
            {  ans+=2;  }
            else if(b3[i]==0&&(b1[i]|b2[i])==1&&(b1[i]&b2[i])!=1)
            {   
                ans++;
            }
        }
        return ans;
    }
};