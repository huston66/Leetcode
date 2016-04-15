int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    queue<int> left;
    int read(char *buf, int n) {
        int len=0;
        while(left.size())
        {
            buf[len++]=left.front();
            left.pop();
            if(len==n)
                return len;
        }

        while(1)
        {
            int curr=read4(buf+len);
            len+=curr;
            if(curr<4)
                break;
            if(len>=n)
                break;
        }

        for(int i=n;i<len;i++)
        {
            left.push(buf[i]);
        }

        int end=min(n,len);
        buf[end]='\0';
        return end;
    }
};