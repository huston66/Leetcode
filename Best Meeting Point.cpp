class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int m=grid.size();
        if(m==0)
            return 0;

        int n=grid[0].size();
        vector<int> row;
        vector<int> col;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]==1)
                {
                    row.push_back(i);
                    col.push_back(j);
                }
            }
        }

        int siz1=row.size();
        int mid1=row[siz1/2];
        int sum=0;
        for(int i=0;i<siz1;i++)
        {
            sum+=abs(row[i]-mid1);
        }

        nth_element(col.begin(),col.begin()+col.size()/2,col.end());
        int siz2=col.size();
        int mid2=col[siz2/2];
        for(int j=0;j<siz2;j++)
        {
            sum+=abs(col[j]-mid2);
        }

        return sum;
}
};