// 207. Course Schedule :: https://leetcode.com/problems/course-schedule/

class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<int> graph[n+1];
        int in[n];
        memset(in,0,sizeof(in));
        for(int i=0;i<pre.size();i++)
        {
            graph[pre[i][0]].push_back(pre[i][1]);
            in[pre[i][1]]++;
        }
        queue<int> q;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(in[i]==0)
            {
                q.push(i);
                ans++;
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            for(auto i:graph[node])
            {
                in[i]--;
                if(in[i]==0)   { ans++; q.push(i); }
            }
        }
        
        if(ans==n)  return true;
        else    return false;
        
    }
};