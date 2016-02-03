class Solution {
public:
    vector<int>pa(n+1,0);
    vector<int>h(n+1,0);
    int find(int x){
        if(pa[x]!=x)
            return pa[x]=find(x);
        return x;
    }

    int connect(int x,int y){
        x=find(x);
        y=find(y);

        if(x==y)
            return 0;

        if(h[x]<h[y])
        {
            pa[x]=y;
        }
        else
        {
            if(h[x]==h[y])
                h[x]++;
            pa[y]=x;
        }
        return 1;
    }

    int countComponents(int n, vector<pair<int, int>>& edges) {
        for(int i=0;i<n;i++)
        {
            pa[i]=i;
            h[i]=0;
        }    

        int siz=edges.size();
        int ans=n;
        for(int i=0;i<siz;i++)
        {
            int a=edges[i].first;
            int b=edges[i].second;
            if(connect(a,b))
                ans--;
        }

        return ans;
    }
};