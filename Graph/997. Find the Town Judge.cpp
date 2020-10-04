class Solution {
public:
    int findJudge(int N, vector<vector<int>>& a) {
        vector<int> indegree(N+1);
        vector<int> outdegree(N+1);
        for(int i=0;i<a.size();i++)
        {
            outdegree[a[i][0]]++;
            indegree[a[i][1]]++;
        }
        int ans=-1;
        for(int i=1;i<=N;i++)
        {
            if(outdegree[i]==0&&indegree[i]==N-1)
            {
                ans=i; break;
            }        
        }
        return ans;
    }
};