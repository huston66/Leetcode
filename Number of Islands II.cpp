class Solution {
private:
    vector<int>pa(m*n,-1);
public: 
    void find(int x){
        if(x!=pa[x])
            return pa[x]=find(pa[x]);
        return x;
    }

    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        vector<pair<int,int>> pp={{1,0},{0,1},{-1,0},{0,-1}};
        int siz=positions.size();
        vector<int> ret;
        int cnt=0;
        for(int i=0;i<siz;i++)
        {
            int x=positions[i].first;
            int y=positions[i].second;
            int id=x*n+y;
            pa[id]=id;
            int root1=id;
            cnt++;
            for(int i=0;i<4;i++)
            {
                int xx=x+pp[i].first;
                int yy=y+pp[i].second;
                int idd=xx*n+y;
                if(xx<0||yy<0||x>=m||y>=n||pa[idd]==-1)
                {
                    continue;
                }
                
                int root2=find(idd);
                if(root1!=root2)
                {
                    pa[root1]=root2;
                    root1=root2;
                    cnt--;
                }
            }
            ret.push_back(cnt);
    }

    return ret;
} 
};