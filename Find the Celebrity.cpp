class Solution: public Relation {
    int findCelebrity(int n) {
        if(n<=1)
            return n;

        int ans=0;
        for(int i=1;i<n;i++)
        {
            if(knows(ans,i))
                ans=i;
        }

        for(int i=0;i<n;i++)
        {
            if(i!=ans)
            {
                if(!knows(i,ans)||knows(ans,i))
                    return -1;
            }
        }

        return ans;
    }
}