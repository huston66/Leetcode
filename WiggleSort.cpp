class Solution {
public: 
    void wiggleSort(vector<int>& nums) {
        int siz=nums.size();
        for(int i=1;i<siz;i++)
        {
            if(nums[i]&1)
            {
                if(nums[i]<nums[i-1])
                    swap(nums[i],nums[i-1]);
            }
            else
            {
                if(nums[i]>nums[i-1])
                    swap(nums[i],nums[i-1]);
            }
        }
    } 
};