/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL)
            return "#";
        return to_string(root->val)+","+serialize(root->left)+","+serialize(root->right);
    }
    
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        return mydes(data);
    }
    
    TreeNode* mydes(string& data){
        if(data[0]=='#')
        {
            if(data.size()>2)
                data=data.substr(2);
            return NULL;
        }
        
        int val=myhelper(data);
        TreeNode* tre=new TreeNode(val);
        tre->left=mydes(data);
        tre->right=mydes(data);
        return tre;
    }
    
    int myhelper(string& s){
        int pos=s.find(",");
        int ret=stoi(s.substr(0,pos));
        s=s.substr(pos+1);
        return ret;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));