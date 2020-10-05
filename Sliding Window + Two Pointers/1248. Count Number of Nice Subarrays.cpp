// 1248. Count Number of Nice Subarrays :: https://leetcode.com/problems/count-number-of-nice-subarrays/

class Solution {
public:
    int numberOfSubarrays(vector<int>& a, int k) {
        int ans=0;
        int start=0;
        int end=0;
        int curr_odd=0;
        int n=a.size();
        int even_no=0;
        while(end<n)
        {
            if(a[end++]%2!=0)
            {
                curr_odd++;
                even_no=0;
            }
            if(k==curr_odd)
            {
                while(k==curr_odd)
                {
                    if(a[start++]%2!=0)
                        curr_odd--;
                    even_no++;
                }
               
            }
             ans+=even_no;
        }
        return ans;
    }
};