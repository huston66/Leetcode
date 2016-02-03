class Solution {
public:
    bool canPermutePalindrome(string s) {
        int dict[256]={0};
        int len=s.length();
        for(int i=0;i<len;i++)
        {
            dict[s[i]]++;
        }

        int ret=0;
        for(int i=0;i<256;i++)
        {
            if(dict[i]%2!=0)
                ret++;
        }

        return ret<=1;
    }   
};