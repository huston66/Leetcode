class Solution {
public:
    int minCostII(vector<vector<int>>costs) {
        int m=costs.size();
        if(m==0)
            return 0;

        int k=costs[0].size();
        int min1=0;
        int min2=0;
        vector<int>dp(k,0);

        for(int i=0;i<m;i++)
        {
            int oldmin1=min1;
            int oldmin2=min2;
            min1=INT_MAX;
            min2=INT_MAX;
            for(int j=0;j<k;j++)
            {
                if(dp[j]!=oldmin1||oldmin1==oldmin2){
                    dp[j]=oldmin1+costs[i][j];
                }
                else
                {
                    dp[j]=oldmin2+costs[i][j];
                }

                if(dp[j]<min1)
                {
                    min2=min1;
                    min1=dp[j];
                }
                else if(dp[j]<min2)
                {
                    min2=dp[j];
                }
            }
        }

        return min1;
    }
};