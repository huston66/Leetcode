class Solution {
    public:
        int countUnivalSubtrees(TreeNode* root) {
            int count=0;
            dfs(root,count);
            return count;
        }

        bool dfs(TreeNode* root,int &count){
            if(root==NULL)
                return 1;

            bool left=dfs(root->left,count);
            bool right=dfs(root->right,count);
            if((left&&right)&&(root->left==NULL||root->left->val==root->val)
                &&(root->right==NULL||root->right->val==root->val))
            {
                count++;
                return 1;
            }
            return 0;
        }
    };