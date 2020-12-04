// 547. Friend Circles ::https://leetcode.com/problems/friend-circles/

class Solution {
public:
    int find(int i, int par[])
    {
        if(par[i]==-1)
        {
            return i;
        }
        else{
            return par[i]=find(par[i],par);
        }
    }
    void merge(int u,int v, int par[])
    {
        int x=find(u,par);
        int y=find(v,par);
        par[y]=x;
    }
    int findCircleNum(vector<vector<int>>& M) {
       int n=M.size();
       int par[n];
       memset(par,-1,sizeof(par));
       
       for(int i=0;i<n;i++)
       {
           for(int j=0;j<n;j++)
           {
               if(M[i][j]==0)   continue;
               else{
                   int u=find(i,par); 
                   int v=find(j,par);
                 
                   if(u!=v)
                   {
                       merge(u,v,par);
                   }
               }
           }
       }
       
        int c=0;
        for(auto i:par)
        {
            if(i==-1)   c++;
        }
        
        return c;
        
    }
};