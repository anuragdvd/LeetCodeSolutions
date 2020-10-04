// 1042. Flower Planting With No Adjacent:: https://leetcode.com/problems/flower-planting-with-no-adjacent/

class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<int> ans(n,0);
        vector<int> graph[n+1];
        
        for(int i=0;i<paths.size();i++)
        {
            graph[paths[i][0]].push_back(paths[i][1]);
            graph[paths[i][1]].push_back(paths[i][0]);
        }
        
        for(int i=1;i<=n;i++)
        {
            vector<bool> color(5,false);
            for(auto j:graph[i])
            {
                if(ans[j-1]!=0)
                {
                    color[ans[j-1]]=true;
                }
            }
            for(int j=1;j<=4;j++)
            {
                if(color[j]==false)
                {
                    ans[i-1]=j;
                    break;
                }
            }
        }
        
        return ans;
        
    }
};