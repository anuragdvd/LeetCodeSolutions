// 684. Redundant Connection :: https://leetcode.com/problems/redundant-connection/

class Solution {
public:
    int find(int i,int par[]){
        if(par[i]==-1)
        {
            return i;
        }
        else{
            return par[i]=find(par[i],par);        
        }
    }
    void merge(int u,int v,int par[])
    {
        int x=find(u,par);
        int y=find(v,par);
        par[x]=y;
        
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        int par[n+1];
        memset(par,-1,sizeof(par));
        vector<int> ans(2);
        for(int i=0;i<n;i++)
        {
            int x=find(edges[i][0],par);
            int y=find(edges[i][1],par);
            if(x==y)
            {
                ans[0]=edges[i][0];
                ans[1]=edges[i][1];
            }
            else{
                merge(x,y,par);
            }
        }
        
        return ans;
        
    }
};