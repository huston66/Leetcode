class Solution {
private:
    unordered_map<char,string>mp1;
    unordered_map<string,char>mp2;
public:
    bool wordPatternMatch(string pattern, string str) {
        int plen=pattern.length();
        int slen=str.length();

        return dfs(pattern,str,0,0,plen,slen);
    }

    bool dfs(string pattern,string str,int a,int b,int plen,int slen){
        if(a==plen||b==slen)
        {
            if(a==plen && b==slen)
                return 1;
            return 0;
        }

        for(int i=1;b+i<=slen;i++){
            bool is=0;
            string curr=str.substr(b,i);
            if(mp1.count(str[a]))
                if(mp1[str[a]]!=curr)
                    continue;

            if(mp2.count(curr))
                if(mp2[curr]!=str[a])
                    continue;

            if(mp1.count(str[a])==0 && mp2.count(curr)==0)
            {
                mp1[str[a]]=curr;
                mp2[curr]=str[a];
                is=1;
            }

            if(dfs(pattern,str,a+1,b+i,plen,slen))
                return 1;

            if(is)
            {
                mp1.erase(str[a]);
                mp2.erase(curr);
            }
        }

        return 0;
    }
};