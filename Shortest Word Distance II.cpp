class WordDistance {
private:
    unordered_map<string,vector<int>>mp;
public:
    WordDistance(vector<string>& words) {
        int siz=words.size();
        for(int i=0;i<siz;i++)
        {
            mp[words[i]].push_back(i);
        }
    }

    int shortest(string word1, string word2) {
        int len1=mp[word1].size();
        int len2=mp[word2].size();

        int i=0;
        int j=0;
        int mi=INT_MAX;
        while(i<len1&&j<len2){
            int index1=mp[word1][i];
            int index2=mp[word2][j];
            if(index1<index2)
            {
                mi=min(mi,index2-index1);
                i++;
            }
            else
            {
                mi=min(mi,index1-index2);
                j++;
            }
        }

        return mi;
    }
};