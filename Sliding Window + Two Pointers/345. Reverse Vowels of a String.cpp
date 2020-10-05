// 345. Reverse Vowels of a String :: https://leetcode.com/problems/reverse-vowels-of-a-string/

class Solution {
public:
    string reverseVowels(string s) {
        int n=s.size();
        int i=0,j=n-1;
        set<char> vowels={'a','e','i','o','u','A','E','I','O','U'};
        
        while(i<j)
        {
            if(vowels.find(s[i])==vowels.end())
            {
                i++;
            }
            if(vowels.find(s[j])==vowels.end())
            {
                j--;
            }
            if(vowels.find(s[i])!=vowels.end() && vowels.find(s[j])!=vowels.end())
            {
                swap(s[i],s[j]); 
                i++; 
                j--;
            }
        }
        
        return s;
      
        
    }
};