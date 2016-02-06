class Solution {
private:
    priority_queue<pair<double,int>>pq;
public:
    void dfs(TreeNode* root,double target,int k){
        if(root==NULL)
        {
            return;
        }

        pq.push_back(make_pair(abs(root->val-target),root->val));
        if(pq.size()>k)
            pq.pop();
        dfs(root->left,target,k);
        dfs(root->right,target,k);
    }

    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int>ret;
        dfs(root,target,k);

        while(pq.size())
        {
            ret.push_back(pq.top().second);
            pq.pop();
        }
        return ret;
    }
}