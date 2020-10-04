// 1557. Minimum Number of Vertices to Reach All Nodes :: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> ans;
        vector<int> indegree(n,0);
        
        for(int i=0;i<edges.size();i++)
        {
            indegree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++)
        {
            if(indegree[i]==0)
                ans.push_back(i);
        }
        return ans;
        
    }
};

