class Solution {
public:
    vector<string> ret;
    vector<string> generatePalindromes(string s) {
        int slen=s.length();
        unordered_map<char,int>mp;
        for(int i=0;i<slen;i++){
            mp[s[i]]++;
        }

        unordered_map<char,int>::iterator iter;
        int odd=0;
        int N=0;
        string mid="";
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            if(iter->second%2)
            {
                mid=iter->first;
                odd++;
            }
            iter->second/=2;
            N+=iter->second;
        }

        if(odd<=1)
        {
            string curr="";
            dfs(mid,mp,N,curr);
            return ret;
        }
        else
            return ret;
    }

    void dfs(string mid,unordered_map<char,int>&mp,int N,string curr){
        if(curr.length()==N)
        {
            string temp=reverse(curr.begin(),curr.end());
            temp=temp+mid+curr;
            ret.push_back(temp);
            return;
        }

        map<char,int>::iterator iter;
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            if(iter->second>0)
            {
                iter->second--;
                dfs(mid,mp,N,curr+iter->first);
                iter->second++;
            }
        }
    }
};