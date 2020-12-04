// 1319. Number of Operations to Make Network Connected :: https://leetcode.com/problems/number-of-operations-to-make-network-connected/

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
    int makeConnected(int n, vector<vector<int>>& connections) {
        int par[n];
        int extra=0;
        memset(par,-1,sizeof(par));
        for(int i=0;i<connections.size();i++)
        {
            int x=find(connections[i][0],par);
            int y=find(connections[i][1],par);
            if(x!=y)
            {
                merge(x,y,par);
            }
            if(x==y)
            {
                extra++;
            }
        }
        int ans=0;
        for(auto i:par) if(i==-1)   ans++;
        ans--;
        if(ans-extra>0) return -1;
        else    return ans;
    }
};