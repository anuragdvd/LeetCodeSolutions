// 424. Longest Repeating Character Replacement :: https://leetcode.com/problems/longest-repeating-character-replacement/

class Solution {
public:
    int characterReplacement(string s, int k) {
        int start=0,end=0,ans=0;
        unordered_map<char,int> mp;
        int freq1=0;
        int freq2=0;
       
        char mx;
        for(;end<s.length();end++)
        {
            mp[s[end]]++;
            if(mp[s[end]]>freq1)
            {
                freq1=mp[s[end]];
                mx=s[end];
            }
            int len=end-start+1;
            if(len-freq1>k)
            {
                while(len-freq1>k&&start<=end)
                {
                    if(mp[s[start]]>freq1)  freq1=mp[s[start]], mx=s[start];
                    if(len-freq1<=k)    break;
                    mp[s[start]]--;
                    if(s[start]==mx)    freq1--;
                    len--;
                    start++;
                }
            }
            
            ans=max(ans,end-start+1);
        }
        return ans;
    }
};