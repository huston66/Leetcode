class Solution {
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> v;
        stack<TreeNode*>pre;
        stack<TreeNode*>suc;

        while(root){
            if(target<=root->val)
            {
                suc.push(root);
                root=root->left;
            }
            else
            {
                pre.push(root);
                root=root->right;
            }
        }

        TreeNode* tre;
        while(k--){
            if(pre.size()==0&&suc.size()==0){
                break;
            }
            else if(pre.size()==0&&suc.size()>0){
                tre=getSuccessor(suc);
                v.push_back(tre->val);
            }
            else if(suc.size()==0&&pre.size()>0){
                tre=getPredecessor(pre);
                v.push_back(tre->val);
            }
            else{
                if(abs(suc.top()->val-target)<abs(pre.top()->val-target)){
                    tre=getSuccessor(suc);
                    v.push_back(tre->val);
                }
                else
                {
                    tre=getPredecessor(pre);
                    v.push_back(tre->val);
                }
            }
        }

        return v;
    }

    TreeNode* getPredecessor(stack<TreeNode*>&pre){
        TreeNode* ret=pre.top();
        pre.pop();
        TreeNode* tre=ret;
        tre=tre->left;
        while(tre){
            pre.push(tre);
            tre=tre->right;
        }

        return ret;
    }

    TreeNode* getSuccessor(stack<TreeNode*>&suc){
        TreeNode* ret=suc.top();
        suc.pop();
        TreeNode* tre=ret;
        tre=tre->right;
        while(tre){
            suc.push(tre);
            tre=tre->left;
        }

        return ret;
    }
}

    