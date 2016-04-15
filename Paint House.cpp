class Solution {
public:
    int minCost(vector<vector<int>> costs) {
        int m=costs.size();
        if(m==0)
            return 0;

        vector<int>pre(3,0);
        vector<int>curr(3,0);
        pre[0]=costs[0][0];
        pre[1]=costs[0][1];
        pre[2]=costs[0][2];

        for(int i=1;i<m;i++)
        {
            curr[0]=min(pre[1],pre[2])+costs[i][0];
            curr[1]=min(pre[0],pre[2])+costs[i][1];
            curr[2]=min(pre[0],pre[1])+costs[i][2];

            pre[0]=curr[0];
            pre[1]=curr[1];
            pre[2]=curr[2];
        }

        return min(pre[0],min(pre[1],pre[2]));
    }
};