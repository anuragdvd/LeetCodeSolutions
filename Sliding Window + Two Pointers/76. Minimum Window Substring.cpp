// 76. Minimum Window Substring :: https://leetcode.com/problems/minimum-window-substring/

class Solution {
public:
    string minWindow(string s, string t) {
        map<char,int> mp;
      
        //storing frequency for second string
        for(auto i:t)
        {
            mp[i]++;
        }
        
        int start=0;
        int end=0;
        int sz=s.length();
        int head=0;
        int ans=INT_MAX;
        int curr_counter=t.length();

        while(end<sz)
        {
            if(mp.find(s[end])!=mp.end())
            {
                mp[s[end]]--;
                if(mp[s[end]]>=0)
                {
                    curr_counter--;
                }
            }
            end++;
            if(curr_counter==0)
            {
                while(curr_counter==0&&start<end)
                {
                    if(ans>end-start)
                    {
                        ans=end-start;
                        head=start;
                    }
                    if(mp.find(s[start])!=mp.end())
                    {
                        mp[s[start]]++;
                        if(mp[s[start]]==1)
                            curr_counter++;
                    }
                    start++;                    
                }
            }
           
        }
        cout<<ans;
    return ans==INT_MAX?"":s.substr(head,ans);        
        
    }
};