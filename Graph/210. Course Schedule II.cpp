// 210. Course Schedule II :: https://leetcode.com/problems/course-schedule-ii/

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int> graph[n+1];
        int in[n];
        memset(in,0,sizeof(in));
        for(int i=0;i<pre.size();i++)
        {
            graph[pre[i][1]].push_back(pre[i][0]);
            in[pre[i][0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
             //   cout<<i;
                q.push(i);
                ans.push_back(i);
               
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto i:graph[node])
            {
                //cout<<i;
                in[i]--;
                if(in[i]==0)   { ans.push_back(i); q.push(i); }
            }
        }
        
        if(ans.size()!=n)  ans.clear();
        return ans;
    }
};