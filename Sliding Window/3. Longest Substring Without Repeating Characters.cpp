// 3. Longest Substring Without Repeating Characters :: https://leetcode.com/problems/longest-substring-without-repeating-characters/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
	// maintain a window if we have already seen the character before then shift the window by increasing start. This problem can be also solved by dp. 
        map<char,int> mp; 
        int start=0,end=0;
        if(s.length()==0)   return 0;
        int ans=INT_MIN;
        for(;end<s.length();end++)
        {
            if(mp.find(s[end])!=mp.end())
            {
                start=max(mp[s[end]]+1,start); 
            }
            mp[s[end]]=end;
            ans=max(ans,end-start+1);
            
           
        }
        return ans;
    }
};