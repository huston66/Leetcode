
int largestBSTSubtree(TreeNode* root) {
    if(root == NULL)
        return 0;

    int res=0;
    int mini;
    int maxi;

    dfs(root,mini,maxi,res);
    return res;
}

bool dfs(TreeNode* root,int& mini,int& maxi,int& res){
    if(root==NULL)
        return 1;

    int lmn,lma,rmn,rma,ln,rn;
    bool left=dfs(root->left,lmn,lma,ln);
    bool right=dfs(root->right,rmn,rma,rn);

    if(left&&right){
        if((!root->left||root-val>=lma)&&(!root->right||root->val<=rmi))
        res+=ln+rn+1;
        mini=root->left?lmn:root->val;
        maxi=root->right?rma:root->val;
        return 1;
    }

    res=max(ln,rn);
    return 0;
}