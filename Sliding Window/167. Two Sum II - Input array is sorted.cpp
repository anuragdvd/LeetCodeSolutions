// 167. Two Sum II - Input array is sorted :: https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        int start=0;
        int end=nums.size()-1;
        
        while(start<end)
        {
           int sum=nums[start]+nums[end];
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
        vector<int> ans;
        ans.push_back(start+1); ans.push_back(end+1);
        return ans;
        
    }
};