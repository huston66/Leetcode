class ZigzagIterator {
public:
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if(v1.size()>0)
            q.push(make_pair(v1.begin(),v1.end()));
        if(v2.size()>0)
            q.push(make_pair(v2.begin(),v2.end()));
    }
    
    int next() {
        auto p=q.front();
        auto it=p.first;
        auto itend=p.second;
        q.pop();
        if(it+1<itend)
            q.push(make_pair(it+1,itend));
        return *it;
    }
    
    bool hasNext() {
        return q.size()>0;
    }
private:
    queue<pair<vector<int>::iterator,vector<int>::iterator>>q;
};