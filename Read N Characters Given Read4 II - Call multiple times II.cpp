int read4(char *buf);

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int ptr=0;
    int cnt=0;
    char* buff[4];
    int read(char *buf, int n) {
        int len=0;
        while(len<n)
        {
            if(ptr==0)
            {
                cnt=read4(buff);
            }

            if(cnt==0)
                break;
            while(len<n&&ptr<cnt)
            {
                buf[len++]=buff[ptr++];
            }

            if(ptr==cnt)
                ptr=0;
        }

        return len;
};