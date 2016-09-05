class Solution {
public:
    bool verifyPreorder(vector<int>& preorder){
        int siz=preorder.size();

        int low=INT_MIN;
        int pos=-1;

        for(int i=0;i<siz;i++){
            if(preorder[i]<low)
                return 0;

            while(pos>=0&&preorder[pos]<preorder[i]){
                low=preorder[pos--];
            }

            preorder[++pos]=preorder[i];
        }

        return 1;
    }
};

