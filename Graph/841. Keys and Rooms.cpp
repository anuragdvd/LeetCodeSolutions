// 841. Keys and Rooms : https://leetcode.com/problems/keys-and-rooms/

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> graph[rooms.size()+1];
        for(int i=0;i<rooms.size();i++)
        {
            for(auto j:rooms[i])
            {
                graph[i].push_back(j);
            }
        }
        
        queue<int> q;
        q.push(0);
        int n=rooms.size();
        vector<bool> visited(n,false);
        visited[0]=true;
        while(!q.empty())
        {
            int curr=q.front();
            q.pop();
            for(auto i:graph[curr])
            {
                if(!visited[i])
                {
                    visited[i]=true;
                    q.push(i);
                }
            }
        }
        
        bool flag=true;
        
        for(auto i:visited)
        {
            if(i==false)
                flag=false;
        }
        
        return flag;
        
    }
};