class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        int siz=strings.size();
        unordered_map<string,vector<string>>mp;
        vector<vector<string>>ret;

        for(int i=0;i<siz;i++){
            string s=strings[i];
            int len=s.length();
            string t="";
            for(int j=1;j<len;j++){
                int diff=s[j]-s[j-1];
                if(diff<0)
                    diff+=26;
                t+="a"+to_string(diff);
            }
            mp[t].push_back(s);
        }

        unordered_map<string,vector<string>>::iterator iter;
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            vector<string>curr=iter->second;
            sort(curr.begin(),curr.end());
            ret.push_back(curr);
        }

        return ret;
    }
}; 