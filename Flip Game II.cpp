class Solution {
private:
    unordered_map<string,bool>mp;
public:
    bool canWin(string s) {
        int slen=s.length();
        if(s==""||slen<2)
            return 0;

        if(mp.count(t))
        {
            return mp[t];
        }

        for(int i=0;i<slen-1;i++)
        {
            if(s[i]==s[i+1])
            {
                if(s[i]=='+')
                {
                    string t=s;
                    t[i]='-';
                    t[i+1]='-';
                    
                    bool is=canWin(t);
                    if(is==0)
                    {
                        mp[s]=1;
                        return 1;
                    }
                }
            }
        }

        mp[s]=0;
        return 0;
    }
}