class Solution {
private:
    vector<string> ret;
public:
    vector<string> generateAbbreviations(string word) {
        int len=word.length();
        if(len==0)
            return ret;

        dfs(word,0,len,"",0);
        return ret;
    }

    void dfs(string word,int i,int len,string curr,bool prenum){
        if(i==len)
        {
            ret.push_back(curr);
            return;
        }

        dfs(word,i+1,len,curr+word[i],0);
        if(prenum==0){
            for(int j=1;i+j<=len;j++){
                dfs(word,i+j,len,curr+to_string(j),1);
            }
        }
    }
};