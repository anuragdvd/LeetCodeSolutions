// https://leetcode.com/problems/best-time-to-buy-and-sell-stock/submissions/


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==0||n==1)  return 0;
        int min_price=0;
        int max_diff=0;
        
        max_diff=prices[1]-prices[0];
        min_price=min(prices[0],prices[1]);
        
        for(int i=2;i<prices.size();i++)
        {
            min_price=min(min_price,prices[i]);
            max_diff=max(max_diff,prices[i]-min_price);
        }
        
        return max(0,max_diff);
        
       
    }
};