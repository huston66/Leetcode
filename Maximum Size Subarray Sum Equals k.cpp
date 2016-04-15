class Solution {
public:
    int maxSubArrayLen(vector<int>& a, int k){
        int ma=0;
        unordered_map<int,int>mp;
        mp[0]=-1;

        int curr=0;
        int siz=a.size();
        for(int i=0;i<siz;i++){
            curr+=a[i];
            if(mp.count(curr-k))
            {
                ma=max(ma,i-mp[curr-k]);
            }
            else
            {
                mp[curr]=i;
            }
        }

        return ma;
    }
};