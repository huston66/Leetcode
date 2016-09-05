class Solution {
public:
    bool verifyPostorder(vector<int>& postorder){
        int siz=postorder.size();
        int k=siz;
        int upper=INT_MAX;

        for(int i=siz-1;i>=0;i--){
            if(postorder[i]>upper)
                return 0;

            while(k<siz&&postorder[k]>postorder[i])
                upper=postorder[k++];

            postorder[--k]=postorder[i];
        }

        return 1;
    }
};