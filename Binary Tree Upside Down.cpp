class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if(root==NULL||root->left==NULL)
            return root;

        TreeNode* left=root->left;
        TreeNode* right=root->right;
        TreeNode* newRoot=upsideDownBinaryTree(left);
        newRoot->right=root;
        newRoot->left=right;
        root->left=NULL;
        root->right=NULL;

        return newRoot;
    }
}

    