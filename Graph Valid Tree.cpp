class Solution {
public:
    int find(int x,vector<int> &pa){
        if(x!=pa[x])
        {
            return pa[x]=find(pa[x]);
        }
        return x;
    }

    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<int>pa(n+1,0);
        
        for(int i=0;i<n;i++)
            pa[i]=i;

        int siz=edges.size();
        for(int i=0;i<siz;i++)
        {
            int x=edges[i].first;
            int y=edges[i].second;
            x=find(x,pa);
            y=find(y,pa);
            if(x==y)
                return 0;
            pa[x]=y;
        }

        return edges.length()==n-1;
    }
};