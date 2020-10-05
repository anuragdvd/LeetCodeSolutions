// 1. Two Sum:: https://leetcode.com/problems/two-sum/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /* nlogn solution by using sorting. 
        
        vector<pair<int,int>> a;
        for(int i=0;i<nums.size();i++)
        {
            a.push_back({nums[i],i});
        }
        sort(a.begin(),a.end());
        int start=0;
        int end=a.size()-1;
        
        while(start<end)
        {
           int sum=a[start].first+a[end].first;
           if(sum==target)
           {
               break;
           }
           else if(sum>target)
           {
               end--;
           }
           else if(sum<target)
           {
               start++;
           }    
               
        }
        
        */
        
        
        unordered_map<int,int> mp;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            int remaining=target-nums[i];
            if(mp.find(remaining)!=mp.end())
            {
                ans.push_back(mp[remaining]);
                ans.push_back(i);
                return ans;
            }
            mp[nums[i]]=i;
        }
       
        return ans;
    }
};