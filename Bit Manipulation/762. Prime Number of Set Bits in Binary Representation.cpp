// 762. Prime Number of Set Bits in Binary Representation :: https://leetcode.com/problems/prime-number-of-set-bits-in-binary-representation/

class Solution {
public:
    int countPrimeSetBits(int L, int R) {
        // lets how many bits can be set 
        // log2(10^6) = approx 20
        // we need to store only prime numbers till 20 for solving this problem
        
        set<int> s;
        s.insert(2);
        for(int n=3;n<=20;n++)
        {
            bool flag=true;
        for(int i=2;i*i<=n;i++)
        {
            if(n%i==0)
            {
                flag=false; break;
            }
        }
            if(flag)
                s.insert(n);               
        }
        
        int ans=0;
        
        for(int i=L;i<=R;i++)
        {
            int val=__builtin_popcount(i);
            if(s.find(val)!=s.end())    ans++;
        }
        
        return ans;
        
    }
}