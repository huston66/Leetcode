class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int am=A.length();
        int an=A[0].length();
        int bn=B[0].length();

        vector<vector<int>> res(am,vector<int>(bn,0));
        vector< vector<pair<int,int>> >vt;
        for(int i=0;i<am;i++)
        {
            vector<pair<int,int>>temp;
            for(int j=0;j<an;j++)
            {
                if(A[i][j])
                {
                    temp.push_back(make_pair(j,A[i][j]));
                }
            }
            vt.push_back(temp);
        }

        for(int i=0;i<am;i++)
        {
            vector<pair<int,int>> v;
            v=vt[i];
            for(int j=0;j<v.size();j++)
            {
                int col=v[j].first;
                int val=v[j].second;
                for(int k=0;k<bn;k++)
                {
                    res[i][k]+=val*B[col][k];
                }
            }
        }

        return res;
    }
};