class Solution {
public:
    int threeSumSmaller(vector<int> nums, int target) {
        int siz=nums.size();
        if(siz==0)
            return 0;

        sort(nums.begin(),nums.end());
        int l=0;
        int r=siz-1;
        int cnt=0;
        for(int i=0;i<siz-2;i++)
        {
            int a=nums[i];
            int l=i+1;
            int r=siz-1;
            while(l<r)
            {
                int curr=a+nums[l]+nums[r];
                if(curr<target)
                {
                    cnt+=r-l;
                    l++;
                }
                else
                    r--;
            }
        }

        return cnt;
    }
};