class Solution {
public:
    int shortestDistance(vector<string>& words, string word1, string word2) {
        int siz=words.size();
        int pos1=-1;
        int pos2=-1;
        int mi=INT_MAX;
        for(int i=0;i<siz;i++){
            if(words[i]==word1)
            {
                pos1=i;
                if(pos2!=-1)
                    mi=min(pos1-pos2,mi);
            }
            else if(words[i]==word2)
            {
                pos2=i;
                if(pos1!=-1)
                    mi=min(pos2-pos1,mi);
            }
        }

        return mi;
    }
};