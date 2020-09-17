class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        bool flag=true;
        string brute;
        for(int i=0;i<s.length()-1;i++)
        {
            brute+=s[i];
            int k=0,j=i+1;
            while(j!=s.length())
            {
                if(s[j]!=brute[k])
                {    
                    flag=false;
                    break;
                }   
                k=(k+1)%(i+1);
                j++;
            }
            if(flag&&k==0)
                return true;
            else
                flag=true;
        }
        
        return false;
        
    }
};