class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int m=rooms.size();
        if(m==0)
            return;
        
        int n=rooms[0].size();
        int dir[][2]={{1,0},{-1,0},{0,-1},{0,1}};

        queue<pair<int,int>>q;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(rooms[i][j]==0)
                {
                    q.push(make_pair(i,j));
                }
            }
        }

        while(q.size())
        {
            pair<int,int>p = q.front();
            q.pop();

            int x=p.first;
            int y=p.second;
            for(int i=0;i<4;i++)
            {
                int xx=x+dir[i][0];
                int yy=y+dir[i][1];
                if(xx>=0&&xx<m&&yy>=0&&yy<n&&rooms[xx][yy]==INT_MAX)
                {   
                    rooms[xx][yy]=rooms[x][y]+1;
                    q.push(make_pair(xx,yy));
                }
            }
        }
};