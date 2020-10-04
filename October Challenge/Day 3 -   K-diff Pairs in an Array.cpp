//  K-diff Pairs in an Array :: https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3482/

class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        map<int,int> mp;
        for(auto i:nums)
            mp[i]++;
        
        set<pair<int,int>> ans;
        for(auto i: nums)
        {
            if(mp[i-k]!=0&&k!=0)
            {
                ans.insert({i,i-k});
            }
        }
        
        if(k==0)
        {
            int ans=0;
            for(auto i:mp)
            {
                if(i.second>1)  ans++;
            }
            return ans;
            
        }
        
        return ans.size();
        
    }
};

