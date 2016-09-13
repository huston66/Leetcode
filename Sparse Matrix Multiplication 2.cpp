typedef pair<pair<int,int>,int>pos_val;

class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        if(A.empty()||A[0].empty()||B[0].empty())
            return vector<vector<int>>();

        vector<pos_val> map_A, map_B;

        int n=A.size();
        int m=B[0].size();
        int mid=B.size();

        vector<vector<int>> C(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<mid;j++)
                if(A[i][j]!=0){
                    pos_val tmp(pair<int,int>(i,j),A[i][j]);
                    map_A.push_back(tmp);
                }
        }

        for(int i=0;i<mid;i++){
            for(int j=0;j<m;j++){
                if(B[i][j]!=0){
                    pos_val tmp(pair<int,int>(i,j),B[i][j]);
                    map_B.push_back(tmp);
                }
            }
        }

        for(int i=0;i<map_A.size();i++){
            for(int j=0;j<map_B.size();j++){
                if(map_A[i].first.second==map_B[j].first.first)
                    C[map_A[i].first.first][map_B[j].first.second]+=map_A[i].second*map_B[j].second;
            }
        }

        return C;
    }
};