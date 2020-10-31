// 1405. Longest Happy String :: https://leetcode.com/problems/longest-happy-string/

class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int,char>> pq;
        if(a!=0)
            pq.push({a,'a'});
        if(b!=0)
            pq.push({b,'b'});
        if(c!=0)
            pq.push({c,'c'});
        string s="";
        int n=a+b+c;
        while(!pq.empty())
        {
            pair<int,char> p=pq.top();
           
            pq.pop();
            if(s.length()<2)
            {
                s=s+p.second;
                p.first--;
                if(p.first!=0)
                    pq.push(p);
            }
            else{
                if(s[s.length()-1]==p.second&&s[s.length()-2]==p.second)
                {
                   
                    if(!pq.empty())
                    {
                    pair<int, char> temp=pq.top();
                    pq.pop();
                    pq.push(p);
                    temp.first--;
                    s=s+temp.second;
                    if(temp.first!=0)  pq.push(temp);
                    }
                    else{
                        return s;
                    }
                }
                else{
                        s=s+p.second;
                        p.first--;
                        if(p.first!=0)
                            pq.push(p);
                }
            }
        }
        return s;
    }
};