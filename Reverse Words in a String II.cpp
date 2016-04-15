class Solution {
public:
    void reve(string &s,int l,int r){
        while(l<=r)
        {
            char c=s[l];
            s[l++]=s[r];
            s[r--]=c;    
        }
    }

    void reverseWords(string &s) {
        int len=s.length();
        if(len==0)
            return;

        int l;
        for(int i=0;i<len;i++)
        {
            l=i;
            while(i<len&&s[i]!=' ')
            {
                i++;
            }
            
            if(l!=i-1)
                reve(s,l,i-1);
        }

        reve(s,0,len-1);
    }
};