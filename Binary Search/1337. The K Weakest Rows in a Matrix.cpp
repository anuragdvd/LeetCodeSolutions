// 1337. The K Weakest Rows in a Matrix :: https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/

class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& a, int k) {
        // use binary search for finding number of 1 in every row 
        // store the result in set for keeping the list sorted 
        // store the first k numbers in ans 
        // time - o(nlogm+k)
        
        set<pair<int,int>> s;
        vector<int> ans;
        
        int n=a.size();
        if(n==0)    return ans;
        int m=a[0].size();
        if(m==0)    return ans;
        
        for(int i=0;i<n;i++)
        {
            int l=0;
            int r=m-1;
            while(l<=r)
            {
                int mid=l+(r-l)/2;
                if(a[i][mid]==1)
                {
                    l=mid+1;
                }
                else
                    r=mid-1;
            }
            s.insert({l,i});
        }
        for(auto i:s)
        {
            ans.push_back(i.second);
            if(ans.size()==k)   break;
        }
        
        return ans;
        
        
    }
};