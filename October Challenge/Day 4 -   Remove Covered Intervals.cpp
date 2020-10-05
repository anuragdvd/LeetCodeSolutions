//   Remove Covered Intervals : https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/559/week-1-october-1st-october-7th/3483/

class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        set<pair<int,int>> s;
        
        for(int i=0;i<intervals.size();i++)
        {
            for(int j=0;j<intervals.size();j++)
            {
                if(i==j)    continue;

                if(intervals[i][0]<=intervals[j][0]&&intervals[i][1]>=intervals[j][1])
                {
                    s.insert({intervals[j][0],intervals[j][1]});
                }
            }
        }
        
        cout<<s.size();
        
        return intervals.size()-s.size();
        
    }
};