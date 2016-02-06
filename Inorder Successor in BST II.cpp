class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(root==NULL||p==NULL)
            return NULL;

        TreeNode* suc=NULL;
        while(root){
            if(root->val<=p->val)
                root=root->right;
            else
            {
                suc=p;
                root=root->left;
            }
        }

        return suc;
    }
};