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
            if(mp1.count(pattern[a]))
                if(mp1[pattern[a]]!=curr)
                    continue;

            if(mp2.count(curr))
                if(mp2[curr]!=pattern[a])
                    continue;

            if(mp1.count(pattern[a])==0 && mp2.count(curr)==0)
            {
                mp1[pattern[a]]=curr;
                mp2[curr]=pattern[a];
                is=1;
            }

            if(dfs(pattern,str,a+1,b+i,plen,slen))
                return 1;

            if(is)
            {
                mp1.erase(pattern[a]);
                mp2.erase(curr);
            }
        }

        return 0;
    }
};