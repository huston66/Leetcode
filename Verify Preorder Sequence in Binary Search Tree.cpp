class Solution {
public:
    bool dfs(vector<int>& preorder,int start,int end){
        if(start>=end)
            return 1;

        int root=preorder[start];
        int pos=-1; 
        for(int i=start+1;i<=end;i++)
        {
            if(preorder[i]>root)
            {
                pos=i;
                break;
            }
        }

        if(dfs(preorder,start+1,pos-1)==0)
            return 0;
        if(pos!=-1)
        for(int i=pos+1;i<=end;i++)
        {
            if(preorder[i]<=root)
                return 0;
        }

        return dfs(preorder,pos,end);
    }

    bool verifyPreorder(vector<int>& preorder){
        int siz=preorder.size();
        if(siz<=1)
            return 1;

        return dfs(preorder,0,siz-1);
    }
};