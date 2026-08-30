class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n=nums.size();
        if(n<=2) return n;
        int max_index=0;
        int min_index=0;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[max_index]){
                max_index=i;
            }
            if(nums[i]<nums[min_index]){
                min_index=i;
            }
        }
        int left=min(min_index,max_index);
        int right=max(min_index,max_index);

        int del_front=right+1;
        int del_back=n-left;
        int del_both=(left+1)+(n-right);
        return min({del_front,del_back,del_both});
    }
};