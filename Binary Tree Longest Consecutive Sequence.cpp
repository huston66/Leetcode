class Solution {
public:
    int ma=0;
    int longestConsecutive(TreeNode* root) {
        if(root==NULL)
            return 0;
        dfs(root,0,root->val);
        return ma;
    }

    void dfs(TreeNode* root,int curr,int target){
        if(root==NULL)
            return;

        if(root->val==target)
        {
            curr++;
        }
        else
            curr=1;

        ma=max(ma,curr);
        dfs(root->left,curr,root->val+1);
        dfs(root->right,curr,root->val+1);
    }
};