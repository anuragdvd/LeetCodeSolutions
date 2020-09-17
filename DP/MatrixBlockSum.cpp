// Matrix-block-sum :: https://leetcode.com/problems/matrix-block-sum

class Solution {
public:
    vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int k) {
       vector<vector<int>> dp(mat.size()+1,vector<int>(mat[0].size()+1,0));
        vector<vector<int>> ans(mat.size(),vector<int>(mat[0].size(),0));

        dp[0][0]=mat[0][0];
        for(int i=1;i<=mat[0].size();i++)
        {
            dp[0][i]=mat[0][i-1]+dp[0][i-1];
        }
        for(int i=1;i<=mat.size();i++)
        {
            dp[i][0]=mat[i-1][0]+dp[i-1][0];
        }
        for(int i=1;i<mat.size()+1;i++)
        {
            for(int j=1;j<mat[0].size()+1;j++)
            {
                
                dp[i][j]=dp[i-1][j]+dp[i][j-1]-dp[i-1][j-1]+mat[i-1][j-1];
            }
        }

        for(int i=0;i<mat.size();i++)
        {
            int x1=max(1,i-k+1);
            int sz=mat.size();
            int x2=min(i+k+1,sz);
            for(int j=0;j<mat[i].size();j++)
            {
                sz=mat[i].size();
                int y1=max(1,j-k+1);
                int y2=min(j+k+1,sz);
                
                ans[i][j]=dp[x2][y2]-dp[x1-1][y2]-dp[x2][y1-1]+dp[x1-1][y1-1];
            }
        }
        
        
        return ans;
    }
};