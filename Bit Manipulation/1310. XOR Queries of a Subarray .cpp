// 1310. XOR Queries of a Subarray :: https://leetcode.com/problems/xor-queries-of-a-subarray/

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        // 1 , 3, 4 , 8 == [1 , 2 , 6 , 14 ]
        // 1 ^ 3 = 01 ^ 11 = 10 
        // 010 ^ 100 = 110
        // 0110 ^ 1000 = 1110 
        // queries : 0 , 1 == (1^3) === pre[2]
        // q2: 1,2 == (3^4) == (2^4) == (4^1^3) == pre[2]^pre[0]
        // q3 : 0,3 == (8^1^3^4)
        // q4: 3,3 = (8^4^1^3)^6
        int n=arr.size();
        vector<int> pre(n+1);
        pre[0]=arr[0];
        for(int i=1;i<n;i++)
        {
            pre[i]=arr[i]^pre[i-1];
        }
        vector<int> ans;
        for(int i=0;i<queries.size();i++)
        {
            int l,r;

            l=queries[i][0];
            r=queries[i][1];
            if(l==0)
            {
                ans.push_back(pre[r]);
            }
            else{
                ans.push_back(pre[r]^pre[l-1]);
            }
        }
        return ans;
        
    }
};