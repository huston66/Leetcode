class Solution {
    vector<vector<int>> ret;
    public:
        void dfs(int n,vector<int>&curr){
            int i;
            if(curr.empty()==1)
                i=2;
            else
                i=curr.back();

            for(;i<=n/i;i++)
            {   
                if(n%i==0)
                {
                    curr.push_back(i);
                    curr.push_back(n/i);
                    ret.push_back(curr);
                    curr.pop_back();
                    dfs(n/i,curr);
                    curr.pop_back();
                }
            }
        }

        vector<vector<int>> getFactors(int n) {
            vector<int> curr;
            dfs(n,curr);
            return ret;
        }
    };