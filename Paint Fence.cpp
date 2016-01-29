public class Solution {
    public int numWays(int n, int k) {
        if(n<=0||k<=0)
            return 0;

        if(n==1)
            return k;
        int presame=0;
        int prediff=k;

        for(int i=1;i<n;i++){
            int same=prediff;
            int diff=(k-1)*(presame+prediff);
            
            prediff=diff;
            presame=same;
        }

        return presame+prediff;
    }
};