// 785. Is Graph Bipartite? :: https://leetcode.com/problems/is-graph-bipartite/

class Solution {
public:
    bool BFS(int src,vector<int> color,vector<vector<int>>& graph)
    {
        
        queue<int> q;
        q.push(src);
        color[src]=0;
        bool flag=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto i:graph[curr])
            {
               // cout<<i<<endl;
                if(color[i]==color[curr])   flag=false;
                if(color[i]==-1)
                {
                    color[i]=!color[curr];
                    q.push(i);
                }
            }
        }
        return flag;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(),-1);
        
        int idx=0;
        bool ans=true;        
        
        for(int i=0;i<graph.size();i++)
        {
            if(color[i]==-1)
            {
                ans=BFS(i,color,graph);
            }
            if(ans==false)  break;
        }

        return ans;
        
    }
};