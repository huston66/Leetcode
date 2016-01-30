class WordDistance {
public:
    int shortestWordDistance(vector<string>& words, string word1, string word2) {
        long long ans=INT_MAX;
        int siz=words.size();

        long long p1=INT_MAX;
        long long p2=-INT_MAX;

        bool same=(word1==word2);
        for(int i=0;i<siz;i++)
        {
            if(words[i]==word1)
            {
                p1=i;
                if(same)
                {
                    swap(p1,p2);
                }
            }
            else if(words[i]==word2)
            {
                p2=i;
            }
            ans=min(ans,abs(p1-p2));
        }

        return ans;
}
};