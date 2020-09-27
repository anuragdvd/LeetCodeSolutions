// 1456. Maximum Number of Vowels in a Substring of Given Length ::
https://leetcode.com/problems/maximum-number-of-vowels-in-a-substring-of-given-length/

class Solution {
public:
    int maxVowels(string s, int k) {
        int n=s.length();
        int curr=0;
        int start=0;
        int end=0;
        int ans=INT_MIN;
        for(;end<n;end++)
        {
            if(end-start+1>k)
            {
                if(s[start]=='a'||s[start]=='e'||s[start]=='o'||s[start]=='i'||s[start]=='u') 
                    curr--;
                start++;
            }
            if(s[end]=='a'||s[end]=='e'||s[end]=='o'||s[end]=='i'||s[end]=='u') 
                    curr++;
            ans=max(ans,curr);
        }
        return ans;
    }
};