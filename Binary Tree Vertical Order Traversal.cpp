class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> ret;
        if(root==NULL)
            return ret;

        map<int,vector<int>>mp;
        queue<pair<int,TreeNode*>>q;

        q.push(make_pair(0,root));

        while(q.size()){
            pair<int,TreeNode*> pa=q.front();
            q.pop();

            int a=pa.first;
            TreeNode* tre=pa.second;

            mp[a].push_back(tre->val);
            if(tre->left)
                q.push(make_pair(a-1,tre->left));
            if(tre->right)
                q.push(make_pair(a+1,tre->right));
        }

        map<int,vector<int>>::iterator iter;
        for(iter=mp.begin();iter!=mp.end();iter++)
        {
            ret.push_back(iter->second);
        }
    }
};