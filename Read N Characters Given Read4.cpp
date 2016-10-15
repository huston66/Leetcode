class Solution {
public:
    int read(char *buf, int n) {
        int res=0;
        for(int i=0;i<=n/4;i++)
        {
            int curr=read4(buf+res);
            res+=curr;
            if(curr<4)
                break;
        }

        return min(res,n);
    }
}