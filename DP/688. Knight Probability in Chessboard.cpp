// 688. Knight Probability in Chessboard :: https://leetcode.com/problems/knight-probability-in-chessboard/

class Solution {
public:
    double knightProbability(int N, int K, int r, int c) {
        double dp[N][N][2];
		vector<vector<int>> dir{{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
        memset(dp,0.00,sizeof(dp));
        dp[r][c][0]=1;
        int flag=0;
        for(int k=1;k<=K;k++)
        {
             flag=!flag;
            for(int i=0;i<N;i++)
            {
                for(int j=0;j<N;j++)
                {
                    for(int rr=0;rr<8;rr++)
                    {
                        int x=i+dir[rr][0];
                        int y=j+dir[rr][1];
                        
                        if(x<0||y<0||x>=N||y>=N)  continue; 
                        dp[x][y][flag]+=0.125*dp[i][j][!flag];
                       
                    }
                    dp[i][j][!flag]=0;
                    
                }
            }
           
        }
        double ans=0.00;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                ans+=dp[i][j][flag];  
            }
        }
        return ans;
        
    }
};