class Solution {
public:
    bool verifyPreorder(vector<int>& preorder){
        int siz=preorder.size();
        stack<int>s;
        int low=INT_MIN;

        for(int i=0;i<siz;i++)
        {
            if(preorder[i]<low)
                return 0;

            while(s.size()&&preorder[i]>s.top())
            {
                low=s.top();
                s.pop();
            }
            s.push(preorder[i]);
        }

        return 1;
    }
};

