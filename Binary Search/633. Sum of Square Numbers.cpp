class Solution {
public:
    bool judgeSquareSum(int c) {
        set<long long int> s;
        for(int i=0;i<=sqrt(c);i++)
        {
            s.insert(i*i);
        }
        for(int i=0;i<=sqrt(c);i++)
        {
            if(s.find(c-i*i)!=s.end())
            {
                return true;
            }
        }
        return false;
    }
};