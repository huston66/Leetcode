class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int am=A.length();
        if(am==0)
        int an=A[0].length();
        int bn=B[0].length();

        vector<vector<int>> res(am,vector<int>(bn,0));
        for(int i=0;i<am;i++)
        {
            for(int k=0;k<an;k++)
            {
                if(A[i][k]!=0)
                {
                    for(int j=0;j<bn;j++)
                    {
                        if(B[k][j]!=0)
                        {
                            res[i][j]+=A[i][k]*B[k][j];
                        }
                    }
                }
            }
        }

        return res;
    }
};