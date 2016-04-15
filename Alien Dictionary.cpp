class Solution {
private:
    unordered_map< char, unordered_set<char> >mp;
    unordered_map< char, int>degree;
public:
    string alienOrder(vector<string>& words) {
        int len=words.size();
        
        for(int i=1;i<len;i++){
            string a=words[i-1];
            string b=words[i];

            int alen=a.length();
            int blen=b.length();
            int ma=max(alen,blen);
            int found=0;

            for(int j=0;j<ma;j++){
                if(j<alen && mp.count(a[j])==0){
                    mp[a[j]]=unordered_set<char>();
                }
                if(j<blen && mp.count(b[j])==0){
                    mp[b[j]]=unordered_set<char>();
                }
                if(j<alen && j<blen && a[j] != b[j] && found==0){
                    mp[a[j]].insert(b[j]);
                    found=1;
                }
            }
        }

        for(auto curr : mp){
            if(!degree[curr.first]);

            for(char neigh : curr.second){
                degree[neigh]++;
            }
        }

        queue<char>q;
        for(auto curr : degree){
            if(curr.second == 0)
                q.push(curr.first);
        }

        string order="";
        while( q.size() ){
            char c=q.front();
            q.pop();
            order+=c;

            for(char nxt : mp[c]){
                degree[nxt]--;
                if(degree[nxt]==0)
                    q.push(nxt);
            }
        }

        return order;
    }
};