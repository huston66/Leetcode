class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int slen=s.length();
        int tlen=t.length();

        if(slen>tlen)
            return isOneEditDistance(t,s);

        if(slen<tlen-1||s==t)
            return 0;

        for(int i=0;i<slen;i++){
            if(s[i]!=t[i])
            {
                if(slen==tlen)
                    s[i]=t[i];
                else
                    s.insert(i,1,t[i]);
                break;
            }
        }

        return (s==t)||(s+t[tlen-1]==t);
    }
};