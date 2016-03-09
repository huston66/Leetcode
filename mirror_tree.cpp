void mirror_tree(TreeNode* root){
	if(root==NULL){
		return;
	}

	mirror_tree(root->left);
	mirror_tree(root->right);

	TreeNode* temp=root->left;
	root->left=root->right;
	root->right=temp;
}