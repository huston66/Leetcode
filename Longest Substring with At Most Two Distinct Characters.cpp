class Solution {
public:
    int lengthOfLongestSubstringTwoDistinct(string s) {
        int len=s.length();
        int l=0;
        int r=len-1;

        int mp[256];
        int count=0;
        int ma=0;
        memset(mp,0,sizeof(mp));
        while(r<len&&l<=r){
            if(mp[s[r]]>0)
                mp[s[r]]++;
            else
            {
                mp[s[r]]++;
                count++;
                while(count>2){
                    mp[s[l]]--;
                    if(mp[s[l]]==0)
                    {
                        count--;
                    }
                    l++;
                }
            }

            ma=max(ma,r-l+1);
        }

        return ma;
    }
};