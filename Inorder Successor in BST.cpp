class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if(!root)
            return NULL;

        stack<TreeNode*>s;
        TreeNode* curr=root;
        TreeNode* prev=NULL;

        while(s.size()||curr){
            while(curr){
                s.push(curr);
                curr=curr->left;
            }

            TreeNode* t=s.top();
            s.pop();

            if(prev==p)
                return t;

            prev=t;
            t=t->right;
        }

        return NULL;
    }
};