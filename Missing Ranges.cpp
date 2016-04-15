class Solution {
public:
    string getrange(int a,int b){
        if(a==b)
            return to_string(a)+"->"+to_string(b);
        return to_string(a);
    }

    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> ret;
        int siz=nums.size();
        int nxt=lower;
        for(int i=0;i<siz;i++){
            if(nums[i]<nxt)
                continue;
            else if(nums[i]==nxt)
                nxt=nums[i]+1;
            else
            {
                string s=getrange(nxt,nums[i]-1);
                ret.push_back(s);
                nxt=nums[i]+1;
            }
        }

        if(nxt<=upper){
            string s=getrange(nxt,upper);
            ret.push_back(s);
        }

        return ret;
    }
};