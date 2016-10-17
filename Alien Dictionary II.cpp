class Solution {
public:
    unordered_set<char>open;
    vector<pair<char,char>>pa;
    
    string toporder(){
        unordered_map<char,unordered_set<char>>adj;
        int out[26]={0};
    
        int tot=open.size();
    
        for(auto curr:pa){
            char from=curr.first;
            char to=curr.second;
    
            if(adj[to].count(from)==0){
                adj[to].insert(from);
                out[from-'a']++;
            }
        }
    
        unordered_set<char>leaves;
    
        for(int i=0;i<26;i++){
            char c=(char)('a'+i);
            if(open.count(c)&&out[i]==0){
                leaves.insert(c);
            }
        }
    
        string ret="";
        while(leaves.size()){
            unordered_set<char>nxt;
            for(auto curr:leaves){
                for(auto from:adj[curr]){
                    if(--out[from-'a']==0){
                        nxt.insert(from);
                    }
                }
    
                ret=curr+ret;
            }
    
            leaves=nxt;
        }
    
        if(ret.length()!=tot)
            return "";
    
        return ret;
    }
    
    string alienOrder(vector<string>& words) {
        int siz=words.size();
        for(int i=0;i<siz;i++){
            for(auto c:words[i]){
                open.insert(c);
            }
        }
    
        for(int i=1;i<siz;i++){
            string a=words[i-1];
            string b=words[i];
    
            int alen=a.length();
            int blen=b.length();
            int mi=min(alen,blen);
    
            int pos;
            for(pos=0;pos<mi&&a[pos]==b[pos];pos++);
            if(pos<alen){
                if(pos==blen){
                    return "";
                }
    
                pa.push_back(make_pair(a[pos],b[pos]));
            }
        }
    
        return toporder();
    }
};