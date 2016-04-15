struct TreeNode {
      int val;
      TreeNode* left;
      TreeNode* right;
      TreeNode(int x) { val = x; left=NULL; right=NULL;}
    };


class Solution {
private:
        int ret;
        double mi=DBL_MAX;
public:
        int closestValue(TreeNode* root, double target) {
            dfs(root,target);
            return ret;
        }

        void dfs(TreeNode* root,double target){
            if(root==NULL)
                return;

            if(abs(root->val-target)<mi)
            {
                mi=abs(root->val-target);
                ret=root->val;
            }

            if(root->val>target)
                dfs(root->left,target);
            else
                dfs(root->right,target);
        }
};